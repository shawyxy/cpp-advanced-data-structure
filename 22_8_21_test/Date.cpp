//
// Created by 肖越 on 2022/8/21.
//
#include "Date.h"
Date& Date::operator=(const Date& d)
{
    if(this != &d)
    {
        _year = d._year;
        _month = d._month;
        _day = d._day;
    }
    return *this;
}
bool Date::operator==(const Date& d)
{
    return _year == d._year
           && _month == d._month
           && _day == d._day;
}
bool Date::operator!=(const Date& d)
{
    return !(*this == d);
}
bool Date::operator>(const Date& d)
{
    if ((_year > d._year)
        || (_year == d._year && _month > d._month)
        || (_year == d._year && _month == d._month && _day > d._day))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool Date::operator>=(const Date& d)
{
    return (*this > d) || (*this == d);
}
bool Date::operator<(const Date& d)
{
    return !(*this >= d);
}
bool Date::operator<=(const Date& d)
{
    return !(*this > d);
}
Date& Date::operator+=(int day)
{
    _day += day;
    while (_day > GetMonthDay(_year, _month))
    {
        _day -= GetMonthDay(_year, _month);
        ++_month;
        if (_month == 13)
        {
            _year++;
            _month = 1;
        }
    }

    return *this;
}
Date Date::operator+(int day)
{
    //Date ret(*this);
    Date ret = *this;
    ret += day;

    return ret;
}

Date& Date::operator++() // 前置
{
    return *this += 1;
}
Date Date::operator++(int) // 后置
{
    Date tmp(*this);
    *this += 1;

    return tmp;
}