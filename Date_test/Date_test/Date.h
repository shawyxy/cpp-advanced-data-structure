#pragma once
#include <iostream>

using namespace std;
class Date
{
public:
	void SetYear(int year);
	int GetYear();
private:
	int _year;
	int _month;
	int _day;
};