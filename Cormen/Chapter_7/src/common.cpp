
#include "common.h"

#include <iostream>
#include <iomanip>
#include <random>


std::vector<int> generate_random_int_seq( unsigned sizeOfArray, int maxInt )
{
  std::vector<int> res( sizeOfArray );

  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen( rd() ); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> dis( 10, maxInt );

  for ( int n = 0; n < sizeOfArray; ++n )
    res[ n ] = dis( gen );

  return res;
}


int get_random_number( int l, int r )
{
  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen( rd() ); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_int_distribution<> dis( l, r );

  return dis( gen );
}