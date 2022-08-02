#pragma once
#include "Piece.h"
class GoldGen :
    public Piece
{
public:
    GoldGen(int _ri, int _ci, Clor _C, Board* _b, char _name);
    bool IsValidMove(Board* bptr,int er, int ec);
    void draw(int _ri, int _ci);
};

