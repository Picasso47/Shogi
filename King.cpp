#include "King.h"
#include"Rook.h"
King::King(int _ri, int _ci, Clor _C, Board* _b, char _name) :Piece(_ri, _ci, _C, _b, _name)
{

}
bool King::IsValidMove(Board* bptr,int er, int ec)
{
	int dc, dr;
	dc = abs(ec - ci);
	dr = abs(er - ri);
	if ((dc == 1 || dr == 1))
	{
		return ((IsDiagonal(ri, ci, er, ec)) && Isdiagonalclear(bptr, ri, ci, er, ec) ||
			(IsHorizontal(ri, ci, er, ec) && Ishorizontalclear(bptr, ri, ci, er, ec) || IsVertical(ri, ci, er, ec) && Isverticalclear(bptr, ri, ci, er, ec)));
	}
	else
	{
		return false;
	}
}
void King::draw(int _ri, int _ci)
{
	((C == BLCK ? readimagefile("king_b-removebg-preview.gif", _ci + 6, _ri+4, _ci + 70, _ri + 73) : readimagefile("w_king-removebg-preview.gif", _ci + 8, _ri+5, _ci + 68, _ri + 70)));
	//outstreamxy(ci, ri, bgiout);
}