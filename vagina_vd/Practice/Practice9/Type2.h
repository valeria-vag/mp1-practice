#ifndef _TYPE_2_H_
#define _TYPE_2_H_
#include "Time.h"
#include "Task.h"

class Type2 : public Task
{
private:
	Time time_start, time_finish;
public:
	Type2(string, Date, Time, Time);
	void print();
};
#endif