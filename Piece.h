#pragma once
#include"Header.h"
#include"Board.h"
using namespace std;
class Board;
class Piece
{
protected:
	int ri;
	int ci;
	Clor C;
	Board* b;
	char name;
	bool IsHorizontal(int sr, int sc, int er, int ec)
	{
		return sr == er;
	}
	bool IsVertical(int sr, int sc, int er, int ec)
	{
		return sc == ec;
	}
	bool IsDiagonal(int sr, int sc, int er, int ec)
	{
		int dc = abs(ec - sc);
		int dr = abs(er - sr);
		return dc == dr;
	}
	bool Ishorizontalclear(Board* bptr,int _sri, int _sci, int _dri, int _dci)
	{
		int cs = 0, ce = 0;
		if (_dci > _sci) { cs = _sci + 1; ce = _dci - 1; }
		if (_dci < _sci) { cs = _dci + 1; ce = _sci - 1; }
		for (int c = cs; c <= ce; c++)
		{
			if (bptr->givecellatr_c(_sri, c) != NULL)
			{
				return false;
			}
		}
		return true;
	}
	bool Isverticalclear(Board* bptr,int _sri, int _sci, int _dri, int _dci)
	{
		int strtr = 0, endr = 0;
		if (_dri > _sri) { strtr = _sri + 1; endr = _dri - 1; }
		if (_dri < _sri) { strtr = _dri + 1; endr = _sri - 1; }
		for (int c = strtr; c <= endr; c++)
		{
			if (bptr->givecellatr_c(c, _sci) != NULL)
			{
				return false;
			}
		}
		return true;
	}
	bool Isdiagonalclear(Board* bptr,int _sri, int _sci, int _dri, int _dci)
	{
		int dif = abs(_dri - _sri);
		int sr = 0, sc = 0;
		if ((_dci > _sci) && (_dri > _sri))
		{
			sr = _sri; sc = _sci;
		}
		if ((_dci < _sci) && (_dri < _sri))
		{
			sr = _dri; sc = _dci;
		}
		if ((_dci > _sci && _dri < _sri))
		{
			sr = _dri; sc = _dci;
		}
		if ((_dci < _sci) && (_dri > _sri))
		{
			sr = _sri; sc = _sci;
		}

		if (_dci > _sci && _dri > _sri || _dci < _sci && _dri < _sri)
		{
			for (int i = 1; i < dif; i++)
			{
				if (bptr->givecellatr_c(sr + i, sc + i) != NULL)
				{
					return false;
				}
			}
			return true;
		}
		if (_dci > _sci && _dri < _sri || _dci < _sci && _dri > _sri)
		{
			for (int i = 1; i < dif; i++)
			{
				if (bptr->givecellatr_c(sr + i, sc - i) != NULL)
				{
					return false;
				}
			}
			return true;

		}

	} 
public:
	Piece(int m_ri, int m_ci, Clor m_C, Board* _b, char _name);
	virtual  bool IsValidMove(Board*, int er, int ec) = 0;
	virtual void draw(int ri,int ci) = 0;
	void move(int sci, int sri, int dci, int dri);
	char givepiecename();
	Clor givecolour();
	virtual ~Piece();
};