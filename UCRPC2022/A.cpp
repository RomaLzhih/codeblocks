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
int k;
int c[3];
bool flag;

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   k = READ();
   int maxGal = ceil( 1.0 * k / 1 );
   int maxSick = ceil( 1.0 * k / 29 );
   int maxGalleon = ceil( 1.0 * k / ( 29 * 17 ) );
   for( int i = 0; i < 29; i++ )
   {
      for( int j = 0; j < 17; j++ )
      {
         int forGal = k - i - 29 * j;
         if( forGal >= 0 && forGal % ( 17 * 29 ) == 0 )
         {
            printf( "%d %d %d", ( k - i - 29 * j ) / ( 17 * 29 ), j, i );
            return 0;
         }
      }
   }
   return 0;
}