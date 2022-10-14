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
map<string, int> mp;
map<int, string> newmp;
vector<string> name{ "Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin" };

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   string s1, s2, s;
   cin >> s1 >> s2;
   mp[s1] = 0;
   mp[s2] = 0;
   while( getline( cin, s ) )
   {
      if( s == "" ) continue;
      if( s.find( " " ) == string::npos )
      {
         //  cout << s << endl;
         mp[s] += 10;
      }
      else
      {
         //  cout << s.substr( 0, s.find_first_of( " " ) ) << endl;
         mp[s.substr( 0, s.find_first_of( " " ) )] += 150;
      }
   }

   int score1 = -1, score2 = -1;
   for( auto i : mp )
   {
      //   cout << i.first << " " << i.second << endl;
      if( score1 == -1 )
      {
         score1 = i.second, s1 = i.first;
      }
      else
      {
         score2 = i.second, s2 = i.first;
      }
   }

   score1 = score1 == -1 ? 0 : score1;
   score2 = score2 == -1 ? 0 : score2;

   if( score1 == score2 )
   {
      cout << "Tie" << endl;
      cout << score1 << "-" << score2 << endl;
   }
   else if( score1 > score2 )
   {
      cout << s1 << " wins" << endl;
      cout << score1 << "-" << score2 << endl;
   }
   else
   {
      cout << s2 << " wins" << endl;
      cout << score2 << "-" << score1 << endl;
   }
   return 0;
}