#include "ChessGraphics.h"
#include"Board.h"
#include"Cell.h"
#include "GoldGen.h"
#include"graphics.h"
#include<vector>
#include"Header.h"
ChessGraphics::ChessGraphics()
{
	savecursor=true;
	loadcursor=true;
}
void ChessGraphics::backgroundprint()
{
	readimagefile("Add a heading(5).jpg", 0, 0, 1600, 950);
	readimagefile("SaveGame.JPG", 1400, 200, 1500, 244);
	readimagefile("LoadGame.JPG", 1405, 305, 1500, 350);
	readimagefile("undo-transformed.gif", 740, 620, 800, 680);
	readimagefile("undoyF.JPG", 750, 630, 790, 670);
	readimagefile("Exit non press.JPG", 1485, 842, 1520, 880);
	readimagefile("block_f-removebg-preview.gif", 680, 80, 800, 170);
	readimagefile("block_f-removebg-preview.gif", 680, 530, 800, 620);
}
void ChessGraphics::printBorder(int r, int c)
{
	r *= dimBOX;
	c *= dimBOX;
	readimagefile("Capture-removebg-preview(3).gif", c-8 , r-10, c + 83, r - 107);
}
void ChessGraphics::printredBorder(int r, int c)
{
	r *= dimBOX;
	c *= dimBOX;
	readimagefile("Capture-removebg-preview(4).gif", c - 28, r - 22, c + 86, r - 139);
}
void ChessGraphics::printBox(int r, int c)
{
	int color_int;
	if ((r + c) % 2 == 0)
	{
		color_int = CYAN;
	}
	else
	{
		color_int =WHITE;
	}
	setfillstyle(SOLID_FILL, color_int);
	bar(c*dimBOX, r*dimBOX, (c+1) * dimBOX, (r + 1)* dimBOX);
	
}
void ChessGraphics::printPiece(int r, int c, Board* b)
{
	int d_row = r * dimBOX;
	int d_col = c * dimBOX;
	if (b->givecellatr_c(r, c)->givepieceatcell() != nullptr)
		b->givecellatr_c(r, c)->givepieceatcell()->draw(d_row, d_col);
}
void ChessGraphics::onlypiecesdraw(Board* b)
{
	for (int ri = 0; ri < BoardDim; ri++)
	{
		for (int ci = 0; ci < BoardDim; ci++)
		{
			printPiece(ri, ci, b);
		}
	}
}
void ChessGraphics::drophighlight(Board* b)
{
	for (int ri = 0; ri < BoardDim; ri++)
	{
		for (int ci = 0; ci < BoardDim; ci++)
		{
			if (b->givecellatr_c(ri, ci) == nullptr)
			{
				printBorder(ri, ci);
			}
		}
	}
}
void ChessGraphics::dropunhighlight(Board* b)
{
	for (int ri = 0; ri < BoardDim; ri++)
	{
		for (int ci = 0; ci < BoardDim; ci++)
		{
			if (b->givecellatr_c(ri, ci) == nullptr)
			{
			
				printBox(ri, ci);
			}
		}
	}
}
void ChessGraphics::capturedpiecedraw(Board* b,int** ttlpieces)
{
	int drow = 1, dcolb = 0;
	int pieceatindexcol = 0;
	for (int ri = 0; ri <= CapturedBoardrowDim; ri++)
	{
		for (int ci = captureboardcolmake - 1; ci >=0; ci--)
		{
			if (ci >= 10 && ci < 19)//pawns
			{
				dcolb = addition + 6;
				pieceatindexcol = 6;
			}
			if (ci == 0)//Rook
			{
				dcolb = addition + 0;
				pieceatindexcol = 0;
			}
			if (ci == 1 || ci == 2)//Gold Gen
			{
				dcolb = addition + 1;
				pieceatindexcol = 0;
			}
			if (ci == 3)//Bishop
			{
				dcolb = addition + 2;
				pieceatindexcol = 2;

			}
			if (ci == 4 || ci == 5)//Knight
			{
				dcolb = addition + 3;
				pieceatindexcol = 3;

			}
			if (ci == 6 || ci == 7)//Lance
			{
				dcolb = addition + 4;
				pieceatindexcol = 4;
			}	
			if (ci == 8 || ci == 9)//SilverGen
			{
				dcolb = addition + 5;
				pieceatindexcol = 5;

			}
				if(b->givecellatr_c(ri, ci)->givepieceatcell()!=nullptr)
			b->givecellatr_c(ri, ci)->givepieceatcell()->draw((drow)*dimBOX,(dcolb)*dimBOX);
				else
					printBox(drow, dcolb);
		}
		drow = 7;
	}
}
void ChessGraphics::printBoard(Board* b)
{
	for (int ri = 0; ri < BoardDim; ri++)
	{
		for (int ci = 0; ci < BoardDim; ci++)
		{
			printBox(ri, ci);
		}
	}

	for (int ri = capturedboardBLCKkrow_pos; ri <= CapturedBoardrowDim ; ri++)
	{
		for (int ci = addition; ci < CapturedBoardcolDim + addition; ci++)
		{
			printBox(ri, ci);
		}
	}
	for (int ri = capturedboardWHTrow_pos; ri <= CapturedBoardrowDim+6; ri++)
	{
		for (int ci = addition; ci < CapturedBoardcolDim + addition; ci++)
		{
			printBox(ri, ci);
		}
	}

}
void ChessGraphics::printselectstatus()
{
	readimagefile("Selection.JPG", 1100, 363, 1270, 385);
}
void ChessGraphics::printdropstatus()
{
	readimagefile("Drop.JPG", 1100, 363, 1270, 385);
}
void ChessGraphics::printdeststatus()
{
	readimagefile("Dest.JPG", 1100, 361, 1270, 388);
}
void ChessGraphics::cusrsorsave()
{
		readimagefile("savegames.JPG", 1400, 200, 1500, 249);
}
void ChessGraphics::noncursosave()
{
	readimagefile("SaveGame.JPG", 1400, 200, 1500, 244);
}
void ChessGraphics::cursorload()
{
		readimagefile("loadgames.JPG", 1405, 305, 1500, 350);
}
void ChessGraphics::noncursorload()
{
	readimagefile("LoadGame.JPG", 1405, 305, 1500, 350);
}
void ChessGraphics::buttoncall()
{
}
void ChessGraphics::undoclick()
{
	readimagefile("undofG.JPG", 750, 630, 790, 670);
}
void ChessGraphics::undonormal()
{
	readimagefile("undoyF.JPG", 750, 630, 790, 670);
}
void ChessGraphics::impassdisplay()
{
	readimagefile("Impass.jpg", 0, 0, 600, 200);
	readimagefile("NO.JPG", 320, 30,400, 50);
	readimagefile("Yes.JPG", 190, 30, 240, 50);
}
void ChessGraphics::promotiondisplay(bool& allowpromotion)
{
	int _sri = 0, _sci = 0;
	readimagefile("Pawnpromotion.JPG", 0, 0, 600, 200);
	readimagefile("NO.JPG", 340, 35, 410, 55);
	readimagefile("Yes.JPG", 200, 35, 250, 53);
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
	}
	getmouseclick(WM_LBUTTONDOWN, _sci, _sri);
	_sci;
	_sri;
	if (_sri >= 30 && _sri <= 55)
	{
		if (_sci >= 180 && _sci <= 265)
		{
			allowpromotion = true;
		}
		if (_sci >= 330 && _sci <= 420)
		{
			allowpromotion = false;
		}
	}
 }
