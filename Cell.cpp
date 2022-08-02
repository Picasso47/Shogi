#include"Cell.h"
Cell::Cell()
{
	Piece* P;
}
Cell::Cell(Piece* P)
{
	Ps = P;
}
Cell Cell::getpiecepointer(int _ri, int _ci)
{
	return Ps;
}
void Cell::drawpiece()
{
	
}
Clor Cell::cellpiececlor()
{
	if (this == NULL)
		return DASH;
	return Ps->givecolour();
}
void Cell::cellmove(int _sri, int _sci, int _dri, int _dci)
{
	Ps->move(_sri, _sci, _dri, _dci);
}
Piece* Cell::givepieceatcell()
{
	if (this == NULL)
		return NULL;
	return Ps;
}
Cell::~Cell()
{
	Ps->~Piece();
}