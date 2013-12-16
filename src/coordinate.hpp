#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate {
 public:
  Coordinate(int file, int rank);
  const int file;
  const int rank;
 private:
  Coordinate& operator=(const Coordinate& rhs);
};

#endif
