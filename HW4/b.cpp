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
#define rep( i, a, b ) for( int i = ( a ); i <= ( b ); i++ )
#define per( i, a, b ) for( int i = ( a ); i >= ( b ); i-- )
#define MP( x, y ) make_pair( x, y )
#define PB( x ) push_back( x )
#define CLR( a ) memset( a, 0, sizeof( a ) )
#define MEM( a, x ) memset( a, x, sizeof( a ) )
#define ALL( x ) begin( x ), end( x )
#define LL long long
#define Lson ( index * 2 )
#define Rson ( index * 2 + 1 )
#define MOD ( (int)1000000007 )
#define MAXN 1000 + 5
///**********************************START*********************************///
int n, k;
char s[MAXN];
map<char, int> mp;
int f[MAXN][MAXN];

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   scanf( "%d %d", &n, &k );
   int p;
   rep( i, 1, k )
   {
      scanf( "%d", &p );
      mp['a' + i - 1] = p;
   }
   scanf( "%s", s + 1 );
   rep( i, 1, n ) f[i][i] = 0;

   for( int i = n - 1; i >= 1; i-- )
   {
      for( int j = i + 1; j <= n; j++ )
      {
         if( s[i] == s[j] )
            f[i][j] = f[i + 1][j - 1];
         else
         {
            f[i][j] = min( f[i][j - 1] + mp[s[j]],
                           min( f[i + 1][j] + mp[s[i]],
                                f[i + 1][j - 1] + mp[s[i]] + mp[s[j]] ) );
         }
      }
   }
   cout << f[1][n] << endl;
   return 0;
}