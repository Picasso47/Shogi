#include "Knight.h"
Knight::Knight(int _ri, int _ci, Clor _C, Board* _b, char _name) :Piece(_ri, _ci, _C, _b, _name)
{

}
bool Knight::IsValidMove(Board* bptr,int er, int ec)
{
	int dc, dr;
	dc = abs(ec - ci);
	dr = (er - ri);
	switch (C)
	{
	case BLCK:
		if ((dr == 2 && dc == 1) || (dr == 1 && dc == 2))
		{
			return true;
		}
		break;
	case WHT:
		if ((dr == -2 && dc == 1) || (dr == -1 && dc == 2))
		{
			return true;
		}
		break;
	default:
		break;
	}
	return false;
}
void Knight::draw(int _ri, int _ci)
{
	((C == BLCK ? readimagefile("knight-removebg-preview.gif", _ci-2 , _ri+2, _ci + 87, _ri + 90) : readimagefile("w_knight-removebg-preview.gif", _ci -17, _ri-15, _ci + 79, _ri +85)));
	//outstreamxy(ci, ri, bgiout);
}