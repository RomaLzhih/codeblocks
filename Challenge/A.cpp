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
#define MAXN 2000000 + 5
///**********************************START*********************************///
struct NODE
{
   LL l, r;
   bool
   operator<( const NODE& b ) const
   {
      return l == b.l ? r < b.r : l < b.l;
   };
} a[MAXN], b[MAXN];
int na = 0, nb = 0;
vector<NODE> ma, mb;

void
doMergeA()
{
   LL l = a[1].l, r = a[1].r;
   rep( i, 2, na )
   {
      if( a[i].l > r )
      {
         ma.push_back( { l, r } );
         l = a[i].l, r = a[i].r;
      }
      else if( a[i].r > r )
      {
         r = a[i].r;
      }
   }
   ma.push_back( { l, r } );
   // for (auto i : ma) cout << i.l << " " << i.r << endl;

   return;
}

void
doMergeB()
{
   LL l = b[1].l, r = b[1].r;
   rep( i, 2, nb )
   {
      if( b[i].l > r )
      {
         mb.push_back( { l, r } );
         l = b[i].l, r = b[i].r;
      }
      else if( b[i].r > r )
      {
         r = b[i].r;
      }
   }
   mb.push_back( { l, r } );
   // for (auto i : mb) cout << i.l << " " << i.r << endl;

   return;
}

LL
caplen( const LL& a, const LL& b, const LL& c, const LL& d )
{
   LL s = min( b, d ) - max( a, c ) + 1;
   return max( 1ll * 0, s );
}

LL
finalMerge()
{
   LL sum = 0;
   int i = 0, j = 0;
   LL len = 0;
   vector<bool> v( ma.size() + 1, 0 );

   while( i < ma.size() )
   {
      len = ma[i].r - ma[i].l + 1;
      if( j >= mb.size() )
      {
         sum += v[i] ? 0 : len;
         v[i++] = 1;
         continue;
      }

      LL cap = caplen( ma[i].l, ma[i].r, mb[j].l, mb[j].r );
      if( cap == 0 )
      {
         if( mb[j].r < ma[i].l )
         {  //* b is left to a, move b
            j++;
         }
         else
         {  //* b is right to a, move a
            sum += v[i] ? 0 : len;
            v[i++] = 1;
         }
      }
      else
      {
         sum += v[i] ? 0 : len;
         v[i] = 1;
         sum -= cap;

         if( ( ma[i].l <= mb[j].l ) && ( ma[i].r >= mb[j].r ) )
         {
            //* b in a, move b
            j++;
         }
         else if( ( ma[i].l >= mb[j].l ) && ( ma[i].r <= mb[j].r ) )
         {
            //* a in b, move a
            i++;
         }
         else if( ( ma[i].l < mb[j].l ) && ( ma[i].r >= mb[j].l ) &&
                  ( ma[i].r < mb[j].r ) )
         {
            //* a left cap on b, move a
            i++;
         }
         else if( ( mb[j].l < ma[i].l ) && ( mb[j].r >= ma[i].l ) &&
                  ( mb[j].r < ma[i].r ) )
         {
            //* b left cap on a, move b
            j++;
         }
      }
   }

   for( int j = 0; j < mb.size(); j++ )
   {
      sum += 3 * ( mb[j].r - mb[j].l + 1 );
   }
   return sum;
}

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   LL T;
   int n, m;
   LL l, r, c;
   scanf( "%lld %d %d", &T, &n, &m );
   rep( i, 1, n )
   {
      scanf( "%lld %lld %lld", &l, &r, &c );
      if( c == 0 )
         a[++na].l = l, a[na].r = r;
      else
         b[++nb].l = l, b[nb].r = r;
   }
   rep( i, 1, m )
   {
      scanf( "%lld %lld %lld", &l, &r, &c );
      if( c == 0 )
         a[++na].l = l, a[na].r = r;
      else
         b[++nb].l = l, b[nb].r = r;
   }
   sort( a + 1, a + na + 1 );
   sort( b + 1, b + nb + 1 );

   if( na ) doMergeA();
   if( nb ) doMergeB();

   printf( "%lld", finalMerge() );
   return 0;
}