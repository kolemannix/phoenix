#ifndef POSITION_H
#define POSITION_H

#include "bitmap_util.h"

using namespace Bitmap;

// Piece codes - 2nd bit is "sliding bit", 4th bit is color bit
extern const int pc_w_pawn;
extern const int pc_w_knight;
extern const int pc_w_bishop;
extern const int pc_w_rook;
extern const int pc_w_queen;
extern const int pc_w_king;

extern const int pc_b_pawn;
extern const int pc_b_knight;
extern const int pc_b_bishop;
extern const int pc_b_rook;
extern const int pc_b_queen;
extern const int pc_b_king;

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

  int mailbox[8][8];

  bitmap* piece_maps[32];

};

#endif
