#include "test.h"
#include <iostream>
using namespace std;
class A
{
public:
    A( A& a)
    {
        _a = a._a;
        cout << "构造" << _a << endl;
    }
    ~A()
    {
        cout << "析构" << _a << endl;
    }
private:
    int _a;
};

//-------------------------------------
//A a3(3);
//
//void fun()
//{
//	static int i = 0;
//	static A a0(0);
//	A a1(1);
//	A a2(2);
//	static A a4(4);
//}
//int main()
//{
//	fun();
//    fun();
//	return 0;
//}
