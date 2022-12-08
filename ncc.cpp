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
#define N 100000 + 5
#define M 200000 + 5
///**********************************START*********************************///
int ver[M], Next[M], head[N], dfn[N], low[N];
int _stack[N], ins[N], c[N];
vector<int> scc[N];
int n, m, tot, num, top, cnt;

void
add( int x, int y )
{
   ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

void
tarjan( int x )
{
   dfn[x] = low[x] = ++num;
   _stack[++top] = x, ins[x] = 1;
   for( int i = head[x]; i; i = Next[i] )
   {
      if( !dfn[ver[i]] )
      {
         tarjan( ver[i] );
         low[x] = min( low[x], low[ver[i]] );
      }
      else if( ins[ver[i]] )
         low[x] = min( low[x], dfn[ver[i]] );
   }
   if( dfn[x] == low[x] )
   {
      cnt++;
      int y;
      do
      {
         y = _stack[top--], ins[y] = 0;
         c[y] = cnt, scc[cnt].push_back( y );
      } while( x != y );
   }
}

int vc[M], nc[M], hc[N], tc;
void
add_c( int x, int y )
{
   vc[++tc] = y, nc[tc] = hc[x], hc[x] = tc;
}

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   n = 11;
   add( 1, 2 );
   add( 2, 4 );
   add( 1, 4 );
   add( 3, 1 );
   add( 4, 3 );

   add( 5, 4 );
   add( 6, 5 );
   add( 6, 7 );
   add( 7, 4 );

   add( 4, 8 );
   add( 7, 8 );
   add( 8, 9 );
   add( 8, 10 );
   add( 7, 11 );
   add( 11, 10 );
   add( 10, 9 );
   rep( i, 1, n ) if( !dfn[i] ) tarjan( i );
   cout << cnt << endl;
   rep( i, 1, cnt )
   {
      for( auto i : scc[i] ) cout << i << " ";
      cout << endl;
   }
   return 0;
}