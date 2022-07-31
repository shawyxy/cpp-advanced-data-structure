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

//class Date
//{
//public:
//	int _year;
//	int GetYear();
//	void SetYear(int year);
//};
//int Date::GetYear()
//{
//	return _year;
//}
//void Date::SetYear(int year)
//{
//	_year = year;
//}
//int main()
//{
//	Date date1;//实例化对象
//	//通过公有成员函数访问公有成员变量
//	date1.SetYear(2021);
//	cout << date1.GetYear() << endl;
//	//直接访问公有成员变量
//	date1._year = 2022;
//	cout << date1._year << endl;
//	return 0;
//}
//class bb
//{
//	int a;
//private:
//	int b;
//	void bfunc()
//	{
//		cout << "private" << endl;
//	}
//public:
//	
//};
//class aa
//{
//public:
//	int a;
//	void afunc()
//	{
//		cout << "public" << endl;
//	}
//};
//int main()
//{
//	aa a;
//	a.a = 1;
//	a.afunc();
//	return 0;
//}


//
//class Date
//{
//public:
//	void Year()
//	{
//		cout << _day << endl;
//	}
//private:
//	int _year = 1;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date dog;
//	
//	
//	dog.Year();
//	return 0;
//}
//class Dog
//{
//	int _age;
//public:
//	void eat()
//	{
//		cout << "eat" << endl;
//	}
//};
//int main()
//{
//	Dog wangcai;
//	wangcai.eat();
//	return 0;
//}