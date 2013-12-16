#ifndef BITMAP_UTIL
#define BITMAP_UTIL

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

namespace Bitmap {

extern int ns_init();
extern int dummy;

typedef uint64_t bitmap; 

extern bitmap set_mask[64];
extern string separator;
extern void printBitmap(bitmap x, bool with_grid = true); 
extern int cardinality(bitmap x);
}

#endif
