#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:
    int GetMonthDay(int year, int month)
    {

    }
    void DatePrint()
    {
        cout << _year << "/" << _month << "/" << _day << endl;
    }
    Date() {}
    Date(int year, int month, int day)
    {
        _year = year;
        _month = month;
        _day = day;
    }
private:
    int _year;
    int _month;
    int _day;
};