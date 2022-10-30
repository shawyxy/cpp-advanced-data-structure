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
// class Base {
// public:
// 	virtual void func1() { cout << "Base::func1" << endl; }
// 	virtual void func2() { cout << "Base::func2" << endl; }
// private:
// 	int b1 = 1;
// };

// class Derive : public Base{
// public:
// 	virtual void func1() { cout << "Derive::func1" << endl; }
// 	virtual void func2() { cout << "Derive::func2" << endl; }
// private:
// 	int d = 2;
// };
// typedef void(*VFPTR)();
// void PrintVFTable(VFPTR table[])
// {
//     for (size_t i = 0; table[i] != nullptr; i++)
//     {
//         printf("VFT[%d]:%p-->", i, table[i]);
//         VFPTR pf = table[i];
//         pf();
//     }
// } 
// int main()
// {
// 	Base b;
// 	Derive d;

// 	PrintVFTable((VFPTR*)(*(int*)&b)); // 父类虚表 
// 	PrintVFTable((VFPTR*)(*(int*)&d)); // 子类虚表 

// 	return 0;
    
// }
// #include <iostream>
// #include <string>
// #include <list>
// using namespace std;
//int main()
//
//{
//
//    int ar[] = { 0,1, 2, 3, 4, 5, 6, 7, 8, 9 };
//
//    int n = sizeof(ar) / sizeof(int);
//
//    list<int> mylist(ar, ar+n);
//
//    list<int>::iterator pos = find(mylist.begin(), mylist.end(), 5);
//
//    reverse(mylist.begin(), pos);
//
//    reverse(pos, mylist.end());
//
//    list<int>::const_reverse_iterator crit = mylist.crbegin();
//
//    while(crit != mylist.crend())
//
//    {
//        break;
//        cout<<*crit<<" ";
//
//        ++crit;
//
//    }
//
//    cout<<endl;
//
//}
//class A
//{
//public:
//    A():_val(0){test();}
//    virtual void func()
//    {
//        cout << _val << endl;
//    }
//    void test(){func();}
//public:
//    int _val;
//};
//class B : public A
//{
//public:
//    B(){test();}
//    virtual void func()
//    {
//        ++_val;
//        cout << _val << endl;
//    }
//};
//int main()
//{
//    A* p = new B;
//    p->test();
//    return 0;
//}

//bool func1(string& str2) // isdigit && isalpha
//{
//    int len = str2.size();
//    for(int i = 0; i < len; i++)
//    {
//        if(!isdigit(str2[i]) || !isalpha(str2[i]))
//        {
//            return false;
//        }
//    }
//    return true;
//}
//bool func2(string& str1)
//{
//    int len1 = str1.size();
//    for(int i = 0; i < len1; i++)
//    {
//        if(str1[i] == '*' || str1[i] == '?')
//        {
//            return true;
//        }
//    }
//    return false;
//}
//void BigtoSmall(string& str2)
//{
//    int len = str2.size();
//    for(int i = 0; i < len; i++)
//    {
//        if(str2[i] > 'A' || str2[i] < 'Z')
//        {
//            str2[i] += 32;
//        }
//    }
//}
//int main()
//{
//    string str1, str2;
//    getline(cin, str1);
//    getline(cin, str2);
//    if(func1(str2)) // 如果str2有其他字符
//    {
//        cout << "false" << endl;
//        return 0;
//    }
//    if(func2(str1)) // 如果没有* ? 符号
//    {
//        if(str1 != str2)
//            cout << "false" << endl;
//        else
//            cout << "true" << endl;
//        return 0;
//    }
//    BigtoSmall(str2);
//    int len1 = str1.size(), len2 = str2.size();
//    int len = max(len1, len2);
//    int i = 0;
//    for(i = 0; i < len; i++)
//    {
//        if(str1[i] != str2[i])
//        {
//            if(str1[i] == '?')
//            {
//                cout<<"false"<<endl;
//                break;
//            }
//            else if(str1[i] == '*')
//            {
//                cout<<"false"<<endl;
//                break;
//            }
//            else if(str1[i] != '?' && str1[i] != '*')
//            {
//                cout<<"false"<<endl;
//                break;
//            }
//            else
//                break;
//        }
//        else
//            continue;
//    }
//    if(len == i)
//        cout << "true" << endl;
//    return 0;
//}
//class A
//{
//public:
//      void func()
//      {
//          cout << "A::func" << endl;
//      }
//};
//class B : public A
//{
//public:
//      void func(int a)
//      {
//          cout << "B::func" << endl;
//          a = 1;
//          cout << a << endl;
//      }
//};
//int main()
//{
//    A a;
//    B b;
//    a = b;
//    a.func();
//}
