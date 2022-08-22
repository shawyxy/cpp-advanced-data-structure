#include "Date.h"
using namespace std;
void test1()
{
    Date d1(1,2,1);
    Date d2(d1);

    d1.DatePrint();
    d2.DatePrint();
}
void test2()
{
    Date d1(2002,2,1);
    Date d2;
    d2 = d1;
    d1.DatePrint();
    d2.DatePrint();
}
int main()
{

    return 0;
}

//class A
//{
//    A()
//    {
//        cout << "构造" + *this <<endl;
//    }
//    ~A()
//    {
//        cout << "构造" + *this <<endl;
//    }
//private:
//    int val;
//};