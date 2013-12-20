#ifndef MAGIC_H
#define MAGIC_H

#include "bitboard_util.hpp"

using Bitboard::bitboard;
using Bitboard::printBitboard;

namespace Magic {
  extern bitboard bishop_attacks[64][512];
  extern bitboard rook_attacks[64][4096];
  extern bitboard rook_masks[64];
  extern bitboard bishop_masks[64];
  extern bitboard edge_squares;
  extern const bitboard bishop_magic[64]; 
  extern const bitboard rook_magic[64];
}

#endif
