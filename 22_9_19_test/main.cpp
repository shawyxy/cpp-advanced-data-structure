#include <iostream>
#include <vector>
using namespace std;

void test1()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    cout << "size:" << v.size() << endl;
    cout << "capacity" << v.capacity() << endl;
    cout << "front:" << v.front() << endl;
    cout << "back:" << v.back() << endl;
    cout << "v[0]:" << v[0] << endl;
    cout << "v:";
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

    v.insert(v.begin(), 0);
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
    vector<int> v1;
    vector<int> v2(10, 5);

    int array[] = { 1,2,3,4,5 };
    vector<int> v3(array, array+sizeof(array)/sizeof(array[0]));

    vector<int> v4(v3);
    cout << "v2:";
    for (size_t i = 0; i < v2.size(); ++i)
    {
        cout << v2[i] << " ";
    }
    cout << endl;

    cout << "v3:";
    auto it = v3.begin();
    while (it != v3.end())
    {
        cout << *it << " ";
        ++it;
    }
    cout << endl;

    cout << "v4:";
    for (auto e : v4)
    {
        cout << e << " ";
    }
    cout << endl;
}

int main() {
    test1();
    cout << "-----------" << endl;
    test2();
    return 0;
}
