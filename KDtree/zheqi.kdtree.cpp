#include <bits/stdc++.h>
using namespace std;

template <int dim>
struct Point
{
   array<double, dim> a;
   inline double &
   operator[]( size_t id )
   {
      return a[id];
   };
   const inline double &
   operator[]( size_t id ) const
   {
      return a[id];
   };
};

template <int dim>
struct PointSet
{
   int n;
   vector<Point<dim>> data;
   PointSet( int _n ) : n( _n )
   {
      data.resize( n );
      input();
   }
   inline Point<dim> &
   operator[]( size_t id )
   {
      return data[id];
   }
   const inline Point<dim> &
   operator[]( size_t id ) const
   {
      return data[id];
   }
   void
   input()
   {
      for( int i = 0; i < n; i++ )
      {
         for( int j = 0; j < dim; j++ )
         {
            scanf( "%lf", &data[i][j] );
         }
      }
   }
   auto
   begin()
   {
      return data.begin();
   }
   const auto
   begin() const
   {
      return data.begin();
   }
   auto
   end()
   {
      return data.end();
   }
   const auto
   end() const
   {
      return data.end();
   }
};

// insert your code below

#define SIZE_LIB 100005
#define EPS ( 1e-12 )

struct cmp
{
   uint32_t d;

   cmp( uint32_t d_ ) : d( d_ ) {}

   template <typename Iter>
   bool
   operator()( Iter lhs, Iter rhs )
   {
      return lhs[d] + EPS < rhs[d];
   }
};

template <int dim>
inline double
dist_L2norm( const Point<dim> &u, const Point<dim> &v )
{
   double sum = 0;
   for( int i = 0; i < dim; ++i )
   {
      const auto delta = u[i] - v[i];
      sum += delta * delta;
   }
   return sum;
}

template <int dim>
inline double
dist_L2norm( const Point<dim> &u, const Point<dim> &v, uint32_t d )
{
   double delta = u[d] - v[d];
   return delta * delta;
}

template <typename T>
struct priority_queue_k : priority_queue<T>
{
   uint32_t size_limit;
   priority_queue_k( uint32_t k ) : priority_queue<T>(), size_limit( k ) {}

   template <typename U>
   void
   push_( U &&value )
   {
      if( this->size() < size_limit || value <= this->top() )
         priority_queue<T>::push( forward<U>( value ) );

      if( this->size() > size_limit ) this->pop();
   }

   void
   push( const T &value )
   {
      push_( value );
   }

   void
   push( T &&value )
   {
      push_( std::move( value ) );
   }

   bool
   full() const
   {
      return this->size() >= size_limit;
   }
};

template <int dim>
struct KDtree
{
   struct node
   {
      node *lch, *rch;
      uint32_t d;
      Point<dim> p;
   };
   node lib[SIZE_LIB], *mm = lib, *root;

   node *
   alloc_node()
   {
      return ++mm;
   }

   template <typename Iter>
   node *
   build( Iter begin, Iter end, uint32_t d )
   {
      if( begin == end ) return nullptr;

      const uint32_t n = distance( begin, end );
      auto mid = begin + n / 2;
      nth_element( begin, mid, end, cmp( d ) );

      /*
      static random_device rd;
      static mt19937 gen(rd());
      static uniform_int_distribution<> dis_i(0,dim-1);
      */
      const uint32_t nd = ( d + 1 ) % dim;  // dis_i(gen);
      node *u = alloc_node();
      u->p = *mid;
      u->d = d;
      u->lch = build( begin, mid, nd );
      u->rch = build( next( mid ), end, nd );

      return u;
   }

   KDtree( PointSet<dim> ps ) : root( build( ps.begin(), ps.end(), 0 ) ) {}

   void
   search( node *u, const Point<dim> &q, priority_queue_k<double> &res )
   {
      if( u == nullptr ) return;

      bool safe_lp = false, safe_rp = false;
      auto cmp_d = cmp( u->d );
      if( cmp_d( q, u->p ) )
      {
         search( u->lch, q, res );
         safe_lp = true;
      }
      else if( cmp_d( u->p, q ) )
      {
         search( u->rch, q, res );
         safe_rp = true;
      }

      double dist_p = dist_L2norm( u->p, q );
      res.push( dist_p );
      if( !res.full() || dist_L2norm( q, u->p, u->d ) < res.top() + EPS )
         if( !safe_lp ) search( u->lch, q, res );

      if( !res.full() || dist_L2norm( q, u->p, u->d ) < res.top() + EPS )
         if( !safe_rp ) search( u->rch, q, res );
   }

   double
   search( const Point<dim> &q, int k )
   {
      priority_queue_k<double> res( k );
      search( root, q, res );
      return sqrt( res.top() );
   }
};

// insert your code above

template <int dim>
void
kNearestNeighbor( const PointSet<dim> &points )
{
   // insert your code below

   KDtree<dim> kdt( points );

   // insert your code above
   int q;
   scanf( "%d", &q );
   vector<double> ans( q );
   for( int i = 0; i < q; i++ )
   {
      int k;
      scanf( "%d", &k );
      Point<dim> p;
      for( int j = 0; j < dim; j++ )
      {
         scanf( "%lf", &p[j] );
      }
      double ret = 0;
      // insert your code below

      ret = kdt.search( p, k );

      // insert your code above
      ans[i] = ret;
   }
   for( int i = 0; i < q; i++ )
   {
      printf( "%.8f%c", ans[i], " \n"[i == q - 1] );
   }
}

int
main()
{
   int n, k;
   scanf( "%d%d", &n, &k );
   if( k == 2 )
   {
      PointSet<2> points( n );
      kNearestNeighbor<2>( points );
   }
   else if( k == 3 )
   {
      PointSet<3> points( n );
      kNearestNeighbor<3>( points );
   }
   else if( k == 4 )
   {
      PointSet<4> points( n );
      kNearestNeighbor<4>( points );
   }
   else if( k == 5 )
   {
      PointSet<5> points( n );
      kNearestNeighbor<5>( points );
   }
   else
   {
      throw std::runtime_error( "Dimension not supported." );
   }
   return 0;
}
