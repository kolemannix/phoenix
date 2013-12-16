#include "coordinate.hpp"

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

Coordinate& Coordinate::operator=(const Coordinate& rhs) {
  file = rhs.file;
  rank = rhs.rank;
  return *this;
}

int Coordinate::squareIndex() const {
  return rank * 8 + file;
}
