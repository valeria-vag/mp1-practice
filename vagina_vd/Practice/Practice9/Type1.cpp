#include "Type1.h"
#include <iostream>
using namespace std;

Type1::Type1(string _description, Date _date)
{
    description = _description;
    date = _date;
}

Type1::~Type1()
{
    description.clear();
}

void Type1::print()
{
    cout << "  " << description << endl;
}