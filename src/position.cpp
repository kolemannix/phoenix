#include "position.h"

Position::Position() {
  w_king =   0x0000000000000010;
  w_queen =  0x0000000000000008;
  w_rook =   0x0000000000000081;
  w_bishop = 0x0000000000000034;
  w_knight = 0x0000000000000042;
  w_pawn =   0x000000000000ff00;

  b_king =   0x1000000000000000;
  b_queen =  0x0800000000000000;
  b_rook =   0x8100000000000000;
  b_bishop = 0x3400000000000000;
  b_knight = 0x4200000000000000;
  b_pawn =   0x00ff000000000000;

  w_pieces = w_king | w_queen 
      | w_rook | w_bishop 
      | w_knight | w_pawn;
  b_pieces = b_king | b_queen 
      | b_rook | b_bishop 
      | b_knight | b_pawn;

  occupied = w_pieces | b_pieces;

}

void Position::make_move(int s, int d) {
  bitmap src = set_mask[s];
  bitmap dst = set_mask[d];
  Bitmap::printBitmap(src);
  Bitmap::printBitmap(dst);
}

void Position::printOccupied() {
  cout << occupied << endl;
  Bitmap::printBitmap(occupied, true);
}
