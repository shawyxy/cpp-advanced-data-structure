#include <iostream>

using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
        int count = 0, i = 0;
        while(i < s.size())
        {
            if(s[i] == ' ')
            {
                count++;
            }
            i++;
        }
        int old_sz = s.size();
        int new_sz = old_sz + 2 * count;
        s.resize(new_sz);

        for(int i = new_sz - 1, j = old_sz - 1; j < i; i--, j--)
        {
            if(s[j] == ' ')
            {
                s[i] = '0';
                s[i - 1] = '2';
                s[i - 2] = '%';
                i -= 2;
            }
            else
            {
                s[i] = s[j];
            }
        }
        return s;
    }
};
void test1()
{
    Solution s;
    cout << s.replaceSpace("hello world");
}
//class Solution2 {
//public:
//    string reverseWords(string s) {
//
//
//        int begin = 0, end = s.size() - 1;
//        //整体反转
//        int i = 0;
//
//        while(i < s.size())
//        {
//            if(s.front() == ' ')
//                s.erase(s.begin());
//            if(s.back() == ' ')
//                s.pop_back();
//            i++;
//        }
//        reverse(s.begin(), s.end());
//        //每个单词部分反转
//        i = 0;
//        while(i < s.size())
//        {
//            if(s[i] == ' ')
//            {
//                if(s[i + 1] == ' ')
//                {
//                    s.erase(s.begin() + i);
//                    i++;
//                }
//                else
//                {
//                    end = i - 1;
//                    reverse(s.begin() + begin, s.begin() + end + 1);
//                    begin = i + 1;
//                    i++;
//                }
//
//            }
//            else
//            {
//
//                i++;
//            }
//        }
//        reverse(s.begin() + begin, s.end());
//        return s;
//    }
//};
class Solution2 {
public:
    string reverseWords(string s) {


        int begin = 0, end = s.size() - 1;
        int i = 0;

        while(i < s.size())
        {
            if(s.front() == ' ')
                s.erase(s.begin());
            if(s.back() == ' ')
                s.pop_back();
            i++;

            if(s[i] == ' ')
            {
                if(s[i + 1] == ' ')
                {
                    s.erase(s.begin() + i);

                    s.erase(s.begin() + i + 1);

                    i += 2;
                }
            }
        }
        reverse(s.begin(), s.end());
        //每个单词部分反转
        i = 0;
        while(i < s.size())
        {
            if(s[i] == ' ')
            {
                // if(s[i + 1] == ' ')
                // {
                //     s.erase(s.begin() + i);
                //     i++;
                // }
                // else
                {
                    end = i - 1;
                    reverse(s.begin() + begin, s.begin() + end + 1);
                    begin = i + 1;
                    i++;
                }

            }
            else
            {

                i++;
            }
        }
        reverse(s.begin() + begin, s.end());
        return s;
    }
};
void test2()
{
    Solution2 s;
   cout <<  s.reverseWords(
           "  Bob    Loves  Alice   ");

}
int main()
{
    test2();
    return 0;
}
