#include <iostream>
#include <vector>
#include <bitset>
#include <assert.h>
using namespace std;

//int main()
//{
//    vector<int> v{1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 1, 3, 5, 7, 9};
//    bitset<4294967295>* bs1 = new bitset<4294967295>;
//    bitset<4294967295>* bs2 = new bitset<4294967295>;
//    for (auto e : v)
//    {
//        if (!bs1->test(e) && !bs2->test(e))     //00->01
//        {
//            bs2->set(e);
//        }
//        else if (!bs1->test(e) && bs2->test(e)) //01->10
//        {
//            bs1->set(e);
//            bs2->reset(e);
//        }
//        else if (bs1->test(e) && !bs2->test(e)) //10->10
//        {
//            continue;
//        }
//        else
//        {
//            assert(false);
//        }
//    }
//    for (size_t i = 0; i < 4294967295; i++)
//    {
//        if (!bs1->test(i) && bs2->test(i)) //01
//            cout << i << endl;
//    }
//    return 0;
//}
int main()
{
    vector<int> v{1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 1, 3, 5, 7, 9, 2};
    bitset<4294967295>* bs1 = new bitset<4294967295>;
    bitset<4294967295>* bs2 = new bitset<4294967295>;
    for (auto e : v)
    {
        if (!bs1->test(e) && !bs2->test(e))     // 00->01
        {
            bs2->set(e);
        }
        else if (!bs1->test(e) && bs2->test(e)) // 01->10
        {
            bs1->set(e);
            bs2->reset(e);
        }
        else if (bs1->test(e) && !bs2->test(e)) // 10->11
        {
            bs2->set(e);
        }
        else                                              //
        {
            continue;
        }
    }
    for (size_t i = 0; i < 4294967295; i++)
    {
        if (!bs1->test(i) && bs2->test(i))      // 01 or 10
            cout << i << endl;
    }
    return 0;
}