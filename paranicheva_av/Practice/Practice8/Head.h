#ifndef HEAD_H
#define HEAD_H

class Matrix
{
	double *m;
	int rows, cols;
public:
	Matrix();
	Matrix(int _rows, int _cols);
	Matrix(double* _m, int _rows, int _cols);
	Matrix(const Matrix& M);
	~Matrix();
	Matrix& Fill();
	void Out();
	Matrix operator= (const Matrix& M);
	Matrix operator+ (const Matrix& M)const;
	Matrix operator- (const Matrix& M)const;
	Matrix operator* (const Matrix&)const;
	Matrix operator+ (double a)const;
	Matrix operator- (double a)const;
	Matrix operator* (double a)const;
	double* operator[] (int ind) const;
	bool operator== (const Matrix& m) const;
};

#endif