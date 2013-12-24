#include "bitboard.hpp"
#include "position.hpp"
#include "types.hpp"

#include <iostream>

int main() {
  Bitboards::init();


  Position p;
  p.setDebug(true);
  Move m = make_move(SQ_E2, SQ_E4);
  p.make_move(m);
  p.printOccupied();
}
