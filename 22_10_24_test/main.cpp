// #include<iostream>
// #include <math.h>
// #include <string>
// using namespace std;
// int main()
// {
//     int n = 0;
//     cin >> n;
//     char op = ' ';
//     int a = 0, b = 0;
//     string str;
//     str.resize(1024);
//     int max = 0;
//     for (int i = 0; i < n; i++)
//     {
//             cin >> op >> a >> b;
//             if (a >= max)
//             {
//                 max = a;
//             }
//             if (b >= max)
//             {
//                 max = b;
//             }
//     }
//     str[0] = 0;
//     for (int i = 1; i <= n; i++)
//     {
//         str[i] = pow(2, i - 1) + str[i - 1];
//         if (max - str[i] < 0)
//         {
//             cout << i;
//             return 0;
//         }
//     }
//     return 0;
// }
#include <iostream>
#include <vector>
using namespace std;
int func(int n, int rest, int start, int pos, vector< vector<int> >& dp)
{
    if(rest == 0)
    {
        if(start == pos)
        {
            if(dp[start][rest] == -1)
            //     dp[start][rest] = 1;
            // else
                return dp[start][rest] = 1;
        }
        else
        {
            if(dp[start][rest] == -1)
            //     dp[start][rest] = 0;
            //  else
                return dp[start][rest] = 0;
        }
    }
    else
    {
        if(start == 1)
        {
            if(dp[start][rest] == -1)
                dp[start][rest] = dp[start + 1][rest--];
            else
                return dp[start + 1][rest--];
        }
        else if(start == n)
        {
            if(dp[start][rest] == -1)
                dp[start][rest] = dp[start - 1][rest--];
            else
                return dp[start - 1][rest--];
        }
        else
        {
            if(dp[start][rest] == -1)
                dp[start][rest] = dp[start - 1][rest--] + dp[start + 1][rest--];
            else
                return dp[start - 1][rest--] + dp[start + 1][rest--];
        }
    }
    
    // if(rest == 0) // 剩余步数为0
    // {
    //     if(start == pos) // 刚好到位置
    //         return 1;
    //     else             // 没有到位置
    //         return 0;
    // }
    // else          // 剩余步数不为零，继续
    // {
    //     // 在最左边
    //     if(start == 1)
    //     {
    //         return func(n, rest - 1, start + 1, pos, dp); // 只能往右走
    //     }
    //     // 在最右边
    //     else if(start == n)
    //     {
    //         return func(n, rest - 1, start - 1, pos, dp); // 只能往左走
    //     }
    //     // 在中间
    //     else
    //     {
    //         return func(n, rest - 1, start - 1, pos, dp) + func(n, rest - 1, start + 1, pos, dp); // 左边 + 右边
    //     }
    // }
}
int main()
{
    int n = 0, rest = 0, start = 0, pos = 0;
    cin >> n >> start >> rest >> pos;
    vector< vector<int> > dp(n + 1, vector<int>(n + 1, -1));
    int count = func(n, rest, start, pos, dp);
    cout << count << endl;
    return 0;
}