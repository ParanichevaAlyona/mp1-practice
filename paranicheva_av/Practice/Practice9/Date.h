#ifndef DATE_H
#define DATE_H

class Date
{
private:
	int d, m, y;
public:
	Date();
	Date(int _d, int _m, int _y);
	~Date();

	int Setd(int _d, int _m, int _y);
	int Setm(int _m);
	int Sety(int _y);
	bool Leapy(int _y);
	int Getd();
	int Getm();
	int Gety();
	
	void Print();
	Date& operator=(const Date date);
	bool operator==(const Date& tmp);	
};

#endif