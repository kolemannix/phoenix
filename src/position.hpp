#ifndef POSITION_H
#define POSITION_H

#include "bitmap_util.hpp"
#include "mailbox_util.hpp"
#include "move.hpp"

using namespace Bitmap;
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

  bitmap w_king, b_king;
  bitmap w_queen, b_queen;
  bitmap w_rook, b_rook;
  bitmap w_bishop, b_bishop;
  bitmap w_knight, b_knight;
  bitmap w_pawn, b_pawn;

  bitmap occupied;
  bitmap w_pieces, b_pieces;

  bitmap attacks_from[64];
  bitmap attacks_to[64];
  
  bitmap rank_attacks[64][64];
  bitmap file_attacks[64][64];
  bitmap pos_diag_attacks[64][64];
  bitmap neg_diag_attacks[64][64];

  piececode mailbox[8][8];

  bitmap* piece_maps[32];

};

#endif
