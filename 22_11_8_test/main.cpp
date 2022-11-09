//
// Created by 肖越 on 2022/11/8.
//
#include<iostream>
#include <string>
using namespace std;
int main()
{
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int len1 = str1.size(), len2 = str2.size();
    if(len1 < len2)// 确保长度小的str1
    {
        string str = str1;
        str1 = str2;
        str2 = str;
    }
    string ret1;
    for(int i = 0; i < len1; i++)
    {
        for(int j = 0; j < len1; j++)
        {
            string substr(str1.begin() + i, str1.begin() + j);
            if(str2.find(substr) != string::npos)
            {
                if(j - i > ret1.size())
                {
                   string ret2(str2.begin() + i, str2.begin() + j);
                }
                ret1 = ret2;
            }
        }
    }
    return 0;
}