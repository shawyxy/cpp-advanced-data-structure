//#include <iostream>
//using namespace std;
//class Date
//{
//    int _month;
//private:
//    int _year;
//public:
//    void SetYear(int year);
//    int GetYear();
//    void Print();
//};
//void Date::SetYear(int year)
//{
//    _year = year;
//}
//int Date::GetYear()
//{
//    return _year;
//}
//int main()
//{
//
//    return 0;
//}
/*
int main()
{
    Date date2;
    //	通过公有成员函数访问私有成员变量
    date2.SetYear(2021);
    cout << date2.GetYear() << endl;
    //直接访问私有成员变量不可行
    //date2._year = 2022;
    return 0;
}*/
//using namespace std;
//class Person
//{
//public:
//    int age;
//};
//int main()
//{
//    Person xiaoming;
//    xiaoming.age = 18;
//    cout << xiaoming.age << endl;
//    return 0;
//}
#include <iostream>
using namespace std;
class Date
{
public:
    void SetFunc(int year, int month, int day)
    {
        year = year;
        month = month;
        day = day;
    }
    void GetFunc()
    {
        cout << year << "/" << month << "/" << day << endl;
    }

private:
    int year;
    int month;
    int day;
};
int main()
{
    Date date;
    date.SetFunc(2022, 8, 2);
    date.GetFunc();
    return 0;
}
//class Date
//{
//    int _month;
//public:
//    int _year;
//public:
//    void  static Print();
//};
//
//void Date::Print()
//{
//    cout << "Date::Print" << endl;
//}
//class A1
//{
//public:
//    void f1(){};
//private:
//    int _a;
//};
//class A2
//{
//public:
//    void f2(){};
//};
//class A3
//{};
//int main()
//{
//    cout << sizeof(A1) << endl;
//    cout << sizeof(A2) << endl;
//    cout << sizeof(A3) << endl;
//    return 0;
//}

//int main()
//{
//    Date* date1;
//    date1 = nullptr;
//    (*date1).Print();
//    return 0;
//}
//int main()
//{
//    //实例化两个对象,初始化它们的成员
//    Date Date3;
//    Date Date4;
//    Date3._year = 2021;
//    Date4._year = 2022;
//    //打印一下成员变量和成员函数的地址
//    Date3.Print();
//    Date4.Print();
//    cout << &Date3._year << endl;
//    cout << &Date4._year << endl;
//    return 0;
//}

