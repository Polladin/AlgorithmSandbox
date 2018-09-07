
#include "common.h"


#include <vector>
#include <iostream>
#include <cmath>
#include <iomanip>


void max_heapify_req( std::vector<int> & heap, const unsigned idx )
{
  unsigned left = idx * 2;
  unsigned right = idx * 2 + 1;
  unsigned newIdx = idx;

  if ( left < heap.size() && heap[ newIdx ] < heap[ left ] )
    newIdx = left;

  if ( right < heap.size() && heap[ newIdx ] < heap[ right ] )
    newIdx = right;

  if ( newIdx != idx )
  {
    std::swap( heap[ idx ], heap[ newIdx ] );
    max_heapify( heap, heap.size(), newIdx );
  }
}


int main()
{
  // Generate random array
  auto arr = generate_random_int_seq( 6 );

  // Make a heap
  for ( unsigned i = 0; i < arr.size() / 2; ++i )
    max_heapify_req( arr, arr.size() / 2 - i );

  // Print heap
  print_heap( arr );

  // Wait ...
  std::cin.get();
}