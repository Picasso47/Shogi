#include "Board.h"
#include"Pawn.h"
#include"Rook.h"
#include"Knight.h"
#include"Bishop.h"
#include"Lance.h"
#include"King.h"
#include"GoldGen.h"
#include"PromotedRook.h"
#include"SilverGen.h"
#include"PromotedBishop.h"
#include"PromotedSilver.h"
#include"PromotedKnight.h"
#include"PromotedLance.h"
#include"PromotedPawn.h"
#include"ChessGraphics.h"
#include"Cell.h"
#include<fstream>
#include<string>
#include"Timer.h"
#include"Player.h"
Board::Board()
{
	Cs = new Cell * *[BoardDim];
	for (int ri = 0; ri < BoardDim; ri++)
	{
		Cs[ri] = new Cell * [BoardDim];
		for (int ci = 0; ci < BoardDim; ci++)
		{
			switch (ri)
			{
			case 0:
				switch (ci)
				{
				case 0:
					Cs[ri][ci] = new Cell(new Lance(ri, ci, BLCK, this, 'l'));
					break;
				case 1:
					Cs[ri][ci] = new Cell(new Knight(ri, ci, BLCK, this, 'n'));
					break;
				case 2:
					Cs[ri][ci] = new Cell(new SilverGen(ri, ci, BLCK, this, 's'));
					break;
				case 3:
					Cs[ri][ci] = new Cell(new GoldGen(ri, ci, BLCK, this, 'g'));
					break;
				case 4:
					Cs[ri][ci] = new Cell(new King(ri, ci, BLCK, this, 'k'));
					break;
				case 5:
					Cs[ri][ci] = new Cell(new GoldGen(ri, ci, BLCK, this, 'g'));
					break;
				case 6:
					Cs[ri][ci] = new Cell(new SilverGen(ri, ci, BLCK, this, 's'));
					break;
				case 7:
					Cs[ri][ci] = new Cell(new Knight(ri, ci, BLCK, this, 'n'));
					break;
				case 8:
					Cs[ri][ci] = new Cell(new Lance(ri, ci, BLCK, this, 'l'));
					break;
				default:
					Cs[ri][ci] = nullptr;
				}
				break;
			case 1:
				switch (ci)
				{
				case 1:
					Cs[ri][ci] = new  Cell(new Rook(ri, ci, BLCK, this, 'r'));
					break;
				case 7:
					Cs[ri][ci] = new Cell(new Bishop(ri, ci, BLCK, this, 'b'));
					break;
				default:
					Cs[ri][ci] = nullptr;
				}
				break;
			case 2:
				Cs[ri][ci] = new Cell(new Pawn(ri, ci, BLCK, this, 'p'));
				break;
			case 6:
				Cs[ri][ci] = new Cell(new Pawn(ri, ci, WHT, this, 'P'));
				break;
			case 7:
				switch (ci)
				{
				case 1:
					Cs[ri][ci] = new Cell(new Bishop(ri, ci, WHT, this, 'B'));
					break;
				case 7:
					Cs[ri][ci] = new  Cell(new Rook(ri, ci, WHT, this, 'R'));
					break;
				default:
					Cs[ri][ci] = nullptr;
				}
				break;
			case 8:
				switch (ci)
				{
				case 0:
					Cs[ri][ci] = new Cell(new Lance(ri, ci, WHT, this, 'L'));
					break;
				case 1:
					Cs[ri][ci] = new Cell(new Knight(ri, ci, WHT, this, 'N'));
					break;
				case 2:
					Cs[ri][ci] = new Cell(new SilverGen(ri, ci, WHT, this, 'S'));
					break;
				case 3:
					Cs[ri][ci] = new Cell(new GoldGen(ri, ci, WHT, this, 'G'));
					break;
				case 4:
					Cs[ri][ci] = new Cell(new King(ri, ci, WHT, this, 'K'));
					break;
				case 5:
					Cs[ri][ci] = new Cell(new GoldGen(ri, ci, WHT, this, 'G'));
					break;
				case 6:
					Cs[ri][ci] = new Cell(new SilverGen(ri, ci, WHT, this, 'S'));
					break;
				case 7:
					Cs[ri][ci] = new Cell(new Knight(ri, ci, WHT, this, 'N'));
					break;
				case 8:
					Cs[ri][ci] = new Cell(new Lance(ri, ci, WHT, this, 'L'));
					break;
				default:
					Cs[ri][ci] = nullptr;
				}
				break;
			default:
				Cs[ri][ci] = nullptr;
			}
		}
	}
}
Board::Board(int z)
{
	Cs = new Cell * *[capturedBoardSize];
	for (int ri = 0; ri < capturedBoardSize; ri++)
	{
		Cs[ri] = new Cell * [captureboardcolmake];
		for (int ci = 0; ci < captureboardcolmake; ci++)
		{
			Cs[ri][ci] = nullptr;
		}
	}
}
void Board::addcell(char sym)
{
	switch (sym)
	{
	case 'R':
	case'D':
		Cs[0][0] = new  Cell(new Rook(0, 0, BLCK, this, 'r'));
		break;
	case 'r':
	case'd':
		Cs[1][0] = new  Cell(new Rook(1, 0, WHT, this, 'R'));
		break;
	case 'G':
		if (Cs[0][1] == nullptr)
		Cs[0][1] = new Cell(new GoldGen(0, 1, BLCK, this, 'g'));
		else
			Cs[0][2] = new Cell(new GoldGen(0, 1, BLCK, this, 'g'));
		break;
	case 'g':
		if (Cs[1][1] == nullptr)
		Cs[1][1] = new Cell(new GoldGen(1, 1, WHT, this, 'G'));
		else
			Cs[1][2] = new Cell(new GoldGen(1, 1, WHT, this, 'G'));
		break;
	case 'B':
	case'O':
		if (Cs[0][3] == nullptr)
		Cs[0][3] = new Cell(new Bishop(0, 2, BLCK, this, 'b'));
		break;
	case 'b':
	case'o':
		Cs[1][3] = new Cell(new Bishop(1, 2, WHT, this, 'B'));
		break;
	case 'N':
	case'Z':
		if (Cs[0][4] == nullptr)
		Cs[0][4] = new Cell(new Knight(0, 4, BLCK, this, 'n'));
		else
			Cs[0][5] = new Cell(new Knight(0, 4, BLCK, this, 'n'));
		break;
	case 'n':
	case'z':
		if (Cs[1][4] == nullptr)
		Cs[1][4] = new Cell(new Knight(1, 4, WHT, this, 'N'));
		else
			Cs[1][5] = new Cell(new Knight(1, 4, WHT, this, 'N'));
		break;
	case'l':
	case'm':
		if (Cs[1][6] == nullptr)
		Cs[1][6] = new Cell(new Lance(1, 5, WHT, this, 'L'));
		else
			Cs[1][7] = new Cell(new Lance(1, 5, WHT, this, 'L'));
		break;
	case'L':
	case'M':
		if (Cs[0][6] == nullptr)
		Cs[0][6] = new Cell(new Lance(0, 5, BLCK, this, 'l'));
		else
		Cs[0][7] = new Cell(new Lance(0, 5, BLCK, this, 'l'));
		break;
	case'S':
	case'A':
		if (Cs[0][8] == nullptr)
		Cs[0][8] = new Cell(new SilverGen(0, 6, BLCK, this, 's'));
		else
		Cs[0][9] = new Cell(new SilverGen(0, 6, BLCK, this, 's'));
		break;
	case's':
	case'a':
		if (Cs[1][8] == nullptr)
		Cs[1][8] = new Cell(new SilverGen(1, 6, WHT, this, 'S'));
		else
			Cs[1][9] = new Cell(new SilverGen(1, 6, WHT, this, 'S'));
		break;
	case 'P':
	case'V':
		for (int ci = 10; ci < 19; ci++)
		{
			if (Cs[0][ci] == nullptr)
			{
				Cs[0][ci] = new Cell(new Pawn(0, 3, BLCK, this, 'p'));
				break;
			}
		}
		break;
	case 'p':
	case'v':
		for (int ci = 10; ci < 19; ci++)
		{

			if (Cs[1][ci] == nullptr)
			{

				Cs[1][ci] = new Cell(new Pawn(1, 3, WHT, this, 'P'));
				break;
			}
		}
		break;
	}
}
void Board::addcelltocptrbrd(char sym)
{
	switch (sym)
	{
	case 'r':
		Cs[0][0] = new  Cell(new Rook(0, 0, BLCK, this, 'r'));
		break;
	case 'R':
		Cs[1][0] = new  Cell(new Rook(1, 0, WHT, this, 'R'));
		break;
	case 'g':
		if (Cs[0][1] == nullptr)
			Cs[0][1] = new Cell(new GoldGen(0, 1, BLCK, this, 'g'));
		else
			Cs[0][2] = new Cell(new GoldGen(0, 1, BLCK, this, 'g'));
		break;
	case 'G':
		if (Cs[1][1] == nullptr)
			Cs[1][1] = new Cell(new GoldGen(1, 1, WHT, this, 'G'));
		else
			Cs[1][2] = new Cell(new GoldGen(1, 1, WHT, this, 'G'));
		break;
	case 'b':
		if (Cs[0][3] == nullptr)
			Cs[0][3] = new Cell(new Bishop(0, 2, BLCK, this, 'b'));
		break;
	case 'B':
		Cs[1][3] = new Cell(new Bishop(1, 2, WHT, this, 'B'));
		break;
	case 'n':
		if (Cs[0][4] == nullptr)
			Cs[0][4] = new Cell(new Knight(0, 4, BLCK, this, 'n'));
		else
			Cs[0][5] = new Cell(new Knight(0, 4, BLCK, this, 'n'));
		break;
	case 'N':
		if (Cs[1][4] == nullptr)
			Cs[1][4] = new Cell(new Knight(1, 4, WHT, this, 'N'));
		else
			Cs[1][5] = new Cell(new Knight(1, 4, WHT, this, 'N'));
		break;
	case'L':
		if (Cs[1][6] == nullptr)
			Cs[1][6] = new Cell(new Lance(1, 5, WHT, this, 'L'));
		else
			Cs[1][7] = new Cell(new Lance(1, 5, WHT, this, 'L'));
		break;
	case'l':
		if (Cs[0][6] == nullptr)
			Cs[0][6] = new Cell(new Lance(0, 5, BLCK, this, 'l'));
		else
			Cs[0][7] = new Cell(new Lance(0, 5, BLCK, this, 'l'));
		break;
	case's':
		if (Cs[0][8] == nullptr)
			Cs[0][8] = new Cell(new SilverGen(0, 6, BLCK, this, 's'));
		else
			Cs[0][9] = new Cell(new SilverGen(0, 6, BLCK, this, 's'));
		break;
	case'S':
		if (Cs[1][8] == nullptr)
			Cs[1][8] = new Cell(new SilverGen(1, 6, WHT, this, 'S'));
		else
			Cs[1][9] = new Cell(new SilverGen(1, 6, WHT, this, 'S'));
		break;
	case 'p':
		for (int ci = 10; ci < 19; ci++)
		{
			if (Cs[0][ci] == nullptr)
			{
				Cs[0][ci] = new Cell(new Pawn(0, 3, BLCK, this, 'p'));
				break;
			}
		}
		break;
	case 'P':
		for (int ci = 10; ci < 19; ci++)
		{

			if (Cs[1][ci] == nullptr)
			{

				Cs[1][ci] = new Cell(new Pawn(1, 3, WHT, this, 'P'));
				break;
			}
		}
		break;
	}
}
Board::Board(int& pturn,int** ptr,Board* cptrboard,std::string str,Player *sp,Timer* Tb)
{
	ifstream Rdr(str);
	char a;
	Cs = new Cell * *[BoardDim];
	for (int ri = 0; ri < BoardDim; ri++)
	{
		Cs[ri] = new Cell * [BoardDim];
		for (int ci = 0; ci < BoardDim; ci++)
		{
			Rdr >> a;
			switch (a)
			{
			case 'r':
				Cs[ri][ci] = new  Cell(new Rook(ri, ci, BLCK, this, 'r'));
				break;
			case 'R':
				Cs[ri][ci] = new  Cell(new Rook(ri, ci, WHT, this, 'R'));
				break;
			case 'k':
				Cs[ri][ci] = new Cell(new King(ri, ci, BLCK, this, 'k'));
				break;
			case 'K':
				Cs[ri][ci] = new Cell(new King(ri, ci, WHT, this, 'K'));
				break;
			case 'g':
				Cs[ri][ci] = new Cell(new GoldGen(ri, ci, BLCK, this, 'g'));
				break;
			case 'G':
				Cs[ri][ci] = new Cell(new GoldGen(ri, ci, WHT, this, 'G'));
				break;
			case 'b':
				Cs[ri][ci] = new Cell(new Bishop(ri, ci, BLCK, this, 'b'));
				break;
			case 'B':
				Cs[ri][ci] = new Cell(new Bishop(ri, ci, WHT, this, 'B'));
				break;
			case 'p':
				Cs[ri][ci] = new Cell(new Pawn(ri, ci, BLCK, this, 'p'));
				break;
			case 'P':
				Cs[ri][ci] = new Cell(new Pawn(ri, ci, WHT, this, 'P'));
				break;
			case 'n':
				Cs[ri][ci] = new Cell(new Knight(ri, ci, BLCK, this, 'n'));
				break;
			case 'N':
				Cs[ri][ci] = new Cell(new Knight(ri, ci, WHT, this, 'N'));
				break;
			case'L':
				Cs[ri][ci] = new Cell(new Lance(ri, ci, WHT, this, 'L'));
				break;
			case'l':
				Cs[ri][ci] = new Cell(new Lance(ri, ci, BLCK, this, 'l'));
				break;
			case's':
				Cs[ri][ci] = new Cell(new SilverGen(ri, ci, BLCK, this, 's'));
				break;
			case'S':
				Cs[ri][ci] = new Cell(new SilverGen(ri, ci, WHT, this, 'S'));
				break;
			case 'd':
				Cs[ri][ci] = new  Cell(new PromotedRook(ri, ci, BLCK, this, 'd'));
				break;
			case 'D':
				Cs[ri][ci] = new  Cell(new PromotedRook(ri, ci, WHT, this, 'D'));
				break;
			case 'o':
				Cs[ri][ci] = new  Cell(new PromotedBishop(ri, ci, BLCK, this, 'o'));
				break;
			case 'O':
				Cs[ri][ci] = new  Cell(new PromotedBishop(ri, ci, WHT, this, 'O'));
				break;
			case'a':
				Cs[ri][ci] = new Cell(new PromotedSilver(ri, ci, BLCK, this, 'a'));
				break;
			case'A':
				Cs[ri][ci] = new Cell(new PromotedSilver(ri, ci, WHT, this, 'A'));
				break;
			case'z':
				Cs[ri][ci] = new Cell(new PromotedKnight(ri, ci, BLCK, this, 'z'));
				break;
			case'Z':
				Cs[ri][ci] = new Cell(new PromotedKnight(ri, ci, WHT, this, 'Z'));
				break;
			case'm':
				Cs[ri][ci] = new Cell(new PromotedLance(ri, ci, BLCK, this, 'm'));
				break;
			case'M':
				Cs[ri][ci] = new Cell(new PromotedLance(ri, ci, WHT, this, 'M'));
				break;
			case'v':
				Cs[ri][ci] = new Cell(new PromotedPawn(ri, ci, BLCK, this, 'v'));
				break;
			case'V':
				Cs[ri][ci] = new Cell(new PromotedPawn(ri, ci, WHT, this, 'V'));
				break;
			default:
				Cs[ri][ci] = nullptr;
				break;
			}
		}
	}
	int b = 0;
	for (int ri = 0; ri < capturedBoardSize; ri++)
	{
		for (int ci = 0; ci < CapturedBoardcolDim; ci++)
		{
			Rdr >> b;
		    ptr[ri][ci]=b;
		}
	}
	for (int ri = 0; ri < capturedBoardSize; ri++)
	{
		for (int ci = 0; ci < captureboardcolmake; ci++)
		{
			Rdr >> a;
			cptrboard->addcelltocptrbrd(a);
		}
	}
	std::string u;
 	for (int i = 0; i < capturedBoardSize; i++)
	{
		Rdr >> u;
		sp[i].providename(u);
		Rdr >> b;
		sp[i].providepoints(b);
		if (i == 0)
		{
			Rdr >> b;
			sp[i].providecolr(b);
		}
		if (i == 1)
		{
			Rdr >> b;
			sp[i].providecolr(b);
		}
	}
	Rdr >> pturn;
	for (int i = 0; i < capturedBoardSize; i++)
	{
		Rdr >> Tb[i];
	}
	Rdr.close();
}
void Board::addcell_(char sym,int** ptr)
{
	int type = 0, index = 0;
	switch (sym)
	{
	case 'R':
		type = 0, index = 0;
		ptr[type][index] += 1;
		break;
	case 'r':
		type = 1; index = 0;
		ptr[type][index] += 1;
		break;
	case 'G':
		type = 0, index = 1;
		ptr[type][index] += 1;
		break;
	case 'g':
		type = 1; index = 1;
		ptr[type][index] += 1;
		break;
	case 'B':
		type = 0, index = 2;
		ptr[type][index] += 1;
		break;
	case 'b':
		type = 1; index = 2;
		ptr[type][index] += 1;
		break;
	case 'N':
		type = 0, index = 3;
		ptr[type][index] += 1;
		break;
	case 'n':
		type = 1; index = 3;
		ptr[type][index] += 1;
		break;
	case'l':
		type = 1; index = 4;
		ptr[type][index] += 1;
		break;
	case'L':
		type = 0, index = 4;
		ptr[type][index] += 1;
		break;
	case'S':
		type = 0, index = 5;
		ptr[type][index] += 1;
		break;
	case's':
		type = 1; index = 5;
		ptr[type][index] += 1;
		break;
	case 'P':
		type = 0, index = 6;
		ptr[type][index] += 1;
		break;
	case 'p':
		type = 1; index = 6;
		ptr[type][index] += 1;
		break;
	}
}
void Board::addnewcelltoorgboard(char a, int ri, int ci)
{
	switch (a)
	{
	case 'r':
		Cs[ri][ci] = new  Cell(new Rook(ri, ci, BLCK, this, 'r'));
		break;
	case 'R':
		Cs[ri][ci] = new  Cell(new Rook(ri, ci, WHT, this, 'R'));
		break;
	case 'k':
		Cs[ri][ci] = new Cell(new King(ri, ci, BLCK, this, 'k'));
		break;
	case 'K':
		Cs[ri][ci] = new Cell(new King(ri, ci, WHT, this, 'K'));
		break;
	case 'g':
		Cs[ri][ci] = new Cell(new GoldGen(ri, ci, BLCK, this, 'g'));
		break;
	case 'G':
		Cs[ri][ci] = new Cell(new GoldGen(ri, ci, WHT, this, 'G'));
		break;
	case 'b':
		Cs[ri][ci] = new Cell(new Bishop(ri, ci, BLCK, this, 'b'));
		break;
	case 'B':
		Cs[ri][ci] = new Cell(new Bishop(ri, ci, WHT, this, 'B'));
		break;
	case 'p':
		Cs[ri][ci] = new Cell(new Pawn(ri, ci, BLCK, this, 'p'));
		break;
	case 'P':
		Cs[ri][ci] = new Cell(new Pawn(ri, ci, WHT, this, 'P'));
		break;
	case 'n':
		Cs[ri][ci] = new Cell(new Knight(ri, ci, BLCK, this, 'n'));
		break;
	case 'N':
		Cs[ri][ci] = new Cell(new Knight(ri, ci, WHT, this, 'N'));
		break;
	case'L':
		Cs[ri][ci] = new Cell(new Lance(ri, ci, WHT, this, 'L'));
		break;
	case'l':
		Cs[ri][ci] = new Cell(new Lance(ri, ci, BLCK, this, 'l'));
		break;
	case's':
		Cs[ri][ci] = new Cell(new SilverGen(ri, ci, BLCK, this, 's'));
		break;
	case'S':
		Cs[ri][ci] = new Cell(new SilverGen(ri, ci, WHT, this, 'S'));
		break;
	default:
		Cs[ri][ci] = nullptr;
		break;
	}
}
void Board::promotion(int _sri, int _sci, int _pturn)
{
	char sym;
	bool allowpromotion = true;
	int t1 = 0;
	sym = Cs[_sri][_sci]->givepieceatcell()->givepiecename();
	if ((_sri >= 6 && _sri <= 8) && (_sci >= 0 && _sci <= 8) && _pturn == 1 && sym!='k' && sym != 'd' && sym != 'o' && sym != 'a' && sym != 'm' && sym != 'z' && sym != 'v')
	{
		t1 = initwindow(600, 200, "PROMOTION", 200, 200);
		setcurrentwindow(t1);
		GFXB->promotiondisplay(allowpromotion);
		if (allowpromotion)
		{
			switch (sym)
			{
			case 'r':
				Cs[_sri][_sci] = new Cell(new PromotedRook(_sri, _sci, BLCK, this, 'd'));
				break;
			case 'b':
				Cs[_sri][_sci] = new Cell(new PromotedBishop(_sri, _sci, BLCK, this, 'o'));
				break;
			case's':
				Cs[_sri][_sci] = new Cell(new PromotedSilver(_sri, _sci, BLCK, this, 'a'));
				break;
			case'n':
				Cs[_sri][_sci] = new Cell(new PromotedKnight(_sri, _sci, BLCK, this, 'z'));
				break;
			case'l':
				Cs[_sri][_sci] = new Cell(new PromotedLance(_sri, _sci, BLCK, this, 'm'));
				break;
			case'p':
				Cs[_sri][_sci] = new Cell(new PromotedPawn(_sri, _sci, BLCK, this, 'v'));
				break;
			default:
				break;
			}
		}
		closegraph(t1);
	}
	if ((_sri >= 0 && _sri <= 2) && (_sci >= 0 && _sci <= 8) && _pturn == 0 && sym!='K' && sym != 'D' && sym != 'O' && sym != 'A' && sym != 'M' && sym != 'Z' && sym != 'V')
	{
		t1 = initwindow(600, 200, "PROMOTION", 200, 200);
		setcurrentwindow(t1);
		GFXB->promotiondisplay(allowpromotion);
		if (allowpromotion)
		{
			switch (sym)
			{
			case 'R':
				Cs[_sri][_sci] = new Cell(new PromotedRook(_sri, _sci, WHT, this, 'D'));
				break;
			case 'B':
				Cs[_sri][_sci] = new Cell(new PromotedBishop(_sri, _sci, WHT, this, 'O'));
				break;
			case'S':
				Cs[_sri][_sci] = new Cell(new PromotedSilver(_sri, _sci, WHT, this, 'A'));
				break;
			case'N':
				Cs[_sri][_sci] = new Cell(new PromotedKnight(_sri, _sci, WHT, this, 'Z'));
				break;
			case'L':
				Cs[_sri][_sci] = new Cell(new PromotedLance(_sri, _sci, WHT, this, 'M'));
				break;
			case'P':
				Cs[_sri][_sci] = new Cell(new PromotedPawn(_sri, _sci, WHT, this, 'V'));
				break;
			default:
				break;
			}
		}
		closegraph(t1);
	}
}
Board::Board(Board* orgptr)
{
	Cs = new Cell * *[BoardDim];
	for (int ri = 0; ri < BoardDim; ri++)
	{
		Cs[ri] = new Cell * [BoardDim];
		for (int ci = 0; ci < BoardDim; ci++)
		{
			char a = orgptr->givecellatr_c(ri, ci)->givepieceatcell()->givepiecename();
			switch (a)
			{
			case 'r':
				Cs[ri][ci] = new  Cell(new Rook(ri, ci, BLCK, this, 'r'));
				break;
			case 'R':
				Cs[ri][ci] = new  Cell(new Rook(ri, ci, WHT, this, 'R'));
				break;
			case 'k':
				Cs[ri][ci] = new Cell(new King(ri, ci, BLCK, this, 'k'));
				break;
			case 'K':
				Cs[ri][ci] = new Cell(new King(ri, ci, WHT, this, 'K'));
				break;
			case 'g':
				Cs[ri][ci] = new Cell(new GoldGen(ri, ci, BLCK, this, 'g'));
				break;
			case 'G':
				Cs[ri][ci] = new Cell(new GoldGen(ri, ci, WHT, this, 'G'));
				break;
			case 'b':
				Cs[ri][ci] = new Cell(new Bishop(ri, ci, BLCK, this, 'b'));
				break;
			case 'B':
				Cs[ri][ci] = new Cell(new Bishop(ri, ci, WHT, this, 'B'));
				break;
			case 'p':
				Cs[ri][ci] = new Cell(new Pawn(ri, ci, BLCK, this, 'p'));
				break;
			case 'P':
				Cs[ri][ci] = new Cell(new Pawn(ri, ci, WHT, this, 'P'));
				break;
			case 'n':
				Cs[ri][ci] = new Cell(new Knight(ri, ci, BLCK, this, 'n'));
				break;
			case 'N':
				Cs[ri][ci] = new Cell(new Knight(ri, ci, WHT, this, 'N'));
				break;
			case'L':
				Cs[ri][ci] = new Cell(new Lance(ri, ci, WHT, this, 'L'));
				break;
			case'l':
				Cs[ri][ci] = new Cell(new Lance(ri, ci, BLCK, this, 'l'));
				break;
			case's':
				Cs[ri][ci] = new Cell(new SilverGen(ri, ci, BLCK, this, 's'));
				break;
			case'S':
				Cs[ri][ci] = new Cell(new SilverGen(ri, ci, WHT, this, 'S'));
				break;
			case 'd':
				Cs[ri][ci] = new  Cell(new PromotedRook(ri, ci, BLCK, this, 'd'));
				break;
			case 'D':
				Cs[ri][ci] = new  Cell(new PromotedRook(ri, ci, WHT, this, 'D'));
				break;
			case 'o':
				Cs[ri][ci] = new  Cell(new PromotedBishop(ri, ci, BLCK, this, 'o'));
				break;
			case 'O':
				Cs[ri][ci] = new  Cell(new PromotedBishop(ri, ci, WHT, this, 'o'));
				break;
			case'a':
				Cs[ri][ci] = new Cell(new PromotedSilver(ri, ci, BLCK, this, 'a'));
				break;
			case'A':
				Cs[ri][ci] = new Cell(new PromotedSilver(ri, ci, WHT, this, 'A'));
				break;
			case'z':
				Cs[ri][ci] = new Cell(new PromotedKnight(ri, ci, BLCK, this, 'z'));
				break;
			case'Z':
				Cs[ri][ci] = new Cell(new PromotedKnight(ri, ci, WHT, this, 'Z'));
				break;
			case'm':
				Cs[ri][ci] = new Cell(new PromotedLance(ri, ci, BLCK, this, 'm'));
				break;
			case'M':
				Cs[ri][ci] = new Cell(new PromotedLance(ri, ci, WHT, this, 'M'));
				break;
			case'v':
				Cs[ri][ci] = new Cell(new PromotedPawn(ri, ci, BLCK, this, 'v'));
				break;
			case'V':
				Cs[ri][ci] = new Cell(new PromotedPawn(ri, ci, WHT, this, 'V'));
				break;
			default:
				Cs[ri][ci] = nullptr;
				break;
			}
		}
	}
}
void Board::DisplayBoard()
{
	for (int ri = 0; ri < BoardDim; ri++)
	{
		for (int ci = 0; ci < BoardDim; ci++)
		{
			if (Cs[ri][ci] == nullptr)
			{
				bgiout << "-";
				outstreamxy(ri, ci, bgiout);
			}
			else
				Cs[ri][ci]->drawpiece();
		}
		cout << endl;
	}
}

