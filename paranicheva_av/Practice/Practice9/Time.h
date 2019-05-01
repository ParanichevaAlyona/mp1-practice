#ifndef TIME_H
#define TIME_H

class Time
{
private:
	int min, h;
public:
	Time();
	Time(int _min, int _h);
	~Time();
	int Setmin(int _min);
	int Seth(int _h);
	int Getmin();
	int Geth();
	void Print();
	Time& operator=(const Time time);
};

#endif