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
#define MAXN 100 + 5
///**********************************START*********************************///

int dr[] = { 1, -1, 0, 0, 0 };
int dc[] = { 0, 0, 1, -1, 0 };

int a[MAXN][MAXN][MAXN];
int f[MAXN][MAXN][MAXN];
bool v[MAXN][MAXN][MAXN];

int n, p, b;
int sr, sc;
int mxt = -1;

bool
legal( int x, int y )
{
   return x >= 1 && x <= n && y >= 1 && y <= n;
}

int
dp( int x, int y, int t )
{
   if( v[x][y][t] != 0 ) return f[x][y][t];
   v[x][y][t] = 1;
   int mx = 0;
   rep( i, 0, 4 )
   {
      int nx = x + dr[i];
      int ny = y + dc[i];
      int nt = t + 1;
      if( legal( nx, ny ) && nt <= mxt )
      {
         mx = max( mx, dp( nx, ny, nt ) );
      }
   }

   if( a[x][y][t] == 1 )
      f[x][y][t] = mx + 1;
   else if( a[x][y][t] == -1 )
      f[x][y][t] = mx - ceil( 1.0 * mx / 2 );
   else
      f[x][y][t] = mx;

   return f[x][y][t];
}

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif

   memset( f, 0, sizeof( f ) );
   memset( v, 0, sizeof( v ) );
   memset( a, 0, sizeof( a ) );

   scanf( "%d %d %d", &n, &p, &b );
   scanf( "%d %d", &sr, &sc );
   sr++, sc++;
   int x, y, t;
   rep( i, 1, p )
   {
      scanf( "%d %d %d", &x, &y, &t );
      x++, y++;
      a[x][y][t] = 1;
      mxt = max( mxt, t );
   }
   rep( i, 1, b )
   {
      scanf( "%d %d %d", &x, &y, &t );
      x++, y++;
      a[x][y][t] = -1;
      mxt = max( mxt, t );
   }

   int ans = -1;

   cout << dp( sr, sc, 0 ) << endl;

   // rep( i, 1, n ) rep( j, 1, n ) ans = max( ans, f[i][j][1] );

   // rep( i, 1, n ) rep( j, 1, n ) rep( t, 1, mxt ) cout
   //     << i << " " << j << " " << t << " " << f[i][j][t] << endl;

   // cout << ans << endl;
   return 0;
}