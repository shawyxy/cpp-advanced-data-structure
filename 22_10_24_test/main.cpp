#include<iostream>
#include <math.h>
#include <string>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    char op = ' ';
    int a = 0, b = 0;
    string str;
    str.resize(1024);
    int max = 0;
    for (int i = 0; i < n; i++)
    {
            cin >> op >> a >> b;
            if (a >= max)
            {
                max = a;
            }
            if (b >= max)
            {
                max = b;
            }
    }
    str[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        str[i] = pow(2, i - 1) + str[i - 1];
        if (max - str[i] < 0)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}