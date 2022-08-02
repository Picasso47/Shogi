#pragma once
#include "OneDShape.h"

class Segment :public OneDShape
{
public:
	Segment(string n, Point Ps[]);

	void Print();
	void Draw();

	~Segment();
};

