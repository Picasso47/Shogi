#pragma once
#include<string>
#include<string.h>
#include "Timer.h"
#include"Header.h"
using namespace std;
class Timer;
class Player
{
protected:
	Clor C;
	Timer T;
	string name;
	int points;
public:
	Player();
	Player(string _name, Clor _C,int pointd,Timer);
	Clor giveplayerclr();
	string givename();
	int givepoints(int);
	int getpoints(int);
	int givepointsofplayer();
	void providename(string&);
	void providepoints(int&);
	void providecolr(int);
};


