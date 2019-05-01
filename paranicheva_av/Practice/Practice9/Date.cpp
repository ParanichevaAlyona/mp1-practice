#include <iostream>
#include "Date.h"
using namespace std;

Date::Date()
{
	d = 0;
	m = 0;
	y = 0;
}
Date::Date(int _d, int _m, int _y)
{	
	y = Sety(_y);
	m = Setm(_m);
	d = Setd(_d, _m, _y);
}
Date::~Date()
{
	d = 0;
	m = 0;
	y = 0;
}
bool Date::Leapy(int _y)
{
	if (_y % 4 == 0)
	{ 
		if (_y % 100 == 0)
		{
			if (_y % 400 ==0)
				return true;
			return false;
		}
		return true;
	}
	return false;
}
int Date::Setd(int _d, int _m, int _y)
{
	int k[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (_m == 2)
		if (Leapy(_y))
			k[1] = 29;
	if ((_d >= 1) && (_d <= k[_m - 1]))
	d = _d;
	else throw "The day is incorrect";
	return _d;
}
int Date::Setm(int _m)
{
	if ((_m >= 1) && (_m <= 12))
		m = _m;
	else throw "The month is incorrect";
	return _m;
}
int Date::Sety(int _y)
{
	if ((_y >= 1900) && (_y <= 2100))
	y = _y;
	else throw "The year is incorrect"; 
	return _y;
}
int Date::Getd()
{
	return d;
}
int Date::Getm()
{
	return m;
}
int Date::Gety()
{
	return y;
}
void Date::Print()
{
	cout << d << "/" << m << "/" << y << endl;
}
bool Date::operator==(const Date& tmp)
{
	if ((d == tmp.d) && (m == tmp.m) && (y == tmp.y))
		return true;
	return false;
}
Date& Date::operator=(const Date date)
{
	d = date.d;
	m = date.m;
	y = date.y;
	return *this;
}