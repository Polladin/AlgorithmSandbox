
#include <vector>

// Print Heap
void print_heap( const std::vector<int> & arr );


// Generate random INT array
std::vector<int> generate_random_int_seq( unsigned sizeOfArray, int maxInt = 99 );


// Build HEAP
void build_heap( std::vector<int> & arr );

// MAX HEAPIFY
void max_heapify( std::vector<int> & heap, const unsigned heapSize, const unsigned idx );