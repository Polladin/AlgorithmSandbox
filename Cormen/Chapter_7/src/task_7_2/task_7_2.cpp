
#include "common.h"

#include <iostream>


std::pair<int, int> partition( std::vector<int> & arr, int l, int r )
{
  int elem = arr[ r ]; 
  int idx = l - 1;
  int equalElems = 0;

  for ( int i = l; i < r; ++i )
  {
    if ( arr[ i ] <= elem )
    {
      if ( arr[ i ] == elem )
        ++equalElems;
      else
        equalElems = 0;

      std::swap( arr[ ++idx ], arr[ i ] );
    }
  }

  std::swap( arr[ ++idx ], arr[ r ] );

  if ( equalElems > 0 )
    std::cout << "first : " << idx - equalElems << " second : " << idx << std::endl;

  return { idx  - equalElems, idx };
}


std::pair<int, int> partition_randomized( std::vector<int> & arr, int l, int r )
{
  std::swap( arr[ r ], arr[ get_random_number( l, r ) ] );
  return partition( arr, l, r );
}


void quick_sort( std::vector<int> & arr, int l, int r)
{
  if ( l < r )
  {
    auto p = partition_randomized( arr, l, r );
    quick_sort( arr, l, p.first - 1 );
    quick_sort( arr, p.second + 1, r );
  }
}


int main()
{
  auto arr = generate_random_int_seq( 200 );

  print_arr( arr );

  quick_sort( arr, 0, arr.size() - 1 );

  print_arr( arr );

  std::cin.get();
}