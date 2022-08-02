#include "PromotedLance.h"
PromotedLance::PromotedLance(int _ri, int _ci, Clor _C, Board* _b, char _name) :GoldGen(_ri, _ci, _C, _b, _name)
{

}
bool PromotedLance::IsValidMove(Board* bptr,int er, int ec)
{

	return GoldGen::IsValidMove(bptr, er, ec);
}
void PromotedLance::draw(int _ri, int _ci)
{
	((C == BLCK ? readimagefile("b_pro_lance-removebg-preview.gif", _ci -9, _ri + 3, _ci + 80, _ri + 68) : readimagefile("pro_w_lance-removebg-preview.gif", _ci - 9, _ri + 3, _ci + 80, _ri + 68)));
	//outstreamxy(ci, ri, bgiout);
}