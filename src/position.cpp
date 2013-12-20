#include "position.hpp"


Position::Position() {
  debug_mode = false;
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

  occupied = 0xffff00000000ffff;
  empty = ~occupied;

}
/**
 * @brief Make the specified move
 *
 * Assume the move is legal
 * @param move The move to make
 */
void Position::make_move(Move move) {
  bitboard from_square = set_mask[move.src.squareIndex()];
  bitboard to_square = set_mask[move.dst.squareIndex()];
  piececode src_piece = mailbox[move.src.rank][move.src.file];
  piececode dst_piece = mailbox[move.dst.rank][move.dst.file];
  bitboard from_to_mask = from_square ^ to_square;

  // from stuff
  piece_boards[src_piece]  ^=  from_to_mask;   // update piece bitboard
  piece_boards[move.color]  ^=  from_to_mask;   // update white or black color bitboard
  // to stuff
  if (move.capture) {
    piece_boards[dst_piece] ^= to_square;
    piece_boards[otherColor(move.color)] ^= to_square;
    occupied            ^=  from_square;   // update occupied ...
    empty               ^=  from_square;   // ... and empty bitboard
  } else {
    occupied            ^=  from_to_mask;   // update occupied ...
    empty               ^=  from_to_mask;   // ... and empty bitboard
  }

  // Update mailbox
  piececode tmp = mailbox[move.src.rank][move.src.file];
  mailbox[move.src.rank][move.src.file] = pc_empty;
  mailbox[move.dst.rank][move.dst.file] = tmp;

  // ----------- debug ------------
  if (debug_mode) {
    cout << "from square\n";
    printBitboard(from_square);
    cout << "to square\n";
    printBitboard(to_square);
    cout << "from_to_mask\n";
    printBitboard(from_to_mask);
    cout << "from piece\n";
    printBitboard(piece_boards[src_piece]);
    cout << "to piece\n";
    printBitboard(piece_boards[dst_piece]);
    cout << "white pieces" << endl;
    printBitboard(piece_boards[pc_w_pieces]);
    cout << "black pieces" << endl;
    printBitboard(piece_boards[pc_b_pieces]);
    cout << "occupied" << endl;
    printBitboard(occupied);
    cout << "empty" << endl;
    printBitboard(empty);
  }

  white_to_move = !white_to_move;
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

inline piececode Position::otherColor(piececode color) {
  return (color == pc_w_pieces ? pc_b_pieces : pc_w_pieces);
}

void Position::setDebug(bool d) {
  debug_mode = d;
}
