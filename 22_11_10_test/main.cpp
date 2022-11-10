//#include <iostream>
//#include <stack>
//#include <vector>
//
//using namespace std;
//
//string& func(stack<int>& st1, stack<int>& st2)
//{
//    string ret;
//    while(!st1.empty() && !st2.empty())
//    {
//        ret.push_back(st2.top());
//        st2.pop();
//        ret.push_back(st1.top());
//        st1.pop();
//    }
//    return ret;
//}
//int main()
//{
//    int T = 0;
//    cin >> T;
//    while(T--)
//    {
//        int n = 0, k = 0;
//        cin >> n >> k;
//        stack<int> st1;
//        stack<int> st2;
//        string ret;
//        string v;
//        v.resize(2 * n);
//        int num = 0;
//        for(int i = 0; i < 2 * n; i++)
//        {
//            cin >> num;
//            v.push_back(num);
//        }
//        while(k--)
//        {
//            v = ret;
//            for(int i = 0; i < n; i++)
//            {
//                st1.push(v[i]);
//            }
//            for(int i = n; i< n * 2; i++)
//            {
//                st2.push(v[i]);
//            }
//            ret = func(st1, st2);
//        }
//
//
//        for(int i = 0; i < ret.size() - 1; i++)
//        {
//            cout << i << " ";
//        }
//        cout << ret[ret.size() - 1];
//    }
//    return 0;
//}

#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    stack<int> st1;
    stack<int> st2;

    int T = 0, n = 0, k = 0;
    cin >> T;
    while(T--)
    {
        cin >> n >> k;

        vector<int> v(2 * n,0);

        for(int i=0;i<n;i++)
        {
            cin>>v[2*i];
            cin>>v[2*i+1];
        }

        while(k--)
        {
            for(int i=0;i<n;i++)
            {
                right.push(v[n+i]);
                left.push(v[i]);
            }

            for(int i=n;i>0;i--)
            {
                v[2*i-1] = right.top();
                right.pop();
                v[2*i-2] = left.top();
                left.pop();
            }
        }

        for(int i=0;i<2*n;i++) cout<<v[i]<<" ";
        cout<<endl;
    }

}
