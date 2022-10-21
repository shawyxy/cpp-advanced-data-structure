//#include <iostream>
//using namespace std;
//int main()
//{
//    int n = 0;
//    cin >> n;
//    int count = 0, fast = 0, slow = 0;
//    int i = 0;
//    while(i < 32 && fast < 32 && slow < 32)
//    {
//        while(i < 32 && ((n >> i) & 1) == 0 && slow < 32)
//        {
//        cout << ((n>>i) & 1) << " ";
//
//            i++;
//            slow = i;
//        }
//        if((slow - fast) > count)
//        {
//            count = slow - fast;
//        }
//        fast = slow;
//        while(i < 32 && ((n >> i) & 1) == 1 && fast < 32)
//        {
//       cout << ((n>>i) & 1) << " ";
//
//            i++;
//            fast = i;
//        }
//        if((fast - slow) > count)
//        {
//            count = fast - slow;
//        }
//        slow = fast;
//    }
//
//    cout << count << endl;
//    return 0;
//}
#include <iostream>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;
    int count = 0, fast = 0, slow = 0;
    int i = 0;
    while(i < 32 && fast < 32 && slow < 32)
    {
        while(i < 32 && ((n >> i) & 1) == 0 && slow < 32)
        {
           // cout << "i:" << i << " ";
           // cout << ((n>>i) & 1) << endl;

            i++;
            slow = i;
        }
        if((slow - fast) > count && ((n >> fast) & 1) == 1 && ((n >> slow - 1) & 1) == 1)
        {
            count = slow - fast;
        }
        fast = slow;
        while(i < 32 && ((n >> i) & 1) == 1 && fast < 32)
        {
            //cout << "i:" << i << endl;
           // cout << ((n>>i) & 1) << " ";

            i++;
            fast = i;
        }
        if((fast - slow) > count && ((n >> fast - 1) & 1) == 1 && ((n >> slow) & 1) == 1)
        {
            count = fast - slow;
        }
        slow = fast;
    }

    cout << count << endl;
    return 0;
}