#pragma once
#include "Shape.h"
#include "Point.h"

class Circle :public Shape
{
	Point Center;
	int Rad;

public:
	Circle(string s, Point p, int r);
	void Draw();
	~Circle();
};

