// write your code here cpp
#include <iostream>
#include <string>
using namespace std;
string func(string str)
{
    string ret;
    int num = 0;
    int len = str.size();
    while(len)
    {
        num += str[len - 1] - '0';
        //cout << "fun" <<str[len - 1] << endl;
        len--;
    }
    ret = to_string(num);
    return ret;
}
int main()
{
    string str;
    string ret;
    //getline(cin, str);
    while(cin >> str)
    {
        ret = func(str);
        while(ret.size() > 1)
        {
            ret = func(ret);
        }
        cout << ret << endl;
    }
    return 0;
}