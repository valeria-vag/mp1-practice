#ifndef _DATE_H_
#define _DATE_H_
#include <iostream>
#include <exception>
using namespace std;

class Date
{
private:
    int y = 0, m = 0, d = 0;
public:
    Date();
    Date(int, int, int);
    ~Date();
    bool operator==(Date) const;
    const Date& operator=(Date&);

    friend ostream& operator<<(ostream&, const Date&);
    friend istream& operator>>(istream&, Date&);
};

//Exceptions
class Exception_date : exception
{
private:
    const string mes;
public:
    Exception_date(string e)
        : mes(e)
    {
    }
    const char* what() const { return mes.c_str(); }
};
#endif