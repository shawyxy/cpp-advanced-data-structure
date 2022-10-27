#include <iostream>
using namespace std;
////父类
//class Person
//{
//public:
//    //父类的虚函数
//    virtual void BuyTicket()
//    {
//        cout << "买票-全价" << endl;
//    }
//};
////子类
//class Student : public Person
//{
//public:
//    //子类的虚函数重写了父类的虚函数
//    virtual void BuyTicket()
//    {
//        cout << "买票-半价" << endl;
//    }
//};
////子类
//class Soldier : public Person
//{
//public:
//    //	子类继承了父类虚函数的声明，即使不加virtual也是虚函数
//    void BuyTicket()
//    {
//        cout << "优先-买票" << endl;
//    }
//};
//class Base{
//public:
//    virtual void Show(int n = 10)const{    //提供缺省参数值
//        std::cout << "Base:" << n << std::endl;
//    }
//};
//
//class Base1 : public Base{
//public:
//    virtual void Show(int n = 20)const{     //重新定义继承而来的缺省参数值
//        std::cout << "Base1:" << n << std::endl;
//    }
//};

//class A{};  // 父类
//class B : public A{};  // 子类
//class Person
//{
//public:
//    //返回父类A的指针
//    virtual A* fun()
//    {
//        cout << "A* Person::fun()" << endl;
//        return new A;
//    }
//};
//class Student : public Person
//{
//public:
//    //返回子类B的指针
//    virtual B* fun()
//    {
//        cout << "B* Student::fun()" << endl;
//        return new B;
//    }
//};
//int main()
//{
//    Person* ptr1 = new Person;
//    Person* ptr2 = new Student;
//    ptr1->fun(); //A* Person::fun()
//    ptr2->fun(); //B* Student::fun()
//    return 0;
//}

//int main(){
//
//    Base* p1 = new Base1;
//    p1->Show(5);           //#1
//    p1->Show();            //#2
//
//    return 0;
//}
//
//int main()
//{
//    Person* p = new Person;
//    p->BuyTicket();
//
//    Person* p1 = new Student;
//    p1->BuyTicket();
//
//    Person* p2 = new Soldier;
//    p2->BuyTicket();
//    return 0;
//}


////父类
//class Person
//{
//public:
//    virtual ~Person()
//    {
//        cout << "~Person()" << endl;
//    }
//};
////子类
//class Student : public Person
//{
//public:
//    virtual ~Student()
//    {
//        cout << "~Student()" << endl;
//    }
//};
//int main()
//{
//    // 父类指针指向父类和子类对象,并分别调用析构函数
//    Person* parent = new Person;
//    delete parent;
//
//    Person* child = new Student;
//    delete child;
//
//    return 0;
//}

//class A
//{
//public:
//    virtual void fun() = 0;
//};
//class B : public A
//{
//    virtual void fun()
//    {
//        cout << "B" << endl;
//    }
//};
//int main()
//{
//    A* b = new B;
//    b->fun();
//    return 0;
//}
class Base
{
public:
    virtual void Func()
    {
        cout << "Func()" << endl;
    }
private:
    int _b = 1;
};
int main()
{
    Base b;
    cout << sizeof(b) << endl; //8
    return 0;
}