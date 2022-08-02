#include "Piece.h"
Piece::Piece(int m_ri, int m_ci, Clor m_C, Board* _b, char _name)
{
	ri = m_ri;
	ci = m_ci;
	C = m_C;
	b = _b;
	name = _name;
}
void Piece::move(int sri, int sci, int dri, int dci)
{
	this->ri = dri;
	this->ci = dci;
}
Clor Piece::givecolour()
{
	if (this == NULL)
		return DASH;
	return C;
}
char Piece::givepiecename()
{
	if (this == NULL)
		return NULL;
	return name;
}
Piece::~Piece()
{
	ri = NULL;
	ci = NULL;
	C = DASH;
	b = nullptr;
	name = NULL;
}
