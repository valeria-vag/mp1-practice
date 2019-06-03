#include "Type2.h"

Type2::Type2(string _description, Date _date, Time _time1, Time _time2)
{
	description = _description;
	date = _date;
	time_start = _time1;
	time_finish = _time2;
}

void Type2::print()
{
	cout << "  " << description << " " << time_start << "-" << time_finish << endl;
}