#include "Lance.h"
Lance::Lance(int _ri, int _ci, Clor _C, Board* _b, char _name) :Piece(_ri, _ci, _C, _b, _name)
{

}
bool Lance::IsValidMove(Board* bptr,int er, int ec)
{
	int dr = 0, dc = 0;
	dr = abs(er - ri);
	dc = abs(ec - ci);
	switch (C)
	{
	case BLCK:
		if (er > ri && (dr == 2 || dr == 1) && dc == 0)
		{
			return Isverticalclear(bptr, ri, ci, er, ec);
		}
		break;
	case WHT:
		if (er < ri && (dr == 2 || dr == 1) && dc == 0)
		{
			return Isverticalclear(bptr, ri, ci, er, ec);
		}
		break;
	default:
		break;
	}
	return false;
}
void Lance::draw(int _ri, int _ci)
{
	((C == BLCK ? readimagefile("lance_black-removebg-preview.gif", _ci -1 , _ri+5, _ci + 80, _ri + 67) : readimagefile("lance_white_-removebg-preview.gif", _ci +1, _ri+5, _ci + 74, _ri + 68)));
}