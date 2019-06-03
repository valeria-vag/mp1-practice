#ifndef _TIME_H_
#define _TIME_H_
#include "iostream"
using namespace std;

class Time
{
private:
    int h = 0, m = 0;
public:
    Time();
    Time(int, int);
    ~Time();
    const Time& operator=(Time&);

    friend ostream& operator<<(ostream&, const Time&);
};
#endif