#define _CRT_SECURE_NO_WARNINGS 1

//#include<iostream>
//#include <algorithm>
//using namespace std;
//const int N = 1024;
//int dp[N][N];
//int func(int n)
//{
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= n; j++)
//        {
//            if (i == 1 || j == 1)
//                dp[i][j] = 1;
//            for (int k = 0; k * i <= j; k++)
//            {
//
//            }
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
#include <iostream>
using namespace std;

const int N = 64;
int factor[N];

int pos = 0;
int n = 0;
void DFSPrint(int index, int sum, int n) 
{
	if (index == n || sum >= n) 
	{
		if (sum == n) 
		{
			for (int i = 0; i < pos; i++)
			{
				if (i < pos - 1)
					cout << factor[i] << "+";
				else
				{
					cout << index << "=" << sum << endl;
					if (index + 1 == n)
						cout << n << "=" << n << endl;
				}
			}
		}
		return;
	}

	factor[pos++] = index;
	DFSPrint(index, sum + index, n);

	pos--;
	DFSPrint(index + 1, sum, n);
}


int main()
{
	while (cin >> n)
	{
		int dp[N] = { 0 };
		dp[0] = 1;

		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
				dp[j] = dp[j] + dp[j - i];

		cout << dp[n] << endl;

		DFSPrint(1, 0, n);
	}
	return 0;
}
//
//#include <iostream>
//using namespace std;
//const int N = 64;
//int f[N][N];
//
//int func(int n)
//{
//	for (int i = 0; i <= n; i++) {
//		f[i][0] = 1;					
//	}
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//		{
//			f[i][j] = f[i - 1][j] + f[i][j - i];
//		}
//	return f[n][n];
//}
//int main()
//{
//	int n = 0;
//	int sum = 0;
//	while (cin >> n)
//	{
//		cout << func(n) << endl;
//		for (int i = 0; i <= n; i++)
//		{
//			sum = 0;
//			for (int j = 0; j <= n; j++)
//			{
//				/*sum += j;
//				if(sum <= j)*/
//				cout << f[i][j] << " ";
//			}
//			cout << endl;
//		}
//	}
//	return 0;
//}