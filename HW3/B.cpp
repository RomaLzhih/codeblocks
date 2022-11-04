#pragma GCC optimize( 3 )
#include <time.h>

#include <algorithm>
#include <bitset>
#include <cctype>
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
const int INF = 2147483647;
const long long LLINF = 9223372036854775807;
const double PI = acos( -1.0 );

inline int
READ()
{
   char ch;
   while( ( ch = getchar() ) < 48 || 57 < ch )
      ;
   int ans = ch - 48;
   while( 48 <= ( ch = getchar() ) && ch <= 57 )
      ans = ( ans << 3 ) + ( ans << 1 ) + ch - 48;
   return ans;
}

#define rep( i, a, b ) for( int i = ( a ); i <= ( b ); i++ )
#define per( i, a, b ) for( int i = ( a ); i >= ( b ); i-- )
#define FOREACH( i, t ) \
   for( typeof( t.begin() ) i = t.begin(); i != t.end(); i++ )
#define MP( x, y ) make_pair( x, y )
#define PB( x ) push_back( x )
#define SET( a ) memset( a, -1, sizeof( a ) )
#define CLR( a ) memset( a, 0, sizeof( a ) )
#define MEM( a, x ) memset( a, x, sizeof( a ) )
#define ALL( x ) begin( x ), end( x )
#define LL long long
#define Lson ( index * 2 )
#define Rson ( index * 2 + 1 )
#define pii pair<int, int>
#define pll pair<LL, LL>
#define MOD ( (int)1000000007 )
#define MAXN 1000 + 5
///**********************************START*********************************///

int dr[] = { 1, -1, 0, 0 };
int dc[] = { 0, 0, 1, -1 };

LL a[MAXN][MAXN];
int f[MAXN][MAXN];

int n, m;

bool
legal( int x, int y )
{
   return x >= 1 && x <= n && y >= 1 && y <= m;
}

int
dp( int x, int y )
{
   if( f[x][y] != 1 ) return f[x][y];
   int mx = 0;
   rep( i, 0, 3 )
   {
      int nx = x + dr[i];
      int ny = y + dc[i];
      if( legal( nx, ny ) && a[x][y] > a[nx][ny] )
      {
         mx = max( mx, dp( nx, ny ) + 1 );
      }
   }
   f[x][y] = mx;
   return f[x][y];
}

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   scanf( "%d %d", &n, &m );
   rep( i, 1, n ) rep( j, 1, m )
   {
      scanf( "%lld", &a[i][j] );
      f[i][j] = 1;
   }
   int ans = -1;
   rep( i, 1, n ) rep( j, 1, m ) ans = max( ans, dp( i, j ) + 1 );
   cout << ans << endl;
   return 0;
}