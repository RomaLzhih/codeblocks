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
int n;
struct NODE
{
   int id, cnt;
   bool
   operator<( const NODE& b ) const
   {
      return cnt > b.cnt;
   }
};

vector<NODE> g1, g2, g3;

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   n = READ();
   int id, sc, g;
   rep( i, 1, n )
   {
      scanf( "%d %d", &g, &sc );
      if( g == 1 )
         g1.push_back( NODE{ i, sc } );
      else if( g == 2 )
         g2.push_back( NODE{ i, sc } );
      else if( g == 3 )
         g3.push_back( NODE{ i, sc } );
   }
   sort( g1.begin(), g1.end() );
   sort( g2.begin(), g2.end() );
   sort( g3.begin(), g3.end() );

   printf( "%d\n", g1[0].id );
   printf( "%d\n", g2[0].id );
   printf( "%d", g3[0].id );

   return 0;
}