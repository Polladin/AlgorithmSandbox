
#include "common.h"

#include <iostream>


void heap_delete( std::vector<int> & heap, unsigned idx )
{
  if ( heap.size() == 0 )
    return;

  if ( heap.size() > 1 )
  {
    std::swap( heap[ idx ], heap[ heap.size() - 1 ] );
    max_heapify( heap, heap.size() - 1, idx );
  }

  heap.pop_back();
}


int main()
{
  // Generate random array
  auto arr = generate_random_int_seq( 20 );

  std::cout << "Is heap before build : " << std::boolalpha << is_heap( arr, 1 ) << std::endl;
  // Build Heap
  build_heap( arr );
  std::cout << "Is heap after build : " << std::boolalpha << is_heap( arr, 1 ) << std::endl;

  // Print Heap
  print_heap( arr );
  // Delete elem(s)
  heap_delete( arr, 2 );

  std::cout << std::endl;
  // Print Heap
  print_heap( arr );

  std::cout << "Is heap after del : " << std::boolalpha << is_heap( arr, 1 ) << std::endl;

  // Wait ...
  std::cin.get();
}