//
// Created by 肖越 on 2022/9/13.
//

#ifndef INC_22_9_13_STRING_MYSTRING_H
#define INC_22_9_13_STRING_MYSTRING_H

#endif //INC_22_9_13_STRING_MYSTRING_H
#include <iostream>
#include <string.h>
using namespace std;
class Mystring
{
public:
    void Print()
    {
        for(int i = 0; i < _size; i++)
        {
            cout << _str[i] << " ";
        }
        cout << endl;
    }
//    Mystring(const char* str = "")
//    {
//        _size = strlen(str);
//        _capacity = _size;
//        _str = new char[_capacity + 1];
//        strcpy(_str, str);
//    }

//    Mystring(const Mystring& str)
//    {
//        string tmp(str._str);
//        swap(_str, tmp._str);
//        swap(_size, tmp._size);
//        swap(_capacity, tmp._capacity);
//    }
    ~Mystring()
    {
        delete[] _str;
        _str = nullptr;
        _capacity = 0;
        _size = 0;
    }
private:
    size_t _capacity;
    size_t _size;
    char* _str;
public:
    static const size_t npos = -1;
};