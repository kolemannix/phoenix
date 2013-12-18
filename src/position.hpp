#ifndef POSITION_H
#define POSITION_H

#include "bitboard_util.hpp"
#include "mailbox_util.hpp"
#include "move.hpp"

using namespace Bitboard;
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

 private:

  bool isLegalMove(int s, int d);

  bitboard piece_boards[32];

  bitboard occupied, empty;

  bitboard attacks_from[64];
  bitboard attacks_to[64];
  
  bitboard rank_attacks[64][64];
  bitboard file_attacks[64][64];
  bitboard pos_diag_attacks[64][64];
  bitboard neg_diag_attacks[64][64];

  piececode mailbox[8][8];

  bool white_to_move;
};

#endif
