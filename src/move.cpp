#include "move.hpp"

Move::Move(Square s, Square d, piececode c, bool ca): 
    src(s), 
    dst(d), 
    color(c),
    capture(ca) {
    }

Move::Move(string san, piececode c) {
  src = Square(san.substr(0,2)); 
  if (san.length() == 5) {
    dst = Square(san.substr(3,2));
    capture = true;
  } else {
    dst = Square(san.substr(2,2));
    capture = false;
  }
  color = c; 
}

string Move::toString() const {
  return src.toString() + (capture ? "x" : "") + dst.toString();
}
