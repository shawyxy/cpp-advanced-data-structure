#include <iostream>
using namespace std;
#include <vector>
#include "OpenHashTable.h"

void OpenHashTableTest1()
{
    int a[] = { 1, 11, 4, 15, 26, 7, 44,55,99,78 };
    HashTable<int, int> ht;
    for (auto e : a)
    {
        ht.Insert(make_pair(e, e));
    }
    ht.Print();
    ht.Erase(99);
    cout << "---------------" << endl;
    ht.Print();

    cout << "---------------" << endl;
    cout << (ht.Find(26)->_kv.first) << endl;

}
int main()
{
    OpenHashTableTest1();
}
