#pragma once
#include"Header.h"
#include"Piece.h"
class Piece;
class Cell
{
protected:
    Piece* Ps;
public:
    Cell();
    Cell(Piece* Ps);
    Cell getpiecepointer(int _ri, int _ci);
    void drawpiece();
    Clor cellpiececlor();
    void cellmove(int _sri, int _sci, int _dri, int _dci);
    Piece* givepieceatcell();
    ~Cell();
};

