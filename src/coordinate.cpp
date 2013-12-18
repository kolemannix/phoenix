#include "coordinate.hpp"

char file_chars[8] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'};

Coordinate::Coordinate(int f, int r){
  if (f < 0 || f > 7 || r < 0 || r > 7) {
    throw 42;
  }
  file = f;
  rank = r;
}

Coordinate::Coordinate(int index){
  int f = index % 8;
  int r = index / 8;
  if (f < 0 || f > 7 || r < 0 || r > 7) {
    throw 42;
  }
  file = f;
  rank = r;
}

Coordinate::Coordinate(std::string san) {
  int f;
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

Coordinate& Coordinate::operator=(const Coordinate& rhs) {
  file = rhs.file;
  rank = rhs.rank;
  return *this;
}

int Coordinate::squareIndex() const {
  return rank * 8 + file;
}

std::string Coordinate::toString() const {
  std::string rep = file_chars[file] + std::to_string(rank + 1); 
  return rep;
}
