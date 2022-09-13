#include <iostream>
#include <string>
using namespace std;
class Solution1 {
public:

    void reverseSubstr(string& s, int begin, int end)
    {
        while (begin < end)
        {
            swap(s[begin++], s[end--]);
        }
    }
    string reverseStr(string s, int k) {
        int num = s.size(), count = 0;
        int begin = 0, end = k - 1;

        while (num >= 0)
        {
            if (num < k)
            {
                reverseSubstr(s, begin + (2 * k) * count, s.size() - 1);
            }
            else
//            if (num < 2 * k || num >= k)
            {
                reverseSubstr(s, begin + (2 * k) * count, end + (2 * k) * count);
                count++;

            }
            num -= (2 * k);
        }
        return s;
    }
};

class Solution3 {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size(), len2 = num2.size();
        int len = len1 + len2;

        int count = 0;
        //一定要初始化新串的值,否则后面会出现随机值
        string ret(len, '0');
        for(int i = len1 - 1; i >= 0; i--)
        {
            for(int j = len2 - 1; j >= 0; j--)
            {
                //tmp是当前位之和
                int tmp = (num1[i] - '0') * (num2[j] - '0') + (ret[i + j + 1] - '0');
                //当前的最后一位,得
                ret[i + j + 1] = tmp % 10 + '0';
                ret[i + j] += tmp / 10;
            }
        }
        for(int i = 0; i < len; i++)
        {
            if(ret[i] != '0')
                return ret.substr(i);
        }
        return "0";
    }
};
//int main() {
//    //Solution1 s;
//    //cout << s.reverseStr("abcdefg", 8);
////Let's take LeetCode contest
//    //Solution2 s2;
////    cout << s2.reverseWords("Let's take LeetCode contest");
//    //cout << s2.reverseWords("God Ding");
//
//    Solution3 s3;
//    cout << s3.multiply("123", "456") << endl;
//    return 0;
//}
//void func(string s)
//{
//    char a[128] = { 0 };
//    int len = s.size();
//    for(int i = 0; i < len; i++)
//    {
//        a[s[i] - '0']++;
//    }
//    for(int i = 0; i < 128; i++)
//    {
//        if(a[i] == 1)
//        {
//            cout << a[i] << endl;
//            return;
//        }
//    }
//    cout << "-1" << endl;
//}
#include<iostream>
#include<string>
#include<vector>

using namespace std;
//
int main(){
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++)
    {
        if(s.find_first_of(s[i]) == s.find_last_of(s[i]))
        {
            cout << s[i] << endl;
            break;
        }
        if(i == s.size() - 1)
            cout << "-1" << endl;
    }
    return 0;
}