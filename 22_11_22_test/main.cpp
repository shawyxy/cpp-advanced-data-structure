//#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <map>
#include <set>
#include <string>
using namespace std;
void set_test1()
{
    set<int> s1;            // 构造int类型的set容器

    set<int> s2(s1);        // 用s1拷贝构造s2

    string str = "hello world";
    set<char> s3(str.begin(), str.end()); // 迭代器区间构造

    set <int, greater<int>> s4; // 构造int类型,比较方式为大于的set容器
}
void set_test2()
{
    set<int> s;
    s.insert(1);
    s.insert(1);        // set去重
    s.insert(2);
    s.insert(5);
    s.insert(4);
    s.insert(3);
    cout << "使用范围for遍历set元素(有序):" << endl;
    for(auto e : s)
    {
        cout << e << endl;
    }
    cout << endl;

    cout << "删除值为1的元素,使用正向迭代器遍历set元素:" << endl;
    s.erase(1);
    set<int>::iterator it = s.begin();
    while(it != s.end())
    {
        cout << *it << " "; // 使用'*'操作符访问set元素
        ++it;
    }
    cout << endl;

    cout << "容器中4的个数:" << endl;
    cout << s.count(4) << endl;

    cout << "容器清空,判空:" << endl;

    s.clear();
    cout << s.empty() << endl;

    cout << "交换两个容器的数据" << endl;
    set<int> tmp = { 7, 8, 9, 10}; // 使用数组初始化set容器
    s.swap(tmp);

    cout << "使用反向迭代器遍历set元素:" << endl;
    set<int>::reverse_iterator rit = s.rbegin();
    while(rit != s.rend())
    {
        cout << *rit << " ";
        ++rit;
    }
    cout << endl;
}
void set_test3()
{
    multiset<int> ms = {8, 7, 7, 6, 6, 5, 4, 3, 2};

    for(auto e : ms)
    {
        cout << e << " ";
    }
    cout << endl;

    cout << "删除7:" << endl;
    ms.erase(7);
    for(auto e : ms)
    {
        cout << e << " ";
    }
    cout << endl;

    cout << "找到6的位置:" << endl;
    multiset<int>::iterator it = ms.find(6);

    cout << "查看第一个6前面元素的值:" << endl;
    cout << *(--it) << endl;
}
void map_test1()
{
    map<int, string> m1;            // 构造键值对为<int, string>的map容器

    map<int, string> m2(m1);        // 用m1拷贝构造m2

    map<int, string> m3(m2.begin(), m2.end()); // 迭代器区间构造

    map <int, string, greater<int>> m4; //比较方式为大于的map容器
}
void map_test2()
{
    map<int, string> m;

    m.insert(pair<int, string>(1, "一"));
    m.insert(pair<int, string>(4, "四"));
    m.insert(pair<int, string>(2, "二"));
    m.insert(pair<int, string>(3, "三"));

    for(auto e : m)
    {
        cout << "<" << e.first << ", " << e.second << ">" << endl;
    }
    cout << endl;
}
void map_test3()
{
    map<int, string> m;

    m.insert(make_pair(1, "一"));
    m.insert(make_pair(4, "四"));
    m.insert(make_pair(2, "二"));
    m.insert(make_pair(3, "三"));

    for(auto e : m)
    {
        cout << "<" << e.first << ", " << e.second << ">" << endl;
    }
    cout << endl;
}
void map_test4()
{
    map<int, string> m;

    m.insert(make_pair(1, "一"));
    m.insert(make_pair(4, "四"));
    m.insert(make_pair(2, "二"));
    m.insert(make_pair(3, "三"));

    auto pos = m.find(3);
    if(pos != m.end())
    {
        cout << pos->second << endl;
    }
}
void map_test5()
{
    map<int, string> m;

    m.insert(make_pair(1, "一"));
    m.insert(make_pair(4, "四"));
    m.insert(make_pair(2, "二"));
    m.insert(make_pair(3, "三"));

    cout << "找到key=1的元素的value:" << endl;
    cout << m[1] << endl;

    cout << "修改key=1的元素的value为\"one\":" << endl;
    m[1] = "one";

    for(auto e : m)
    {
        cout << "<" << e.first << ", " << e.second << ">" << endl;
    }
    cout << endl;
}
void map_test6()
{
    map<int, string> m;

    m.insert(make_pair(1, "一"));
    m.insert(make_pair(4, "四"));
    m.insert(make_pair(2, "二"));
    m.insert(make_pair(3, "三"));

    for(auto e : m)
    {
        cout << "<" << e.first << ", " << e.second << ">" << endl;
    }

    cout << endl;
    cout << "删除key为1的元素:" << endl;
    m.erase(1);
    cout << "使用范围for正向遍历:" << endl;
    for(auto e : m)
    {
        cout << "<" << e.first << ", " << e.second << ">" << endl;
    }
    cout << endl;

    cout << "插入:<1, \"one\">" << endl;
    m.insert(make_pair(1, "one"));
    cout << "使用反向迭代器遍历:" << endl;
    map<int, string>::reverse_iterator rit = m.rbegin();
    while(rit != m.rend())
    {
        cout << "<" << rit->first << ", " << rit->second << ">" << " ";
        ++rit;
        cout << endl;
    }

    cout << "清空map,";
    m.clear();
    cout << "判空:";
    cout << m.empty() << endl;

}
void map_test7()
{
    multimap<int, string> mm;

    mm.insert(make_pair(1, "一"));
    mm.insert(make_pair(4, "四"));
    mm.insert(make_pair(2, "二"));
    mm.insert(make_pair(2, "二"));
    mm.insert(make_pair(2, "二"));
    mm.insert(make_pair(2, "二"));
    mm.insert(make_pair(3, "三"));

    for(auto e : mm)
    {
        cout << "<" << e.first << ", " << e.second << ">" << endl;
    }
    cout << endl;

    cout << "找到第一个key=2的元素的上一个元素" << endl;
    auto pos = mm.find(2);
    cout << "<" << (--pos)->first << ", " << pos->second << ">" << endl;

    cout << "删除所有key=2的元素" << endl;
    mm.erase(2);
    for(auto e : mm)
    {
        cout << "<" << e.first << ", " << e.second << ">" << endl;
    }
    cout << endl;

}
int main()
{
	//set_test1();
    //set_test2();
    //set_test3();
    //map_test2();
    //map_test3();
    //map_test4();
    //map_test5();
    //map_test6();
    map_test7();

    return 0;
}