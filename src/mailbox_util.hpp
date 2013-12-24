#ifndef MAILBOX_UTIL_H
#define MAILBOX_UTIL_H

#include <iostream>

using std::cout;
using std::endl;
using std::string;

namespace Mailbox {
typedef unsigned char piececode;

// Piece codes
// Piece codes - 2nd bit is "sliding bit", 4th bit is color bit
const piececode pc_empty = 255;

const piececode pc_w_pawn =   0; // 0000
const piececode pc_w_knight = 1; // 0001
const piececode pc_w_bishop = 2; // 0010
const piececode pc_w_rook =   3; // 0011
const piececode pc_w_queen =  6; // 0110
const piececode pc_w_king =   5; // 0101

const piececode pc_b_pawn =   8; // 1000
const piececode pc_b_knight = 9; // 1001
const piececode pc_b_bishop = 10;// 1010
const piececode pc_b_rook =   11;// 1011
const piececode pc_b_queen =  14;// 1110
const piececode pc_b_king =   13;// 1101

const piececode pc_w_pieces =   7;
const piececode pc_b_pieces =   15;

const piececode bishop_mask = 0x2;
const piececode rook_mask = 0x3;
const piececode queen_mask = 0x6;


extern void populateStartingPosition(piececode (&mailbox)[8][8]);

extern std::string pieceName(piececode p);
extern char pieceChar(piececode p);

extern void printMailbox(const piececode (&mailbox)[8][8]);

extern bool isRook(piececode p);
extern bool isBishop(piececode p);
extern bool isQueen(piececode p);

inline bool isRook(piececode p) {
  return (p & rook_mask) == rook_mask;
}
inline bool isBishop(piececode p) {
  return (p & bishop_mask) == bishop_mask;
}
inline bool isQueen(piececode p) {
  return (p & queen_mask) == queen_mask;
}

}

#endif
