#include "Timer.h"
#include<iostream>
#include<iomanip>
Timer::Timer()
{
	this->min = 0;
	this->sec = 0;
}
Timer::Timer(const Timer& T)
{
	this->min = T.min;
	this->sec = T.sec;
	Simplify(this->min, this->sec);
}
const Timer& Timer::operator=(const Timer& T)
{
	this->min = T.min;
	this->sec = T.sec;
	Simplify(this->min, this->sec);
	return *this;
}
Timer::Timer( int m, int s)
{
	Simplify( m, s);
}
void Timer::Simplify(int m, int s)
{
	int carrysec = 0;
	int carrymin = 0;
	if (s >= 60)
	{
		carrysec = s / 60;
		sec = s % 60;
	}
	if (s < 60)
		sec = s;
	if (s < 0)
	{
		sec = 59;
		carrysec = -1;
	}
	min = m + carrysec;
	if (min > 59)
	{
		carrymin = m / 60;
		min = m % 60;
	}
	if (min < 0)
		min = 0;
}


const Timer Timer:: operator ++(int i)
{

	Timer temp = *this;
	this->sec++;
	Simplify(this->min, this->sec);
	temp.Simplify(temp.min, temp.sec);
	return temp;
}
const Timer Timer::operator +(const Timer& T)const
{
	Timer res;
	res.min = this->min + T.min;
	res.sec = this->sec + T.sec;
	res.Simplify(res.min, res.sec);
	return res;
}
const Timer Timer:: operator ++()
{

	Timer temp = *this;
	this->sec++;
	Simplify(this->min, this->sec);
	temp.Simplify(temp.min, temp.sec);
	return *this;
}
const Timer Timer:: operator --(int i)
{

	Timer temp = *this;
	this->sec--;
	Simplify(this->min, this->sec);
	temp.Simplify( temp.min, temp.sec);
	return temp;
}
const Timer Timer:: operator --()
{

	Timer temp = *this;
	this->sec--;
	Simplify(this->min, this->sec);
	temp.Simplify(temp.min, temp.sec);
	return *this;
}
Timer::~Timer()
{
	min = 0;
	sec = 0;
}