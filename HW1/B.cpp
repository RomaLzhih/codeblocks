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
#define MAXN 500000 + 5
///**********************************START*********************************///
LL a[MAXN], b[MAXN];
LL cnt;

void
merge( int l, int mid, int r )
{
   int i = l, j = mid + 1;
   for( int k = l; k <= r; k++ )
   {
      if( j > r || i <= mid && a[i] < a[j] )
         b[k] = a[i++];
      else
         b[k] = a[j++], cnt += mid - i + 1;
   }
   for( int k = l; k <= r; k++ ) a[k] = b[k];
}

void
mergesort( int l, int r )
{
   if( l < r )
   {
      int mid = ( l + r ) / 2;
      mergesort( l, mid );
      mergesort( mid + 1, r );
      merge( l, mid, r );
   }
}

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   int n = READ();
   CLR( a );
   CLR( b );
   cnt = 0;
   rep( i, 0, n - 1 ) scanf( "%lld", &a[i] );
   mergesort( 0, n - 1 );
   printf( "%lld\n", cnt );
   return 0;
}