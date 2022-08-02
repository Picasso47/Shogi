#include "PromotedSilver.h"
PromotedSilver::PromotedSilver(int _ri, int _ci, Clor _C, Board* _b, char _name) :GoldGen(_ri, _ci, _C, _b, _name)
{

}
bool PromotedSilver::IsValidMove(Board* bptr, int er, int ec)
{
	
	return GoldGen::IsValidMove(bptr, er, ec);
}
void PromotedSilver::draw(int _ri, int _ci)
{
	((C == BLCK ? readimagefile("b_pro_silver_gen-removebg-preview.gif", _ci + 2, _ri + 3, _ci + 76, _ri + 73) : readimagefile("w pro silver gen.gif", _ci, _ri + 1, _ci + 75, _ri + 74)));
	//outstreamxy(ci, ri, bgiout);
}