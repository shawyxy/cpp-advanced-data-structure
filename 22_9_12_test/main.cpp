#include <iostream>
#include <string>
using namespace  std;
void test9()
{
    string s1 = "hello";
    cout << s1.substr(1,7) << endl;
}
void test10()
{
    string s1 = "hello";
    string s2 = s1 + " world";
    cout << s2 << endl;
}
void test11()
{
    string s1;
    cin >> s1;
    cout << s1 << endl;
}
void test12()
{
    string s1 = "hello";
    getline(cin, s1);
    cout << s1 << endl;
}
void test13()
{
    string s1 = "hello";
    string s2 = "world";
    if(s1 == s2)
        cout << "s1 == s2" << endl;
    if(s1 < s2)
        cout << "s1 < s2" << endl;
    if(s1 > s2)
        cout << "s1 > s2" << endl;
    if(s1 >= s2)
        cout << "s1 >= s2" << endl;
    if(s1 <= s2)
        cout << "s1 <= s2" << endl;
    if(s1 != s2)
        cout << "s1 != s2" << endl;
}
void test14()
{
    string s = "hello";
    std::reverse(s.begin(), s.end());
    cout << s << endl;
}
//class Solution {
//public:
//    string reverseOnlyLetters(string s) {
//        if(s.empty())
//            return s;
//        size_t begin = 0, end = s.size() - 1;
//        while(begin < end)
//        {
//            while(!isalpha(s[begin]) && begin < end)
//                begin++;
//            while(!isalpha(s[end]) && begin < end)
//                end--;
//
//            swap(s[begin], s[end]);
//            begin++;
//            end--;
//        }
//        return s;
//    }
//};
//int main()
//{
//    //test14();
//    Solution s;
//    cout <<  s.reverseOnlyLetters("7_28]");
//    return 0;
//}
#include <iostream>
#include <string>
using namespace std;

int main(){
    string s = "hello world opop";
    while(s.rfind(' '))
}
