#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1, str2;
    int n = 0;
    getline(cin, str1);
    getline(cin, str2);
    int len1 = str1.size();
    int len2 = str2.size();
    if(len1 > len2)
    {
        string tmp = str1;
        str1 = str2;
        str2 = tmp;
    }
//     cout << str1 << endl;
//     cout << str2 << endl;

    for(int i = 0; i < len1; i++)
    {
        for(int j = i + 1; j <= len1; j++)
        {
            if(str2.find(str1.substr(i, j - i)) != string::npos)
            {
                if(n < j - i - 1)
                    n = j - i;
            }
        }
    }
    cout << n << endl;
    return 0;
}
//#include<iostream>
//#include<string>
//using namespace std;
//int main()
//{
//    string str1, str2;
//    while(cin>>str1>>str2)
//    {
//        int n=0;
//        for(int i=0;i<str1.size();i++)
//        {
//            for(int j=str1.size();j>i;j--)
//            {
//                if(str2.find(str1.substr(i,j-i))!=string::npos)
//                    n=n>(j-i)?n:(j-i);
//            }
//        }
//        cout<<n<<endl;
//    }
//    return 0;
//}