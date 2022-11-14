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
#define MAXN 300000 + 5
///**********************************START*********************************///
multiset<int> s;
int n, k;
int a[MAXN];

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   scanf( "%d %d", &n, &k );
   rep( i, 1, n ) scanf( "%d", &a[i] );
   int l = 1, r = 1;
   int ans = -1;
   while( r <= n )
   {
      s.insert( a[r] );
      while( k < ( *s.rbegin() - *s.begin() ) )
      {
         auto it = s.find( a[l] );
         s.erase( it );
         l++;
      }
      ans = max( ans, r - l + 1 );
      r++;
   }
   cout << ans << endl;
   return 0;
}