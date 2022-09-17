#include <iostream>
using namespace std;
//class A
//
//{
//
//public:
//
//    A(int a)
//
//            :_a1(a)
//
//            ,_a2(_a1)
//
//    {}
//
//
//
//    void Print()
//
//    {
//
//        cout<<_a1<<" "<<_a2<<endl;
//
//    }
//
//private:
//
//    int _a2;
//
//    int _a1;
//
//};
//
//

//
//class A{
//public:
//    A()
//    {
//        cout << "a构造" << endl;
//    }
//    ~A()
//    {
//        cout << "a析构" << endl;
//    }
//};
//class B{
//public:
//    B()
//    {
//        cout << "b构造" << endl;
//    }
//    ~B()
//    {
//        cout << "b析构" << endl;
//    }
//};
//class C{
//public:
//    C()
//    {
//        cout << "c构造" << endl;
//    }
//    ~C()
//    {
//        cout << "c析构" << endl;
//    }
//};
//class D{
//public:
//    D()
//    {
//        cout << "d构造" << endl;
//    }
//    ~D()
//    {
//        cout << "d析构" << endl;
//    }
//};
//C c;
//
//
//int main()
//
//{
//
//    A* pa = new A();
//
//    B b;
//
//    static D d;
//
//    delete pa;
//
//}

//int main()
//
//{
//
//    A a;
//
//    B b;
//
//    static D d;
//
//    return 0;
//
//}
//int main()
//
//{
//
//    string a="hello world";
//
//    string b=a;
//
//    if (a.c_str()==b.c_str())
//
//    {
//
//        cout<<"true"<<endl;
//
//    }
//
//    else cout<<"false"<<endl;
//
//    string c=b;
//
//    c="";
//
//    if (a.c_str()==b.c_str())
//
//    {
//
//        cout<<"true"<<endl;
//
//    }
//
//    else cout<<"false"<<endl;
//
//    a="";
//
//    if (a.c_str()==b.c_str())
//
//    {
//
//        cout<<"true"<<endl;
//
//    }
//
//    else cout<<"false"<<endl;
//
//    return 0;
//
//}
//
//int main()
//
//{
//
//    string str("Hello Bit.");
//
//    str.reserve(111);
//
//    str.resize(5);
//
//    str.reserve(50);
//
//    cout<<str.size()<<":"<<str.capacity()<<endl;
//
//    return 0;
//
//}
//int main(int argc, char *argv[])
//
//{
//
//    string strText = "How are you?";
//
//    string strSeparator = " ";
//
//    string strResult;
//
//    int size_pos = 0;
//
//    int size_prev_pos = 0;
//
//    while((size_pos=strText.find_first_of(strSeparator, size_pos)) != string::npos)
//
//    {
//
//        strResult = strText.substr(size_prev_pos, size_pos-size_prev_pos);
//
//        cout<<strResult<<" ";
//
//        size_prev_pos = ++size_pos;
//
//    }
//
//    if(size_prev_pos != strText.size())
//
//    {
//
//        strResult = strText.substr(size_prev_pos, size_pos-size_prev_pos);
//
//        cout<<strResult<<" ";
//
//    }
//
//    cout<<endl;
//
//    return 0;
//
//}
#include <cmath>
//class Solution {
//public:
//    int StrToInt(string str) {
//        //首先过滤
//        if(str == "")
//            return 0;
//        //检查字符串合法性
//        int len = str.size();
//        for(int i = 0; i < str.size();)
//        {
//            if((str[0] == '+' || str[0] == '-') && str.size() == 1)
//            {
//                return 0;
//            }
//
//
//            if((!isdigit(str[++i])) && i < len)
//                return 0;
//        }
//        int count = 0, num = 0, ret = 0;
//        int end = len - 1;
//        while(end >= 0)
//        {
//            if(str[end] == '+')
//                break;
//            if(str[end] == '-')
//            {
//                ret = -ret;
//                break;
//            }
//
//            //获取最后一个字符对应的数字
//            num = str[end--] - '0';
//            //从后到前，按位相加
//            ret += num * pow(10, count++);
//        }
//        return ret;
//    }
//};
//class Solution {
//public:
//    void reverseString(vector<char>& s) {
//        int n = s.size();
//        for (int left = 0, right = n - 1; left < right; ++left, --right) {
//            swap(s[left], s[right]);
//        }
//    }
//};
//
//int main()
//{
//    Solution s;
//
//    cout << s.reverseString("");
//    return 0;
//}