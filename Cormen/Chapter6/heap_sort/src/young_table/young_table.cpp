
#include "common.h"

#include <iostream>
#include <limits>
#include <vector>

const int MAX_INT = std::numeric_limits<int>::max();
const int MIN_INT = std::numeric_limits<int>::min();

using t_table = std::vector< std::vector< int > >;


t_table table_create( std::size_t N )
{
  return t_table( N, std::vector<int>( N, MAX_INT ) );
}


void table_insert( t_table & tab, int elem )
{
  std::size_t curRow = tab.size() - 1;
  std::size_t curCol = tab[ 0 ].size() - 1;

  if ( elem >= tab[ curRow ][ curCol ] )
    return;

  tab[ curRow ][ curCol ] = elem;

  while ( curRow >= 0 && curCol >= 0 )
  {
    int topVal = curRow > 0 ? tab[ curRow - 1 ][ curCol ] : MIN_INT;
    int leftVal = curCol > 0 ? tab[ curRow ][ curCol - 1 ] : MIN_INT;
    int curVal = tab[ curRow ][ curCol ];

    if ( curVal < topVal && topVal >= leftVal )
    {
      std::swap( tab[ curRow ][ curCol ], tab[ curRow - 1 ][ curCol ] );
      --curRow;
      continue;
    }
    
    if ( curVal < leftVal )
    {
      std::swap( tab[ curRow ][ curCol ], tab[ curRow ][ curCol - 1 ] );
      --curCol;
      continue;
    }

    break;
  }
}


void replace_min( t_table & tab, std::size_t row = 0, std::size_t col = 0 )
{
  if ( row >= tab.size() || col >= tab[ 0 ].size() )
    return;

  int botVal = row + 1 < tab.size() ? tab[ row + 1 ][ col ] : MAX_INT;
  int rightVal = col + 1 < tab[ 0 ].size() ? tab[ row ][ col + 1 ] : MAX_INT;

  if ( botVal < rightVal )
  {
    tab[ row ][ col ] = botVal;
    replace_min( tab, row + 1, col );
  }
  else
  {
    tab[ row ][ col ] = rightVal;
    replace_min( tab, row, col + 1 );
  }

}

int extract_min( t_table & tab )
{
  int res = tab[ 0 ][ 0 ];

  replace_min( tab );

  return res;
}


bool find_val(int val, t_table & tab, std::size_t row, std::size_t col )
{
  if ( tab[ row ][ col ] == val )
    return true;

  if ( val < tab[ row ][ col ] )
  {
    if ( col == 0 )
      return false;
    else
      return find_val( val, tab, row, col - 1 );
  }
  else
  {
    if ( row + 1 == tab.size() )
      return false;
    else
      return find_val( val, tab, row + 1, col );
  }
}


void print_table(const t_table & tab )
{
  for ( const auto & vec : tab )
  {
    for ( auto el : vec )
    {
      std::cout << el << " ";
    }
    std::cout << std::endl;
  }
}


//int main()
//{
//  auto table = table_create( 5 );
//  auto randValues = generate_random_int_seq( 25 );
//
//  for ( auto el : randValues )
//    table_insert(table, el);
//
//  print_table( table );
//  std::cout << "Extract min : " << extract_min( table ) << std::endl;
//  std::cout << std::endl;
//
//  print_table( table );
//  std::cout << "Extract min : " << extract_min( table ) << std::endl;
//  std::cout << std::endl;
//
//  print_table( table );
//  std::cout << "Extract min : " << extract_min( table ) << std::endl;
//  std::cout << std::endl;
//
//  print_table( table );
//
//  std::cout << "\n\nInsert into table 15, 20, 55" << std::endl;
//  for ( auto el : { 15, 20 ,55 } )
//    table_insert( table, el );
//
//  print_table( table );
//
//  std::cout << "\n\nFind val 55 : " << std::boolalpha << find_val( 55, table, 0, table[ 0 ].size() - 1 ) << std::endl;
//  std::cout << "Find val 67 : " << std::boolalpha << find_val( 67, table, 0, table[ 0 ].size() - 1 ) << std::endl;
//
//  // Wait ...
//  std::cin.get();
//}