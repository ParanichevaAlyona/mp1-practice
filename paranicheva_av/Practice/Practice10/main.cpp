#include <iostream>
#include "Container.h"
#include "ContainerA.h"
using namespace std;

void main()
{
	int _size;
	const int _maxsize  = 20;
	cout << "Enter array size" << endl;
	cin >> _size;
	int n;
	Container<int, _maxsize> A(_size);

	try
	{
		A.Fill();
		A.Print();
	}
	catch(const char* s)
	{
		cout << s << endl;
	}

	try
	{
		cout << "Enter the item you want to find" << endl;
		cin >> n;
		cout << A.Find(n) << endl;
	}
	catch(const char* s)
	{
		cout << s << endl;
	}

	try
	{
		cout << "Enter a new array element" << endl;
		cin >> n;
		A.Add(n);
		A.Print();
	}
	catch(const char* s)
	{
		cout << s << endl;
	}

	try
	{
		cout << "Enter the item you want to delete" << endl;
		cin >> n;
		A.Delete(n);
		A.Print();
	}
	catch(const char* s)
	{
		cout << s << endl;
	}

	try
	{
		int i;
		cout << "Enter index" << endl;
		cin >> i;
		cout << A[i] << endl;
	}
	catch(const char* s)
	{
		cout << s << endl;
	}
	
	int _s;
	_s = _size;
	int nn;
	Container<int*, _maxsize> B(_s);

	try
	{
		B.Fill();
		B.Print();
	}
	catch(const char* s)
	{
		cout << s << endl;
	}

	try
	{
		cout << "Enter the item you want to find" << endl;
		cin >> nn;
		cout << B.Find(nn) << endl;
	}
	catch(const char* s)
	{
		cout << s << endl;
	}

	try
	{
		cout << "Enter a new array element" << endl;
		cin >> nn;
		B.Add(nn);
		B.Print();
	}
	catch(const char* s)
	{
		cout << s << endl;
	}

	try
	{
		cout << "Enter the item you want to delete" << endl;
		cin >> nn;
		B.Delete(nn);
		B.Print();
	}
	catch(const char* s)
	{
		cout << s << endl;
	}

	try
	{
		int i;
		cout << "Enter index" << endl;
		cin >> i;
		cout << B[i] << endl;
	}
	catch(const char* s)
	{
		cout << s << endl;
	}

}
