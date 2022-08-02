#include "SilverGen.h"
SilverGen::SilverGen(int _ri, int _ci, Clor _C, Board* _b, char _name) :Piece(_ri, _ci, _C, _b, _name)
{

}
bool SilverGen::IsValidMove(Board* bptr,int er, int ec)
{
	int dc, dr;
	dc = abs(ec - ci);
	dr = abs(er - ri);

	switch (C)
	{
	case BLCK:
		if ((dc == 1 || dr == 1) && !(er < ri && dc == 0) && er!=ri )
		{
			return ((IsDiagonal(ri, ci, er, ec)) && Isdiagonalclear(bptr,ri, ci, er, ec) ||
				(IsHorizontal( ri, ci, er, ec) && Ishorizontalclear(bptr, ri, ci, er, ec) || IsVertical(ri, ci, er, ec) && Isverticalclear(bptr,ri, ci, er, ec)));
		}
		break;
	case WHT:
		if ((dc == 1 || dr == 1) && !(er > ri && dc == 0) && er!=ri)
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
void SilverGen::draw(int _ri, int _ci)
{
	((C == BLCK ? readimagefile("S gen black.gif", _ci+2 , _ri+3, _ci + 76, _ri + 73) : readimagefile("w_silver_gen-removebg-preview.gif", _ci , _ri+1, _ci + 75, _ri + 74)));
	//outstreamxy(ci, ri, bgiout);
}