#include "Bishop.h"
Bishop::Bishop(int _ri, int _ci, Clor _C, Board* _b, char _name) :Piece(_ri, _ci, _C, _b, _name)
{

}
bool Bishop::IsValidMove(Board* bptr,int er, int ec)
{
	return (IsDiagonal(ri, ci, er, ec)) && Isdiagonalclear(bptr, ri, ci, er, ec);
}
void Bishop::draw(int _ri, int _ci)
{
	((C == BLCK ? readimagefile("B_bishop-removebg-preview.gif", _ci + 8, _ri+5, _ci + 68, _ri + 73) : readimagefile("w_bishop-removebg-preview.gif", _ci + 8, _ri+6, _ci + 68, _ri + 70)));
	//outstreamxy(ci, ri, bgiout);
}