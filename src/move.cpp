#include "move.hpp"

Move::Move(int s, int d, piececode c): src(Coordinate(s)), dst(Coordinate(d)), color(c) {}
Move::Move(Coordinate s, Coordinate d, piececode c): src(s), dst(d), color(c) {}
Move::Move(string san, piececode c):
    src(Coordinate(san.substr(2,0))), 
    dst(Coordinate(san.substr(2,2))),
    color(c) {}
