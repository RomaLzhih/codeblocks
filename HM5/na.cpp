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
const LL inf = LLONG_MAX;
const int N = 50010, M = 300010;
int head[N], ver[M], Next[M], d[N];
LL edge[M], now[M];

int n, m, s, t, tot;
LL maxflow;

queue<int> q;
void
add( int x, int y, LL z )
{
   ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
   ver[++tot] = x, edge[tot] = 0, Next[tot] = head[y], head[y] = tot;
}

bool
bfs()
{
   memset( d, 0, sizeof( d ) );
   while( q.size() ) q.pop();
   q.push( s );
   d[s] = 1;
   now[s] = head[s];
   while( q.size() )
   {
      int x = q.front();
      q.pop();
      for( int i = head[x]; i; i = Next[i] )
         if( edge[i] && !d[ver[i]] )
         {
            q.push( ver[i] );
            now[ver[i]] = head[ver[i]];
            d[ver[i]] = d[x] + 1;
            if( ver[i] == t ) return 1;
         }
   }
   return 0;
}

LL
dinic( int x, LL flow )
{
   if( x == t ) return flow;
   LL rest = flow;
   int k, i;
   for( i = now[x]; i && rest; i = Next[i] )
   {
      now[x] = i;
      if( edge[i] && d[ver[i]] == d[x] + 1 )
      {
         k = dinic( ver[i], min( rest, edge[i] ) );
         if( !k ) d[ver[i]] = 0;
         edge[i] -= k;
         edge[i ^ 1] += k;
         rest -= k;
      }
   }
   return flow - rest;
}

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   cin >> n >> m;
   cin >> s >> t;
   tot = 1;
   for( int i = 1; i <= m; i++ )
   {
      int x, y;
      LL c;
      scanf( "%d%d%lld", &x, &y, &c );
      add( x, y, c );
      add( y, x, c );
   }
   LL flow = 0;
   while( bfs() )
      while( flow = dinic( s, inf ) ) maxflow += flow;
   cout << maxflow << endl;
   return 0;
}