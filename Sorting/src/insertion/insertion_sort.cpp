
#include <iostream>
#include <vector>

#include "common.h"


void insertion_sort( std::vector<int> & arr )
{
  for ( std::size_t idx = 1; idx < arr.size(); ++idx )
  {
    std::size_t j = idx;
    int elem = arr[ idx ];

    while ( j > 0 && arr[ j - 1 ] > elem )
    {
      arr[ j ] = arr[ j - 1 ];
      --j;
    }

    arr[ j ] = elem;
  }
}


int main()
{
  auto arr = generate_random_int_seq( 10 );

  insertion_sort( arr );

  for ( auto el : arr )
    std::cout << el << " ";
  std::cout << std::endl;

  std::cin.get();
}