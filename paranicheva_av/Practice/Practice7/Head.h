#ifndef HEAD_H
#define HEAD_H

class Vector
{
private:
	int n;
	double *x;

public:
	Vector();
	Vector(int nn);
	Vector(const Vector& z);
	~Vector();
	Vector& Fill();
	void Out();
	Vector operator+ (const Vector& z) const;
	Vector operator- (const Vector& z) const;
	double operator* (const Vector& z) const;
	Vector operator+ (double a) const;
	Vector operator- (double a) const;
	Vector operator* (double a) const;
	Vector& operator= (const Vector& z);
	double* operator[] (int ind) const;
	double Length();
	Vector& operator+= (const Vector& z);
	Vector& operator-= (const Vector& z);
	Vector& operator+= (double a);
	Vector& operator-= (double a);
	Vector& operator*= (double a);
	void *operator new(size_t size);
	void operator delete(void *v);
	bool operator==(const Vector& z);
};
#endif
