#include "coordinate.hpp"

Coordinate::Coordinate(int f, int r): file(f), rank(r) {
  if (f < 0 || f > 7 || r < 0 || r > 7) {
    throw 42;
  }
}
