#include "PromotedPawn.h"
PromotedPawn::PromotedPawn(int _ri, int _ci, Clor _C, Board* _b, char _name) :GoldGen(_ri, _ci, _C, _b, _name)
{

}
bool PromotedPawn::IsValidMove(Board* bptr,int er, int ec)
{
	return GoldGen::IsValidMove(bptr, er, ec);
}
void PromotedPawn::draw(int _ri, int _ci)
{
	((C == BLCK ? readimagefile("b_pro_pawn-removebg-preview.gif", _ci +4, _ri+2, _ci + 70, _ri + 70) : readimagefile("pro_w_pawn-removebg-preview.gif", _ci + 4, _ri + 2, _ci + 70, _ri + 70)));
	//outstreamxy(ci, ri, bgiout);
}