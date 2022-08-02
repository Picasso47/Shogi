#include "Shape.h"


Shape::Shape(string n) :name(n)
{
}
void Shape::Print()
{
	cout << this->name << endl;
}
void Shape::Draw()
{
	// Does nothing....
}

Shape::~Shape()
{
}
