
#include <iostream>

#include "common.h"

// d -heap

static const unsigned D_HEAP = 3;

unsigned get_heap_height_d( const std::vector<int> arr )
{
  unsigned height = unsigned( std::floor( std::log( arr.size() - 1 ) / std::log( D_HEAP ) ) );
  unsigned maxElemsWithHeight = ( std::pow( (double)D_HEAP, height + 1 ) - 1 ) / ( D_HEAP - 1 );

  if ( arr.size() - 1 > maxElemsWithHeight )
    ++height;

  return height;
}


void print_heap_d( std::vector<int> & arr )
{
  if ( arr.size() < 2 )
    return;

  unsigned heapHeight = get_heap_height_d( arr );

  unsigned mult = 1;
  std::size_t idx = 1;

  for ( unsigned i = 0; i < heapHeight + 1; ++i )
  {
    for ( unsigned j = 0; j < mult && idx < arr.size(); ++j )
    {
      std::cout << arr[ idx++ ] << "   ";
    }
    std::cout << std::endl;

    mult *= D_HEAP;
  }

}

void max_heapify_d( std::vector<int> & heap, const unsigned heapSize, const unsigned idx )
{
  unsigned newIdx = idx;

  for ( unsigned childNum = 0; childNum < D_HEAP; ++childNum )
  {
    unsigned childIdx = idx * D_HEAP + childNum - 1;

    if ( childIdx < heapSize && heap[ childIdx ] >  heap[ newIdx ] )
      newIdx = childIdx;
  }

  if ( newIdx != idx )
  {
    std::swap( heap[ newIdx ], heap[ idx ] );
    max_heapify_d( heap, heapSize, newIdx );
  }
}


void build_heap_d( std::vector<int> & arr )
{
  // Make a heap
  for ( unsigned i = 0; i < arr.size(); ++i )
    max_heapify_d( arr, arr.size(), arr.size() - i );
}


void heap_sort_d( std::vector<int> & arr )
{
  // Build heap
  build_heap_d( arr );
  
  for ( unsigned i = 0; i < arr.size() - 2; ++i )
  {
    std::swap( arr[ 1 ], arr[ arr.size() - 1 - i ] );
    max_heapify_d( arr, arr.size() - i - 1, 1 );
  }
}


int extract_max_d( std::vector<int> &heap )
{
  int res = heap[ 1 ];
  
  std::swap( heap[ 1 ], heap[ heap.size() - 1 ] );
  heap.erase( heap.end() - 1 );

  max_heapify_d( heap, heap.size(), 1 );

  return res;
}


void increase_key( int key, std::size_t idx, std::vector<int> &heap )
{
  if ( key <= heap[ idx ] )
    return;

  heap[ idx ] = key;

  std::size_t parentIdx = ( idx + 1 ) / D_HEAP;
  std::size_t newElemIdx = idx;

  while ( parentIdx >= 1 && heap[ parentIdx ] < heap[ newElemIdx ] )
  {
    std::swap( heap[ parentIdx ], heap[ newElemIdx ] );
    newElemIdx = parentIdx;
    parentIdx = ( parentIdx + 1 ) / 3;
  }
}


void insert_d( int elem, std::vector<int> &heap )
{
  heap.push_back( elem );

  std::size_t parentIdx = heap.size() / D_HEAP;
  std::size_t newElemIdx = heap.size() - 1;

  while ( parentIdx >= 1 && heap[ parentIdx ] < heap[ newElemIdx ] )
  {
    std::swap( heap[ parentIdx ], heap[ newElemIdx ] );
    newElemIdx = parentIdx;
    parentIdx = ( parentIdx + 1 ) / 3;
  }
}


int main()
{
  // Generate random array
  auto arr = generate_random_int_seq( 14 );

  // Build heap
  build_heap_d( arr );

  insert_d( 55, arr );
  insert_d( 10, arr );
  insert_d( 99, arr );

  // Print heap
  print_heap_d( arr );

  increase_key( 78, std::distance( arr.begin(), std::find( arr.begin(), arr.end(), 10 ) ), arr );

  // Print heap
  print_heap_d( arr );

  for ( unsigned i = 1; i < arr.size(); ++i )
    std::cout << arr[ i ] << " ";
  std::cout << std::endl;

  //std::cout << "Extracting ..." << std::endl;

  //while ( arr.size() > 1 )
  //{
  //  std::cout << "elem : " << extract_max_d( arr ) << std::endl;
  //}


  //// Sort
  //heap_sort_d( arr );

  // Wait ...
  std::cin.get();
}
