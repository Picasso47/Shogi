#pragma once

#include "Chess.h"

class Board;
class ChessGraphics :
    public Chess
{
    bool savecursor;
    bool loadcursor;
public:
    ChessGraphics();
    void backgroundprint();
    void printBorder(int r, int c);
    void printPiece(int r, int c, Board* b);
    void printBoard(Board* b);
    void onlypiecesdraw(Board* b);
    void capturedpiecedraw(Board*b,int**);
    void drophighlight(Board* b);
    void dropunhighlight(Board* b);
    void printBox(int r, int c);
    void printselectstatus();
    void printdeststatus();
    void printdropstatus();
    void cusrsorsave();
    void noncursosave();
    void cursorload();
    void noncursorload();
    void buttoncall();
    void undonormal();
    void undoclick();
    void impassdisplay();
    void promotiondisplay(bool&);
    void gameenddisplay();
    void newgaemdisplay(bool&);
    void whiteplayername(string&,int);
    void blackplayername(string&,int);
    void printline(int, int,string&);
    void ChessGraphics::printredBorder(int r, int c);
};

