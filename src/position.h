#ifndef POSITION_H
#define POSITION_H

#include "bitmap_util.h"

using Bitmap::bitmap;
using Bitmap::set_mask;

class Position {
 public:
  void make_move(int src, int dst);
  Position();


  // ----- DEBUG ------
  void printOccupied() const;
  bool validate() const;

 private:
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

};

#endif
