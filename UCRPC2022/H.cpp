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
#define MAXN 10 + 5
///**********************************START*********************************///
int a[MAXN];
LL f[MAXN];
LL dp[MAXN];
int n;
LL ans = -INF;
int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   scanf( "%d", &n );
   for( int i = 1; i <= n; i++ )
   {
      scanf( "%d", &a[i] );
   }
   int k = 1;
   dp[k] = a[1];
   f[k] = a[1];
   for( int i = 2; i <= n; i++ )
   {
      if( dp[k] < a[i] )
      {
         dp[++k] = a[i];
         f[k] = f[k - 1] + a[i];
      }  //如果比最后一个元素大，那么就添加再最后末尾处
      else
      {
         int pos = lower_bound( dp + 1, dp + 1 + k, a[i] ) - dp;
         f[pos] = max( f[pos], f[pos] - dp[pos] + a[i] );
         dp[pos] = a[i];
      }
      //如果比最后一个元素小，那么就替换该序列第一个比他大的数；
   }
   for( int i = 1; i <= n; i++ ) ans = max( ans, f[i] );
   cout << k << endl;
   //    ans = k;
   printf( "%lld\n", ans );
   return 0;
}