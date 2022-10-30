#include <iostream>
using namespace std;
// class Base
// {
// public:
//     virtual void Func1()
//     {
//         cout << "Base::Func1()" << endl;
//     }
//     virtual void Func2()
//     {
//         cout << "Base::Func2()" << endl;
//     }
//     void Func3()
//     {
//         cout << "Base::Func3()" << endl;
//     }
// private:
//     int _b = 1;
// };
// class Derive : public Base
// {
// public:
//     // 子类重写虚函数
//     virtual void Func1()
//     {
//         cout << "Derive::Func1()" << endl;
//     }
// private:
//     int _d = 2;
// };
// int main()
// {
//     Base b1;
//     Base b2;
    
//     Derive d1;
//     Derive d2;
//     return 0;
// }
// class Base
// {
// public:
//     virtual void Func1()
//     {
//         cout << "Base::Func1()" << endl;
//     }
//     virtual void Func2()
//     {
//         cout << "Base::Func2()" << endl;
//     }
//     void Func3()
//     {
//         cout << "Base::Func3()" << endl;
//     }
// private:
//     int _b = 1;
// };
// class Derive : public Base
// {
// public:
//     // 子类重写虚函数
//     virtual void Func1()
//     {
//         cout << "Derive::Func1()" << endl;
//     }
//     // 子类新增虚函数Func2
//     virtual void Func2()
//     {
//         cout << "Derive::Func2()" << endl;
//     }
// private:
//     int _d = 2;
// };
class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int b1 = 1;
};

class Derive : public Base{
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func2() { cout << "Derive::func2" << endl; }
private:
	int d = 2;
};
typedef void(*VFPTR)();
void PrintVFTable(VFPTR table[])
{
    for (size_t i = 0; table[i] != nullptr; i++)
    {
        printf("VFT[%d]:%p-->", i, table[i]);
        VFPTR pf = table[i];
        pf();
    }
} 
int main()
{
	Base b;
	Derive d;

	PrintVFTable((VFPTR*)(*(int*)&b)); // 父类虚表 
	PrintVFTable((VFPTR*)(*(int*)&d)); // 子类虚表 

	return 0;
    
}