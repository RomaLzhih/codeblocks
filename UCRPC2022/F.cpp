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
map<int, int> mpx;
map<int, int> mpy;
int n, deg;
double len;
struct NODE
{
   int pos, num;
};
vector<NODE> X, Y;

int
countX()
{
   len *= 2;
   int l = 0, r = 0;
   int ans = 0;
   int sum = 0;
   while( r < X.size() )
   {
      while( r < X.size() && abs( 1.0 * X[r].pos - X[l].pos ) <= len - EPS )
      {
         sum += X[r].num;
         ans = max( ans, sum );
         r++;
      }
      sum -= X[l].num;
      l++;
      ans = max( ans, sum );
      if( l >= X.size() ) break;
   }
   return ans;
}

int
countY()
{
   len *= 2;
   int l = 0, r = 0;
   int ans = 0;
   int sum = 0;
   while( r < Y.size() )
   {
      while( r < Y.size() && abs( 1.0 * Y[r].pos - Y[l].pos ) <= len + EPS )
      {
         sum += Y[r].num;
         ans = max( ans, sum );
         r++;
      }
      sum -= Y[l].num;
      l++;
      ans = max( ans, sum );
      if( l >= Y.size() ) break;
   }
   return ans;
}

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   scanf( "%d%d", &n, &deg );
   cin >> len;
   int x, y;
   rep( i, 1, n )
   {
      scanf( "%d %d", &x, &y );
      if( mpx.count( x ) )
         mpx[x]++;
      else
         mpx[x] = 1;

      if( mpy.count( y ) )
         mpy[y]++;
      else
         mpy[y] = 1;
   }

   for( auto i : mpx )
   {
      X.push_back( NODE{ i.first, i.second } );
   }
   for( auto i : mpy )
   {
      Y.push_back( NODE{ i.first, i.second } );
   }

   if( deg == 0 )
      cout << countY() << endl;
   else
      cout << countX() << endl;

   return 0;
}