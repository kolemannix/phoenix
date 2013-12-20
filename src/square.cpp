#include "square.hpp"

char file_chars[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

Square::Square() {
  file = -1;
  rank = -1;
}

Square::Square(int f, int r){
  if (f < 0 || f > 7 || r < 0 || r > 7) {
    throw 42;
  }
  file = f;
  rank = r;
}

Square::Square(int index){
  int f = index % 8;
  int r = index / 8;
  if (f < 0 || f > 7 || r < 0 || r > 7) {
    throw 42;
  }
  file = f;
  rank = r;
}

Square::Square(std::string san) {
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
  file = f;
  rank = san[1] - '0' - 1;
}

Square& Square::operator=(const Square& rhs) {
  file = rhs.file;
  rank = rhs.rank;
  return *this;
}

int Square::squareIndex() const {
  return rank * 8 + file;
}

std::string Square::toString() const {
  std::string rep = file_chars[file] + std::to_string(rank + 1); 
  return rep;
}
