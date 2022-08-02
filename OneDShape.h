#pragma once
#include "Shape.h"
#include "Point.h"
class OneDShape : public Shape
{
protected:
	Point P[2];
public:
	OneDShape(string n, Point Ps[]);
	void Print();
	void Draw();
	~OneDShape();
};

