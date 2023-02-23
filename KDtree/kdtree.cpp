#pragma GCC optimize( 3 )

#include <float.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <algorithm>
#include <queue>

#define MAX_DIM 6
#define MAXN 100000 + 5
const long double eps = 1e-10;

int N, Dim, Q, K;
std::priority_queue<long double> q;

struct kd_node_t
{
   long double x[MAX_DIM];
   struct kd_node_t *left, *right;
};

struct node_cmp
{
   node_cmp( size_t index ) : index_( index ) {}
   bool
   operator()( const kd_node_t &n1, const kd_node_t &n2 ) const
   {
      return n1.x[index_] < n2.x[index_];
   }
   size_t index_;
};

struct kd_node_t *root, *found, wp[MAXN];

inline long double
dist( struct kd_node_t *a, struct kd_node_t *b, int dim )
{
   long double t, d = 0.0;
   while( dim-- )
   {
      t = a->x[dim] - b->x[dim];
      d += t * t;
   }
   return d;
}

inline void
swap( struct kd_node_t *x, struct kd_node_t *y )
{
   long double tmp[MAX_DIM];
   memcpy( tmp, x->x, sizeof( tmp ) );
   memcpy( x->x, y->x, sizeof( tmp ) );
   memcpy( y->x, tmp, sizeof( tmp ) );
}

struct kd_node_t *
find_median( struct kd_node_t *start, struct kd_node_t *end, int idx )
{
   if( end <= start ) return NULL;
   if( end == start + 1 ) return start;

   struct kd_node_t *p, *store, *md = start + ( ( end - start ) / 2 ),
                                *bk = start;
   long double pivot;

   int l = 0, r = 0, mid = ( end - start ) >> 1;

   while( 1 )
   {
      pivot = md->x[idx];

      swap( md, end - 1 );
      for( store = p = start; p < end - 1; p++ )
      {
         if( p->x[idx] - pivot < -eps )
         {
            if( p != store ) swap( p, store );
            store++;
         }
      }
      swap( store, end - 1 );

      if( store->x[idx] == md->x[idx] ) return md;
      if( abs( store - bk ) > abs( md - bk ) )
         end = store;
      else
         start = store;
   }
}

struct kd_node_t *
make_tree( struct kd_node_t *t, int len, int i, int dim )
{
   struct kd_node_t *n;
   int nl = len >> 1;
   if( !len ) return 0;

   // std::sort( t, t + len, node_cmp( i ) );

   std::nth_element( t, t + len / 2, t + len, node_cmp( i ) );
   i = ( i + 1 ) % dim;
   n = t + ( len >> 1 );
   n->left = make_tree( t, n - t, i, dim );
   n->right = make_tree( n + 1, t + len - ( n + 1 ), i, dim );

   // n = find_median( t, t + len, i );
   // i = ( i + 1 ) % dim;
   // n->left = make_tree( t, n - t, i, dim );
   // n->right = make_tree( n + 1, t + len - ( n + 1 ), i, dim );

   return n;
}

void
k_nearest( struct kd_node_t *root, struct kd_node_t *nd, int i, int dim )
{
   long double d, dx, dx2;

   if( !root ) return;
   d = dist( root, nd, dim );
   dx = root->x[i] - nd->x[i];
   dx2 = dx * dx;
   // printf( "%Lf %Lf\n", sqrt( d ), q.size() ? sqrt( q.top() ) : -1 );

   if( q.size() < K || d - q.top() < eps )
   {
      q.push( d );
      if( q.size() > K ) q.pop();
   }

   if( ++i >= dim ) i = 0;

   k_nearest( dx > 0 ? root->left : root->right, nd, i, dim );
   if( dx2 - q.top() >= eps && q.size() >= K ) return;
   k_nearest( dx > 0 ? root->right : root->left, nd, i, dim );
}

void
nearest( struct kd_node_t *root, struct kd_node_t *nd, long double &nDist,
         int i, int dim )
{
   long double d, dx, dx2;

   if( !root ) return;
   d = dist( root, nd, dim );
   dx = root->x[i] - nd->x[i];
   dx2 = dx * dx;

   if( d < nDist ) nDist = d;
   if( ++i >= dim ) i = 0;
   nearest( dx > 0 ? root->left : root->right, nd, nDist, i, dim );
   if( dx2 - nDist >= eps ) return;
   nearest( dx > 0 ? root->right : root->left, nd, nDist, i, dim );
}

void
rangeQuery()
{
}

void
query_k_Nearest()
{
   int i, j;
   scanf( "%d", &Q );
   struct kd_node_t z;
   while( Q-- )
   {
      scanf( "%d", &K );
      for( j = 0; j < Dim; j++ ) scanf( "%Lf", &z.x[j] );
      while( !q.empty() ) q.pop();
      k_nearest( root, &z, 0, Dim );
      // printf( "%ld\n", q.size() );
      printf( "%.8Lf\n", sqrt( q.top() ) );
   }
}

void
queryNearest()
{
   int i, j;
   scanf( "%d", &Q );
   struct kd_node_t z;
   while( Q-- )
   {
      long double nDist = LDBL_MAX;
      scanf( "%d", &K );
      for( j = 0; j < Dim; j++ ) scanf( "%Lf", &z.x[j] );
      nearest( root, &z, nDist, 0, Dim );
      // printf( "%ld\n", q.size() );
      printf( "%.8Lf\n", sqrt( nDist ) );

      //* check
      for( int i = 0; i < N; i++ )
      {
         if( dist( wp + i, &z, Dim ) - nDist < -eps )
         {
            printf( "wrong\n" );
         }
      }
   }
}

void
queryRangePoints()
{
}

int
main( void )
{
#ifndef ONLINE_JUDGE
   freopen( "../input.txt", "r", stdin );
#endif

   scanf( "%d %d", &N, &Dim );
   int i, j;

   for( i = 0; i < N; i++ )
   {
      for( j = 0; j < Dim; j++ )
      {
         scanf( "%Lf", &wp[i].x[j] );
      }
   }

   root = make_tree( wp, N, 0, Dim );
   queryNearest();
   // querykNearest();

   return 0;
}
