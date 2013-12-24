#include "square.hpp"

char file_chars[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

Square Squares::fromFileAndRank(int f, int r){
  return Square(r*8+f);
}

Rank Squares::rankOf(Square i) { return Rank(i / 8); }
File Squares::fileOf(Square i) { return File(i % 8); }

Square Squares::fromSAN(std::string san) {
  int f = 0;
  switch (san[0]) {
    case 'a': f = 0; break;
    case 'b': f = 1; break;
    case 'c': f = 2; break;
    case 'd': f = 3; break;
    case 'e': f = 4; break;
    case 'f': f = 5; break;
    case 'g': f = 6; break;
    case 'h': f = 7; break;
  }
  int r  = san[1] - '0' - 1;
  return fromFileAndRank(f, r);
}

std::string Squares::pretty(Square s) {
  int file = s % 8;
  int rank = s / 8;
  std::string rep = file_chars[file] + std::to_string(rank + 1); 
  return rep;
}
