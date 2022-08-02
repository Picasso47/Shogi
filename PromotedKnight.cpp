#include "PromotedKnight.h"
PromotedKnight::PromotedKnight(int _ri, int _ci, Clor _C, Board* _b, char _name) :GoldGen(_ri, _ci, _C, _b, _name)
{

}
bool PromotedKnight::IsValidMove(Board* bptr,int er, int ec)
{

	return GoldGen::IsValidMove(bptr, er, ec);
}
void PromotedKnight::draw(int _ri, int _ci)
{
	((C == BLCK ? readimagefile("b pro knight.gif", _ci - 2, _ri + 2, _ci + 75, _ri + 73) : readimagefile("pro_w_knight-removebg-preview.gif", _ci - 2, _ri+2, _ci + 75, _ri + 73)));
	//outstreamxy(ci, ri, bgiout);
}