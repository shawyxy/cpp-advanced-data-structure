#include "AVLTree.h"
void TestAVLTree1()
{
    int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };  // 测试双旋平衡因子调节
    AVLTree<int, int> t1;
    for (auto e : a)
    {
        t1.Insert(make_pair(e, e));
    }

    t1.InOrder();
    cout << "IsBalance:" << t1.IsBalance() << endl;
}

void TestAVLTree2()
{
    size_t N = 100000;                  // 使用随机数测试
    srand(time(0));
    AVLTree<int, int> t1;
    for (size_t i = 0; i < N; ++i)
    {
        int x = rand() % 100 + 1;
        t1.Insert(make_pair(x, i));
    }
    //t1.InOrder();

    cout << "IsBalance:" << t1.IsBalance() << endl;
}
int main()
{
    //TestAVLTree1();

    TestAVLTree2();
    return 0;
}