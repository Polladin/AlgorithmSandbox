
#include "common.h"

#include <vector>
#include <iostream>


int partition( std::vector<int> & arr, int l, int r )
{
  int elem = arr[ r ];
  int lPos = l - 1;

  bool isAllElementsEqual = true;

  for ( int i = l; i < r; ++i )
  {
    if ( arr[ i ] != elem )
      isAllElementsEqual = false;

    if ( arr[ i ] <= elem )
    {
      std::swap( arr[ ++lPos ], arr[ i ] );
    }
  }

  std::swap( arr[ ++lPos ], arr[ r ] );

  return isAllElementsEqual ? ( l + r ) / 2 : lPos;
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