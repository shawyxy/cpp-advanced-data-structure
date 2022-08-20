#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

class Date
{
public:
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
//class Stack
//{
//public:
//    //...各种方法
//    ~Stack()
//    {
//        if (data)
//        {
//            free(data);
//            data = NULL;
//            _capacity = 0;
//            _size = 0;
//        }
//    }
//private:
//    int _size;
//    int _capacity;
//    int* data;
//};