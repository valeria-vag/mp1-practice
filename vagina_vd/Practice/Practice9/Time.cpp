#include "Time.h"

Time::Time()
{
    h = 0;
    m = 0;
}

Time::Time(int _h, int _m)
{
    h = _h;
    m = _m;
}

Time::~Time()
{
    h = 0;
    m = 0;
}

const Time& Time::operator=(Time& tmp)
{
    h = tmp.h;
    m = tmp.m;
    return *this;
}

ostream& operator<<(ostream& os, const Time& tmp)
{
    os << " ";
    if ((tmp.h > 0) && (tmp.h < 10))
        os << "0" << tmp.h << ":";
    else os << tmp.h << ":";

    if ((tmp.m >= 0) && (tmp.m < 10))
        os << "0" << tmp.m << " ";
    else os << tmp.m << " ";
    return os;
};