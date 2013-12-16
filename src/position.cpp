#include "position.hpp"


Position::Position() {

  Mailbox::populateStartingPosition(mailbox);

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

  piece_maps[pc_w_pawn] = &w_pawn;
  piece_maps[pc_w_knight] = &w_knight;
  piece_maps[pc_w_bishop] = &w_bishop;
  piece_maps[pc_w_rook] = &w_rook;
  piece_maps[pc_w_pawn] = &w_queen;
  piece_maps[pc_w_pawn] = &w_king;

  piece_maps[pc_b_pawn] = &b_pawn;
  piece_maps[pc_b_knight] = &b_knight;
  piece_maps[pc_b_bishop] = &b_bishop;
  piece_maps[pc_b_rook] = &b_rook;
  piece_maps[pc_b_pawn] = &b_queen;
  piece_maps[pc_b_pawn] = &b_king;

}

void Position::make_move(Move move) {
  piececode src_piece = mailbox[move.src.file][move.src.rank];
  piececode dst_piece = mailbox[move.dst.file][move.dst.rank];
  cout << "Source piece: " << Mailbox::pieceName(src_piece) << endl;
  cout << "Dst piece: " << Mailbox::pieceName(dst_piece) << endl;
}


bool Position::validate() const {
  if (w_pieces & b_pieces) {
    // Ensure white and black are mutually disjoint
    cout << "White and Black share squares" << endl;
    return false;
  }
  
  return true;
}

void Position::printOccupied() const {
  cout << cardinality(occupied) << endl;
  Bitmap::printBitmap(occupied, true);
}

piececode Position::pieceAt(int file, int rank) const {
  return mailbox[file][rank];
}

void Position::printMailbox() const {
  Mailbox::printMailbox(mailbox);
}
