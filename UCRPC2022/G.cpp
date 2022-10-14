#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#include <algorithm>
#include <list>
#include <queue>
#include <utility>
#include <vector>

#define up_to( i, n ) for( ( i ) = 0; ( i ) < ( n ); ( i )++ )
using namespace std;
typedef pair<int, int> int_pair;

int
max( int a, int b )
{
   return a > b ? a : b;
}

int
min( int a, int b )
{
   return a < b ? a : b;
}

bool
compar( pair<int, double> a, pair<int, double> b )
{
   return ( a.second > b.second );
}

int
comp_arr( int *students, int *students_original, int n )
{
   int iter, number = 0;
   up_to( iter, n )
   {
      if( students[iter] != students_original[iter] )
      {
         number++;
      }
   }
   return number;
}

bool
search( int *arr, int element, int m )
{
   int i;
   up_to( i, m )
   {
      if( element == arr[i] ) return true;
   }

   return false;
}

class Graph
{
   int V, m;
   int number = 0;

   int *traitor_arr;
   vector<list<int> > adj;

  public:
   Graph( int V, int m );

   void
   addEdge( int v, int w );
   void
   addtrator( int i, int v );
   int
   BFS( int s );
};

Graph::Graph( int V, int m )
{
   this->V = V;
   this->m = m;
   adj.resize( V );
   traitor_arr = (int *)malloc( sizeof( int ) * m );
}

void
Graph::addEdge( int v, int w )
{
   adj[v].push_back( w );
}

void
Graph::addtrator( int i, int v )
{
   traitor_arr[i] = v;
}

int
Graph::BFS( int s )
{
   vector<bool> visited;
   visited.resize( V, false );

   list<int> queue;
   if( search( traitor_arr, s, m ) == true ) return 0;
   visited[s] = true;
   number++;
   queue.push_back( s );
   while( !queue.empty() )
   {
      s = queue.front();
      queue.pop_front();

      for( auto adjecent : adj[s] )
      {
         if( !visited[adjecent] )
         {
            visited[adjecent] = true;
            if( search( traitor_arr, adjecent, m ) == true ) continue;
            number++;
            queue.push_back( adjecent );
         }
      }
   }
   int num = number;
   number = 0;
   return num;
}

int
main()
{
   int member, traitor, parent;
   int i, j, k;
   int *traitor_arr;
   scanf( "%d %d", &member, &traitor );
   Graph g( member, traitor );

   up_to( i, member - 1 )
   {
      scanf( "%d", &parent );
      g.addEdge( parent, i + 1 );
   }
   up_to( i, traitor )
   {
      scanf( "%d", &parent );
      g.addtrator( i, parent );
   }
   int temp = 0;
   up_to( i, member )
   {
      temp = max( temp, g.BFS( i ) );
   }
   printf( "%d\n", temp );
   return 0;
}