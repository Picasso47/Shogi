#include<fstream>
#include<iostream>
#include<string>
#include<windows.h>
#include"ChessGraphics.h"
#include"graphics.h"
#include"Cell.h"
#include"King.h"
#include"Captured_p.h"
#include"Timer.h"
#include<thread>
Chess::Chess()
{
	B = nullptr;
	pturn = 0;
	sri = 0, sci = 0, dri = 0, dci = 0;
	mainwin = 0;
	cptr_p = new int* [2];
	for (int i = 0; i < 2; i++)
	{
		cptr_p[i] = new int[7]{ 0 };
	}
	savegame = '/0';
	cptrbptr = new Board(5);
	islegalmove_bool = true;
	notselfcheck_bool = true;
	checkbool = true;
	gamecontiinue = false;
	exitbutton = false;
	impassbool = false;
	loadgame = false;
	normalload = true;
	droprestriction = false;
	allowdropdest = false;
	timerstop = false;
	status = "Backgroundsave.txt";
	saveload = "Savegame.txt";
}
void Chess::move(int& _sri, int& _sci, int& _dri, int& _dci)
{
	this->sri = _dri;
	this->sci = _dci;
	B->b_move(_sri, _sci, _dri, _dci);
}
void Chess::initiateplayers()
{
	string wname;
	string bname;
	T[0] = Timer(10, 00);
	T[1] = Timer(10, 00);
	GFX->blackplayername(bname,mainwin);
	GFX->whiteplayername(wname,mainwin);
	Plz[0] = Player(wname, WHT, 27,T[0]);
	Plz[1] = Player(bname, BLCK,27,T[1]);
	srand(time(NULL));
	pturn = rand() % 2;
}
void Chess::pieceslect(int& _sri, int& _sci)
{
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
	}
	getmouseclick(WM_LBUTTONDOWN, _sci, _sri);
	if (_sci > 675)
	{
		drop(_sri, _sci);
	}
	_sri = _sri / dimBOX;
	_sci = _sci / dimBOX;
	optionselection(_sri, _sci);
	prvsri = sri;
	prvsci = sci;

}
bool Chess::validselection(Board* tempptr, int _sri, int _sci, Player* AP)
{
	if (_sri < 0 || _sri>8 || _sci < 0 || _sci>8)
		return false;

	if (tempptr->givecolor_cell(_sri, _sci) == AP[pturn].giveplayerclr())
		return true;
	return false;
}
void Chess::destselection(int& _dri, int& _dci)
{
	GFX->printdeststatus();
	while (!ismouseclick(WM_LBUTTONDOWN))
	{

	}
	getmouseclick(WM_LBUTTONDOWN, _dci, _dri);
	_dri = _dri / dimBOX;
	_dci = _dci / dimBOX;
}
bool Chess::validdest(int _dri, int _dci, Player* AP)
{
	if (_dri < 0 || _dri>8 || _dci < 0 || _dci>8)
		return false;
	//	(B->givecolor_piece(_dri, _dci) == NULL) ||
	if ((B->givecolor_cell(_dri, _dci) != AP[pturn].giveplayerclr()))
		return true;
	return false;
}
void Chess::playertrunmsg(Player* AP)
{
	if (pturn == 0)
	{
		readimagefile("wturn.JPG", 1070, 310, 1200, 330);
	}
	if (pturn == 1)
	{
		readimagefile("bturn.JPG", 1070, 310, 1200, 330);
	}
}
int Chess::pturnchange(int pturn)
{
	pturn = (pturn + 1) % 2;
	return pturn;
}
void Chess::design()
{
	GFX->printBoard(B);
}
void Chess::piecesdrawonly()
{
	GFX->capturedpiecedraw(cptrbptr, cptr_p);
}
void Chess::cleardestinationcell(int _sri, int _sci)
{
	GFX->printBox(_sri, _sci);
	GFX->printBox(dri, dci);
	GFX->printPiece(dri, dci, B);
}
bool Chess::legalmove_ofpieceatcell(Board* bptr,int _sri, int _sci, int _dri, int _dci)
{
	if (bptr->givecellatr_c(_sri, _sci) != nullptr)
		return bptr->givecellatr_c(_sri, _sci)->givepieceatcell()->IsValidMove(bptr,_dri, _dci);
}
void Chess::checkFORking(Board* tempptr, Player* AP, int& krow, int& kcol)
{
	char king_sym = (AP[pturn].giveplayerclr() == BLCK) ? 'k' : 'K';
	for (int r = 0; r < BoardDim; r++)
	{
		for (int c = 0; c < BoardDim; c++)
		{
			int cri = r, cci = c;
			King* tempking = dynamic_cast<King*>(tempptr->givecellatr_c(r, c)->givepieceatcell());
			if (tempking != nullptr && validselection(tempptr, cri, cci, AP))
			{
				if (tempking->givepiecename() == king_sym)
				{
					krow = r;
					kcol = c;
					return;
				}
			}
		}
	}
}
bool Chess::check(Board* tempptr, Player* AP)
{
	int krow, kcol;
	pturn = pturnchange(pturn);
	checkFORking(tempptr, AP, krow, kcol);
	pturn = pturnchange(pturn);
	for (int r = 0; r < BoardDim; r++)
	{
		for (int c = 0; c < BoardDim; c++)
		{

			if (validselection(tempptr, r, c, AP) && legalmove_ofpieceatcell(tempptr,r, c, krow, kcol))
			{
				pturn = pturnchange(pturn);
				return true;
			}
		}
	}
	pturn = pturnchange(pturn);
	return false;
}
bool Chess::selfCheck(Player* AP, int _sri, int _sci, int _dri, int _dci)
{
	Board* Temp = new Board(B);
	Temp->b_move(_sri, _sci, _dri, _dci);
	pturn = pturnchange(pturn);
	return check(Temp, AP);
}
void Chess::validpathhighlight()
{
	for (int r = 0; r < BoardDim; r++)
	{
		for (int c = 0; c < BoardDim; c++)
		{
			int desr = r, desc = c;
			if (validdest(desr, desc, Plz) && (legalmove_ofpieceatcell(B,sri, sci, desr, desc)) && !selfCheck(Plz, sri, sci, desr, desc))
			{
				if (B->givecellatr_c(desr, desc) != nullptr)
					GFX->printredBorder(r, c);
				else
				GFX->printBorder(r, c);
			}
		}
	}
}
void Chess::validpathunhighlight()
{
	for (int r = 0; r < BoardDim; r++)
	{
		for (int c = 0; c < BoardDim; c++)
		{
			int desr = r, desc = c;
			if (validdest(desr, desc, Plz) && (legalmove_ofpieceatcell(B,sri, sci, desr, desc)) && !selfCheck(Plz, sri, sci, desr, desc))
			{
				if (B->givecellatr_c(desr, desc) == nullptr)
					GFX->printBox(r, c);
				else
				{
					GFX->printBox(r, c);
					GFX->printPiece(r, c, B);
				}
			}
		}
	}
}
void Chess::capture()
{
	if (B->givecellatr_c(dri, dci) != nullptr)
	{
		pointscounter();
		cptrbptr->addcell_(B->givecellatr_c(dri, dci)->givepieceatcell()->givepiecename(), cptr_p);
		cptrbptr->addcell(B->givecellatr_c(dri, dci)->givepieceatcell()->givepiecename());
	}
}
void Chess::dropcordinatesadjust(int& _sri, int& _sci, bool& dropallow)
{
	if ((_sri >= 75 && _sri <= 150 && _sci >= 825 && _sci <= 1350) && pturn == 1)
	{
		dropallow = true;
		_sri = 0;
		if (_sci > 825 && _sci < 900)
			_sci = 0;
		if (_sci > 900 && _sci < 975)
			_sci = 2;
		if (_sci > 975 && _sci < 1050)
			_sci = 3;
		if (_sci >= 1050 && _sci <= 1125)
			_sci = 5;
		if (_sci >= 1125 && _sci <= 1200)
			_sci = 7;
		if (_sci >= 1200 && _sci <= 1275)
			_sci = 9;
		if (_sci >= 1275 && _sci <= 1350)
		{
			_sci = 10;
			for (int i = 18; i >= _sci; i--)
			{
				if (cptrbptr->givecellatr_c(_sri, i) != nullptr)
				{
					_sci = i;
					return;
				}
			}
		}
		if (cptrbptr->givecellatr_c(_sri, _sci) == nullptr)
			_sci -= 1;
	}
	if ((_sri >= 525 && _sri <= 600 && _sci >= 825 && _sci <= 1350) && pturn == 0)
	{
		dropallow = true;
		_sri = 1;
		if (_sci > 825 && _sci < 900)
			_sci = 0;
		if (_sci > 900 && _sci < 975)
			_sci = 2;
		if (_sci > 975 && _sci < 1050)
			_sci = 3;
		if (_sci >= 1050 && _sci <= 1125)
			_sci = 5;
		if (_sci >= 1125 && _sci <= 1200)
			_sci = 7;
		if (_sci >= 1200 && _sci <= 1275)
			_sci = 9;
		if (_sci >= 1275 && _sci <= 1350)
		{
			_sci = 10;
			for (int i = 18; i >= _sci; i--)
			{
				if (cptrbptr->givecellatr_c(_sri, i) != nullptr)
				{
					_sci = i;
					return;
				}
			}
		}
		if (cptrbptr->givecellatr_c(_sri, _sci) == nullptr)
			_sci -= 1;
	}
}
void Chess::pointscounter()
{
	char sym = B->givecellatr_c(dri, dci)->givepieceatcell()->givepiecename();
	int sp = 0;
	if (sym == 'B' || sym == 'b' || sym == 'r' || sym == 'R' || sym == 'o' || sym == 'O')
	{
		sp = 5;
	}
	else
		sp = 1;
	if (pturn == 0)
 	{ 
		Plz->givepoints(sp);
		Plz[0].getpoints(sp);
	}
	if (pturn == 1)
	{
		Plz->givepoints(sp);
		Plz[1].getpoints(sp);
	}
}
bool Chess::piecewithnowmove(char sym,int _desr)
{
	if ((sym == 'n' || sym == 'l' || sym == 'p') && _desr == 8)
	{
		return true;
	}
	if ((sym == 'N' || sym == 'L' || sym == 'P') && _desr == 0)
	{
		return true;
	}
	if ((sym == 'n') && _desr == 7)
	{
		return true;
	}
	if ((sym == 'N') && _desr == 1)
	{
		return true;
	}
	return false;
}
bool Chess::twopawns(char sym,int constcol)
{
	if (sym == 'p')
	{
		for (int ci = 0; ci < BoardDim; ci++)
		{
			if (B->givecellatr_c(ci, constcol)->givepieceatcell()->givepiecename() == 'p')
				return true;
		}
	}
	if (sym == 'P')
	{
		for (int ci = 0; ci < BoardDim; ci++)
		{
			if (B->givecellatr_c(ci, constcol)->givepieceatcell()->givepiecename() == 'P')
				return true;
		}
	}
	return false;
}
bool Chess::droppawnmate()
{
	pturn = pturnchange(pturn);
	if (doihaveMORE_MOVE())
	{
		pturn = pturnchange(pturn);
		return true;
	}
	pturn = pturnchange(pturn);
	return false;
}
void Chess::drophighlght(int _sri,int _sci,char sym)
{
	for (int ri = 0; ri < BoardDim; ri++)
	{
		for (int ci = 0; ci < BoardDim; ci++)
		{
			droprestriction = piecewithnowmove(sym, ri);
			if (!droprestriction)
				droprestriction=twopawns(sym,ci);
			if (!droprestriction)
				droprestriction = droppawnmate();
					if (B->givecellatr_c(ri, ci) == nullptr && !droprestriction)
			            GFX->printBorder(ri, ci);
		}
	}
}
bool Chess::dropdestselection(int& _dri, int& _dci,char sym)
{
			droprestriction = piecewithnowmove(sym, _dri);
			if (!droprestriction)
				droprestriction = twopawns(sym, _dci);
			if (!droprestriction)
				droprestriction = droppawnmate();
			if (B->givecellatr_c(_dri, _dci) == nullptr && !droprestriction)
				return true;
	return false;
}
void Chess::drop(int _sri, int _sci)
{
	_sri = sri, _sci = sci;
	bool dropallow = false;
	dropcordinatesadjust(_sri, _sci, dropallow);
	if (dropallow && cptrbptr->givecellatr_c(_sri, _sci) != nullptr)  //and piece color and player color are same
	{
		GFX->printdropstatus();
		char a = cptrbptr->givecellatr_c(_sri, _sci)->givepieceatcell()->givepiecename();
		cptrbptr->removecellatr_c(_sri, _sci);
		drophighlght(_sri, _sci, a);
		destselection(dri, dci);
		while (!dropdestselection(dri, dci, a))
		{
			destselection(dri, dci);
		}
		GFX->dropunhighlight(B);
		B->addnewcelltoorgboard(a, dri, dci);
		GFX->printPiece(dri, dci, B);
		GFX->capturedpiecedraw(cptrbptr, cptr_p);
		pturn=pturnchange(pturn);
		playertrunmsg(Plz);
		GFX->printselectstatus();
		getmouseclick(WM_LBUTTONDOWN, _sci, _sri);
	}
}
void Chess::checkmsg()
{
	if (check(B, Plz))
	{
		if (pturn == 0)
			readimagefile("wturn.JPG", 1080, 422, 1210, 442);
		if (pturn == 1)
			readimagefile("bturn.JPG", 1080, 422, 1210, 442);
	}
	else
	{
		readimagefile("simplecolor.JPG", 1080, 422, 1210, 442);
	}
}
void Chess::currentstate(string& str)
{
	ofstream wtr(str);
	for (int ri = 0; ri < BoardDim; ri++)
	{
		for (int ci = 0; ci < BoardDim; ci++)
		{
			if (B->givecellatr_c(ri, ci) != nullptr)
				wtr << B->givecellatr_c(ri, ci)->givepieceatcell()->givepiecename();
			else
				wtr << '-';
		}
		wtr << endl;
	}
	for (int ri = 0; ri < capturedBoardSize; ri++)
	{
		for (int ci = 0; ci < CapturedBoardcolDim; ci++)
		{
			wtr << cptr_p[ri][ci] << " ";
		}
		wtr << '\n';
	}
	for (int ri = 0; ri < capturedBoardSize; ri++)
	{
		for (int ci = 0; ci < captureboardcolmake; ci++)
		{
			if (cptrbptr->givecellatr_c(ri, ci) != nullptr)
				wtr << cptrbptr->givecellatr_c(ri, ci)->givepieceatcell()->givepiecename();
			else
				wtr << '-';
		}
		wtr << endl;
	}
	for (int i = 0; i < capturedBoardSize; i++)
	{
		wtr << Plz[i].givename() << '\n';
		wtr << Plz[i].givepointsofplayer() << '\n';
		if (i == 0)
			wtr << WHT << '\n';
		if (i == 1)
			wtr << BLCK << '\n';
	}
	wtr << pturn << '\n';
	for (int i = 0; i < capturedBoardSize; i++)
	{
		wtr << T[i];
	}
	wtr.close();
}
void Chess::optionselection(int _sri, int _sci)
{
	if (_sri == 3 && _sci >= 18 && _sci <= 20)//savegame
	{
		GFX->cusrsorsave();
		currentstate(saveload);
		delay(1050);
		GFX->noncursosave();
	}
	if (_sri == 4 && _sci >= 18 && _sci <= 20)//loadgame
	{
		GFX->cursorload();
		B = new Board(pturn, cptr_p, cptrbptr, saveload,Plz,T);
		design();
		GFX->onlypiecesdraw(B);
		GFX->capturedpiecedraw(cptrbptr, cptr_p);
		playertrunmsg(Plz);
		pturn = pturnchange(pturn);
		checkmsg();
		GFX->noncursorload();
	}
	if (_sri == 11 && _sci >= 18 && _sci <= 20)
	{
		exitbutton = true;
	}
	if (_sri >= 8 && _sri <= 9 && _sci >= 9 && _sci <= 10)
	{
		GFX->undoclick();
		B = new Board(pturn, cptr_p, cptrbptr, status,Plz,T);
		GFX->printBox(dri, dci);
		GFX->printPiece(prvsri, prvsci, B);
		playertrunmsg(Plz);
		GFX->capturedpiecedraw(cptrbptr, cptr_p);
		GFX->undonormal();
		pieceslect(_sri, _sci);
	}
}
bool Chess::canimove()
{
	Board* Tempo = new Board(B);
	for (int canmove_r = 0; canmove_r < BoardDim; canmove_r++)
	{
		for (int canmove_c = 0; canmove_c < BoardDim; canmove_c++)
		{
			if (validselection(Tempo, canmove_r, canmove_c, Plz))
			{
				for (int ri = 0; ri < BoardDim; ri++)
				{
					for (int ci = 0; ci < BoardDim; ci++)
					{
						if (validdest(ri, ci, Plz) && legalmove_ofpieceatcell(Tempo,canmove_r, canmove_c, ri, ci) && !selfCheck(Plz, canmove_r, canmove_c, ri, ci))
						{
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}
bool Chess::doihaveMORE_MOVE()
{
	Board* Temp1 = new Board(B);
	pturn = pturnchange(pturn);
	return ((check(Temp1, Plz) && !canimove()));
}
void Chess::impass()
{
	int Bkrow = 0, Bkcol = 0;
	int Wkrow = 0, Wkcol = 0;
	int _pturn = pturn;
	int _sci = 0, _sri = 0;
	pturn = 1;
	{
		checkFORking(B, Plz, Bkrow, Bkcol);
	}
	pturn = 0;
	{
		checkFORking(B, Plz, Wkrow, Wkcol);
	}
	if (Bkrow >= 6 && Wkrow <= 2)
	{
		int t1=initwindow(600, 200,"DO YOU WANT TO IMPASS",200,200);
		setcurrentwindow(t1);
		GFX->impassdisplay();
		while (!ismouseclick(WM_LBUTTONDOWN))
		{
		}
		getmouseclick(WM_LBUTTONDOWN, _sci, _sri);
		_sci;
		_sri;
		if ((_sri >= 25 && _sri <= 55) && (_sci >= 170 && _sci <= 260))
		{
			impassbool = true;
		}
		if ((_sri >= 25 && _sri <= 55) && (_sci >= 315 && _sci <= 400))
		{
			impassbool = false;
		}
		closegraph(t1);
	}
	setcurrentwindow(mainwin);
	pturn = _pturn;
}
void Chess::impasswinner()
{
	string a;
	string z = "Click to exit";
	string m = " won by impass rule";
	bool draw = true;
	if (Plz[1].givepointsofplayer() >=24 &&  Plz[0].givepointsofplayer()<24 )
	{
		a = Plz[1].givename();
		m = " won by impass rule";
		draw = false;
	}
	if (Plz[0].givepointsofplayer() >=24 &&  Plz[1].givepointsofplayer()<24)
	{
		a = Plz[0].givename(); 
		m = " won by impass rule";
		draw = false;
	}
	if(draw)
	{
		a = "Draw ";
		m = " Has occured";
	}
	int t1 = initwindow(600, 200, " Winner Declaration ", 200, 200);
	setcurrentwindow(t1);
	string x = a + m;
	GFX->gameenddisplay();
	GFX->printline(130, 120, x);
	GFX->printline(200, 150, z);
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
	}
	closegraph(t1);
	setcurrentwindow(mainwin);
}
void Chess::checkamtewinner()
{
	string a;
	string z = "Click to exit";
	if (pturn==0)
	{
		a = Plz[1].givename();
	}
	if (pturn==1)
	{
		a = Plz[0].givename();
	}
	string b= " won by CheckMate";
	int t1 = initwindow(600, 200, " Winner Declaration ", 200, 200);
	setcurrentwindow(t1);
	GFX->gameenddisplay();
	string c = a + b;
	GFX->printline(170, 120, c);
	GFX->printline(200, 150, z);
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
	}
	closegraph(t1);
	setcurrentwindow(mainwin);
}
void Chess::defaultload()
{
	GFX->cursorload();
	B = new Board(pturn, cptr_p, cptrbptr, saveload,Plz,T);
	design();
	GFX->onlypiecesdraw(B);
	GFX->capturedpiecedraw(cptrbptr, cptr_p);
	playertrunmsg(Plz);
	checkmsg();
	pturn = pturnchange(pturn);
	GFX->noncursorload();
	normalload = false;
}
void Chess::printtime(int& pturn)
{
	bgiout << T[0];
	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	setbkcolor(MAGENTA);
	outstreamxy(707, 565, bgiout);
	bgiout << T[1];
	settextstyle(BOLD_FONT, HORIZ_DIR, 3);
	setbkcolor(MAGENTA);
	outstreamxy(707, 115, bgiout);
	while (pturn!=2)
	{
		while (pturn == 0)
		{
			T[0]--;
			bgiout << T[0];
			settextstyle(BOLD_FONT, HORIZ_DIR, 3);
			setbkcolor(MAGENTA);
			outstreamxy(707, 565, bgiout);
			Sleep(1000);
		}
		while (pturn == 1)
		{
			T[1]--;
			bgiout << T[1];
			settextstyle(BOLD_FONT, HORIZ_DIR, 3);
			setbkcolor(MAGENTA);
			outstreamxy(707, 115, bgiout);
			Sleep(1000);
		}
	}	
}
void Chess::run()
{
	mainwin=initwindow(1600, 950, "SHOKHI");
	setcurrentwindow(mainwin);
	GFX->newgaemdisplay(loadgame);
	GFX->backgroundprint();
	design();
	if (loadgame)
		defaultload();
	if (normalload)
	{
		B = new Board();
		GFX->onlypiecesdraw(B);
		initiateplayers();
	}
	playertrunmsg(Plz);
	std::thread t1(&Chess::printtime,this, ref(pturn));
	do
	{
		GFX->printselectstatus();
		piecesdrawonly();
		do
		{
			do
			{
				pieceslect(sri, sci);
				if (exitbutton)
					break;
			} while (!validselection(B, sri, sci, Plz));
			if (!exitbutton)
			validpathhighlight();
			do
			{
				if (exitbutton)
					break;
				destselection(dri, dci);
			} while (!validdest(dri, dci, Plz));
			if (exitbutton)
				break;
			islegalmove_bool = (legalmove_ofpieceatcell(B,sri, sci, dri, dci));
			notselfcheck_bool = !selfCheck(Plz, sri, sci, dri, dci);
		} while (!(islegalmove_bool && notselfcheck_bool));
		if (exitbutton)
			break;
		capture();
		validpathunhighlight();
		currentstate(status);
		B->b_move(sri, sci, dri, dci);
		B->promotion(dri, dci, pturn);
		setcurrentwindow(mainwin);
		cleardestinationcell(sri, sci);
		checkmsg();
		gamecontiinue = doihaveMORE_MOVE();
		playertrunmsg(Plz);
		impass();
		if (impassbool == true)
			break;
	} while (gamecontiinue == false);
	if (impassbool)
	{
		impasswinner();
	}
	if (gamecontiinue == true)
	{
		checkamtewinner();
	}
	pturn = 2;
	t1.join();
	closegraph(mainwin);
}