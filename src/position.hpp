#ifndef POSITION_H
#define POSITION_H

#include "bitboard.hpp"
#include "types.hpp"
#include "mailbox_util.hpp"

using namespace Bitboards;
using namespace Mailbox;

class Position {
 public:
  void make_move(Move move);
  Position();


  // ----- DEBUG ------
  void printOccupied() const;
  piececode pieceAt(int file, int rank) const;
  void printMailbox() const;
  bool validate() const;
  void setDebug(bool d);

 private:

  bool isLegalMove(int s, int d);

  Bitboard piece_boards[32];

  Bitboard occupied, empty;

  Bitboard attacks_from[64];
  Bitboard attacks_to[64];
  
  Bitboard rank_attacks[64][64];
  Bitboard file_attacks[64][64];
  Bitboard pos_diag_attacks[64][64];
  Bitboard neg_diag_attacks[64][64];

  piececode mailbox[8][8];

  bool white_to_move;
  


  inline piececode otherColor(piececode color);

  bool debug_mode;
};

#endif
