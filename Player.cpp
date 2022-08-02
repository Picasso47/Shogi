#include "Player.h"
Player::Player(string _name, Clor _C,int _points,Timer T)
{
	this->C = _C;
	this->name = _name;
	this->points = _points;
	this->T = T;
}
Player::Player()
{

}
Clor Player::giveplayerclr()
{
	return C;
}
string Player::givename()
{
	return name;
}
int Player::givepoints(int sp)
{
	points = points - sp;
	return points;
}
int Player::givepointsofplayer()
{
	return points;
}
void Player::providename(string& _name)
{
	name = _name;
}
void Player::providepoints(int& _points)
{
	points = _points;
}
void Player::providecolr(int z)
{
	if (z == 1)
		C = WHT;
	if (z == 0)
		C = BLCK;
}
int Player::getpoints(int sp)
{
	points = points + sp;
	return points;
}