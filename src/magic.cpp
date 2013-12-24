#include "magic.hpp"
#include "types.hpp"

Bitboard RMasks[SQUARE_NB];
Bitboard RMagics[SQUARE_NB];
Bitboard* RAttacks[SQUARE_NB];
unsigned RShifts[SQUARE_NB];

Bitboard BMasks[SQUARE_NB];
Bitboard BMagics[SQUARE_NB];
Bitboard* BAttacks[SQUARE_NB];
unsigned BShifts[SQUARE_NB];

Bitboard RTable[0x19000]; // Storage space for rook attacks
Bitboard BTable[0x1480]; 

typedef unsigned (Fn)(Square, Bitboard);
void init_magics(Bitboard table[], Bitboard* attacks[], Bitboard magics[],
                 Bitboard masks[], unsigned shifts[], Square deltas[], Fn index);
void Magic::init() {

  //for (Square s = SQ_A1; s <= SQ_H8; ++s)
  //BSFTable[bsf_index(SquareBB[s] = 1ULL << s)] = s;

  //for (Bitboard b = 1; b < 256; ++b)
  //MS1BTable[b] = more_than_one(b) ? MS1BTable[b - 1] : lsb(b);


  //for (File f = FILE_A; f <= FILE_H; ++f)
  //AdjacentFilesBB[f] = (f > FILE_A ? FileBB[f - 1] : 0) | (f < FILE_H ? FileBB[f + 1] : 0);

  //for (Rank r = RANK_1; r < RANK_8; ++r)
  //InFrontBB[WHITE][r] = ~(InFrontBB[BLACK][r + 1] = InFrontBB[BLACK][r] | RankBB[r]);

  //for (Color c = WHITE; c <= BLACK; ++c)
  //for (Square s = SQ_A1; s <= SQ_H8; ++s)
  //{
  //ForwardBB[c][s]      = InFrontBB[c][rank_of(s)] & FileBB[file_of(s)];
  //PawnAttackSpan[c][s] = InFrontBB[c][rank_of(s)] & AdjacentFilesBB[file_of(s)];
  //PassedPawnMask[c][s] = ForwardBB[c][s] | PawnAttackSpan[c][s];
  //}

  //for (Square s1 = SQ_A1; s1 <= SQ_H8; ++s1)
  //for (Square s2 = SQ_A1; s2 <= SQ_H8; ++s2)
  //if (s1 != s2)
  //{
  //SquareDistance[s1][s2] = std::max(file_distance(s1, s2), rank_distance(s1, s2));
  //DistanceRingsBB[s1][SquareDistance[s1][s2] - 1] |= s2;
  //}

  //int steps[][9] = { {}, { 7, 9 }, { 17, 15, 10, 6, -6, -10, -15, -17 },
  //{}, {}, {}, { 9, 7, -7, -9, 8, 1, -1, -8 } };

  //for (Color c = WHITE; c <= BLACK; ++c)
  //for (PieceType pt = PAWN; pt <= KING; ++pt)
  //for (Square s = SQ_A1; s <= SQ_H8; ++s)
  //for (int i = 0; steps[pt][i]; ++i)
  //{
  //Square to = s + Square(c == WHITE ? steps[pt][i] : -steps[pt][i]);

  //if (is_ok(to) && square_distance(s, to) < 3)
  //StepAttacksBB[make_piece(c, pt)][s] |= to;
  //}

  Square RDeltas[] = { DELTA_N,  DELTA_E,  DELTA_S,  DELTA_W  };
  Square BDeltas[] = { DELTA_NE, DELTA_SE, DELTA_SW, DELTA_NW };

  init_magics(RTable, RAttacks, RMagics, RMasks, RShifts, RDeltas, magic_index<ROOK>);
  init_magics(BTable, BAttacks, BMagics, BMasks, BShifts, BDeltas, magic_index<BISHOP>);
}


