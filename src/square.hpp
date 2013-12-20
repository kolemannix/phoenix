#ifndef SQUARE_H
#define SQUARE_H

#include <string>

extern char file_chars[8];

class Square {
 public:
  Square();
  Square(int file, int rank);
  Square(int index);
  Square(std::string san);
  Square& operator=(const Square& rhs);

  std::string toString() const;
  int squareIndex() const;
  int file;
  int rank;
};

#endif
