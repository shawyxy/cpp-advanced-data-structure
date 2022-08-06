
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

void Date::SetYear(int year)
{
	_year = year;
}
int Date::GetYear()
{
	return this->_year;
}

int main()
{
	Date date;
	date.SetYear(2022);
	cout << date.GetYear() << endl;
	return 0;
}