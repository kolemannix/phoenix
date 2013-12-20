#ifndef MOVE_H
#define MOVE_H

#include <string>
#include "square.hpp"
#include "mailbox_util.hpp"

using std::string;
using Mailbox::piececode;

class Move {
 public:
  Move(Square s, Square d, piececode color, bool capture);
  Move(string san, piececode color);
  Square src;
  Square dst;
  piececode color;
  bool capture;
  string toString() const;
};

#endif
