//#include <iostream>
//using namespace std;
//class Date
//{
//public:
//    void SetFunc(int year, int month, int day)
//    {
//        year = year;
//        month = month;
//        day = day;
//    }
//    void GetFunc()
//    {
//        cout << this->year << "/" << month << "/" << day << endl;
//    }
//private:
//    int year;
//    int month;
//    int day;
//};
//int main()
//{
//    Date date;
//    date.SetFunc(2022, 8, 2);
//    date.GetFunc();
//    return 0;
//}
//class Date
//{
//public:
//    void SetFunc(int year = 2000, int month = 1, int day = 1)
//    {
//        _year = year;
//        _month = month;
//        _day = day;
//    }
//    void GetFunc()
//    {
//        cout << _year << "/" << _month << "/" << _day << endl;
//    }
//
//private:
//    int _year = 1;
//    int _month = 1;
//    int _day = 1;
//};
//int main()
//{
//    Date date;
//    //还未调用Set函数就直接打印
//    date.GetFunc();
//    //不传参
//    date.SetFunc();
//    date.GetFunc();
//    //传参
//    date.SetFunc(2002);
//    date.GetFunc();
//
//    date.SetFunc(2003,2);
//    date.GetFunc();
//
//    date.SetFunc(2004,3,2);
//    date.GetFunc();
//    return 0;
//}
//class A
//{
//public:
//    void PrintA()
//    {
//        cout << "_a" << endl;
//    }
//private:
//    int _a;
//};
//int main()
//{
//    A* p = nullptr;
//    p->PrintA();
//    return 0;
//}

//class A
//{
//public:
//    void PrintA()
//    {
//        cout<<_a<<endl;
//    }
//private:
//    int _a;
//};
//int main()
//{
//    A* p = nullptr;
//    p->PrintA();
//    return 0;
//}
#include <iostream>
using namespace std;
class Date
{
public:
    void SetFunc(int year, int month, int day)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    void GetFunc()
    {
        cout << _year << "/" << _month << "/" << _day << endl;
    }

private:
    int _year;
    int _month;
    int _day;
};
int main()
{
    Date date;
    date.SetFunc(2022, 8, 2);
    date.GetFunc();
    return 0;
}