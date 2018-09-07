
#include "common.h"

#include <iostream>
#include <vector>


void partition( std::vector<int> & arr, int l, int r )
{
  int border = arr[ r ];

  int left = l - 1;

  for ( std::size_t i = l; i < r; ++i )
  {
    if ( arr[ l ] < border )
    {
      ++left;
      std::swap( arr[ left ], arr[ l ] );
    }
  }

  std::swap( arr[ left + 1 ], arr[ r ] );
}


void quick_sort( std::vector<int> & arr, int l, int r )
{
  if ( l < r )
  {
    quick_sort( arr, l, ( r - l ) / 2 );
    quick_sort( arr, ( r - l ) / 2 + 1, r );
    partition( arr, l, r );
  }
}


int main()
{
  auto arr = generate_random_int_seq( 5 );

  print_arr( arr );

  quick_sort( arr, 0, arr.size() - 1 );

  print_arr( arr );

  std::cin.get();
}