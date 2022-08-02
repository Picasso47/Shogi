#pragma once
#include "Piece.h"
class Bishop :
    virtual public Piece
{
public:
    Bishop(int _ri, int _ci, Clor _C, Board* _b, char _name);
    bool IsValidMove(Board*, int er, int ec);
    void draw(int _ri, int _ci);
};