namespace {

Bitboard sliding_attack(Square deltas[], Square sq, Bitboard occupied) {

  Bitboard attack = 0;

  for (int i = 0; i < 4; ++i)
    for (Square s = sq + deltas[i];
         is_ok(s) && square_distance(s, s - deltas[i]) == 1;
         s += deltas[i])
    {
      attack |= s;

      if (occupied & s)
        break;
    }

  return attack;
}


Bitboard pick_random(RKISS& rk, int booster) {

  // Values s1 and s2 are used to rotate the candidate magic of a
  // quantity known to be optimal to quickly find the magics.
  int s1 = booster & 63, s2 = (booster >> 6) & 63;

  Bitboard m = rk.rand<Bitboard>();
  m = (m >> s1) | (m << (64 - s1));
  m &= rk.rand<Bitboard>();
  m = (m >> s2) | (m << (64 - s2));
  return m & rk.rand<Bitboard>();
}


// init_magics() computes all rook and bishop attacks at startup. Magic
// bitboards are used to look up attacks of sliding pieces. As a reference see
// chessprogramming.wikispaces.com/Magic+Bitboards. In particular, here we
// use the so called "fancy" approach.

void init_magics(Bitboard table[], Bitboard* attacks[], Bitboard magics[],
                 Bitboard masks[], unsigned shifts[], Square deltas[], Fn index) {

  int MagicBoosters[][8] = { { 3191, 2184, 1310, 3618, 2091, 1308, 2452, 3996 },
    { 1059, 3608,  605, 3234, 3326,   38, 2029, 3043 } };
  RKISS rk;
  Bitboard occupancy[4096], reference[4096], edges, b;
  int i, size, booster;

  // attacks[s] is a pointer to the beginning of the attacks table for square 's'
  attacks[SQ_A1] = table;

  for (Square s = SQ_A1; s <= SQ_H8; ++s)
  {
    // Board edges are not considered in the relevant occupancies
    edges = ((Rank1BB | Rank8BB) & ~rank_bb(s)) | ((FileABB | FileHBB) & ~file_bb(s));

    // Given a square 's', the mask is the bitboard of sliding attacks from
    // 's' computed on an empty board. The index must be big enough to contain
    // all the attacks for each possible subset of the mask and so is 2 power
    // the number of 1s of the mask. Hence we deduce the size of the shift to
    // apply to the 64 or 32 bits word to get the index.
    masks[s]  = sliding_attack(deltas, s, 0) & ~edges;
    shifts[s] = (Is64Bit ? 64 : 32) - popcount<Max15>(masks[s]);

    // Use Carry-Rippler trick to enumerate all subsets of masks[s] and
    // store the corresponding sliding attack bitboard in reference[].
    b = size = 0;
    do {
      occupancy[size] = b;
      reference[size++] = sliding_attack(deltas, s, b);
      b = (b - masks[s]) & masks[s];
    } while (b);

    // Set the offset for the table of the next square. We have individual
    // table sizes for each square with "Fancy Magic Bitboards".
    if (s < SQ_H8)
      attacks[s + 1] = attacks[s] + size;

    booster = MagicBoosters[Is64Bit][rank_of(s)];

    // Find a magic for square 's' picking up an (almost) random number
    // until we find the one that passes the verification test.
    do {
      do magics[s] = pick_random(rk, booster);
      while (popcount<Max15>((magics[s] * masks[s]) >> 56) < 6);

      std::memset(attacks[s], 0, size * sizeof(Bitboard));

      // A good magic must map every possible occupancy to an index that
      // looks up the correct sliding attack in the attacks[s] database.
      // Note that we build up the database for square 's' as a side
      // effect of verifying the magic.
      for (i = 0; i < size; ++i)
      {
        Bitboard& attack = attacks[s][index(s, occupancy[i])];

        if (attack && attack != reference[i])
          break;

        assert(reference[i] != 0);

        attack = reference[i];
      }
    } while (i != size);
  }
}
}
