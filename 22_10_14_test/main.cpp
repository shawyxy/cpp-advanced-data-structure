#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    int n = 0;
    vector<int> a;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int tmp = 0;
        cin >> tmp;
        a.push_back(tmp);
    }
    int min = 0;
//    for(int i = 0; i < n; i++)
//    {
//        if(a[i] < min)
//            min = a[i];
//    }
    int res = INT_MIN;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] <= 0)
            continue;
        int tmp = 0;
        for(int j = i; j < a.size(); j++)
        {
            tmp += a[j];
            if(res < tmp) res = tmp;
        }
    }
    sort(a.begin(), a.end());
    int ret =  max(a[a.size()-1], res);
    cout << ret << endl;

    return 0;
}
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//    int n = 0;
//    vector<int> a;
//    cin >> n;
//    for(int i = 0; i < n; i++)
//    {
//        int tmp = 0;
//        cin >> tmp;
//        a.push_back(tmp);
//    }
//    int begin = 0, end = 0;
//    int min = 0;
//    for(int i = 0; i < n; i++)
//    {
//        if(a[i] < min)
//            min = a[i];
//    }
//    int ret = min;
//    int sum = 0;
//    while(begin < a.size() && end < a.size())
//    {
//
//        while(a[begin] <= 0 && begin < a.size())
//        {
//            begin++;
//        }
//        if(begin > end)
//            end = begin;
//        while(a[end] > 0 && end < a.size())
//        {
//            sum += a[end];
//            end++;
//        }
//        begin = end;
//        if(begin > 0 && ret < sum)
//        {
//            ret = sum;
//        }
//        sum = 0;
//
//    }
////    if(ret != min && ret < sum)
////    {
////        ret = sum;
////    }
//
//
//    cout << ret << endl;
//
//    return 0;
//}
//#include <iostream>
//#include <string>
//using namespace std;
//
//bool func(string& str)
//{
//    int left = 0, right = str.size() - 1;
//    while(left < right)
//    {
//        if(str[left] == str[right])
//        {
//            left++;
//            right--;
//        }
//        else
//        {
//            return false;
//        }
//    }
//    return true;
//}
//int main()
//{
//    string strA, strB;
//    getline(cin, strA);
//    getline(cin, strB);
//    int count = 0;
//    for(int i = 0; i < strA.size(); i++)
//    {
//        string stra = strA;
//        string tmp = stra.insert(i, strB);
//        if(func(tmp))
//        {
//            count++;
//        }
//    }
//    cout << count << endl;
//    return 0;
//}