//#include<iostream>
//#include <algorithm>
//using namespace std;
//const int N = 1024;
//int dp[N][N] = { 0 };
//int func(int n)
//{
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//            if (i == 1 || j == 1)
//                dp[i][j] = 1;
//            for(int k = 0; k * i <= j; k++)
//                dp[i][j] = max(dp[i][j], dp[i - 1][j - i * k] + i * k);
//        }
//    }
//    return dp[n][n];
//}
//int main()
//{
//    int n = 0;   
//    while (cin >> n) 
//    {
//        cout << func(n) << endl;
//    }
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//
//using namespace std;
//
//const int N = 64;
//int n;
//int dp[N][N];
//int func(int n)
//{
//    dp[0][0] = 1;
//    for (int i = 0; i <= n; i++)
//        for (int j = 1; j <= n; j++)
//        {
//            dp[i][j] = dp[i][j - 1];
//            if (i >= j) dp[i][j] += dp[i - j][j];
//        }
//    return dp[n][n];
//}
//int main()
//{
//    while (cin >> n)
//    {
//        cout << func(n) << endl;
//        for (int i = 0; i <= n; i++)
//        {
//            for (int j = 0; j <= n; j++)
//            {
//                cout << dp[i][j] << " ";
//            }
//            cout << endl;
//        }
//    }
//    return 0;
//}
#include<iostream>
#include<algorithm>
#include <string>
using namespace std;

const int N = 64;
int dp[N];
string ret = "";
int main() 
{
	int n = 0;
	cin >> n;
	dp[0] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = i; j <= n; j++)
		{
			dp[j] = (dp[j] + dp[j - i]);
			if()
		}
	cout << dp[n] << endl;
	return 0;
}

