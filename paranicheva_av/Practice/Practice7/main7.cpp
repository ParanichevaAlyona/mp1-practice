#pragma once
#include <iostream>
#include "Head.h"
using namespace std;

void main()
{
	int nn1, nn2;
	cout << "Enter size of the vector a" << endl;
	cin >> nn1;
	cout << "Enter size of the vector b" << endl;
	cin >> nn2;
	Vector a(nn1), b(nn2), c;

	a.Fill();
	a.Out();
	b.Fill();
	b.Out();
	int k, i;
	do
	{
		double num;
		cout << "1) a + b   2) a - b   3) a * b \n4) c = a   5) a[i]   6) Length" << endl;
		cout << "7) a += num  8) a -= num  9) a *= num \n" << endl;
		cin >> k;
		switch(k)
		{
			case 1:
				try
				{
					c = a + b;
					c.Out();
				}
				catch(const char* s)
				{
					cout << s << endl;
				}
				break;
			case 2:
				try
				{
					c = a - b;
					c.Out();
				}
				catch(const char* s)
				{
					cout << s << endl;
				}
				break;
			case 3:
				try
				{
					double S;
					S = a * b; 
					cout << "Scalar product is " << S << endl;
				}
				catch(const char* s)
				{
					cout << s << endl;
				}
				break;
			case 4:
				try
				{
					c = a;
					c.Out();
				}
				catch(const char* s)
				{
					cout << s << endl;
				}
				break;
			case 5:
				try
				{
					cout << "Enter index" << endl;
					cin >> i;
					cout << a[i];
					i = 0;
				}
				catch(const char* s)
				{
					cout << s << endl;
				}
				break;
			case 6:
				try
				{
					cout << "Find the length of the vector 1)a or vector 2)b" << endl;
					cin >> i;
					switch(i)
					{ 
					case 1:
						cout << "The length of the vector a is " << a.Length() << endl;
						break;
					case 2:
						cout << "The length of the vector a is " << b.Length() << endl;
						break;
					}
				}
				catch(const char* s)
				{
					cout << s << endl;
				}
				break;
			case 7:
				try
				{
					cout << "Insert the number " << endl;
					cin >> num;
					a += num;
					a.Out();
				}
				catch(const char* s)
				{
					cout << s << endl;
				}
				break;
			case 8:
				try
					{
					cout << "Insert the number " << endl;
					cin >> num;
					a -= num;
					a.Out();
					}
				catch(const char* s)
				{
					cout << s << endl;
				}
				break;
			case 9:
				try
				{
					cout << "Insert the number " << endl;
					cin >> num;
					a *= num;
					a.Out();
				}
				catch(const char* s)
				{
					cout << s << endl;
				}
				break;

		}
	}
	while(k != 10);
	Vector *d = new Vector;
	delete d;
}