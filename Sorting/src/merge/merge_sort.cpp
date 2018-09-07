
#include <iostream>
#include <vector>
#include <limits>

#include "common.h"


const std::size_t ARR_SIZE = 20;
std::vector<int> vl( ARR_SIZE / 2 + 2, std::numeric_limits<int>::max() );
std::vector<int> vr( ARR_SIZE / 2 + 2, std::numeric_limits<int>::max() );


void merge( std::vector<int> & arr, int l, int p, int r )
{
  std::size_t left = 0;
  std::size_t right = 0;

  for ( std::size_t i = l; i <= p; ++i )
    vl[ i - l ] = arr[ i ];
  vl[ p - l + 1 ] = std::numeric_limits<int>::max();

  for ( std::size_t i = p + 1; i <= r; ++i )
    vr[ i - p - 1 ] = arr[ i ];
  vr[ r - p ] = std::numeric_limits<int>::max();

  for ( std::size_t i = l; i <= r; ++i )
    arr[ i ] = vl[ left ] < vr[ right ] ? vl[ left++ ] : vr[ right++ ];
}

void merge_sort( std::vector<int> & arr, int l, int r )
{
  if ( l < r )
  {
    merge_sort( arr, l, ( l + r ) / 2 );
    merge_sort( arr, ( l + r ) / 2 + 1, r);
    merge( arr, l, ( l + r ) / 2, r );
  }
}


int main()
{
  auto arr = generate_random_int_seq( ARR_SIZE );

  for ( auto el : arr )
    std::cout << el << " ";
  std::cout << std::endl;

  merge_sort( arr, 0, arr.size() - 1 );

  for ( auto el : arr )
    std::cout << el << " ";
  std::cout << std::endl;

  std::cin.get();
}