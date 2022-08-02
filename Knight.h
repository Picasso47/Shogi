#pragma once
#include "Piece.h"
class Knight :
    public Piece
{
public:
    Knight(int _ri, int _ci, Clor _C, Board* _b, char _name);
    bool IsValidMove(Board*, int er, int ec);;
    void draw(int _ri, int _ci);
};

