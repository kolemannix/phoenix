#include <iostream>
#include "bitmap_util.hpp"
#include "position.hpp"

using namespace std;
using Bitmap::bitmap;


int main() {
  Position p;
  //p.make_move(4, 41);
  p.printOccupied();
  int things[100];
  things[50] = -32;
  cout << things['a'];
  return 0;
}
