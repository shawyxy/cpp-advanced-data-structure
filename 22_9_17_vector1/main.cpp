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
void test2()
{
    xy::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.Print();
    cout << v.capacity() << endl;


    v.insert(4,9);
    v.Print();
    cout << v.capacity() << endl;

}

int main()
{
    test2();
    return 0;
}