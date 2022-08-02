#pragma once
#include"Piece.h"
#include "King.h"
#include"Bishop.h"
class king;

class PromotedBishop :
    public King,public Bishop
{
public:
    PromotedBishop(int _ri, int _ci, Clor _C, Board* _b, char _name);
    bool IsValidMove(Board*, int er, int ec);
    void draw(int _ri, int _ci);
};

