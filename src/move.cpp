#include "move.hpp"

Move::Move(int s, int d) {
  src = Coordinate(s);
  dst = Coordinate(d);
}

Move::Move(Coordinate s, Coordinate d) {
 src = s;
 dst = d;
}

