#pragma once
#include "GoldGen.h"
class PromotedLance :
    public GoldGen
{
public:
    PromotedLance(int _ri, int _ci, Clor _C, Board* _b, char _name);
    bool IsValidMove(Board*, int er, int ec);
    void draw(int _ri, int _ci);
};

