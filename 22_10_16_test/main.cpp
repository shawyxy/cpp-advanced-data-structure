#include <iostream>
#include <string>
#include <algorithm>
#include <list>
#include <queue>
#include <stack>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(int i=0;i<tokens.size();i++)
        {
            if(tokens[i]=="+"||tokens[i]=="-"||tokens[i]=="*"||tokens[i]=="/")
            {
                int num1=st.top();
                st.pop();
                int num2=st.top();
                st.pop();
                if(tokens[i]=="+") st.push(num2+num1);
                if(tokens[i]=="-") st.push(num2-num1);
                if(tokens[i]=="*") st.push((long)num2*(long)num1);
                if(tokens[i]=="/") st.push(num2/num1);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        return st.top();
    }
};
int main()
{
    Solution s;
    vector<string> vs;
    vs.push_back("hello");
    s.evalRPN(vs);
    return 0;
}
//int main()
//
//{
//
//    int array[] = { 1, 2, 3, 4, 0, 5, 6, 7, 8, 9 };
//
//    int n = sizeof(array) / sizeof(int);
//
//    list<int> mylist(array, array+n);
//
//    auto it = mylist.begin();
//
//    while (it != mylist.end())
//
//    {
//
//        if(* it != 0)
//
//            cout<<* it<<" ";
//
//        else
//
//            it = mylist.erase(it);
//
//        ++it;
//
//    }
//
//    return 0;
//
//}
//int main()
//
//{
//
//    queue<char> Q;
//
//    char x,y;
//
//    x='n';y='g';
//
//    Q.push(x);Q.push('i');Q.push(y);
//
//    Q.pop();Q.push('r');Q.push('t');Q.push(x);
//
//    Q.pop();Q.push('s');
//
//    while(!Q.empty())
//
//    {
//
//        x = Q.front();
//
//        Q.pop();
//
//        cout<<x;
//
//    };
//
//    cout<<y;
//
//}
//class A
//
//{
//
//public:
//
//    A ():m_iVal(0){test();}
//
//    virtual void func() { std::cout<<m_iVal<<" ";}
//
//    void test(){func();}
//
//public:
//
//    int m_iVal;
//
//};
//
//
//
//class B : public A
//
//{
//
//public:
//
//    B(){test();}
//
//    virtual void func()
//
//    {
//
//        ++m_iVal;
//
//        std::cout<<m_iVal<< " ";
//
//    }
//
//};
//
//
//
//int main(int argc ,char* argv[])
//
//{
//
//    A*p = new B;
//
//    p->test();
//
//    return 0;
//
//}
//class Solution {
//public:
//    void reverseSubstr(string& s, int begin, int end)
//    {
//        while (begin < end)
//        {
//            swap(s[begin++], s[end--]);
//        }
//    }
//    string& reverseWords(string s) {
//        int begin = 0, end = 0, len = s.size();
//        while(end < len)
//        {
//            while(end < len && s[end] != ' ')
//            {
//                end++;
//            }
//            reverseSubstr(s, begin, end - 1);
//            begin = end + 1;
//            end++;
//        }
//
//        return s;
//    }
//};
//
//int main()
//{
//    Solution s;
//    cout << s.reverseWords("Let's take LeetCode contest");
//    return 0;
//}