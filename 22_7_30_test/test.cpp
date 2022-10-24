#include <iostream>
using namespace std;
class Date
{
	int _month;
private:
	int _year;
public:
	void SetYear(int year);
	int GetYear();
};
void Date::SetYear(int year)
{
	_year = year;
}
int Date::GetYear()
{
	return _year;
}
int main()
{
	Date date2;
	//	通过公有成员函数访问私有成员变量
	date2.SetYear(2021);
	cout << date2.GetYear() << endl;
	//直接访问私有成员变量不可行
	//date2._year = 2022;
	return 0;
}