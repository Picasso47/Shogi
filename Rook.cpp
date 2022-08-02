#include "Rook.h"
Rook::Rook(int _ri, int _ci, Clor _C, Board* _b, char _name) :Piece(_ri, _ci, _C, _b, _name)
{

}
bool Rook::IsValidMove(Board* bptr,int er, int ec)
{
	return (IsHorizontal(ri, ci, er, ec) && Ishorizontalclear(bptr, ri, ci, er, ec) || IsVertical(ri, ci, er, ec) && Isverticalclear(bptr, ri, ci, er, ec));
}
void Rook::draw(int _ri, int _ci)
{
	((C == BLCK ? readimagefile("B_rook-removebg-preview.gif", _ci+8 , _ri+5 , _ci + 65, _ri +70) : readimagefile("w_rook-removebg-preview.gif", _ci , _ri-5, _ci + 110, _ri + 85)));
	//outstreamxy(ci, ri, bgiout);
}