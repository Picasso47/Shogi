#include "Point.h"


Point::Point(string n, int a, int b) :Shape(n)
{
	this->x = a, this->y = b;
}
void Point::Print()
{
	Shape::Print();
	cout << "(" << this->x << "," << this->y << ")" << endl; 
}
void Point::Draw()
{
	putpixel(this->x, this->y, YELLOW);
}

Point::~Point()
{
}
