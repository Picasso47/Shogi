#pragma once
#include"Header.h"
class Piece;
class Pawn;
class Rook;
class Lance;
class PromotedRook;
class Cell;
class Player;
class ChessGraphics;
class Timer;
class Board
{
protected:
	Cell*** Cs;
	ChessGraphics* GFXB;
	Player* sp;
	Timer* Tb;
public:
	Board();
	Board(Board*);
	Board(int&, int**, Board*,std::string,Player*,Timer*);
	Board(int);
	void addcell(char);
	void addcell_(char,int**);
	void addnewcelltoorgboard(char, int, int);
	void DisplayBoard();
	void removecellatr_c(int _sri, int _sci);
	void promotion( int, int, int);
	void b_move(int& _sri, int& _sci, int& _dri, int& _dci);
	Clor givecolor_cell(int& _sri, int& _sci);
	Cell* givecellatr_c(int _sri, int _sci);
	void addcellatr_c(int _sri, int _sci,char sym);
	void Board::addcelltocptrbrd(char sym);
	~Board();
};