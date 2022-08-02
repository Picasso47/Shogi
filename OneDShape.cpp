#include "OneDShape.h"


OneDShape::OneDShape(string n, Point Ps[]) :Shape(n)
{
	P[0] = Ps[0];
	P[1] = Ps[1];
}

void OneDShape::Print()
{
	Shape::Print();
}
void OneDShape::Draw()
{
	Shape::Draw();
}

OneDShape::~OneDShape()
{
}
