#pragma GCC optimize( 3 )
#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
#define rep( i, a, b ) for( int i = ( a ); i <= ( b ); i++ )
#define per( i, a, b ) for( int i = ( a ); i >= ( b ); i-- )
#define MEM( a, x ) memset( a, x, sizeof( a ) )
#define LL long long
#define MOD ( (int)1000000007 )
#define MAXN 1000 + 5
///**********************************START*********************************///

#define lson( index ) ( index << 1 )
#define rson( index ) ( index << 1 | 1 )

struct point
{
   int x, y;
} p[MAXN];

struct kdtree
{
   point c;
   int num;
} kd[MAXN];

bool
cmpx( point const& l, point const& r )
{
   return l.x < r.x;
}

bool
cmpy( point const& l, point const& r )
{
   return l.y < r.y;
}

//* even deep divide by x; odd deep divide by y
void
build( int rt, int l, int r, int deep )
{
   if( l == r )
   {
      kd[rt].c = p[l];
      kd[rt].num = 0;
      return;
   }
   int mid = ( l + r ) >> 1;
   if( !( deep & 1 ) )  // even
   {
      sort( p + l, p + r + 1, cmpx );
   }
   else
   {
      sort( p + l, p + r + 1, cmpy );
   }
   build( lson( rt ), l, mid, deep + 1 );
   build( rson( rt ), mid + 1, r, deep + 1 );
   kd[rt].c = p[mid];
   kd[rt].num = kd[lson( rt )].num + kd[rson( rt )].num;
   return;
}

int n;

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   cin >> n;
   for( int i = 0; i < n; i++ )
   {
      cin >> p[i].x >> p[i].y;
   }
   build( 1, 0, n, 0 );
   return 0;
}