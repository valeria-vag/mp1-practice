#ifndef _TASK_H_
#define _TASK_H_
#include <string>
#include "Date.h"
#include "Time.h"
using namespace std;

class Task
{
protected:
	string description;
	Date date;
public:
	Task();
	Task(string, Date);
	virtual ~Task();
	virtual void print() = 0;
	Date GetDate();
};
#endif