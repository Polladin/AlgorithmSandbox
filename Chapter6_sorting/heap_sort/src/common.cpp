
#include "common.h"

#include <iostream>
#include <iomanip>
#include <random>


void print_heap( const std::vector<int> & arr )
{
  unsigned heapHeight = std::ceil( std::log2( arr.size() ) );

  if ( heapHeight == 0 )
    return;

  unsigned idx = 1;
  unsigned width = 2;
  const char fillSymbol = ' ';

  for ( int i = 0; i < heapHeight && idx < arr.size(); ++i )
  {
    std::cout << std::string( width * (int)std::round( std::pow( 2.0, heapHeight - 1 - i ) ), fillSymbol ).c_str() << std::setw( width ) << arr[ idx++ ];

    for ( int j = 1; j < (int)std::round( std::pow( 2.0, i ) ) && idx < arr.size(); ++j )
    {
      std::cout << std::string( width * ( (int)std::round( std::pow( 2.0, heapHeight - i ) ) - 1 ), fillSymbol ).c_str() << std::setw( width ) << arr[ idx++ ];
    }

    std::cout << std::endl;
  }
}


std::vector<int> generate_random_int_seq( unsigned sizeOfArray, int maxInt )
{
  // Heap start from Index 1
  sizeOfArray += 1;

  std::vector<int> res( sizeOfArray );

  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen( rd() ); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> dis( 10, maxInt );

  for ( int n = 0; n < sizeOfArray; ++n )
    res[ n ] = dis( gen );

  return res;
}


void build_heap( std::vector<int> & arr )
{
  // Make a heap
  for ( unsigned i = 0; i < arr.size() / 2; ++i )
    max_heapify( arr, arr.size(), arr.size() / 2 - i);
}


void max_heapify( std::vector<int> & heap, const unsigned heapSize, const unsigned idx )
{
  unsigned left = idx * 2;
  unsigned right = idx * 2 + 1;
  unsigned newIdx = idx;

  if ( left < heapSize && heap[ newIdx ] < heap[ left ] )
    newIdx = left;

  if ( right < heapSize && heap[ newIdx ] < heap[ right ] )
    newIdx = right;

  if ( newIdx != idx )
  {
    std::swap( heap[ idx ], heap[ newIdx ] );
    max_heapify( heap, heapSize, newIdx );
  }
}
