#include "Pawn.h"
Pawn::Pawn(int _ri, int _ci, Clor _C, Board* _b, char _name) : Piece(_ri, _ci, _C, _b, _name)
{

}
bool Pawn::IsValidMove(Board* bptr,int er, int ec)
{
	int dr = 0, dc = 0;
	dr = abs(er - ri);
	dc = abs(ec - ci);
	switch (C)
	{
	case BLCK:
		if (er > ri && dr==1 && dc == 0)
		{
			return true;
		}
		break;
	case WHT:
		if (er < ri && dr == 1 && dc == 0)
		{
			return true;
		}
		break;
	default:
		break;
	}
	return false;
}
void Pawn::draw(int _ri,int _ci)
{
	((C == BLCK ? readimagefile("B_pawn-removebg-preview.gif", _ci + 8, _ri+4, _ci + 68, _ri + 72) : readimagefile("W_pawn-removebg-preview.gif", _ci + 8, _ri+5, _ci + 68, _ri + 75)));

	//outstreamxy(ci, ri, bgiout);
}