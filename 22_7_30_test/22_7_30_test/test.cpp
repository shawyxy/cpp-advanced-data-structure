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
	//	ͨ�����г�Ա��������˽�г�Ա����
	date2.SetYear(2021);
	cout << date2.GetYear() << endl;
	//ֱ�ӷ���˽�г�Ա����������
	//date2._year = 2022;
	return 0;
}