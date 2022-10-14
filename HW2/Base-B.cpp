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
int M;
int p[MAXN];
struct NODE
{
   int p, id;
   bool
   operator<( const NODE& b ) const
   {
      return p < b.p;
   }
} f[MAXN];

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   scanf( "%d", &M );
   rep( i, 1, 9 )
   {
      scanf( "%d", &p[i] );
      f[i] = NODE{ p[i], i };
   }
   sort( f + 1, f + 9 + 1 );
   //    rep( i, 1, 9 ) cout << f[i].p << " " << f[i].id << endl;
   int num = M / f[1].p;
   int I = f[1].id;
   string ans( num, '0' + I );
   //    cout << ans << endl;
   int re = M - num * p[I];
   int i = 0;
   while( re >= 0 && i < num )
   {
      bool flag = false;
      for( int j = 9; j > I; j-- )
      {
         if( re + p[I] - p[j] >= 0 )
         {
            ans[i] = '0' + j;
            re = re + p[I] - p[j];
            i++;
            flag = true;
            break;
         }
      }
      if( !flag ) break;
   }
   cout << ans << endl;
   return 0;
}