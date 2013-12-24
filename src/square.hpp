#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include "types.hpp"

extern char file_chars[8];

namespace Squares {
  extern Square fromFileAndRank(int file, int rank);
  extern Square fromSAN(std::string san);
  extern Rank rankOf(Square); 
  extern File fileOf(Square);
  extern std::string pretty(Square s);
};

#endif
