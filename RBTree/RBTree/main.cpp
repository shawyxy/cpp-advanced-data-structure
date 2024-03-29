#include "RBTree.h"
void RBTreetest()
{
    RBTree<int, int> tree;

    tree.Insert(make_pair(1, 1));
    tree.Insert(make_pair(2, 2));
    tree.Insert(make_pair(3, 3));
    tree.Insert(make_pair(4, 4));
    tree.Insert(make_pair(5, 5));
    tree.Insert(make_pair(6, 6));
    tree.Insert(make_pair(7, 7));


    //tree.Inorder();
    //tree.ISRBTree();
}
void RBTreetest1()
{
    int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14, 0,5,30,25,20,4,13,30,28,27};  // 测试双旋平衡因子调节
    //int a[] = { 16, 3, 7, 11, 9, 26, 18, 14, 15 };
    RBTree<int, int> t1;
    for (auto e : a)
    {
        t1.Insert(make_pair(e, e));
    }

    t1.InOrder();
    cout << "ISRBTree:" << t1.ISRBTree() << endl;
}

void RBTreetest2()
{
    size_t N = 1000;
    srand(time(0));
    RBTree<int, int> t1;
    for (size_t i = 0; i < N; ++i)
    {
        int x = rand();
        cout << "Insert:" << x << ":" << i << endl;
        t1.Insert(make_pair(x, i));
    }
    cout << "IsBalance:" << t1.ISRBTree() << endl;
}
int main()
{
    RBTreetest();

    RBTreetest1();
    return 0;
}