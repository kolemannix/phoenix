#include <iostream>
#include "bitmap_util.hpp"
#include "position.hpp"

using namespace std;
using Bitmap::bitmap;
using Mailbox::piececode;
using Mailbox::pieceName;


int main() {
  Position p;
  //p.make_move(4, 41);
  for (int y = 0; y < 8; y++) 
    for (int x = 0; x < 8; x++) {
      cout << "(" << y << ", " << x << "): ";
      cout << pieceName(p.pieceAt(y, x)) << endl;
    }

  return 0;
}
