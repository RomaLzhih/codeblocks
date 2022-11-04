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
int dp[105][400005];
int s[105], f[105];
int n;

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   CLR( dp );
   scanf( "%d", &n );
   rep( i, 1, n ) scanf( "%d %d", &s[i], &f[i] );

   int up = 4 * n * 1000;
   int base = up >> 1;

   rep( j, 0, up ) dp[0][j] = INT_MIN / 2;
   dp[0][base] = 0;

   rep( i, 1, n ) rep( j, 0, up )
   {
      dp[i][j] = dp[i - 1][j];
      int tmp = j - ( s[i] - f[i] );
      if( tmp >= 0 && tmp <= up )
      {
         dp[i][j] = max( dp[i][j], dp[i - 1][tmp] + ( s[i] + f[i] ) );
      }
   }

   int ans = 0;
   rep( j, 0, up )
   {
      int diff = j - base;
      int sum = dp[n][j];
      int sumS = ( sum + diff ) >> 1;
      int sumF = ( sum - diff ) >> 1;
      if( sumS >= 0 && sumF >= 0 && dp[n][j] >= 0 ) ans = max( ans, dp[n][j] );
   }
   cout << ans << endl;
   return 0;
}