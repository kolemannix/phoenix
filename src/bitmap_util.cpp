#include "bitmap_util.h"

Bitmap::bitmap Bitmap::set_mask[64] = {0, 1, 2};
int Bitmap::ns_init() {
  cout << "teh hax!\n";
  for (int i = 0; i < 64; i++) {
    bitmap val = ((bitmap)1 << (bitmap)i);
    set_mask[i] = val;
    //printBitmap(val);
  }
  return -1;
}

int Bitmap::dummy = ns_init();

string Bitmap::separator = "-------------------------------";

void Bitmap::printBitmap(bitmap b, bool with_grid) {
  string buffer = "";
  if (with_grid) buffer += "  ";
  buffer += separator;
  for (int y = 7; y >= 0; y--) {
    buffer += "\n"; 
    if (with_grid) {  
      buffer += std::to_string(y + 1);
      buffer += " | ";
    }
    for (int x = 0; x < 8; x++) {
      int index = y*8 + x;
      buffer += std::to_string((b >> index) & 1);
      buffer += " | ";
    }
  }
  buffer += "\n";
  if (with_grid) {
    buffer += "  ";
    buffer += separator;
    buffer += "\n   a | b | c | d | e | f | g | h\n";
  } else buffer += separator;
  cout << buffer << endl;
}