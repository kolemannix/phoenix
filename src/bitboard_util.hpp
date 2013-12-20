#ifndef BITBOARD_UTIL
#define BITBOARD_UTIL

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

namespace Bitboard {

extern int __nsInit();
extern int dummy;

typedef uint64_t bitboard; 

extern bitboard set_mask[64];

extern string separator;
extern void printBitboard(bitboard x, bool with_grid = true); 
extern int cardinality(bitboard x);
}

#endif
