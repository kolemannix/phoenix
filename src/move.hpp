#ifndef MOVE_H
#define MOVE_H

#include <string>
#include "coordinate.hpp"
#include "mailbox_util.hpp"

using std::string;
using Mailbox::piececode;

class Move {
 public:
  Move(int srcIndex, int dstIndex, piececode color);
  Move(Coordinate s, Coordinate d, piececode color);
  Move(string san, piececode color);
  Coordinate src;
  Coordinate dst;
  piececode color;
};

#endif
