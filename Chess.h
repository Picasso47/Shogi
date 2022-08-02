#pragma once
#include"Player.h"
#include"Timer.h";
#include<iostream>
using namespace std;
class Board;
class Piece;
class King;
class Player;
class ChessGraphics;
class Captured_p;
class Timer;
class Chess
{
	Board* B;
	Board* cptrbptr;
	ChessGraphics* GFX;
	Timer* T = new Timer[2];
	int** cptr_p;
	int pturn;
	int sri, sci, dri, dci;
	int tsri, tsci, tdri, tdci;
	int cpturn;
	int prvsri, prvsci;
	char savegame;
	bool islegalmove_bool;
	bool notselfcheck_bool;
	bool checkbool;
	bool gamecontiinue;
	bool loadgame;
	bool normalload;
	bool exitbutton;
	bool impassbool;
	bool droprestriction;
	bool allowdropdest;
	bool timerstop;
	int mainwin;
	int w = 20;
	int b = 20;
	string status;
	string saveload;
	Player* Plz = new Player[2];
public:
	Chess();
	void run();
	int pturnchange(int);
	void checkFORking(Board* tempptr, Player*, int& krow, int& kcol);//returns my king row col
	bool selfCheck(Player*,int _sri,int _sci,int _dri,int _dci);//checks for selfcheck
	bool check(Board*,Player*);//checks for check on other piece
	bool legalmove_ofpieceatcell(Board*,int _sri,int _sci,int _dri,int _dci);
	void validpathhighlight();
	void validpathunhighlight();
	void capture();
	void optionselection(int,int);
	void drop(int _sri,int _sci);
	void dropcordinatesadjust(int&, int&,bool&);
	void playertrunmsg(Player* AP);
	void initiateplayers();
	void pieceslect(int& _sri, int& _sci);
	bool validselection(Board*,int _sri, int _Sci, Player*);
	bool validdest(int _dri, int _dci, Player*);
	void destselection(int& _dri, int& _dci);
	void move(int& _sri, int& _sci, int& _dri, int& _dci);
	void design();
	void piecesdrawonly();
	void checkmsg();
	void cleardestinationcell(int _dri, int _dci);
	void currentstate(string&);
	bool canimove();
	bool doihaveMORE_MOVE();
	void pointscounter();
	void impass();
	void impasswinner();
	void checkamtewinner();
	void defaultload();
	void drophighlght(int,int,char);
	bool piecewithnowmove(char,int _desr);
	bool twopawns(char,int _desc);
	bool droppawnmate();
	bool dropdestselection(int&,int&,char);
	void printtime(int&);
};

