#include "PromotedBishop.h"
PromotedBishop::PromotedBishop(int _ri, int _ci, Clor _C, Board* _b, char _name) :Piece(_ri, _ci, _C, _b, _name), King(_ri, _ci, _C, _b, _name), Bishop(_ri, _ci, _C, _b, _name)
{

}
bool PromotedBishop::IsValidMove(Board* bptr,int er, int ec)
{
	return (King::IsValidMove(bptr, er, ec) || Bishop::IsValidMove(bptr, er, ec));
	//(IsHorizontal(ri, ci, er, ec) && Ishorizontalclear(ri, ci, er, ec) || IsVertical(ri, ci, er, ec) && Isverticalclear(ri, ci, er, ec)
	//|| ((IsDiagonal(ri,ci,er,ec))&&(Isdiagonalclear(ri,ci,er,ec))));
}
void PromotedBishop::draw(int _ri, int _ci)
{
	((C == BLCK ? readimagefile("b_peo_bishop-removebg-preview.gif", _ci + 2, _ri, _ci + 72, _ri + 75) : readimagefile("pro_w_bishop-removebg-preview.gif", _ci + 4, _ri, _ci + 72, _ri + 76)));
	//outstreamxy(ci, ri, bgiout);
}