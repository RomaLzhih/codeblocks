#pragma GCC optimize( 3 )
#include <time.h>

#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
const double EPS = 1e-9;
#define rep( i, a, b ) for( int i = ( a ); i <= ( b ); i++ )
#define per( i, a, b ) for( int i = ( a ); i >= ( b ); i-- )
#define MP( x, y ) make_pair( x, y )
#define PB( x ) push_back( x )
#define CLR( a ) memset( a, 0, sizeof( a ) )
#define MEM( a, x ) memset( a, x, sizeof( a ) )
#define ALL( x ) begin( x ), end( x )
#define LL long long
#define Lson ( index * 2 )
#define Rson ( index * 2 + 1 )
#define MOD ( (int)1000000007 )
#define N 2000 + 5
#define M 4000000 + 5
using namespace std;
struct S
{
   LL x, y, v;
} a[N];
struct T
{
   LL x, y;
} b[N];
int n, m;
LL t;

double
dist( double x, double y, double xx, double yy )
{
   return sqrt( ( x - xx ) * ( x - xx ) + ( y - yy ) * ( y - yy ) );
}

struct augment_path
{
   vector<vector<int> > g;
   vector<int> pa;  // 匹配
   vector<int> pb;
   vector<int> vis;  // 访问
   int n, m;         // 两个点集中的顶点数量
   int dfn;          // 时间戳记
   int res;          // 匹配数

   augment_path( int _n, int _m ) : n( _n ), m( _m )
   {
      pa = vector<int>( n, -1 );
      pb = vector<int>( m, -1 );
      vis = vector<int>( n );
      g.resize( n );
      res = 0;
      dfn = 0;
   }

   void
   add( int from, int to )
   {
      g[from].push_back( to );
   }

   bool
   dfs( int v )
   {
      vis[v] = dfn;
      for( int u : g[v] )
      {
         if( pb[u] == -1 )
         {
            pb[u] = v;
            pa[v] = u;
            return true;
         }
      }
      for( int u : g[v] )
      {
         if( vis[pb[u]] != dfn && dfs( pb[u] ) )
         {
            pa[v] = u;
            pb[u] = v;
            return true;
         }
      }
      return false;
   }

   int
   solve()
   {
      while( true )
      {
         dfn++;
         int cnt = 0;
         for( int i = 0; i < n; i++ )
         {
            if( pa[i] == -1 && dfs( i ) )
            {
               cnt++;
            }
         }
         if( cnt == 0 )
         {
            break;
         }
         res += cnt;
      }
      return res;
   }
};

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   scanf( "%d %d %lld", &n, &m, &t );
   for( int i = 0; i < n; i++ )
   {
      scanf( "%lld%lld%lld", &a[i].x, &a[i].y, &a[i].v );
   }
   for( int i = 0; i < m; i++ )
   {
      scanf( "%lld%lld", &b[i].x, &b[i].y );
   }

   augment_path H( N, M );

   for( int i = 0; i < n; i++ )
   {
      for( int j = 0; j < m; j++ )
      {
         LL A = ( a[i].x - b[j].x ) * ( a[i].x - b[j].x ) +
                ( a[i].y - b[j].y ) * ( a[i].y - b[j].y );
         LL B = a[i].v * t * a[i].v * t;
         if( A <= B )
         {
            H.add( i + m, j );
         }
      }
   }
   int ans = H.solve();
   cout << n - ans << endl;
   return 0;
}
