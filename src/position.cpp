#include "position.hpp"


Position::Position() {
  white_to_move = true;
  Mailbox::populateStartingPosition(mailbox);
  
  for (int i = 0; i < 32; i++) {
    piece_boards[i] = 0;
  }
  piece_boards[pc_w_king] = 0x0000000000000010;
  piece_boards[pc_w_queen] = 0x0000000000000008;
  piece_boards[pc_w_rook] = 0x0000000000000081;
  piece_boards[pc_w_bishop] = 0x0000000000000024;
  piece_boards[pc_w_knight] = 0x0000000000000042;
  piece_boards[pc_w_pawn] = 0x000000000000ff00;

  piece_boards[pc_b_king] = 0x1000000000000000;
  piece_boards[pc_b_queen] = 0x0800000000000000;
  piece_boards[pc_b_rook] = 0x8100000000000000;
  piece_boards[pc_b_bishop] = 0x2400000000000000;
  piece_boards[pc_b_knight] = 0x4200000000000000;
  piece_boards[pc_b_pawn] = 0x00ff000000000000;

  piece_boards[pc_w_pieces] = 0x000000000000ffff;
  piece_boards[pc_b_pieces] = 0xffff000000000000;

  occupied = piece_boards[pc_w_pieces] | piece_boards[pc_b_pieces];
  empty = ~occupied;
  printBitboard(occupied);
  printBitboard(empty);
}
/**
 * @brief Make the specified move
 *
 * Assume the move is legal
 * @param move The move to make
 */
void Position::make_move(Move move) {
  int from_square = set_mask[move.src.squareIndex()];
  int to_square = set_mask[move.dst.squareIndex()];
  piececode src_piece = mailbox[move.src.rank][move.src.file];
  piececode dst_piece = mailbox[move.dst.rank][move.dst.file];
  bitboard piece_bb = piece_boards[src_piece];
  bitboard from_to_bb = from_square ^ to_square;

  piece_bb  ^=  from_to_bb;   // update piece bitboard
  piece_boards[move.color]  ^=  from_to_bb;   // update white or black color bitboard
  occupied            ^=  from_to_bb;   // update occupied ...
  empty               ^=  from_to_bb;   // ... and empty bitboard
  cout << "white pieces" << endl;
  printBitboard(pc_w_pieces);
  cout << "black pieces" << endl;
  printBitboard(pc_b_pieces);
  cout << "occupied" << endl;
  printBitboard(occupied);
  cout << "empty" << endl;
  printBitboard(empty);
}


bool Position::validate() const {
  if (piece_boards[pc_w_pieces] & piece_boards[pc_b_pieces]) {
    // Ensure white and black are mutually disjoint
    cout << "White and Black share squares" << endl;
    return false;
  }

  return true;
}

void Position::printOccupied() const {
  cout << cardinality(occupied) << endl;
  Bitboard::printBitboard(occupied, true);
}

piececode Position::pieceAt(int file, int rank) const {
  return mailbox[file][rank];
}

void Position::printMailbox() const {
  Mailbox::printMailbox(mailbox);
}
