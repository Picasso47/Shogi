#include "PromotedRook.h"
#include"Rook.h"
#include"Bishop.h"
#include"King.h"
PromotedRook::PromotedRook(int _ri, int _ci, Clor _C, Board* _b, char _name) :Piece(_ri, _ci, _C, _b, _name),King(_ri, _ci, _C, _b, _name),Bishop(_ri, _ci, _C, _b, _name), Rook(_ri, _ci, _C, _b, _name)
{

}
bool PromotedRook::IsValidMove(Board* bptr,int er, int ec)
{
	return (King::IsValidMove(bptr, er, ec) || Bishop::IsValidMove(bptr, er, ec) || Rook::IsValidMove(bptr, er, ec));
		//(IsHorizontal(ri, ci, er, ec) && Ishorizontalclear(ri, ci, er, ec) || IsVertical(ri, ci, er, ec) && Isverticalclear(ri, ci, er, ec)
		//|| ((IsDiagonal(ri,ci,er,ec))&&(Isdiagonalclear(ri,ci,er,ec))));
}
void PromotedRook::draw(int _ri, int _ci)
{
	((C == BLCK ? readimagefile("b pro rook.gif", _ci + 6, _ri + 5, _ci + 68, _ri + 70) : readimagefile("w pro rook.gif", _ci + 6, _ri + 5, _ci + 68, _ri + 70)));
	//outstreamxy(ci, ri, bgiout);
}