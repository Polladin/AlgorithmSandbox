
#include <vector>

// Generate random INT array
std::vector<int> generate_random_int_seq( unsigned sizeOfArray, int maxInt = 99 );


// Print arr
template<class TContainer>
void print_arr( TContainer arr )
{
  for ( auto el : arr )
    std::cout << el << " ";
  std::cout << std::endl;
}


