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
#define ull unsigned long long
using namespace std;
const int maxn = 2e4 + 7;
const int HASH = 1e4 + 7;
struct HASHMAP
{
   int head[HASH], next[maxn], size;
   unsigned long long state[maxn];
   int f[maxn];
   void
   init()
   {
      size = 0;
      memset( head, -1, sizeof( head ) );
   }
   int
   insert( unsigned long long val, int _id )
   {
      int h = val % HASH;
      for( int i = head[h]; i != -1; i = next[i] )
         if( val == state[i] )
         {
            return f[i];
         }
      f[size] = _id;
      state[size] = val;
      next[size] = head[h];
      head[h] = size++;
      return f[size - 1];
   }
} H;
int n;
int a[maxn];
ull p[maxn], h[maxn];
const ull P = 999983;
int
judge( int x )
{
   H.init();
   for( int i = x; i < n; ++i )
      if( H.insert( h[i] - h[i - x] * p[x], i ) < i - x ) return 1;
   return 0;
}
int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   p[0] = 1;
   for( int i = 1; i <= maxn; ++i ) p[i] = p[i - 1] * P;
   while( ~scanf( "%d", &n ) && n )
   {
      for( int i = 1; i <= n; ++i ) scanf( "%d", &a[i] );
      for( int i = 1; i < n; ++i ) a[i] = a[i + 1] - a[i];
      h[0] = 0;
      for( int i = 1; i <= n; ++i ) h[i] = h[i - 1] * P + a[i];
      int l = 1, r = n - 1;
      int ans = 0;
      while( l <= r )
      {
         int mid = ( l + r ) / 2;
         if( judge( mid ) )
         {
            l = mid + 1;
            ans = mid;
         }
         else
            r = mid - 1;
      }
      if( ans < 4 ) ans = -1;
      printf( "%d\n", ++ans );
   }
   return 0;
}