#include <iostream>
#include <vector>
using namespace std;
void Print(vector<vector<int>>& vv)
{
    for(int i = 0; i < vv.size(); i++)
    {
        for(int j = 0; j < vv[i].size(); j++)
        {
            cout << vv[i][j] << " ";
        }
        cout << endl;
    }
}
void test1()
{
    //同时分配空间和初始化
    vector<vector<int>> vv1(3, vector<int>(5, 0));
    Print(vv1);

    cout << "--------" << endl;
    //先分配空间后初始化
    vector<vector<int>> vv2;
    vv2.resize(3);
    for(int i = 0; i < vv2.size(); i++)
    {
        vv2[i].resize(5, 1);
    }
    Print(vv2);
}
void test2()
{
    int** aa = (int**)malloc(sizeof(int**) * 3);
    for(int i = 0; i < 3; i++)
    {
        //aa[i] = (int*)malloc(sizeof(int*) * 5);
        *(aa + i) = (int*)malloc(sizeof(int*) * 5);
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            aa[i][j] = 2;
        }
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 5; j++)
        {
            cout << aa[i][j] << " ";
        }
        cout << endl;
    }
}
void test3()
{
    size_t sz;
    vector<int> v;
    sz = v.capacity();
    for (int i = 0; i < 100; ++i)
    {
        v.push_back(i);
        if (sz != v.capacity())
        {
            sz = v.capacity();
            cout << "capacity:" << sz << '\n';
        }
    }
}
void test4()
{
    string str = "hello";

    vector<string> v;

    v.push_back(str);
    v.push_back("world");
    v.push_back(string("!!!"));

    for(auto it : v)
    {
        cout << it;
    }
}
int main() {
    test4();
    return 0;
}
