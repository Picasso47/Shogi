#pragma once
#include"Header.h"
class Piece;
class Pawn;
class Rook;
class Lance;
class Cell;
class Board;
class Captured_p
{
	Board* capturedpieceboard;
	Cell*** Cs;
public:
	Captured_p();
	void Addpiecetoboard(Cell*);
	Cell* givecellatr_c(int,int);
};

