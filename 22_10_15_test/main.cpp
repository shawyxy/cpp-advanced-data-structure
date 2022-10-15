#include<iostream>
using namespace std;
int main(){
    int W, H, counts = 0;
    cin>>W>>H;
    if(W % 4== 0 || H % 4== 0){
        counts = W*H/2;
    }else if(W % 2== 0 && H % 2== 0){
        counts = (W*H/4+ 1) * 2;
    }else{
        counts = W*H/2+ 1;
    }
    cout << count << endl;
    return 0;

}
//#include <iostream>
//#include <math.h>
//using namespace std;
//
//class Solution {
//public:
//    int StrToInt(string str) {
//        if(str == "")
//            return 0;
//        int len = str.size();
//        if(len == 1)
//        {
//            if(!isdigit(str[0]))
//            {
//                return 0;
//            }
//        }
//
//        int flag = 0;
//        int ret = 0;
//        for(int i = 0; i < len; i++)
//        {
//            char ch = str[i];
//            if(ch < '0' || ch > '9')
//            {
//                if(i == 0)
//                {
//                    if(ch == '+' || ch =='-')
//                    {   if(ch == '-')
//                            flag = 1;
//                    }
//                    else
//                    {
//                        return 0;
//                    }
//                }
//                else
//                {
//                    return 0;
//                }
//            }
//            else
//            {
//                ret = ret * 10 + ch - '0';
//            }
//        }
//        if(flag)
//            ret = -ret;
//        return ret;
//    }
//};
//
//int main()
//{
//    Solution s;
//    cout << s.StrToInt("-122") << endl;
//    return 0;
//}
////int main() {
////    int i = 1;
////    printf("%d,%d\n", (i+5, i++));
////    return 0;
////}
//#include <iostream>
//#include <math.h>
//#include <vector>
//using namespace std;
//int main()
//{
//    int x = 0, y = 0;
//    cin >> x >> y;
//    int count = 0;
//    for(int i = 0; i < x; i++)
//    {
//        for(int j = 0; j < y; j++)
//        {
//            vector<vector<int>> a[x][y];
//
//        }
//    }
//    return 0;
//}

//class Solution{
//public:
//    void operator()(int x, int y)
//    {
//        _x = x;
//        _y = y;
//    }
//    int _x;
//    int _y;
//};
