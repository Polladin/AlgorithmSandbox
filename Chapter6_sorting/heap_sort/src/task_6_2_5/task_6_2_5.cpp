
#include "common.h"

#include <iostream>


void max_heapify( std::vector<int> & heap, unsigned idx )
{
  bool stopProcess = false;

  while ( !stopProcess )
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
      idx = newIdx;
    }
    else
    {
      stopProcess = true;
    }
  } 
}


int main()
{
  // Generate random array
  auto arr = generate_random_int_seq( 20 );

  // Make a heap
  for ( unsigned i = 0; i < arr.size() / 2; ++i )
  {
    max_heapify( arr, arr.size() / 2 - i );
  }

  // Print heap
  print_heap( arr );

  // Wait ...
  std::cin.get();
}