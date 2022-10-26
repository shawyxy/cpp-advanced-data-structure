#include<iostream>
using namespace std;
// class A
// {
//     public:
//     void f()
//     {
//         cout << "A" << endl;
//     }
// };
// class B : public A{
// public:
// virtual void f()
// {
//     cout << "B" << endl;
// }
// };
struct A
{
    /* data */
    void foo()
    {
        cout << " foo " << endl;
    }
    virtual void bar()
    {
        cout << " bar " << endl;
    }
    A()
    {
        bar();
    }
};

struct B : A
{
    /* data */
    void foo()
    {
        cout << "b_foo" << endl;
    }
    void bar()
    {
        cout << "b_bar" << endl;
    }
};


int main()
{
//     A* a = new B;
//     a->f();
//     delete a;
    A* p  = new B();
    p->foo();
    p->bar();
    return 0;
}