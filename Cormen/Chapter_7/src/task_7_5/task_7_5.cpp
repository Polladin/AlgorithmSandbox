
#include "common.h"

#include <iostream>


int partition( std::vector<int> & arr, int l, int r )
{
  int elem = r - l < 3 ? arr[r] 
                       : ( arr[ r - 2 ] + arr[ r - 1 ] + arr[ r ] ) / 3;

  int idx = l - 1;

  for ( int i = l; i <= r; ++i )
  {
    if ( arr[ i ] < elem )
      std::swap( arr[ ++idx ], arr[ i ] );
  }

  return idx;
}


void quick_sort( std::vector<int> & arr, int l, int r )
{
  if ( l < r )
  {
    int q = partition( arr, l, r );
    quick_sort( arr, l, q );
    quick_sort( arr, q + 1, r );
  }
}


int main()
{
  auto arr = generate_random_int_seq( 20 );

  print_arr( arr );

  quick_sort( arr, 0, arr.size() - 1 );

  print_arr( arr );

  std::cin.get();
}