void ChessGraphics::gameenddisplay()
{
	readimagefile("winner box.JPG", 0, 0, 600, 200);
}
void ChessGraphics::newgaemdisplay(bool &loadgame)
{
	int _sri = 0, _sci = 0;
	readimagefile("Add a heading.jpg", 0, 0, 1600, 950);
	readimagefile("new game.JPG", 736, 390, 833, 440);
	readimagefile("LoadGame.JPG", 740, 535, 830, 585);
	while (!ismouseclick(WM_LBUTTONDOWN))
	{
	}
	getmouseclick(WM_LBUTTONDOWN, _sci, _sri);
	_sci;
	_sri;
	if (_sci >= 685 && _sci <= 885)
	{
		if (_sri >= 390 && _sri <= 446)
		{
			readimagefile("new game s.JPG", 736, 390, 833, 440);
			loadgame = false;
		}
		if (_sri >= 535 && _sri <= 591)
		{
			readimagefile("loadgames.JPG", 740, 535, 830, 585);
			loadgame = true;
		}
	}
}
void ChessGraphics::blackplayername(string& name, int mw)
{
	int t1 = initwindow(600, 200, " Black Player ", 200, 200);
	setcurrentwindow(t1);
	char a = '\0';
	int z = 0;
	readimagefile("Black player.JPG", 0, 0, 600, 200);
	for (int i = 0, y = 0; a != 13; i++, y += 20,z++)
	{
		while (!kbhit())
		{

		}
		a = getch();
		name.push_back(a);
		settextstyle(BOLD_FONT, HORIZ_DIR, 4);
		bgiout << name[i];
		setbkcolor(MAGENTA);
		outstreamxy(172 + y, 120, bgiout);
	}
	//name.push_back('\0');
	closegraph(t1);
	setcurrentwindow(mw);
}
void ChessGraphics::whiteplayername(string& name, int mw)
{
	int t1 = initwindow(600, 200, " White Player ", 200, 200);
	setcurrentwindow(t1);
	char a = '\0';
	int z = 0;
	readimagefile("Player white.JPG", 0, 0, 600, 200);
	for (int i = 0, y = 0; a != 13; i++, y += 20,z++)
	{
		while (!kbhit())
		{

		}
		a = getch();
		name.push_back(a);
		settextstyle(BOLD_FONT, HORIZ_DIR, 4);
		bgiout << name[i];
		setbkcolor(MAGENTA);
		outstreamxy(172 + y, 120, bgiout);
	}
	//name.push_back('\0');
	closegraph(t1);
	setcurrentwindow(mw);
}
void ChessGraphics::printline(int _sri, int _sci,string& a)
{
	settextstyle(BOLD_FONT, HORIZ_DIR, 2);
	bgiout << a;
	setbkcolor(MAGENTA);
	outstreamxy(_sri, _sci, bgiout);

}