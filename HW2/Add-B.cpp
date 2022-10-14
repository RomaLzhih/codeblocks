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
#define MAXN 4000000 + 5
///**********************************START*********************************///
struct NODE
{
   long long l, r;
   bool
   operator<( const NODE& b ) const
   {
      return l < b.l;
   }
} inv[MAXN];

struct NEWNODE
{
   LL l, r;
   bool
   operator<( const NEWNODE& b ) const
   {
      return r > b.r;
   }
};

priority_queue<NEWNODE> q;

LL a[MAXN];

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   int n, m, nl = 0, ml = 0;
   scanf( "%d %d", &n, &m );
   rep( i, 1, n )
   {
      scanf( "%lld", &a[i] );
   }
   rep( i, 1, m )
   {
      scanf( "%lld %lld", &inv[i].l, &inv[i].r );
   }
   sort( a + 1, a + n + 1 );
   sort( inv + 1, inv + m + 1 );

   int i = 1, j = 1;
   int cnt = 0;
   while( i <= n )
   {
      while( j <= m )
      {
         if( inv[j].l <= a[i] )
         {
            q.push( NEWNODE{ inv[j].l, inv[j].r } );
            j++;
         }
         else
            break;
      }
      while( q.size() && q.top().r < a[i] )
      {
         q.pop();
      }

      if( !q.size() )
      {
         i++;
      }
      else if( q.top().r >= a[i] )
      {
         cnt++;
         i++;
         q.pop();
      }
   }
   cout << cnt << endl;
   return 0;
}