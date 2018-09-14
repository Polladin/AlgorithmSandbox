
#include "common.h"

#include <iostream>


int partition( std::vector<int> & arr, int l, int r )
{
  int elem = arr[ r ];
  int idx = l - 1;

  for ( int i = l; i < r; ++i )
  {
    if ( arr[ i ] < elem )
      std::swap( arr[++idx], arr[i] );
  }

  std::swap( arr[ ++idx ], arr[ r ] );

  return idx;
}


void quick_sort( std::vector<int> & arr, int l, int r )
{
  while ( l < r )
  {
    int q = partition( arr, l, r );
    
    if ( q - l < r - q )
    {
      quick_sort( arr, l, q - 1 );
      l = q + 1;
    }
    else
    {
      quick_sort( arr, q + 1, r );
      r = q - 1;
    }
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

