// #include<iostream>
// #include <math.h>
// #include <string>
// using namespace std;
// int main()
// {
//     int n = 0;
//     cin >> n;
//     char op = ' ';
//     int a = 0, b = 0;
//     string str;
//     str.resize(1024);
//     int max = 0;
//     for (int i = 0; i < n; i++)
//     {
//             cin >> op >> a >> b;
//             if (a >= max)
//             {
//                 max = a;
//             }
//             if (b >= max)
//             {
//                 max = b;
//             }
//     }
//     str[0] = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         str[i] = pow(2, i - 1) + str[i - 1];
//         if (max - str[i] < 0)
//         {
//             cout << i;
//             return 0;
//         }
//     }
//     return 0;
// }
// #include <iostream>
// #include <vector>
// using namespace std;
// int num = 1e9 + 7;

// int func(int n, int rest, int start, int pos, vector< vector<int> >& dp)
// {
    
//     if(dp[start][rest] != -1)
//         return dp[start][rest] % num;
    
//     int ret = 0;
//     if(rest == 0)
//     {
//         if(start == pos)
//             ret = 1;
//         else
//             ret = 0;
//     }
//     else
//     {
//         if(start == 1)
//             ret = func(n, rest - 1, start + 1, pos, dp) % num;
//         else if(start == n)
//             ret = func(n, rest - 1, start - 1, pos, dp) % num;
//         else
//             ret = (func(n, rest - 1, start - 1, pos, dp) + 
//                   func(n, rest - 1, start + 1, pos, dp)) % num;
//     }
//     dp[start][rest] = ret;
//     return ret;
    
//     // if(rest == 0) // 剩余步数为0
//     // {
//     //     if(start == pos) // 刚好到位置
//     //         return 1;
//     //     else             // 没有到位置
//     //         return 0;
//     // }
//     // else          // 剩余步数不为零，继续
//     // {
//     //     // 在最左边
//     //     if(start == 1)
//     //     {
//     //         return func(n, rest - 1, start + 1, pos, dp); // 只能往右走
//     //     }
//     //     // 在最右边
//     //     else if(start == n)
//     //     {
//     //         return func(n, rest - 1, start - 1, pos, dp); // 只能往左走
//     //     }
//     //     // 在中间
//     //     else
//     //     {
//     //         return func(n, rest - 1, start - 1, pos, dp) + func(n, rest - 1, start + 1, pos, dp); // 左边 + 右边
//     //     }
//     // }
// }
// int fun(int n, int rest, int start, int pos, vector< vector<int> >& dp)
// {
//     if(n < 2 || start < 1 || start > n || pos < 1 || pos > n || rest < 1)
//         return -1;
//     int count = func(n, rest, start, pos, dp);
//     return count;
// }
// int main()
// {
//     int n = 0, rest = 0, start = 0, pos = 0;
//     cin >> n >> start >> rest >> pos;
//     vector< vector<int> > dp(n + 1, vector<int>(n + 1, -1));

    
//     cout << fun(n, rest, start, pos, dp) << endl;
//     return 0;
// }

// #include <iostream>
// #include <vector>
// using namespace std;
// bool func(vector<int>& a)
// {
//     long long A = 0, B = 1;
//     int len = a.size();
//     for(int i = 0; i < len; i++)
//     {
//         A += a[i];
//         B *= a[i];
//     }
//     if(A > B)
//         return true;
//     return false;
// }
// int main()
// {
//     vector<int> a;
//     int n = 0;
//     cin >> n;
//     a.resize(n);
//     for(int i = 0; i < n; i++)
//     {
//         int num = 0;
//         cin >> num;
//         a[i] = num;
//     }
//     int count = 0;
//     // vector<int> tmp(a.begin(), a.begin() + 3);
//     // for(int i = 0; i < tmp.size(); i++)
//     // {
//     //     cout << tmp[i] << " ";
//     // }
//     // tmp.erase(tmp.begin() + 1);

