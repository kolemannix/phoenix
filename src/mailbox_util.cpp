#include "mailbox_util.hpp"

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

void Mailbox::printMailbox(const piececode (&mailbox)[8][8]) {
  for (int rank = 7; rank >= 0; rank--) {
    cout << " +---+---+---+---+---+---+---+---+\n ";
    for (int file = 0; file < 8; file++) {
      cout << "| " << pieceChar(mailbox[rank][file]) << " ";
    }
    cout << "|\n";
  }
  cout << " +---+---+---+---+---+---+---+---+\n";
}

string Mailbox::pieceName(piececode p) {
  if (p == pc_empty) return "-";

  string name = "";
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

char Mailbox::pieceChar(piececode p) {
  switch (p) {
    case pc_empty: return ' ';
    case pc_w_pawn: return 'P';
    case pc_w_bishop: return 'B';
    case pc_w_knight: return 'N';
    case pc_w_rook: return 'R';
    case pc_w_queen: return 'Q';
    case pc_w_king: return 'K';

    case pc_b_pawn: return 'p';
    case pc_b_bishop: return 'b';
    case pc_b_knight: return 'n';
    case pc_b_rook: return 'r';
    case pc_b_queen: return 'q';
    case pc_b_king: return 'k';
  }
  return 'x';
}
