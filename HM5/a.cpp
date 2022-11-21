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
#define MAXN 100000 + 5
#define MAXM 1000000 + 5
///**********************************START*********************************///
struct rec
{
   int x, y, z;
} edge[MAXM];

int fa[MAXN], n, m, ans = -1;

bool
operator<( rec a, rec b )
{
   return a.z < b.z;
}

int
get( int x )
{
   if( x == fa[x] ) return x;
   return fa[x] = get( fa[x] );
}

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   scanf( "%d %d", &n, &m );
   rep( i, 1, m ) scanf( "%d %d %d", &edge[i].x, &edge[i].y, &edge[i].z );
   sort( edge + 1, edge + m + 1 );
   rep( i, 1, n ) fa[i] = i;
   rep( i, 1, m )
   {
      int x = get( edge[i].x );
      int y = get( edge[i].y );
      if( x == y ) continue;
      fa[x] = y;
      ans = max( ans, edge[i].z );
   }
   cout << ans << endl;

   return 0;
}