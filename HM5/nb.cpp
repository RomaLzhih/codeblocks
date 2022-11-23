#pragma GCC optimize( 3 )
#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-9;
#define rep( i, a, b ) for( int i = ( a ); i <= ( b ); i++ )
#define per( i, a, b ) for( int i = ( a ); i >= ( b ); i-- )
#define MEM( a, x ) memset( a, x, sizeof( a ) )
#define LL long long
#define MOD ( (int)1000000007 )
#define MAXN 1500 + 5
///**********************************START*********************************///
char g[MAXN][MAXN];
bool vis[MAXN][MAXN];
int t[MAXN][MAXN];
int d[MAXN][MAXN];

int n, m;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
struct NODE
{
   int x, y;
};
NODE swan[2];
queue<NODE> q;

bool
legal( int x, int y )
{
   return x >= 1 && x <= n && y >= 1 && y <= m;
}

void
bfs()
{
   while( !q.empty() )
   {
      int x = q.front().x, y = q.front().y;
      q.pop();
      for( int i = 0; i < 4; i++ )
      {
         int nx = x + dr[i];
         int ny = y + dc[i];
         if( legal( nx, ny ) && !vis[nx][ny] && t[x][y] + 1 < t[nx][ny] )
         {
            t[nx][ny] = t[x][y] + 1;
            vis[nx][ny] = 1;
            q.push( { nx, ny } );
         }
      }
   }
}

int
bfs2()
{
   MEM( vis, 0 );
   while( !q.empty() ) q.pop();
   q.push( swan[0] );
   vis[swan[0].x][swan[0].y] = 1;
   d[swan[0].x][swan[0].y] = 0;
   while( !q.empty() )
   {
      int x = q.front().x, y = q.front().y;
      q.pop();
      vis[x][y] = 0;
      for( int i = 0; i < 4; i++ )
      {
         int nx = x + dr[i];
         int ny = y + dc[i];
         if( legal( nx, ny ) && d[x][y] < d[nx][ny] && t[nx][ny] != d[nx][ny] )
         {
            d[nx][ny] = max( d[x][y], t[nx][ny] );
            if( !vis[nx][ny] )
            {
               vis[nx][ny] = 1;
               q.push( { nx, ny } );
            }
         }
      }
   }
   return d[swan[1].x][swan[1].y];
}

int
main()
{
#ifndef ONLINE_JUDGE
   freopen( "input.txt", "r", stdin );
#endif
   scanf( "%d %d\n", &n, &m );
   MEM( vis, 0 );

   int cnt = 0;
   rep( i, 1, n )
   {
      rep( j, 1, m )
      {
         t[i][j] = INT_MAX;
         d[i][j] = INT_MAX;
         scanf( "%c", &g[i][j] );
         if( g[i][j] == '.' )
         {
            q.push( { i, j } );
            vis[i][j] = 1;
            t[i][j] = 0;
         }
         else if( g[i][j] == 'L' )
         {
            q.push( { i, j } );
            vis[i][j] = 1;
            t[i][j] = 0;
            swan[cnt++] = { i, j };
         }
      }
      getchar();
   }
   bfs();
   cout << bfs2() << endl;
   return 0;
}