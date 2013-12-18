#ifndef COORDINATE_H
#define COORDINATE_H

#include <string>

extern char file_chars[8];

class Coordinate {
 public:
  Coordinate(int file, int rank);
  Coordinate(int index);
  Coordinate(std::string san);
  Coordinate& operator=(const Coordinate& rhs);

  std::string toString() const;
  int squareIndex() const;
  int file;
  int rank;
};

#endif
