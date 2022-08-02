#pragma once
#include"Piece.h"
#include "Rook.h"
#include "Bishop.h"
class King :
   virtual public Piece
{
public:
    King(int _ri, int _ci, Clor _C, Board* _b, char _name);
    bool IsValidMove(Board*, int er, int ec);
    void draw(int _ri, int _ci);
};



