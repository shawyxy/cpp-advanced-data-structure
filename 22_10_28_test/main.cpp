#include <iostream>
using namespace std;
class Base
{
public:
    virtual void Func()
    {
        cout << "Func()" << endl;
    }
private:
    int _b = 1;
};
int main()
{
    Base b;
    cout << sizeof(b) << endl; //8
    return 0;
}
//#include <vector>
//class Solution {
//public:
//    vector<vector<int>> generate(int numRows) {
//        vector<vector<int> > a(numRows);
//        for(int i = 0; i < numRows; i++)
//        {
//            a[i].resize(i + 1);
//
//            a[i][i] = 1;
//            a[0][i] = 1;
//        }
//
//        for(int i = 0; i < numRows; i++)
//        {
//            for(int j = 1; j < i; j++)
//            {
//                a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
//            }
//        }
//
//        return a;
//
//    }
//};
//int main()
//{
//    Solution s;
//    s.generate(5);
//    vector<vector<int>> v;
//    for(int i = 0; i < v.size(); i++)
//    {
//        for(int j = 0; j < v[i].size(); j++)
//        {
//            cout << v[i][j] << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}
