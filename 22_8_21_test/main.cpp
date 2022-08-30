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
    //拷贝构造,赋值重载
    Date d1(2002,2,1);
    Date d2;
    d2 = d1;
    Date d3(d2);
    d1.DatePrint();
    d2.DatePrint();
    d3.DatePrint();
    //+= + ++重载
    Date d4 = d1 + 100;
    d4.DatePrint();
    d4 += 1;
    d4.DatePrint();

}

int main()
{
    test2();
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