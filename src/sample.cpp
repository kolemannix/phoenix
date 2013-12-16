#include <iostream>
#include "bitmap_util.h"
#include "position.h"

using namespace std;
using Bitmap::bitmap;


int main() {
  Position p;
  p.make_move(4, 41);
  //p.printOccupied();
  return 0;
}
