//
// Created by 肖越 on 2022/8/16.
//

#ifndef INC_22_8_16_TEST_DATE_H
#define INC_22_8_16_TEST_DATE_H

#endif //INC_22_8_16_TEST_DATE_H
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
    Date()
    {
        _year = 111;
        _month = 222;
        _day = 1;
    }
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
class Stack
{
public:
    //...各种方法
    ~Stack()
    {
        if(data)
        {
            free(data);
            data = NULL;
            _capacity = 0;
            _size = 0;
        }
    }
private:
    int _size;
    int _capacity;
    int* data;
};
