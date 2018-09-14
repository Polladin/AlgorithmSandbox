
#include "common.h"

#include <iostream>


int hoare_partition( std::vector<int> & arr, int l, int r )
{
  int elem = arr[ l ];

  while ( l < r )
  {
    while ( arr[ r ] > elem )
      --r;
    while ( arr[ l ] < elem )
      ++l;

    if ( l < r )
      std::swap( arr[ l ], arr[ r ] );
  }

  return r;
}


void quick_sort( std::vector<int> & arr, int l, int r )
{
  if ( l < r )
  {
    int q = hoare_partition( arr, l, r );
    quick_sort( arr, l, q );
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