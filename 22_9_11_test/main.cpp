
//void test1()
//{
//    int *ptr = new int;
//    for(int i = 0; i < 3; i++)
//        cout << *(ptr+i) << endl;
//}
//class A
//{
//public:
//    A()
//    {
//        cout << "析构函数" << this <<endl;
//    }
//    ~A()
//    {
//        cout << "构造函数" << this << endl;
//    }
//
//
//private:
//    int _a;
//};
#include <iostream>
#include <string>
using namespace std;

void test1()
{
    string s1 = "hello";
    string s2 = s1;
    string s3("world");
    string s4(s3);
    string s5(5,'a');

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
    cout << s5 << endl;
}
//void test3()
//{
//    string s = "hello";
//    cout << s.size() << endl;
//    cout << s.length() << endl;
//
//    cout << s.capacity() << endl;
//}
void test4()
{
    string s1 = "hello";
    string s2;

    cout << "s1 isEmpty?" << s1.empty() << endl;
    cout << "s2 isEmpty?" <<  s2.empty() << endl;

    s1.clear();
    cout << "s1 isEmpty?" <<  s1.empty() << endl;

    cout << "s1 capacity:" << s1.capacity() << endl;
    s1.reserve(25);
    cout << "s1 capacity:" <<  s1.capacity() << endl;

    string s3 = "world";
    s3.resize(8,'a');
    cout << s3 << endl;
}
void test5()
{
    string s1 = "hello";

    //std::basic_string<char>::iterator i = s1.rbegin();
//    for(;i < s1.end(); i++)
//    {
//        cout << *i << " ";
//    }

}
void test6()
{
    string s1 = "hell";
    s1.push_back('o');
    cout << s1 << endl;

    s1.append(" world");
    cout << s1 << endl;

    s1 += "!!!";
    cout << s1 << endl;

}
void test7()
{
    string s = "hello";
    const char* c = s.c_str();
    cout << c << endl;
}
void test8()
{
    string s1 = "hello";
    string::iterator b = s1.begin();
    string::iterator e = s1.end();

    cout << s1.find('e') << endl;

    cout << string::npos << endl;


}
int main()
{
    test8();
    return 0;
}
