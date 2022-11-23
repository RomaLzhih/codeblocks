#pragma GCC optimize( 3 )
#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
#define rep( i, a, b ) for( int i = ( a ); i <= ( b ); i++ )
#define per( i, a, b ) for( int i = ( a ); i >= ( b ); i-- )
#define MEM( a, x ) memset( a, x, sizeof( a ) )
#define LL long long
#define MOD ( (int)1000000007 )
#define SIZE 2000 + 5
#define MAXN 2000 * 2000 + 5
///**********************************START*********************************///

int n, m, s, t;
const int INF = 0x7fffffff;

struct Edge
{
   int from, to, cap, flow;
};
struct Dinic
{
   int n, m, s, t;
   vector<Edge> edges;
   vector<int> G[MAXN];
   bool vis[MAXN];
   int d[MAXN];
   int cur[MAXN];
   void
   init( int n )
   {
      for( int i = 0; i < MAXN; i++ ) G[i].clear();
      edges.clear();
      memset( d, 0, sizeof( d ) );
   }
   void
   AddEdge( int from, int to, int cap )
   {
      edges.push_back( { from, to, cap, 0 } );
      edges.push_back( { to, from, 0, 0 } );
      m = edges.size();
      G[from].push_back( m - 2 );
      G[to].push_back( m - 1 );
   }
   bool
   BFS()
   {
      int x, i;
      memset( vis, 0, sizeof( vis ) );
      queue<int> Q;
      Q.push( s );
      d[s] = 0;
      vis[s] = 1;
      while( !Q.empty() )
      {
         x = Q.front(), Q.pop();
         for( i = 0; i < G[x].size(); i++ )
         {
            Edge &e = edges[G[x][i]];
            if( !vis[e.to] && e.cap > e.flow )
            {
               vis[e.to] = 1;
               d[e.to] = d[x] + 1;
               Q.push( e.to );
            }
         }
      }
      return vis[t];
   }
   int
   DFS( int x, int a )
   {
      if( x == t || a == 0 ) return a;
      int flow = 0, f;
      for( int &i = cur[x]; i < G[x].size(); i++ )
      {
         Edge &e = edges[G[x][i]];
         if( d[x] + 1 == d[e.to] &&
             ( f = DFS( e.to, min( a, e.cap - e.flow ) ) ) > 0 )
         {
            e.flow += f;
            edges[G[x][i] ^ 1].flow -= f;
            flow += f;
            a -= f;
            if( a == 0 ) break;
         }
      }
      return flow;
   }
   int
   query()
   {
      int ans = 0;
      for( int i = 0; i < G[s].size(); i++ )
      {
         Edge &e = edges[G[s][i]];
         if( e.cap < m ) ans++;
      }
      return ans;
   }
   void
   print()
   {
      }
   int
   Maxflow( int s, int t )
   {
      this->s = s, this->t = t;
      int flow = 0;
      while( BFS() )
      {
         memset( cur, 0, sizeof( cur ) );
         flow += DFS( s, INF );
      }
      return flow;
   }
} D;

LL g[SIZE][SIZE];
int ID[SIZE][SIZE];
int id = 0;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

bool
legal( int x, int y )
{
   return x >= 1 && x <= n && y >= 1 && y <= m;
}

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   scanf( "%d %d", &n, &m );
   D.init( n * m + 10 );

   rep( i, 1, n ) rep( j, 1, m )
   {
      scanf( "%lld", &g[i][j] );
      ID[i][j] = ++id;
   }
   s = id + 1, t = id + 2;
   rep( x, 1, n ) rep( y, 1, m )
   {
      rep( i, 0, 3 )
      {
         int nx = x + dr[i];
         int ny = y + dc[i];
         if( legal( nx, ny ) && g[x][y] > g[nx][ny] )
            D.AddEdge( ID[x][y], ID[nx][ny], m );
      }
   }
   rep( x, 1, 1 ) rep( y, 1, m )
   {
      bool flag = false;
      rep( i, 0, 3 )
      {
         int nx = x + dr[i];
         int ny = y + dc[i];
         if( legal( nx, ny ) && g[nx][ny] > g[x][y] ) flag = true;
      }
      if( !flag ) D.AddEdge( s, ID[x][y], m );
   }
   rep( x, n, n ) rep( y, 1, m ) D.AddEdge( ID[x][y], t, 1 );

   int maxflow = D.Maxflow( s, t );
   //    cout << maxflow << endl;
   if( maxflow == m )
   {
      printf( "1\n" );
      printf( "%d", D.query() );
   }
   else
   {
      printf( "0\n" );
      cout << maxflow << endl;
   }

   return 0;
}