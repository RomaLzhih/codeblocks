#pragma GCC optimize( 3 )
#include <time.h>

#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
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

template <typename T, typename U>
bool
allequal( const T &t, const U &u )
{
   return t == u;
}

template <typename T, typename U, typename... Others>
bool
allequal( const T &t, const U &u, Others const &...args )
{
   return ( t == u ) && allequal( u, args... );
}

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

string S;
map<int, char> mp = { { 1, 'O' }, { -1, 'X' } };

bool
checkWin( string a, char c )
{
   if( allequal( a[0], a[1], a[2], c ) ) return true;
   if( allequal( a[3], a[4], a[5], c ) ) return true;
   if( allequal( a[6], a[7], a[8], c ) ) return true;

   if( allequal( a[0], a[3], a[6], c ) ) return true;
   if( allequal( a[1], a[4], a[7], c ) ) return true;
   if( allequal( a[2], a[5], a[8], c ) ) return true;

   if( allequal( a[0], a[4], a[8], c ) ) return true;
   if( allequal( a[2], a[4], a[6], c ) ) return true;

   return false;
}

int
dfs( string s, int cur )
{
   if( checkWin( s, 'O' ) ) return 1;
   if( checkWin( s, 'X' ) ) return -1;
   if( (int)std::count( s.begin(), s.end(), '#' ) == 0 ) return 0;

   bool draw = false;
   for( int i = 0; i < 9; i++ )
   {
      if( s[i] != '#' ) continue;

      s[i] = mp[cur];
      int res = dfs( s, -cur );
      s[i] = '#';
      if( res == cur ) return res;
      if( res == -1 ) draw = true;
   }
   if( draw )
      return 0;
   else
      return -cur;
}

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   string s;
   int nx = 0, no = 0;
   rep( i, 1, 3 )
   {
      cin >> s;
      S.append( s.c_str() );
   }
   rep( i, 0, 8 )
   {
      if( S[i] == 'X' )
         nx++;
      else if( S[i] == 'O' )
         no++;
   }

   if( (int)std::count( S.begin(), S.end(), '#' ) == 9 )
   {
      cout << "Draw" << endl;
      return 0;
   }
   else if( checkWin( S, 'O' ) )
   {
      cout << "Noughts win" << endl;
      return 0;
   }
   else if( checkWin( S, 'X' ) )
   {
      cout << "Crosses win" << endl;
      return 0;
   }

   int st = nx > no ? 1 : -1;
   int ans = dfs( S, st );
   if( ans == 0 )
      cout << "Draw" << endl;
   else if( ans == 1 )
      cout << "Noughts win" << endl;
   else if( ans == -1 )
      cout << "Crosses win" << endl;

   return 0;
}