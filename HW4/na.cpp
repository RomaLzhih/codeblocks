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
#define MOD ( (unsigned long long)999983 )
#define MAXN 200000 + 5
///**********************************START*********************************///

int n;
int a[MAXN];
unsigned long long p[MAXN], h[MAXN];

const int SIZE = MAXN;
const int M = 1e5 + 7;

struct HashTable
{
   struct Node
   {
      int next, value;
      unsigned long long key;
   } data[SIZE];

   int head[M], size;

   void
   init()
   {
      size = 0;
      memset( head, 0, sizeof( head ) );
   }

   int
   f( unsigned long long key )
   {
      return key % M;
   }

   int
   get( unsigned long long key )
   {
      for( int p = head[f( key )]; p; p = data[p].next )
         if( data[p].key == key ) return data[p].value;
      return -1;
   }

   int
   modify( int key, int value )
   {
      for( int p = head[f( key )]; p; p = data[p].next )
         if( data[p].key == key ) return data[p].value = value;
   }

   int
   add( unsigned long long key, int value )
   {
      if( get( key ) != -1 ) return -1;
      data[++size] = ( Node ){ head[f( key )], value, key };
      head[f( key )] = size;
      return value;
   }
} H;

bool
check( int x )
{
   H.init();
   for( int i = x; i < n; ++i )
   {
      int ext = H.get( h[i] - h[i - x] * p[x] );
      if( ext != -1 && ext < i - x )
         return 1;
      else
         H.add( h[i] - h[i - x] * p[x], i );
   }
   return 0;
}

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   p[0] = 1;
   rep( i, 1, MAXN ) p[i] = p[i - 1] * MOD;

   scanf( "%d", &n );
   rep( i, 1, n ) scanf( "%d", &a[i] );

   rep( i, 1, n - 1 ) a[i] = a[i + 1] - a[i];
   h[0] = 0;
   rep( i, 1, n ) h[i] = h[i - 1] * MOD + a[i];

   int ans = 0;
   int l = 1, r = n - 1;
   while( l <= r )
   {
      int m = ( l + r ) >> 1;
      if( check( m ) )
         l = m + 1, ans = m;
      else
         r = m - 1;
   }
   cout << ans + 1 << endl;

   return 0;
}