//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int main()
//{
//    vector<int> arr(128, 0);
//
//    string str;
//    getline(cin, str);
//    int len = str.size();
//    for(int i = 0; i < len; i++)
//    {
//        arr[str[i] - '0']++;
//
//    }
//    //cout << str;
//    int index = 0;
//    for(int i = 0; i <  len; i++)
//    {
//        //cout << arr[str[i] - '0'] << " ";
//
//        if(arr[str[i] - '0'] == 1)
//        {
//            index = i;
//            break;
//        }
//    }
//    printf("%c\n", str[index]);
//
//    return 0;
//}
#include <iostream>
//#include <vector>
using namespace std;
int func(int a, int b) // 求最大公约数
{
    int c = a % b;
    while(c)
    {
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}

int main()
{

    int n = 0, power = 0;
    while(~scanf("%d %d", &n, &power))
    {
        //vector<int> a(n, 0);
//        //cin >> n >> power;
//        for(int i = 0; i < n; i++)
//        {
//            int num = 0;
//            cin >> num;
//            a.push_back(num);
//        }

        int num = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> num;
            if(power >= num)
            {
                power += num;
            }
            else
            {
                power += func(num, power);
            }
        }

        cout << power << endl;
        power = 0;
    }
    return 0;
}

