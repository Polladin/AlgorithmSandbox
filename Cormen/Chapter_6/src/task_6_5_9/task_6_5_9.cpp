
#include <common.h>

#include <iostream>
#include <iomanip>
#include <memory>
#include <list>


struct Node
{
  Node() {}

  Node( std::list<int>::iterator i_it, std::list<int>::iterator  i_ite)
    : it( i_it )
    , ite( i_ite )
  {}

  int get_val() const { return *it; }

  std::list<int>::iterator it;
  std::list<int>::iterator ite;
};


void print_heap_list( const std::vector<Node> & arr )
{
  unsigned heapHeight = std::ceil( std::log2( arr.size() ) );

  if ( heapHeight == 0 )
    return;

  unsigned idx = 1;
  unsigned width = 2;
  const char fillSymbol = ' ';

  for ( int i = 0; i < heapHeight && idx < arr.size(); ++i )
  {
    std::cout << std::string( width * (int)std::round( std::pow( 2.0, heapHeight - 1 - i ) ), fillSymbol ).c_str() << std::setw( width ) << arr[ idx++ ].get_val();

    for ( int j = 1; j < (int)std::round( std::pow( 2.0, i ) ) && idx < arr.size(); ++j )
    {
      std::cout << std::string( width * ( (int)std::round( std::pow( 2.0, heapHeight - i ) ) - 1 ), fillSymbol ).c_str() << std::setw( width ) << arr[ idx++ ].get_val();
    }

    std::cout << std::endl;
  }
}


void min_heapify_list(std::vector<Node> & arr, unsigned idx)
{
  unsigned left = idx * 2;
  unsigned right = idx * 2 + 1;
  unsigned newIdx = idx;

  if ( left < arr.size() && arr[ left ].get_val() < arr[ newIdx ].get_val() )
    newIdx = left;

  if ( right < arr.size() && arr[ right ].get_val() < arr[ newIdx ].get_val() )
    newIdx = right;

  if ( newIdx != idx )
  {
    std::swap( arr[ idx ], arr[ newIdx ] );
    min_heapify_list( arr, newIdx );
  }
}

void build_heap_list( std::vector<Node> & arr )
{
  // Make a heap
  for ( unsigned i = 0; i < arr.size() / 2; ++i )
    min_heapify_list( arr, arr.size() / 2 - i );
}


std::list<int> merge_lists( std::vector<std::list<int>> lists )
{
  std::vector<Node> heap;
  std::list<int> res;

  // Fake 0 elem
  heap.emplace_back();

  for ( auto & el : lists )
    heap.emplace_back( el.begin(), el.end() );

  // Build heap
  build_heap_list( heap );

  // Print Heap
  print_heap_list( heap );
  
  // Merge
  while ( heap.size() > 1 )
  {
    min_heapify_list( heap, 1 );

    // get min
    res.push_back( heap[ 1 ].get_val() );
    ++heap[ 1 ].it;

    // Delete list if it was ended
    if ( heap[ 1 ].it == heap[ 1 ].ite )
      heap.erase( heap.begin() + 1 );
  }

  return res;
}


std::list<int> create_list( unsigned size )
{
  auto arr = generate_random_int_seq( size );

  auto lst = std::list<int>( arr.begin(), arr.end() );
  lst.sort();

  return lst;
}


int main()
{
  const unsigned LIST_SIZE = 6;

  // Get 3 list
  std::vector<std::list<int>> lists{  create_list( LIST_SIZE )
                                    , create_list( LIST_SIZE + 6 )
                                    , create_list( LIST_SIZE + 1 ) };

  // Print lists
  for ( const auto & lst : lists )
  {
    for ( auto el : lst )
    {
      std::cout << el << ", ";
    }
    std::cout << std::endl;
  }

  // Merge lists
  auto resList = merge_lists( lists );

  // Print
  for ( auto el : resList )
    std::cout << el << ", ";

  std::cout << std::endl;

  // Wait ...
  std::cin.get();
}
