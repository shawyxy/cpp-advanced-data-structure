//
// Created by 肖越 on 2022/8/14.
//

#ifndef INC_22_8_14_DATE_DATE_H
#define INC_22_8_14_DATE_DATE_H

#endif //INC_22_8_14_DATE_DATE_H
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
    Date(){}
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
