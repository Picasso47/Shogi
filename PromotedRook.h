#pragma once
#include"Piece.h"
#include"King.h"
#include"Bishop.h"
#include"Rook.h"
class King;
class Rook;
class Bishop;
class PromotedRook :
    public King,public Bishop,public Rook
{
public:
    PromotedRook(int _ri, int _ci, Clor _C, Board* _b, char _name);
    bool IsValidMove(Board*, int er, int ec);
    void draw(int _ri, int _ci);
};

