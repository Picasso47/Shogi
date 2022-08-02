#pragma once
#include<iostream>
#include<iomanip>
#include<ostream>
#include<fstream>
#include"Header.h"
using namespace std;

class Timer
{
private:
	int min;
	int sec;
public:
	Timer();
	Timer(const Timer&);
	Timer(int, int);
	void Simplify(int, int);
	const Timer& operator=(const Timer& T);
	const Timer operator ++(int i);
	const Timer operator +(const Timer&)const;
	const Timer operator -(const Timer&)const;
	const Timer operator ++();
	const Timer operator --(int i);
	const Timer operator --();
	~Timer();
	friend ostream& operator<<(ostream& bgiout, const Timer& T)
	{
		bgiout << setfill('0') << setw(2) << T.min << ":";
		bgiout << setfill('0') << setw(2) << T.sec;
		bgiout << endl;
		return bgiout;
	}
	friend ifstream& operator>>(ifstream& Rdr, Timer& T)
	{
		Rdr.ignore();
		Rdr >> T.min;
		Rdr.ignore();
		Rdr >> T.sec;
		T.Simplify(T.min, T.sec);
		return Rdr;
	}
};