#include "Myvector.h"

//void test1()
//{
////    xy::vector<int> v;
////    cout << v.size();
//    xy::vector<int> v;
//    //v.push_back();
////    for(auto& a : v)
////    {
////        cout << *a << " ";
////    }
////    cout << endl;
//}
void test1()
{
    xy::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.Print();

    v.pop_back();
    v.Print();
}
void TestXyVector1()
{
    xy::vector<int> v1;
    xy::vector<int> v2(10, 5);

    int array[] = { 1,2,3,4,5 };
    xy::vector<int> v3(array, array+sizeof(array)/sizeof(array[0]));

    xy::vector<int> v4(v3);

    for (size_t i = 0; i < v2.size(); ++i)
    {
        cout << v2[i] << " ";
    }
    cout << endl;

    auto it = v3.begin();
    while (it != v3.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    for (auto e : v4)
    {
        cout << e << " ";
    }
    cout << endl;
}

void TestXyVector2()
{
    xy::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;
    cout << v[0] << endl;
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;

    v.pop_back();
    v.pop_back();
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;

    v.insert(0, 0);
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;

    v.erase(v.begin() + 1);
    for (auto e : v)
    {
        cout << e << " ";
    }
    cout << endl;
}


void test2()
{
    xy::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.Print();
    cout << v.capacity() << endl;


    v.insert(v.begin()+3,9);
    v.Print();
    cout << v.capacity() << endl;

}

int main()
{
    //test2();

    TestXyVector1();
    //cout << "-------------"<< endl;
    //TestXyVector2();
    return 0;
}