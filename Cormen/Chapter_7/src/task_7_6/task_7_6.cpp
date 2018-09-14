
#include <iostream>

#include "common.h"


struct Interval
{
  Interval() {}

  Interval( int l, int r )
    : left( l ), right( r )
  {}

  int left, right;

  bool operator < ( const Interval & val )
  {
    return right < val.left;
  }

  bool operator > ( const Interval & val )
  {
    return left > val.right;
  }
};


std::pair<int, int> partition( std::vector<Interval> & arr, int l, int r )
{
  Interval elem = arr[ r ];
  int idxL = l - 1;

  for ( int i = l; i < r; ++i )
  {
    if ( arr[ i ] < elem )
      std::swap( arr[ ++idxL ], arr[ i ] );
  }

  std::swap( arr[ ++idxL ], arr[ r ] );

  int idxR = r;

  for ( int i = r - 1; i > idxL; --i )
  {
    if ( arr[ i ] > elem )
    {
      std::cout << "i : [" << arr[ i ].left << ", " << arr[ i ].right << "]";
      std::cout << "   elem : [" << elem.left << ", " << elem.right << "]" << std::endl;
      std::swap( arr[ --idxR ], arr[ i ] );
    }
      
  }

  return { idxL, idxR };
}

void quick_sort( std::vector<Interval> & arr, int l, int r )
{
  if ( l < r )
  {
    auto q = partition( arr, l, r );
    quick_sort( arr, l, q.first - 1 );
    quick_sort( arr, q.second + 1, r );
  }
}

int main()
{
  std::vector< Interval > arr =
  { { 3, 6 }, {1, 5}, {-1, 2}, {8, 10}, {4, 5}, {-3,-2}, {0, 5}, {7, 9} };

  for ( const auto & el : arr )
    std::cout << "[" << el.left << ", " << el.right << "] ";
  std::cout <<  std::endl;

  quick_sort( arr, 0, arr.size() - 1 );

  for ( const auto & el : arr )
    std::cout << "[" << el.left << ", " << el.right << "] ";
  std::cout << std::endl;

  std::cin.get();
}