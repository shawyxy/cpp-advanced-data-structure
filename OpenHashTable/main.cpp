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
void OpenHashTableTest2()
{
    int a[] = { 1, 11, 4, 15, 26, 7, 44,55,99,78 };
    HashTable<int, int> ht;
    for (auto e : a)
    {
        ht.Insert(make_pair(e, e));
    }
    ht.Print();

    ht.Insert(make_pair(22,22));
    cout << endl;

    ht.Print();

    ht.Erase(44);
    ht.Erase(4);
    cout << endl;


    ht.Print();

}

void OpenHashTableTest3()
{
    string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };

    HashTable<string, int> countHT;
    //HashTable<string, int>> countHT;
    for (auto& str : arr)
    {
        auto ptr = countHT.Find(str);
        if (ptr)
        {
            ptr->_kv.second++;
        }
        else
        {
            countHT.Insert(make_pair(str, 1));
        }
    }
    countHT.Print2();
}

void OpenHashTableTest4()
{

    int n = 9000000;
    vector<int> v;
    v.reserve(n);
    srand(time(0));
    for (int i = 0; i < n; ++i)
    {
        //v.push_back(i);
        v.push_back(rand() + i);    // 重复少
        //v.push_back(rand());      // 重复多
    }

    size_t begin1 = clock();
    HashTable<int, int> ht;
    for (auto e : v)
    {
        ht.Insert(make_pair(e, e));
    }
    size_t end1 = clock();

    cout << "数据个数:" << ht.Size() << endl;
    cout << "表的长度:" << ht.TablesSize() << endl;
    cout << "桶的个数:" << ht.BucketNum() << endl;
    cout << "平均每个桶的长度:" << (double)ht.Size() / (double)ht.BucketNum() << endl;
    cout << "最长的桶的长度:" << ht.MaxBucketLenth() << endl;
    cout << "负载因子:" << (double)ht.Size() / (double)ht.TablesSize() << endl;
}

int main()
{
    OpenHashTableTest4();
}
