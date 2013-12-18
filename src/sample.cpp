#include <iostream>
#include "bitboard_util.hpp"
#include "position.hpp"
#include "move.hpp"

using namespace std;
using Bitboard::bitboard;
using Mailbox::piececode;
using Mailbox::pieceName;


int main() {
  Position p;
  Move move(Coordinate("e2"), Coordinate("e4"), pc_w_pieces);
  //p.printMailbox();
  p.make_move(move);
  //p.printMailbox();

  return 0;
}
