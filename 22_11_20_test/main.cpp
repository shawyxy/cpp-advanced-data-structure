//#include <iostream>
//using namespace std;
//int main()
//{
//    int n = 0, count = 0;
//    while(cin >> n)
//    {
//
//    }
//    return 0;
//}
// write your code here cpp
#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string str2 = "VWXYZABCDEFGHIJKLMNOPQRSTU";
    string str;

    while(getline(cin, str))
    {
        int len = str.size();
        string ret;
        ret.resize(len);
        int i = 0;
        while(i < len)
        {
            if(str1.find(str[i]) != -1)
            {
                ret[i] = str2[str1.find(str[i])];
            }
            else if(str[i] == ' ')
            {
                ret[i] = ' ';
            }
            i++;
        }
        cout << ret << endl;
    }
    return 0;
}