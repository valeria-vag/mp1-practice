#include "Task.h"
#include "Date.h"
#include <string>
using namespace std;

Task::Task()
{

}

Task::Task(string _description, Date _date)
{
	description = _description;
	date = _date;
}

Task::~Task()
{
	description = '0';
}

Date Task::GetDate()
{
	return date;
};