#include "Segment.h"


Segment::Segment(string n, Point Ps[]) :OneDShape(n, Ps)
{
}

void Segment::Print()
{
	// _______
}

void Segment::Draw()
{
	line(this->P[0].getX(), this->P[0].getY(), this->P[1].getX(), this->P[1].getY());
}


Segment::~Segment()
{
}
