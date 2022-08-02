#include "GoldGen.h"
GoldGen::GoldGen(int _ri, int _ci, Clor _C, Board* _b, char _name) :Piece(_ri, _ci, _C, _b, _name)
{

}
bool GoldGen::IsValidMove(Board* bptr,int er, int ec)
{
	int dc, dr;
	dc = abs(ec - ci);
	dr = abs(er - ri);
	
	switch (C)
	{
	case BLCK:
		if ((dc == 1 || dr == 1) && !(er<ri && dc==1))
		{
			return ((IsDiagonal(ri, ci, er, ec)) && Isdiagonalclear(bptr, ri, ci, er, ec) ||
				(IsHorizontal(ri, ci, er, ec) && Ishorizontalclear(bptr, ri, ci, er, ec) || IsVertical(ri, ci, er, ec) && Isverticalclear(bptr, ri, ci, er, ec)));
		}
		break;
	case WHT:
		if ((dc == 1 || dr == 1)&& !(er > ri && dc == 1))
		{
			return ((IsDiagonal(ri, ci, er, ec)) && Isdiagonalclear(bptr, ri, ci, er, ec) ||
				(IsHorizontal(ri, ci, er, ec) && Ishorizontalclear(bptr, ri, ci, er, ec) || IsVertical(ri, ci, er, ec) && Isverticalclear(bptr, ri, ci, er, ec)));
		}
		break;
	default:
		break;
	}
	return false;
}
void GoldGen::draw(int _ri, int _ci)
{
	((C == BLCK ? readimagefile("G gen black.gif", _ci , _ri+5, _ci + 70, _ri + 70) : readimagefile("G gen white.gif", _ci+2 , _ri+4, _ci + 73, _ri + 70)));
	//outstreamxy(ci, ri, bgiout);
}