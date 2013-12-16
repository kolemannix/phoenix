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
  p.printMailbox();

  return 0;
}
