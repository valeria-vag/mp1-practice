#include "ToDoList.h"
#include "Date.h"
#include "Type1.h"
#include "Type2.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

ToDoList::ToDoList()
{
	count = 0;
}

ToDoList::~ToDoList()
{
	count = 0;
	delete[] * tasks;
}

void ToDoList::read(const string file_str)
{
	string s;
	string str, tmp;
	int type;
	int year, month, day;
	int hour1, minute1;
	int hour2, minute2;
	string _description;

	ifstream fin(file_str);
	if (fin.is_open())
	{
		fin >> count;
		if (count < 1)
			throw Exception_task("  Count tasks isn't correct!");
		tasks = new Task*[count];
		int j = -1;

		while (!fin.eof())
		{
			getline(fin, s);
			type = atoi(s.c_str());
			s.erase(0, 2); //delete type

			if (type == 1)
			{
				str = ";";
				for (int i = 0; i < s.find(str, 0); i++)
					_description += s[i];
				s.erase(0, s.find(str, 0) + 1); //delete description

				str = ":";
				for (int i = 0; i < s.find(str, 0); i++)
				{
					tmp += s[i];
				}
				year = atoi(tmp.c_str());
				s.erase(0, s.find(str, 0) + 1); //delete year
				tmp.clear();
				for (int i = 0; i < s.find(str, 0); i++)
				{
					tmp += s[i];
				}
				month = atoi(tmp.c_str());
				s.erase(0, s.find(str, 0) + 1); //delete month
				tmp.clear();
				for (int i = 0; i < s.size(); i++)
				{
					tmp += s[i];
				}
				day = atoi(tmp.c_str());
				s.erase(0, s.find(str, 0)); //delete day
				tmp.clear();

				Date _date(year, month, day);
				tasks[j] = new Type1(_description, _date);
			}

			else if (type == 2)
			{
				str = ";";
				for (int i = 0; i < s.find(str, 0); i++)
					_description += s[i];
				s.erase(0, s.find(str, 0) + 1);

				str = ":";
				for (int i = 0; i < s.find(str, 0); i++)
				{
					tmp += s[i];
				}
				year = atoi(tmp.c_str());
				s.erase(0, s.find(str, 0) + 1);
				tmp.clear();

				for (int i = 0; i < s.find(str, 0); i++)
				{
					tmp += s[i];
				}
				month = atoi(tmp.c_str());
				s.erase(0, s.find(str, 0) + 1);
				tmp.clear();

				for (int i = 0; i < s.find(str, 0); i++)
				{
					tmp += s[i];
				}
				day = atoi(tmp.c_str());
				s.erase(0, s.find(str, 0) + 1);
				tmp.clear();
				for (int i = 0; i < s.find(str, 0); i++)
				{
					tmp += s[i];
				}
				hour1 = atoi(tmp.c_str());
				s.erase(0, s.find(str, 0) + 1); //delete hours
				tmp.clear();
				for (int i = 0; i < s.find(str, 0); i++)
				{
					tmp += s[i];
				}
				minute1 = atoi(tmp.c_str());
				s.erase(0, s.find(str, 0) + 1); //delete minutes
				tmp.clear();
				for (int i = 0; i < s.find(str, 0); i++)
				{
					tmp += s[i];
				}
				hour2 = atoi(tmp.c_str());
				s.erase(0, s.find(str, 0) + 1);
				tmp.clear();
				for (int i = 0; i < s.size(); i++)
				{
					tmp += s[i];
				}
				minute2 = atoi(tmp.c_str());
				s.erase(0, s.find(str, 0) + 1);
				tmp.clear();

				Time _time1(hour1, minute1);
				Time _time2(hour2, minute2);
				Date _date(year, month, day);
				tasks[j] = new Type2(_description, _date, _time1, _time2);
			}
			s.clear();
			_description.clear();
			j++;
		}
	}
	fin.close();
}

void ToDoList::print(Date _date)
{
	int f = 0;
	cout << endl << "  __PLANS ON " << _date << "__\n" << endl;
	for (int i = 0; i < count; i++)
	{
		if (tasks[i]->GetDate() == _date)
		{
			tasks[i]->print();
			f = 1;
		}
	}
	if (f == 0)
		throw Exception_free("You are free for this day!");
};