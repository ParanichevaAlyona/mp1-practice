#ifndef TODOLIST_H
#define TODOLIST_H

class Todolist
{
public:
	Task **tasks;
	int count;
	Todolist();
	Todolist(int _count);
	~Todolist();

	void Read();
	void Print();
};

#endif