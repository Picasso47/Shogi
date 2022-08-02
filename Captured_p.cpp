#include "Board.h"
#include"Pawn.h"
#include"Rook.h"
#include"Knight.h"
#include"Bishop.h"
#include"Lance.h"
#include"King.h"
#include"GoldGen.h"
#include"SilverGen.h"
#include"Cell.h"
#include "Captured_p.h"
Captured_p::Captured_p()
{
	int z=0;
	Board* capturedpieceboard = new Board(z);
}
void Captured_p::Addpiecetoboard(Cell* orgptr)
{
			char a = orgptr->givepieceatcell()->givepiecename();
			capturedpieceboard->addcell(a);
}
Cell* Captured_p::givecellatr_c(int _sri, int _sci)
{
	return Cs[_sri][_sci];
}