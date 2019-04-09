#pragma once
#include <iostream>
#include "Head.h"
using namespace std;

Vector::Vector()
{
	n = 0;
	x = NULL;
}
Vector::Vector(int nn)
{
	n = nn;
	x = new double[nn];
}
Vector::Vector(const Vector& z)
{
	n = z.n;
	x = new double[z.n];
	for(int i = 0; i < z.n; i++)
		x[i] = z.x[i];
}
Vector::~Vector()
{
	delete[]x;
	n = 0;
}
Vector& Vector:: Fill()
{
	cout << "Enter vector coordinates" << endl;
	for (int i = 0; i < n; i++)
		cin >> x[i];
	return (*this);
}
void Vector:: Out()
{
	cout << "Vector coordinates is" << endl;
	for (int i = 0; i < n; i++)
		cout << x[i];
	cout << endl;
}
Vector Vector::operator+ (const Vector& z) const
{
	if(z.n != n)
		throw "Error";
	Vector res(z);
	for (int i = 0; i < n; i++)
		res.x[i] += x[i];
	return res;
}
Vector Vector::operator- (const Vector& z) const
{
	if(z.n != n)
		throw "Error";
	Vector res(z);
	for (int i = 0; i < n; i++)
		res.x[i] -= x[i];
	return res;
}
double Vector::operator* (const Vector& z) const
{
	if(z.n != n)
		throw "Error";
	double S = 0;
	for(int i = 0; i < n; i++)
		S += x[i] * z.x[i];
	return S;
}
Vector Vector::operator+ (double a) const
{
	Vector res(*this);
	for (int i = 0; i < n; i++)
		res.x[i] += a;
	return res;
}
Vector Vector::operator- (double a) const
{
	Vector res(*this);
	for (int i = 0; i < n; i++)
		res.x[i] -= a;
	return res;
}
Vector Vector::operator* (double a) const
{
	Vector res(*this);
	for (int i = 0; i < n; i++)
		res.x[i] *= a;
	return res;
}
Vector& Vector::operator= (const Vector& z) 
{
	if (*this == z)
	{
		return*this; 
	}
	delete[] x;
	n = z.n;
	x = new double[z.n];
	for(int i = 0; i < z.n; i++)
		x[i] = z.x[i];
	return *this;
}
double* Vector::operator[] (int ind) const
{
	if ((ind < 0) || (ind >= n))
		throw "Error";
	return &(x[ind]);
}
double Vector::Length()
{
	double S = 0, res;
	for (int i = 0; i < n; i++)
		S += x[i] * x[i];
	res = sqrt(S);
	return res;
}
Vector& Vector::operator+= (const Vector& z)
{
	if(z.n != n)
		throw "Error";
	for (int i = 0; i < n; i++)
		x[i] += z.x[i];
	return *this;
}
Vector& Vector::operator-= (const Vector& z)
{
	if(z.n != n)
		throw "Error";
	for (int i = 0; i < n; i++)
		x[i] -= z.x[i];
	return *this;
}
Vector& Vector::operator+= (double a)
{
	for (int i = 0; i < n; i++)
		x[i] += a;
	return *this;
}
Vector& Vector::operator-= (double a)
{
	for (int i = 0; i < n; i++)
		x[i] -= a;
	return *this;
}
Vector& Vector::operator*= (double a)
{
	for (int i = 0; i < n; i++)
		x[i] *= a;
	return *this;
}
void  *Vector::operator new(size_t size)
{
	void* p = new Vector[size];
	cout << "Allocated " << size << " bytes" << endl;
	return p;
}
void Vector::operator delete(void *x)
{
	delete[]x;
}
bool Vector::operator==(const Vector& z)
{
	if (n != z.n) return false;
	int f = 0;
	for (int i = 0; i < n; i++)
	{
		if (x[i] != z.x[i]) f = 1;
	}
	if (f == 1) return false;
	return true;
}