Clor Board::givecolor_cell(int& _sri, int& _sci)
{
	return Cs[_sri][_sci]->cellpiececlor();
}
void Board::b_move(int& _sri, int& _sci, int& _dri, int& _dci)
{
	Cs[_dri][_dci] = Cs[_sri][_sci];
	Cs[_sri][_sci]->cellmove(_sri, _sci, _dri, _dci);
	Cs[_sri][_sci] = nullptr;
}
Cell* Board::givecellatr_c(int _sri, int _sci)
{
	return Cs[_sri][_sci];
}
void Board::removecellatr_c(int _sri, int _sci)
{
	Cs[_sri][_sci] = nullptr;
}
void Board::addcellatr_c(int _Sri, int _sci,char sym)
{
	switch (sym)
	{
	case 'r':
		Cs[_Sri][_sci] = new  Cell(new Rook(_Sri, _sci, BLCK, this, 'r'));
		break;
	case 'R':
		Cs[_Sri][_sci] = new  Cell(new Rook(_Sri, _sci, WHT, this, 'R'));
		break;
	case 'k':
		Cs[_Sri][_sci] = new Cell(new King(_Sri, _sci, BLCK, this, 'k'));
		break;
	case 'K':
		Cs[_Sri][_sci] = new Cell(new King(_Sri, _sci, WHT, this, 'K'));
		break;
	case 'g':
		Cs[_Sri][_sci] = new Cell(new GoldGen(_Sri, _sci, BLCK, this, 'g'));
		break;
	case 'G':
		Cs[_Sri][_sci] = new Cell(new GoldGen(_Sri, _sci, WHT, this, 'G'));
		break;
	case 'b':
		Cs[_Sri][_sci] = new Cell(new Bishop(_Sri, _sci, BLCK, this, 'b'));
		break;
	case 'B':
		Cs[_Sri][_sci] = new Cell(new Bishop(_Sri, _sci, WHT, this, 'B'));
		break;
	case 'p':
		Cs[_Sri][_sci] = new Cell(new Pawn(_Sri, _sci, BLCK, this, 'p'));
		break;
	case 'P':
		Cs[_Sri][_sci] = new Cell(new Pawn(_Sri, _sci, WHT, this, 'P'));
		break;
	case 'n':
		Cs[_Sri][_sci] = new Cell(new Knight(_Sri, _sci, BLCK, this, 'n'));
		break;
	case 'N':
		Cs[_Sri][_sci] = new Cell(new Knight(_Sri, _sci, WHT, this, 'N'));
		break;
	case'L':
		Cs[_Sri][_sci] = new Cell(new Lance(_Sri, _sci, WHT, this, 'L'));
		break;
	case'l':
		Cs[_Sri][_sci] = new Cell(new Lance(_Sri, _sci, BLCK, this, 'l'));
		break;
	case's':
		Cs[_Sri][_sci] = new Cell(new SilverGen(_Sri, _sci, BLCK, this, 's'));
		break;
	case'S':
		Cs[_Sri][_sci] = new Cell(new SilverGen(_Sri, _sci, WHT, this, 'S'));
		break;
	case 'd':
		Cs[_Sri][_sci] = new  Cell(new PromotedRook(_Sri, _sci, BLCK, this, 'd'));
		break;
	case 'D':
		Cs[_Sri][_sci] = new  Cell(new PromotedRook(_Sri, _sci, WHT, this, 'D'));
		break;
	case 'o':
		Cs[_Sri][_sci] = new  Cell(new PromotedBishop(_Sri, _sci, BLCK, this, 'o'));
		break;
	case 'O':
		Cs[_Sri][_sci] = new  Cell(new PromotedBishop(_Sri, _sci, WHT, this, 'o'));
		break;
	case'a':
		Cs[_Sri][_sci] = new Cell(new PromotedSilver(_Sri, _sci, BLCK, this, 'a'));
		break;
	case'A':
		Cs[_Sri][_sci] = new Cell(new PromotedSilver(_Sri, _sci, WHT, this, 'A'));
		break;
	case'z':
		Cs[_Sri][_sci] = new Cell(new PromotedKnight(_Sri, _sci, BLCK, this, 'z'));
		break;
	case'Z':
		Cs[_Sri][_sci] = new Cell(new PromotedKnight(_Sri, _sci, WHT, this, 'Z'));
		break;
	case'm':
		Cs[_Sri][_sci] = new Cell(new PromotedLance(_Sri, _sci, BLCK, this, 'm'));
		break;
	case'M':
		Cs[_Sri][_sci] = new Cell(new PromotedLance(_Sri, _sci, WHT, this, 'M'));
		break;
	case'v':
		Cs[_Sri][_sci] = new Cell(new PromotedPawn(_Sri, _sci, BLCK, this, 'v'));
		break;
	case'V':
		Cs[_Sri][_sci] = new Cell(new PromotedPawn(_Sri, _sci, WHT, this, 'V'));
		break;
	default:
		Cs[_Sri][_sci] = nullptr;
		break;
	}
}
Board::~Board()
{
	 
	for (int ri = 0; ri < capturedBoardSize; ri++)
	{
		for (int ci = 0; ci < captureboardcolmake; ci++)
		{
			delete Cs[ri][ci];
		}
		delete [ri] Cs;
	}
	delete[] Cs;
}

