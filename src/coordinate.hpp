#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
 public:
  Coordinate(int file, int rank);
  Coordinate(int index);
  Coordinate& operator=(const Coordinate& rhs);
  int squareIndex() const;
  int file;
  int rank;
};

#endif
