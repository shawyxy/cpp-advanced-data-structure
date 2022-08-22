//
// Created by 肖越 on 2022/8/21.
//

#ifndef INC_22_8_21_TEST_DATE_H
#define INC_22_8_21_TEST_DATE_H

#endif //INC_22_8_21_TEST_DATE_H
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
    int GetMonthDay(int year, int month)
    {
        static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int day = days[month];
        if (month == 2
            && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
        {
            day += 1;
        }

        return day;
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
    //运算符重载
    Date& operator=(const Date& d);
    bool operator==(const Date& d);
    bool operator!=(const Date& d);
    bool operator>(const Date& d);
    bool operator>=(const Date& d);
    bool operator<(const Date& d);
    bool operator<=(const Date& d);

    Date operator+(int day);
    Date& operator+=(int day);

    Date& operator++(); // 前置
    Date operator++(int); // 后置

private:
    int _year;
    int _month;
    int _day;
};
//class Stack
//{
//public:
//    //...���ַ���
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
//class Date
//{
//    //...
//public:
//    Func();             //默认构造函数
//    Func(const Date&);  //拷贝构造函数
//    //...
//};
