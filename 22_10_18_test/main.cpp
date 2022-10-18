#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    int flag1 = 0, flag2 = 0, n = 0;
    cin >> n;
    if(n == 0)
    {
        cout << "none" << endl;
        return -1;
    }
    int count = 0;
    str.resize(2 * n + 1);
    for(int i = 1; i <= n + 1; i++)
    {
        string tmp;
        getline(cin, tmp);        count++;

        str[i * 2 - 1] = tmp[0];
        str[i * 2] = tmp.size() - '0';
    }
    cout << count << endl;

    for(int i = 1; i < n; )
    {
        if(str[2 * i - 1] <= str[2 * i + 1])
        {
            i++;
            if(i == 2)
                flag1 = 1;
        }
        else
        {
            break;
        }
    }
    for(int i = 1; i < n; )
    {
        if(str[2 * i] <= str[2 * (i + 1)])
        {
            i++;
            if(i == 2)
                flag2 = 1;
        }
        else
        {
            break;
        }
    }
    
    if(flag1 == 1 && flag2 == 0)
    {
        cout << "lexicographically" << endl;
    }
    else if(flag1 == 0 && flag2 == 1)
    {
        cout << "lengths" << endl;
    }
    else if(flag1 == 1 && flag2 == 1)
    {
        cout << "both" << endl;
    }
    else
    {
        cout << "none" << endl;
    }
    return 0;
}
//#include <iostream>
//using namespace std;
//int main()
//{
//
//    int a = 0, b = 0, tmp = 0;
//    cin >> a >> b;
//    int num1 = a, num2 = b;
//    while(a % b)
//    {
//        tmp = a % b;
//        a = b;
//        b = tmp;
//    }
//
//    cout << (num1 * num2) / b << endl;
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//
//// 以普通函数的方式实现自定义排序规则
//bool mycomp(int i, int j)
//{
//    return (i < j);
//}
//// 以函数对象的方式实现自定义排序规则
//// 实际上就是仿函数
//class mycomp2
//{
//public:
//    bool operator() (int i, int j)
//    {
//        return (i < j);
//    }
//};
//// 对Less类模板按照指针方式特化
//template<>
//struct less<char*>
//{
//    bool operator()(char* x, char* y) const
//    {
//        return *x < *y;
//    }
//};
//int main()
//{
//    // 直接调用sort,默认升序
//    vector<int> v1 = {9, 5, 2, 1, 3, 0, 8, 6, 7, 4};
//    sort(v1.begin(), v1.end());
//    for(int i = 0; i < v1.size(); i++)
//    {
//        cout << v1[i] << " ";
//    }
//    cout << endl;
//    // 直接调用sort,传入greater<T>(),指定降序排序
//    // 这是一个用类实现的伪函数
//    vector<int> v2 = {9, 5, 2, 1, 3, 0, 8, 6, 7, 4};
//    sort(v2.begin(), v2.end(), greater<int>());
//    for(int i = 0; i < v2.size(); i++)
//    {
//        cout << v2[i] << " ";
//    }
//    cout << endl;
//    // 调用自定义的比较函数,升序
//    vector<int> v3 = {9, 5, 2, 1, 3, 0, 8, 6, 7, 4};
//    sort(v3.begin(), v3.end(), mycomp);
//    for(int i = 0; i < v3.size(); i++)
//    {
//        cout << v3[i] << " ";
//    }
//    cout << endl;
//    // 调用自定义的mycomp2类,升序
//    // 实际上重载了()操作符,它是一个仿函数
//    vector<int> v4 = {9, 5, 2, 1, 3, 0, 8, 6, 7, 4};
//    sort(v4.begin(), v4.end(), mycomp2());
//    for(int i = 0; i < v4.size(); i++)
//    {
//        cout << v4[i] << " ";
//    }
//    cout << endl;
//
////    char str1[] = "1234";
////    char str2[] = "6789";
//    vector<char*> a = {"5678", "1234"};
//
//    sort(a.begin(), a.end(),less<char*>());
//    for(int i = 0; i < a.size(); i++)
//    {
//        cout << a[i] << " ";
//    }
//    cout << endl;
//    return 0;
//}
//template<class T1, class T2>
//class AA
//{
//public:
//    //构造函数
//    AA()
//    {
//        cout << "AA<T1, T2>" << endl;
//    }
//private:
//    T1 _t1;
//    T2 _t2;
//};
//template<>
//class AA<int, float>
//{
//public:
//    //构造函数
//    AA()
//    {
//        cout << "AA<int, float>" << endl;
//    }
//private:
//    int _t1;
//    float _t2;
//};
//
////两个参数偏特化为指针类型
//template<class T1, class T2>
//class AA<T1&, T2&>
//{
//public:
//// 构造函数
//AA()
//{
//    cout << "AA<T1&, T2&>" << endl;
//}
//private:
//T1 _t1;
//T2 _t2;
//};
////两个参数偏特化为引用类型
//template<class T1, class T2>
//class AA<T1*, T2*>
//{
//public:
//// 构造函数
//AA()
//{
//    cout << "AA<T1*, T2*>" << endl;
//}
//private:
//T1 _t1;
//T2 _t2;
//};
//
//int main()
//{
//    AA<int*, double*> a3;
//    AA<int&, float&> a4;
//
//    return 0;
//}
//bool Compare(T x, T y)
//{
//    return x == y;
//}
//int main() {
//    cout << Compare(1, 1) << endl;		// 1
//    cout << Compare(1.1, 1.1) << endl;	// 1
//
//    char str1[] = "1";
//    char str2[] = "1";
//
//    cout << Compare(str1, str2) << endl;	// 0
//    return 0;
//}
