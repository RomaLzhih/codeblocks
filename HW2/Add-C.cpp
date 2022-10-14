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
#define MAXN 100000 + 5
///**********************************START*********************************///
int N;
struct NODE
{
   int id;
   LL r = 0;
   bool
   operator<( const NODE& b ) const
   {
      return r < b.r;
   }
} a[MAXN], b[MAXN];

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   LL x1, y1, x2, y2;
   LL x, y;
   scanf( "%lld %lld %lld %lld", &x1, &y1, &x2, &y2 );
   scanf( "%d", &N );
   rep( i, 1, N )
   {
      scanf( "%lld %lld", &x, &y );
      a[i].id = i;
      b[i].id = i;

      a[i].r = ( x - x1 ) * ( x - x1 ) + ( y - y1 ) * ( y - y1 );
      b[i].r = ( x - x2 ) * ( x - x2 ) + ( y - y2 ) * ( y - y2 );
   }
   sort( a + 1, a + N + 1 );
   LL mx = 0;
   LL ans = LLINF;

   per( i, N, 0 )
   {
      ans = min( ans, a[i].r + mx );
      if( b[a[i].id].r > mx ) mx = b[a[i].id].r;
   }
   cout << ans << endl;
   return 0;
}