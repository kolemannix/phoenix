#ifndef MOVE_H
#define MOVE_H

#include <string>
#include "coordinate.hpp"
using std::string;

class Move {
 public:
  Move(int srcIndex, int dstIndex);
  Move(Coordinate s, Coordinate d);
  Move(string san);
  Coordinate src;
  Coordinate dst;
};

#endif
