
#include "common.h"

#include <iostream>
#include <vector>


int partition( std::vector<int> & arr, int l, int r )
{
  int border = arr[ r ];

  int left = l - 1;

  for ( std::size_t i = l; i < r; ++i )
  {
    if ( arr[ i ] <= border )
    {
      ++left;
      std::swap( arr[ left ], arr[ i ] );
    }
  }

  std::swap( arr[ left + 1 ], arr[ r ] );

  return left + 1;
}


void quick_sort( std::vector<int> & arr, int l, int r )
{
  if ( l < r )
  {
    int pos = partition( arr, l, r );

    quick_sort( arr, l, pos - 1 );
    quick_sort( arr, pos + 1, r );
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