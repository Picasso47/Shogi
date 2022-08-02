#pragma once
#include "Shape.h"
class Point : public Shape
{
protected :
	int x, y;
public:
	Point(){}
	Point(string n, int a, int b);
	void setX(int a){ this->x = a; }
	void setY(int a){ this->y = a; }
	int getX(){ return x; }
	int getY(){ return y; }
	void Print();
	void Draw();

	~Point();
};

