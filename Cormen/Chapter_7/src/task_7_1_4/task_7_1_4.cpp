
#include "common.h"

#include <vector>
#include <iostream>


int partition( std::vector<int> & arr, int l, int r )
{
  int b = arr[ r ];
  int ri = l - 1;

  for ( std::size_t i = l; i < r; ++i )
  {
    if ( arr[ i ] >= b )
    {
      ++ri;
      std::swap( arr[ i ], arr[ ri ] );
    }
  }

  std::swap( arr[ ri + 1 ], arr[ r ] );

  return ri + 1;
}


void quick_sort( std::vector<int> & arr, int l, int r )
{
  if ( l < r )
  {
    int q = partition( arr, l, r );
    quick_sort( arr, l, q - 1 );
    quick_sort( arr, q + 1, r );
  }
}


int main()
{
  auto arr = generate_random_int_seq( 10 );

  print_arr( arr );

  quick_sort( arr, 0, arr.size() - 1 );

  print_arr( arr );

  std::cin.get();
}