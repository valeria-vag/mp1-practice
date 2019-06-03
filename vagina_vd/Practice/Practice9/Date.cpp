#include "Date.h"

Date::Date()
{
    y = 0000;
    m = 0;
    d = 0;
}

Date::Date(int _y, int _m, int _d)
{
    y = _y;
    m = _m;
    d = _d;
}

Date::~Date()
{
    y = 0;
    m = 0;
    d = 0;
}

bool Date::operator==(Date tmp) const
{
    return ((y == tmp.y) && (m == tmp.m) && (d == tmp.d));
}

const Date& Date::operator=(Date& tmp)
{
    y = tmp.y;
    m = tmp.m;
    d = tmp.d;
    return *this;
}

ostream& operator<<(ostream &os, const Date & tmp)
{
    os << " ";
    if ((tmp.d > 0) && (tmp.d < 10))
        os << "0" << tmp.d << ".";
    else os << tmp.d << ".";

    if ((tmp.m > 0) && (tmp.m < 10))
        os << "0" << tmp.m << ".";
    else os << tmp.m << ".";

    if ((tmp.y >= 0) && (tmp.y < 1000))
        os << "0" << tmp.y << "";
    else os << tmp.y << "";

    return os;
}

istream& operator>>(istream& is, Date& tmp)
{
    cout << "  Enter the year: ";
    is >> tmp.y;
    if (tmp.y < 0)
        throw Exception_date("Date isn't correct!");

    cout << "  Enter the month: ";
    is >> tmp.m;
    if ((tmp.m < 1) || (tmp.m > 12))
        throw Exception_date("Date isn't correct!");

    cout << "  Enter the day: ";
    is >> tmp.d;
    if ((tmp.d < 1) || (tmp.d > 31))
        throw Exception_date("Date isn't correct!");

    return is;
};