//     // cout << endl;
//     // for(int i = 0; i < tmp.size(); i++)
//     // {
//     //     cout << tmp[i] << " ";
//     // }cout << endl;
//     for(int i = 2; i <= n; i++)
//     {
//         vector<int> tmp1(a.begin(), a.begin() + i);
//         for(int j = -1; j < i; j++)
//         {
//             vector<int> tmp2(tmp1.begin(), tmp1.end());
//             if(j >= 0)
//             {
//                 tmp2.erase(tmp2.begin() + j);
//             }   
//             if(func(tmp2))
//                     count++;
//         }
//     }
//     cout << count << endl;
//     return 0;
// }
// #include <iostream>
// #include <algorithm>
// #include <vector>
// using namespace std;
// int cont = 0;
// void ContOne(int, vector<int>, int, int, int);
// int main(void)
// {
//     int n = 0, numb = 0, OneCont(0);        //OneCont用来记录1的总个数
//     vector<int> list;
//     cin >> n;
//     while (n--)
//     {
//         cin >> numb;
//         if (numb > 1)
//             list.push_back(numb);
//         else
//             OneCont++;
//     }
//     cont = OneCont - 1; 
//     if (!list.empty())
//     {
//         sort(list.begin(), list.end()); 
//         for (int i = 1; i <= OneCont; i++) ContOne(i, list, 0, i, 1);
//     }
//     cout << cont << endl;
//     return 0;
// }
// void ContOne(int OneNub, vector<int> list, int nowBit, int sum, int mult)
// {
//     for (int i = nowBit; i < list.size(); i++) 
//     {
//         sum += list[i], mult *= list[i];
//         if (sum <= mult) 
//             break;
//         else
//             cont++;
//         ContOne(OneNub, list, i + 1, sum, mult);
//         sum -= list[i], mult /= list[i]; 
//         while (i < list.size() - 1 && list[i] == list[i + 1]) 
//             i++;  
//     }
// }

// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;
// int getresult(int bag[], int begin, int end, int sum, int pro)
// {
//     int result = 0;
//     for(int i = begin; i < end; i++)
//     {
//         sum += bag[i];
//         pro *= bag[i];
//         if(sum > pro)
//         {
//             result += 1 + getresult(bag, i + 1, end, sum, pro);
//         }
//         else if(sum==pro)
//         {
//             result += getresult(bag, i + 1, end, sum, pro);
//         }
//         else 
//         {
//             //break;
//         }
//         sum -= bag[i];
//         pro /= bag[i];
//         while(bag[i+1] == bag[i])
//         { 
//             i++;
//         }
//     }
//     return result;
// }
// int main()
// {
//     int n = 0;
//     while(cin >> n)
//     {
//         int *bag = new int[n];
//         for(int i = 0; i < n; i++)
//         {
//             cin >> bag[i];
//         }
//         sort(bag, bag+n);
//         cout << getresult(bag, 0, n, 0, 1) << endl;
//     }
// }
#include <iostream>
#include <string>
using namespace std;
class Base{
public:
    Base(int j) : i(j) {}

};
//class A
//{
//    void test(float a)
//    {
//        cout << "1";
//    }
//};
//class B : public A{
//    void test(int b)
//    {
//        cout << "2";
//    }
//};
//int main()
//{
//    A *a = new A;
//    B *b = new B;
//    a = b;
//    a.test();
//    return 0;
//}
//class A{
//public:
//    virtual void d()
//    {
//        cout << "d" << endl;
//    }
//};
//class b : public A{
//public:
//
//    void d()
//    {
//        cout << "b" << endl;
//    }
//};
//class c : public A{
//public:
//
//    void d()
//    {
//        cout << "c" << endl;
//    }
//};
//
//void func(A ptr)
//{
//    ptr.d();
//}
//int main()
//{
//    A a;
//    b b1;
//    c c1;
//    func(a);
//    func(b1);
//    func(b1);
//    return 0;
//}