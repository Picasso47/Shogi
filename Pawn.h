#pragma once
#include "Piece.h"
#include<iostream>
using namespace std;
class Pawn :
    public Piece
{
    bool isFirstMove;
public:
    Pawn(int _ri, int _ci, Clor _C, Board* _b, char _name);
    bool IsValidMove(Board*,int er, int ec);
    void draw(int ri,int ci);
};


