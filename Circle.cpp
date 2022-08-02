#include "Circle.h"


Circle::Circle(string s, Point p, int r) :Shape(s), Center(p), Rad(r)
{
}

void Circle::Draw()
{
	circle(Center.getX(), Center.getY(), this->Rad);
}
Circle::~Circle()
{
}
