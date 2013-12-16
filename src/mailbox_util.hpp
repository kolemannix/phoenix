#ifndef MAILBOX_UTIL_H
#define MAILBOX_UTIL_H

#include <string>
#include "coordinate.hpp"

namespace Mailbox {
  typedef unsigned char piececode;

  // Piece codes
  extern const piececode pc_empty;

  extern const piececode pc_w_pawn;
  extern const piececode pc_w_knight;
  extern const piececode pc_w_bishop;
  extern const piececode pc_w_rook;
  extern const piececode pc_w_queen;
  extern const piececode pc_w_king;

  extern const piececode pc_b_pawn;
  extern const piececode pc_b_knight;
  extern const piececode pc_b_bishop;
  extern const piececode pc_b_rook;
  extern const piececode pc_b_queen;
  extern const piececode pc_b_king;

  extern void populateStartingPosition(piececode (&mailbox)[8][8]);
  extern std::string pieceName(piececode p);

  extern Coordinate coordinateFromIndex(int index);
  extern int indexFromCoordinate(Coordinate c);
}

#endif
