#include "bitboard_util.hpp"

Bitboard::bitboard Bitboard::set_mask[64] = {0};
int Bitboard::__nsInit() {
  for (int i = 0; i < 64; i++) {
    bitboard val = ((bitboard)1 << (bitboard)i);
    set_mask[i] = val;
  }
  return -1;
}

int Bitboard::cardinality (bitboard x) {
  int count = 0;
  while (x) {
    count++;
    x &= x - 1; // reset LS1B
  }
  return count;
}

int Bitboard::dummy = __nsInit();

string Bitboard::separator = "-------------------------------";

void Bitboard::printBitboard(bitboard b, bool with_grid) {
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
