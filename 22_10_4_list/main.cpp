#include "MyList.h"
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
void test5()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    list<int>::iterator pos = find(lt.begin(), lt.end(), 2);
    lt.insert(pos, 99); //在2的位置插入99
    PrintList(lt);//1 99 2 3
    pos = find(lt.begin(), lt.end(), 3);
    lt.insert(pos, 2, 8); //在3的位置插入2个8
    PrintList(lt);//1 9 2 8 8 3
    vector<int> v(2, 7);
    pos = find(lt.begin(), lt.end(), 1);
    lt.insert(pos, v.begin(), v.end()); //在1的位置插入2个7
    PrintList(lt);
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
void test6()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);

    list<int>::iterator pos = find(lt.begin(), lt.end(), 2);
    lt.erase(pos); //删除2
    PrintList(lt);
    pos = find(lt.begin(), lt.end(), 4);
    lt.erase(pos, lt.end()); //删除3及其之后的元素
    PrintList(lt);
}
void test7()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    cout << lt.size() << endl;
}
void test8()
{
    list<int> lt(5, 7);
    PrintList(lt);
    lt.resize(7, 6); //将size扩大为6，扩大的值为6
    PrintList(lt);

    lt.resize(2); //将size缩小为2
    PrintList(lt);

}
void test9()
{
    list<int> lt1;
    lt1.push_back(1);

    list<int> lt2;
    cout << lt1.empty() << endl;
    cout << lt2.empty() << endl;
}
void test10()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);

    lt.clear();
    cout << lt.empty() << endl;
}
void test11()
{
    list<int> lt;
    lt.push_back(3);
    lt.push_back(2);
    lt.push_back(1);

    lt.sort();
    PrintList(lt);
}
void test12()
{
    list<int> lt1(3, 2);
    list<int> lt2(3, 6);
    lt1.splice(lt1.begin(), lt2); //将容器lt2拼接到容器lt1的开头
    PrintList(lt1);

    list<int> lt3(3, 3);
    list<int> lt4(3, 7);
    list<int>::iterator pos = ++lt3.begin();
    lt3.splice(pos, lt4, lt4.begin()); //将容器lt4的第一个数据拼接到容器lt3的第二个位置pos
    PrintList(lt3);


    list<int> lt5(3, 4);
    list<int> lt6(3, 8);
    lt5.splice(lt5.begin(), lt6, lt6.begin(), lt6.end()); //将容器lt6的指定迭代器区间内的数据拼接到容器lt5的开头
    PrintList(lt5);
}
void test13()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(2);
    lt.push_back(4);
    PrintList(lt);

    lt.remove(2);
    PrintList(lt);
}
bool func(int& val)
{
    return val == 2;
}
void test14()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(2);
    lt.push_back(4);
    PrintList(lt);

    lt.remove_if(func);

    PrintList(lt);
}
void test15()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(2);
    lt.push_back(4);
    PrintList(lt);

    lt.unique();

    PrintList(lt);
}
void test16()
{
    list<int> lt1;
    lt1.push_back(3);
    lt1.push_back(8);
    lt1.push_back(1);
    lt1.sort(); //将容器lt1排为升序

    list<int> lt2;
    lt2.push_back(6);
    lt2.push_back(2);
    lt2.push_back(9);
    lt2.push_back(5);
    lt2.sort(); //将容器lt2排为升序

    lt1.merge(lt2); //将lt2合并到lt1当中

    PrintList(lt1);
}
void test17()
{
    list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    PrintList(lt);

    lt.reverse();

    PrintList(lt);
}
void test18()
{
    list<char> lt(3, 'a');
    lt.assign(3, 'b'); //将新内容分配给容器，替换其当前内容
    PrintList(lt);
    string s("hello world");
    lt.assign(s.begin(), s.end()); //将新内容分配给容器，替换其当前内容
    PrintList(lt);
}
void test19()
{
    list<int> lt1 = {1, 2, 3, 4};
    list<int> lt2 = {5, 6, 7, 8};
    lt1.swap(lt2);

    PrintList(lt1);
    PrintList(lt2);
}
void MyListTest()
{
    xy::test1();
    cout << "------------------------" << endl;
    xy::test2();
    cout << "------------------------" << endl;
    xy::test3();
}
void STL_test()
{
    test1();
    cout << "------------------------" << endl;
    test2();
    cout << "------------------------" << endl;
    test3();
    cout << "------------------------" << endl;
    test4();
    cout << "------------------------" << endl;
    test5();
    cout << "------------------------" << endl;
    test6();
    cout << "------------------------" << endl;
    test8();
    cout << "------------------------" << endl;
    test9();
    cout << "------------------------" << endl;
    test11();
    cout << "------------------------" << endl;
    test12();
    cout << "------------------------" << endl;
    test13();
    cout << "------------------------" << endl;
    test15();
    cout << "------------------------" << endl;
    test19();
    cout << "------------------------" << endl;
}
int main()
{
    MyListTest();
    return 0;
}