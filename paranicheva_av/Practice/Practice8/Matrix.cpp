#include <iostream>
#include "Head.h"
using namespace std;

Matrix::Matrix()
{
	rows = 0;
	cols = 0;
	m = NULL;
}
Matrix::Matrix(int _rows, int _cols)
{
	rows = _rows;
	cols = _cols;
	m = new double[rows * cols];
}
Matrix::Matrix(double* _m, int _rows, int _cols)
{
	rows = _rows;
	cols = _cols;
	m = new double[rows * cols];
	m = _m;
}
Matrix::Matrix(const Matrix& M)
{
	rows = M.rows;
	cols = M.cols;
	m = new double[rows * cols];
	for(int i = 0; i < rows * cols; i++)
		m[i] = M.m[i];
}
Matrix::~Matrix()
{
	delete[]m;
	rows = 0;
	cols = 0;
}
Matrix& Matrix::Fill()
{
	cout << "Enter elements of matrix" << endl;
	for (int i = 0; i < rows * cols; i++)
		cin >> m[i];
	return *this;
}
void Matrix::Out()
{
	cout << "Matrix:" << endl;
	for (int i = 0; i < rows * cols; i++)
		{
			cout << m[i] << "  ";
			if ((i + 1)  % cols == 0 )
				cout << endl;
		}
}
Matrix Matrix::operator= (const Matrix& M) 
{
	delete[] m;
	rows = M.rows;
	cols = M.cols;
	m = new double[rows * cols];
	for(int i = 0; i < rows * cols; i++)
		m[i] = M.m[i];
	return *this;
}
Matrix Matrix::operator+ (const Matrix& M) const
{
	if(rows == M.rows && cols == M.cols)
	{
		Matrix res(rows, cols);
		for(int i = 0; i < rows * cols; i++)
			res.m[i] = m[i] + M.m[i];
		return res;
	}
	else
		throw "Error";
}
Matrix Matrix::operator- (const Matrix& M) const
{
	if(rows == M.rows && cols == M.cols)
	{
		Matrix res(rows, cols);
		for(int i = 0; i < rows * cols; i++)
			res.m[i] = m[i] - M.m[i];
		return res;
	}
	else
		throw "Error";
}
Matrix Matrix::operator* (const Matrix& M) const
{
	if (cols != M.rows)
		throw "Error";
	Matrix res(rows, M. cols);
	for(int i = 0; i < rows; i++)
		for(int j = 0; j < cols; j++)
			for(int k = 0; k < rows; k++)
				res.m[i * M.cols + j] += M.m[i * cols + k] * M.m[k * M.cols + j];
}
Matrix Matrix::operator+ (double a) const
{
	for (int i = 0; i < rows * cols; i++)
		m[i] += a;
	return *this;
}
Matrix Matrix::operator- (double a) const
{
	for (int i = 0; i < rows * cols; i++)
		m[i] -= a;
	return *this;
}
Matrix Matrix::operator* (double a) const
{
	for (int i = 0; i < rows * cols; i++)
		m[i] *= a;
	return *this;
}
double* Matrix::operator[] (int ind) const
{
	if ((ind < 0) || (ind >= rows * cols))
		throw "Error";
	return &(m[(cols * ind)]);
}
bool Matrix:: operator== (const Matrix& M) const
{
    if ((rows != M.rows) || (cols != M.cols)) return false;
    for (int i = 0; i < rows * cols; i++)
    {
        if (m[i] != M.m[i]) 
            return false;
    }
    return true;
}