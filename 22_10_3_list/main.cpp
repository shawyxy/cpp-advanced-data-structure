#include "myList.h"
#include <iostream>
#include <list>
using namespace std;

template<class T>
void PrintList(const list<T>& l)
{
    auto it = l.begin();
    while (it != l.end())
    {
        cout << *it << " ";
        ++it;
    }

    cout << endl;
}
void test1()
{
    list<int> ls;
    //测试尾插
    ls.push_back(1);
    ls.push_back(2);
    ls.push_back(3);
    ls.push_back(4);
    list<int>::iterator it;

    PrintList(ls);

    //测试头插
    ls.push_front(4);
    ls.push_front(3);
    ls.push_front(2);
    ls.push_front(1);

    PrintList(ls);


    //测试尾删
    ls.pop_back();
    ls.pop_back();

    PrintList(ls);


    //测试头删
    ls.pop_front();
    ls.pop_front();

    PrintList(ls);


}
void test2()
{
    list<int> ls;
    //尾插
    ls.push_back(1);
    ls.push_back(2);
    ls.push_back(3);
    ls.push_back(4);
    list<int>::iterator it;

    PrintList(ls);


    //测试插入
    //在值为3的元素的位置之前插入99
    it = find(ls.begin(), ls.end(), 3);
    ls.insert(it, 99);
    PrintList(ls);


    //测试删除
    //删除值为99的位置的元素
    it = find(ls.begin(), ls.end(), 99);
    ls.erase(it);
    PrintList(ls);


    //测试交换
    //交换首尾元素的位置
    swap(ls.front(), ls.back());
    PrintList(ls);

}
void test3()
{
    list<int> l1;
    list<int> l2(10, 5);
    PrintList(l2);

    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    list<int> l3(array, array + sizeof(array) / sizeof(array[0]));
    PrintList(l3);
    //拷贝构造
    list<int> l4(l3);
    PrintList(l4);
    //赋值运算符重载/拷贝构造
    l1 = l4;
    PrintList(l1);
}

void test4()
{
    list<int> l2(10, 5);
    PrintList(l2);

    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 };
    list<int> l3(array, array + sizeof(array) / sizeof(array[0]));
    PrintList(l3);
    //拼接整个(Transfer)
    l2.splice(l2.begin(), l3);
    PrintList(l2);
    if(l3.empty())
    {
        cout << "l3为空" << endl;
    }

}
int main()
{
//    test1();
//    test2();
//    test3();
//    test4();
//    cout << "------------------------" << endl;
    xy::test1();
    cout << "h" << endl;
    xy::test2();
    cout << "h" << endl;

//    xy::test3();
//    cout << "h" << endl;
//
//    xy::test4();
//    cout << "h" << endl;

    return 0;
}