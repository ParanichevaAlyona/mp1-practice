#include <iostream>
#include "Time.h"
using namespace std;

Time::Time()
{
	min = 0;
	h = 0;
}
Time::Time(int _min, int _h)
{
	h = Seth(_h);
	min = Setmin(_min);
}
Time::~Time()
{
	min = 0;
	h = 0;
}
int Time::Setmin(int _min)
{
	if ((_min >= 1) && (_min <= 60))
		min = _min;
	else throw "Error";
	return _min;
}
int Time::Seth(int _h)
{
	if ((_h >= 1) && (_h <= 24))
		h = _h;
	else throw "Error";
	return _h;
}
int Time::Getmin()
{
	return min;
}
int Time::Geth()
{
	return h;
}
void Time::Print()
{
	cout << h << ":" << min << endl;
}
Time& Time::operator=(const Time time)
{
	h = time.h;
	min = time.min;
	return *this;
}