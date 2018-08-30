
#include "common.h"

#include <iostream>

void heap_sort( std::vector<int> &arr )
{
  // Build Heap
  build_heap( arr );

  // Sorting
  for ( int i = arr.size() - 1; i >= 2; --i )
  {
    max_heapify( arr, i + 1, 1 );
    std::swap( arr[ 1 ], arr[ i ] );
  }

}


int main()
{
  // Generate random array
  auto arr = generate_random_int_seq( 6 );

  // Sorting
  heap_sort( arr );

  // Print
  for ( unsigned i = 1; i < arr.size(); ++i )
    std::cout << arr[i] << ", ";
  std::cout << std::endl;

  // Wait ...
  std::cin.get();
}