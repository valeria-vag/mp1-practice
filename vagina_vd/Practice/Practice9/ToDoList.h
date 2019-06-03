#ifndef _TODOLIST_H_
#define _TODOLIST_H_
#include "Task.h"
#include "Date.h"
#include <exception>

class ToDoList
{
private:
	Task **tasks;
	int count;
public:
	ToDoList();
	~ToDoList();
	void read(const string);
	void print(Date);
};

class Exception_free : exception
{
private:
	const string mes;
public:
	Exception_free(string e)
		: mes(e)
	{
	}
	const char* what() const { return mes.c_str(); }
};
class Exception_task : exception
{
private:
	const string mes;
public:
	Exception_task(string e)
		: mes(e)
	{
	}
	const char* what() const { return mes.c_str(); }
};
#endif