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
map<int, char> mp = { { 0, 'O' }, { 1, 'X' } };
map<string, int> state;

bool
checkWin( string s )
{
   if( s[0] == s[1] && s[1] == s[2] ) return true;
   if( s[3] == s[4] && s[4] == s[5] ) return true;
   if( s[6] == s[7] && s[7] == s[8] ) return true;

   if( s[0] == s[3] && s[3] == s[6] ) return true;
   if( s[1] == s[4] && s[4] == s[7] ) return true;
   if( s[2] == s[5] && s[5] == s[8] ) return true;

   if( s[0] == s[4] && s[4] == s[8] ) return true;
   if( s[2] == s[4] && s[4] == s[6] ) return true;

   return false;
}

int
dfs( string s, int cur )
{
   bool win = true;
   for( int i = 0; i < s.size(); i++ )
   {
      if( s[i] != '#' ) continue;

      s[i] = mp[cur];

      if( checkWin( s ) )
      {
         return 1;
      }
      else
      {
         std::string::difference_type n = std::count( s.begin(), s.end(), '#' );
         if( n == 0 ) return -1;
      }

      int res = dfs( s, !cur );
      s[i] = '#';

      if( res == 0 )
      {  // next player lose on new s, I win
         return 1;
      }
      else if( res == -1 )
         // draw on s
         win = false;
      else if( res == 1 )
         // next player win s
         ;
   }
   if( win )     // all new state is he win
      return 0;  // I lose
   else
      return -1;  // draw
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

   int st = nx > no ? 0 : 1;

   if( checkWin( S ) )
   {
      if( st == 0 ) cout << "Crosses win" << endl;
      if( st == 1 ) cout << "Noughts win" << endl;
      return 0;
   }
   else
   {
      std::string::difference_type n = std::count( s.begin(), s.end(), '#' );
      if( n == 0 ) cout << "Draw" << endl;
      return 0;
   }

   int ans = dfs( S, st );

   if( ans == -1 )
      cout << "Draw" << endl;
   else if( ans == 1 )
   {
      if( st == 0 ) cout << "Noughts win" << endl;
      if( st == 1 ) cout << "Crosses win" << endl;
   }
   else if( ans == 0 )
   {
      if( st == 0 ) cout << "Crosses win" << endl;
      if( st == 1 ) cout << "Noughts win" << endl;
   }
   return 0;
}