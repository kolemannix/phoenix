#include "mailbox_util.hpp"

// Piece codes - 2nd bit is "sliding bit", 4th bit is color bit
const Mailbox::piececode Mailbox::pc_empty = 255;


const Mailbox::piececode Mailbox::pc_w_pawn =   0;
const Mailbox::piececode Mailbox::pc_w_knight = 1;
const Mailbox::piececode Mailbox::pc_w_bishop = 2;
const Mailbox::piececode Mailbox::pc_w_rook =   3;
const Mailbox::piececode Mailbox::pc_w_queen =  6;
const Mailbox::piececode Mailbox::pc_w_king =   5;

const Mailbox::piececode Mailbox::pc_b_pawn =   8;
const Mailbox::piececode Mailbox::pc_b_knight = 9;
const Mailbox::piececode Mailbox::pc_b_bishop = 10;
const Mailbox::piececode Mailbox::pc_b_rook =   11;
const Mailbox::piececode Mailbox::pc_b_queen =  14;
const Mailbox::piececode Mailbox::pc_b_king =   13;

void Mailbox::populateStartingPosition(piececode (&mailbox)[8][8]) {
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++) {
			mailbox[x][y] = pc_empty;
		}
	}

	mailbox[0][0] = pc_w_rook;
	mailbox[0][1] = pc_w_knight;
	mailbox[0][2] = pc_w_bishop;
	mailbox[0][3] = pc_w_queen;
	mailbox[0][4] = pc_w_king;
	mailbox[0][5] = pc_w_bishop;
	mailbox[0][6] = pc_w_knight;
	mailbox[0][7] = pc_w_rook;
	for (int x = 0; x < 8; x++) mailbox[1][x] = pc_w_pawn;

	mailbox[7][0] = pc_b_rook;
	mailbox[7][1] = pc_b_knight;
	mailbox[7][2] = pc_b_bishop;
	mailbox[7][3] = pc_b_queen;
	mailbox[7][4] = pc_b_king;
	mailbox[7][5] = pc_b_bishop;
	mailbox[7][6] = pc_b_knight;
	mailbox[7][7] = pc_b_rook;
	for (int x = 0; x < 8; x++) mailbox[6][x] = pc_b_pawn;
}

std::string Mailbox::pieceName(piececode p) {
  if (p == pc_empty) return "-";

  std::string name = "";
  name += ((p >> 3) & 1) ? "black " : "white ";
  switch (p & 0x7) {
    case pc_w_pawn: name += "pawn"; break;
    case pc_w_knight: name += "knight"; break;
    case pc_w_bishop: name += "bishop"; break;
    case pc_w_rook: name += "rook"; break;
    case pc_w_queen: name += "queen"; break;
    case pc_w_king: name += "king"; break;
  }
  return name;
}

Coordinate Mailbox::coordinateFromIndex(int index) {
  int file = index % 8;
  int rank = index / 8;
  return Coordinate(file, rank);
}

int Mailbox::indexFromCoordinate(Coordinate c) {
  return c.file + c.rank*8;
}
