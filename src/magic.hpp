#ifndef MAGIC_H
#define MAGIC_H

#include "bitboard_util.hpp"

using Bitboards::Bitboard;
using Bitboards::pretty;

namespace Magic {

void init();
const std::string pretty(Bitboard b);

extern Bitboard* bishop_attacks[64];
extern Bitboard* rook_attacks[64];
extern Bitboard rook_masks[64];
extern Bitboard bishop_masks[64];
extern Bitboard edge_squares;
extern Bitboard bishop_magics[64]; 
extern Bitboard rook_magics[64];

extern unsigned RShifts[SQUARE_NB];
extern unsigned BShifts[SQUARE_NB];

extern Bitboard SquareBB[SQUARE_NB];
extern Bitboard FileBB[FILE_NB];
extern Bitboard RankBB[RANK_NB];
extern Bitboard AdjacentFilesBB[FILE_NB];
extern Bitboard InFrontBB[COLOR_NB][RANK_NB];
extern Bitboard StepAttacksBB[PIECE_NB][SQUARE_NB];
extern Bitboard BetweenBB[SQUARE_NB][SQUARE_NB];
extern Bitboard LineBB[SQUARE_NB][SQUARE_NB];
extern Bitboard DistanceRingsBB[SQUARE_NB][8];
extern Bitboard ForwardBB[COLOR_NB][SQUARE_NB];
extern Bitboard PassedPawnMask[COLOR_NB][SQUARE_NB];
extern Bitboard PawnAttackSpan[COLOR_NB][SQUARE_NB];
extern Bitboard PseudoAttacks[PIECE_TYPE_NB][SQUARE_NB];

template<PieceType Pt>
FORCE_INLINE unsigned magic_index(Square s, Bitboard occ) {

  Bitboard* const Masks  = Pt == ROOK ? RMasks  : BMasks;
  Bitboard* const Magics = Pt == ROOK ? RMagics : BMagics;
  unsigned* const Shifts = Pt == ROOK ? RShifts : BShifts;

  if (Is64Bit)
    return unsigned(((occ & Masks[s]) * Magics[s]) >> Shifts[s]);

  unsigned lo = unsigned(occ) & unsigned(Masks[s]);
  unsigned hi = unsigned(occ >> 32) & unsigned(Masks[s] >> 32);
  return (lo * unsigned(Magics[s]) ^ hi * unsigned(Magics[s] >> 32)) >> Shifts[s];
}

template<PieceType Pt>
inline Bitboard attacks_bb(Square s, Bitboard occ) {
  return (Pt == ROOK ? rook_attacks : bishop_attacks)[s][magic_index<Pt>(s, occ)];
}

inline Bitboard attacks_bb(Piece p, Square s, Bitboard occ) {

  switch (type_of(p))
  {
    case BISHOP: return attacks_bb<BISHOP>(s, occ);
    case ROOK  : return attacks_bb<ROOK>(s, occ);
    case QUEEN : return attacks_bb<BISHOP>(s, occ) | attacks_bb<ROOK>(s, occ);
  }
}
}

#endif
