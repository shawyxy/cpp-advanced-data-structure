#include <iostream>
using namespace std;
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    while(cin>>str)
    {
        int sc=0;
        int len=str.size();
        //长度分
        if(len<=4)sc+=5;
        else if(len>=5&&len<=7)sc+=10;
        else if(len>=8)sc+=25;
        //字母分
        int xnum=0,dnum=0;
        for(int i=0;i<len;i++)
        {
            if(str[i]>='a'&&str[i]<='z')xnum++;
            if(str[i]>='A'&&str[i]<='Z')dnum++;
        }
        if(xnum!=0)sc+=10;
        if(dnum!=0)sc+=10;
        //数字分
        int num=0;
        for(int i=0;i<len;i++)
        {
            if(str[i]>='0'&&str[i]<='9')num++;
        }
        if(num==1)sc+=10;
        else if(num>=2)sc+=20;
        //符号分
        int fnum=0;
        for(int i=0;i<len;i++)
        {
            if(str[i]>='!'&&str[i]<='/')fnum++;
            else if(str[i]>=':'&&str[i]<='@')fnum++;
            else if(str[i]>='['&&str[i]<='`')fnum++;
            else if(str[i]>='{'&&str[i]<='~')fnum++;
        }
        if(fnum==1)sc+=10;
        else if(fnum>=2)sc+=25;
        //奖励分
        int smax=0;
        if((xnum+dnum)!=0&&num!=0)smax=max(smax,2);
        if((xnum+dnum)!=0&&num!=0&&fnum!=0)smax=max(smax,3);
        if(xnum!=0&&num!=0&&dnum!=0&&fnum!=0)smax=max(smax,5);
        sc+=smax;
        if(sc>=90)cout<<"VERY_SECURE"<<endl;
        else if(sc>=80)cout<<"SECURE"<<endl;
        else if(sc>=70)cout<<"SECURE"<<endl;
        else if(sc>=60)cout<<"STRONG"<<endl;
        else if(sc>=50)cout<<"AVERAGE"<<endl;
        else if(sc>=25)cout<<"AVERAGE"<<endl;
        else if(sc>=0)cout<<"AVERAGE"<<endl;
    }
}

//int main()
//{
//    const int a = 10;
//    int * p = (int*)(&a);
//    *p = 20;
//    cout << a << *p << endl;
//}
//
////template<class T1, class T2>
//
//class Data
//
//{
//
//public:
//
//    Data() { cout << "Data<T1, T2>" << endl; }
//
//private:
//
//    T1 _d1;
//
//    T2 _d2;
//
//};
//
//template <class T1>
//
//class Data<T1, int>
//
//{
//
//public:
//
//    Data() { cout << "Data<T1, int>" << endl; }
//
//private:
//
//    T1 _d1;
//
//    int _d2;
//
//};
//
//template <typename T1, typename T2>
//
//class Data <T1*,T2*>
//
//{
//
//public:
//
//    Data() { cout << "Data<T1*, T2*>" << endl; }
//
//private:
//
//    T1 _d1;
//
//    T2 _d2;
//
//};
//
//template <typename T1, typename T2>
//
//class Data <T1&, T2&>
//
//{
//
//public:
//
//    Data(const T1& d1, const T2& d2)
//
//            : _d1(d1)
//
//            , _d2(d2)
//
//    {
//
//        cout << "Data<T1&, T2&>" << endl;
//
//    }
//
//private:
//
//    const T1 & _d1;
//
//    const T2 & _d2;
//
//};
//
//int main()
//
//{
//
//    Data<double, int> d1;
//
//    Data<int, double> d2;
//
//    Data<int *, int*> d3;
//
//    Data<int&, int&> d4(1, 2);
//
//    return 0;
//
//}
//class A
//
//{
//
//public:
//
//    void f(){ cout<<"A::f()"<<endl; }
//
//    int a;
//
//};
//
//
//
//class B : public A
//
//{
//
//public:
//
//    void f(int a){cout<<"B::f()"<<endl;}
//
//    int a;
//
//};
//
//
//
//int main()
//
//{
//
//    B b;
//
//    b.f();
//
//    return 0;
//
//}
//template<typename Type>
//
//Type Max(const Type &a, const Type &b)
//
//{
//
//cout<<"This is Max<Type>"<<endl;
//
//return a > b ? a : b;
//
//}
//
//template<>
//
//int Max<int>(const int &a, const int &b)
//
//{
//
//cout<<"This is Max<int>"<<endl;
//
//return a > b ? a : b;
//
//}
//
//template<>
//
//char Max<char>(const char &a, const char &b)
//
//{
//
//cout<<"This is Max<char>"<<endl;
//
//return a > b ? a : b;
//
//}
//
//int Max(const int &a, const int &b)
//
//{
//
//cout<<"This is Max"<<endl;
//
//return a > b ? a : b;
//
//}
//
//int main()
//
//{
//
//Max(10,20);
//
//Max(12.34,23.45);
//
//Max('A','B');
//
//Max<int>(20,30);
//
//return 0;
//
//}