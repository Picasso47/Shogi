#pragma once
#include "Piece.h"
class SilverGen :
    public Piece
{
public:
    SilverGen(int _ri, int _ci, Clor _C, Board* _b, char _name);
    bool IsValidMove(Board*,int er, int ec);
    void draw(int _ri,int _ci);
};
