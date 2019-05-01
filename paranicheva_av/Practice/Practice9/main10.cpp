#include <iostream>
#include "Task.h"
#include "Date.h"
#include "Time.h"
#include "ToDoList.h"
using namespace std;

void main()
{
	Todolist List;
	try
	{
	List.Read();
	}
	catch (const char* s)
	{
		cout << s << endl;
	}
	List.Print();
}