#pragma GCC optimize( 3 )
#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
#define rep( i, a, b ) for( int i = ( a ); i <= ( b ); i++ )
#define per( i, a, b ) for( int i = ( a ); i >= ( b ); i-- )
#define MEM( a, x ) memset( a, x, sizeof( a ) )
#define LL long long
#define MOD ( (int)1000000007 )
#define MAXN 1000 + 5
///**********************************START*********************************///

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   int a[] = { 1, 2, 3, 4, 5, 6, 7 };
   int *b = a + 1;
   int *c = a + 2;
   swap( b, c );
   cout << ( c > b ) << endl;

   return 0;
}