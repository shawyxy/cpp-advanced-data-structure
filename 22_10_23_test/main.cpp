//#include "BinaryTree.h"
//#include "BinaryTree.h"
#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <string>
using namespace std;

typedef char BTDataType;

typedef struct BTNode
{
    struct BTNode* left;
    struct BTNode* right;
    BTDataType data;
}BTNode;

//创建结点
BTNode* CreateBTNode(BTDataType x)
{
    BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* str, int* pi)
{
    if (str[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }

    BTNode* root = CreateBTNode(str[(*pi)++]);
    root->left = BinaryTreeCreate(str, pi);
    root->right = BinaryTreeCreate(str, pi);
    return root;
}
// 二叉树销毁
void BinaryTreeDestory(BTNode* root)
{
    if (root == NULL)
        return;
    BinaryTreeDestory(root->left);
    BinaryTreeDestory(root->right);
    free(root);
}
// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
    /*if (root == NULL)
        return 0;
    return   BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;*/
    return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
    assert(k >= 1);
    if (root == NULL)
        return 0;
    if (k == 1)
        return 1;
    return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1) + 1;
}
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
    if (root == NULL)
        return NULL;
    if (root->data == x)
    {
        printf("%d\n", root->data);
        return root;

    }
    BinaryTreeFind(root->left, x);
    BinaryTreeFind(root->right, x);
    return NULL;
}
// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
    if (root == NULL)
    {
        //printf("#");
        return;
    }
    printf("%c", root->data);
    BinaryTreePrevOrder(root->left);
    BinaryTreePrevOrder(root->right);
}
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
    if (root == NULL)
    {
        //printf("#");
        return;
    }
    BinaryTreeInOrder(root->left);
    printf("%c", root->data);
    BinaryTreeInOrder(root->right);
}
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
    if (root == NULL)
    {
        //printf("#");
        return;
    }
    BinaryTreePostOrder(root->left);
    BinaryTreePostOrder(root->right);
    printf("%c", root->data);
}



int main()
{
    string str;
    getline(cin, str);
    BTDataType a[] = "hello";
    int i = 0;
    BTNode* node = BinaryTreeCreate(a, &i);


    BinaryTreePrevOrder(node);
    printf("\n");

    BinaryTreeInOrder(node);
    printf("\n");

    BinaryTreePostOrder(node);
    printf("\n");
    return 0;
}
//class BTNode
//{
//    BTNode* left;
//    BTNode* right;
//    int data;
//};
//void BinaryTreePrevOrderCreate()
//{
//
//}
//// 二叉树前序遍历
//void BinaryTreePrevOrder(BTNode* root)
//{
//    if (root == NULL)
//    {
//        printf("# ");
//        return;
//    }
//    printf("%d ", root->data);
//    BinaryTreePrevOrder(root->left);
//    BinaryTreePrevOrder(root->right);
//}
//// 二叉树中序遍历
//void BinaryTreeInOrder(BTNode* root)
//{
//    if (root == NULL)
//    {
//        printf("# ");
//        return;
//    }
//    BinaryTreeInOrder(root->left);
//    printf("%d ", root->data);
//    BinaryTreeInOrder(root->right);
//}
//// 二叉树后序遍历
//void BinaryTreePostOrder(BTNode* root)
//{
//    if (root == NULL)
//    {
//        printf("# ");
//        return;
//    }
//    BinaryTreePostOrder(root->left);
//    BinaryTreePostOrder(root->right);
//    printf("%d ", root->data);
//}

//bool func(int n)
//{
//    if (n <= 3)
//    {
//        return n > 1;
//    }
//    for(int i = 2; i <= n / 2; i++)
//    {
//        if (n % i == 0)
//        {
//            return false;
//        }
//    }
//    return true;
//}
//int main()
//{
//    int n = 0, a = 0, b = 0;
//    cin >> n;
//    a = n / 2;
//    b = n / 2;
//    //cout << func(9) << func(13) << endl;
//    while(!func(a) || !func(b))
//    {
//        a--;
//        b++;
//    }
//    //cout << ++a << endl << --b << endl;
//    cout << a << endl << b << endl;

//    return 0;
//}
////#include <iostream>
////#include <stdlib.h>
////#include <assert.h>
////#include <string>
////#include <queue>
////using namespace std;
////
////typedef char BTDataType;
////typedef struct BTNode
////{
////    struct BTNode* left;
////    struct BTNode* right;
////    BTDataType data;
////}BTNode;
////
//////创建结点
////BTNode* CreateBTNode(BTDataType x)
////{
////    BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
////    newnode->left = NULL;
////    newnode->data = x;
////    newnode->right = NULL;
////    return newnode;
////}
////
////// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
////BTNode* BinaryTreeCreate(BTDataType* str, int* pi)
////{
////    if (str[*pi] == '#')
////    {
////        (*pi)++;
////        return NULL;
////    }
////
////    BTNode* root = CreateBTNode(str[(*pi)++]);
////    root->left = BinaryTreeCreate(str, pi);
////    root->right = BinaryTreeCreate(str, pi);
////    return root;
////}
////// 二叉树销毁
////void BinaryTreeDestory(BTNode* root)
////{
////    if (root == NULL)
////        return;
////    BinaryTreeDestory(root->left);
////    BinaryTreeDestory(root->right);
////    free(root);
////}
////// 二叉树节点个数
////int BinaryTreeSize(BTNode* root)
////{
////    /*if (root == NULL)
////        return 0;
////    return   BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;*/
////    return root == NULL ? 0 : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
////}
////// 二叉树叶子节点个数
////int BinaryTreeLeafSize(BTNode* root)
////{
////    if (root == NULL)
////        return 0;
////    if (root->left == NULL && root->right == NULL)
////        return 1;
////    return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
////}
////// 二叉树第k层节点个数
////int BinaryTreeLevelKSize(BTNode* root, int k)
////{
////    assert(k >= 1);
////    if (root == NULL)
////        return 0;
////    if (k == 1)
////        return 1;
////    return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1) + 1;
////}
////// 二叉树查找值为x的节点
////BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
////{
////    if (root == NULL)
////        return NULL;
////    if (root->data == x)
////    {
////        printf("%d\n", root->data);
////        return root;
////
////    }
////    BinaryTreeFind(root->left, x);
////    BinaryTreeFind(root->right, x);
////    return NULL;
////}
////// 二叉树前序遍历
////void BinaryTreePrevOrder(BTNode* root)
////{
////    if (root == NULL)
////    {
////        //printf("#");
////        return;
////    }
////    printf("%c", root->data);
////    BinaryTreePrevOrder(root->left);
////    BinaryTreePrevOrder(root->right);
////}
////// 二叉树中序遍历
////void BinaryTreeInOrder(BTNode* root)
////{
////    if (root == NULL)
////    {
////        //printf("#");
////        return;
////    }
////    BinaryTreeInOrder(root->left);
////    printf("%c", root->data);
////    BinaryTreeInOrder(root->right);
////}
////// 二叉树后序遍历
////void BinaryTreePostOrder(BTNode* root)
////{
////    if (root == NULL)
////    {
////        //printf("#");
////        return;
////    }
////    BinaryTreePostOrder(root->left);
////    BinaryTreePostOrder(root->right);
////    printf("%c", root->data);
////}
//////
////int Height (BTNode* root)
////{
////    if(root == NULL)
////        return 0;
////    int m = Height ( root->left );
////    int n = Height(root->right);
////    return (m > n) ? (m + 1) : (n + 1);
////}
//////
//////// 层序遍历
//////void BinaryTreeLevelOrder(BTNode* root)
//////{
//////    //创建并初始化队列
//////    queue q;
//////    QueueInit(&q);
//////    //把根结点放入
//////    if (root)
//////    {
//////        QueuePush(&q, root);
//////    }
//////    //每次只取队头元素(当前的根结点),
//////    //然后将当前根结点的非空孩子结点存入
//////    //终止条件:队空
//////    while (!QueueEmpty(&q))
//////    {
//////        //取队头元素后pop
//////        BTNode* front = QueueFront(&q);
//////        printf("%d ", front->data);
//////        QueuePop(&q);
//////
//////        if (front->left)
//////        {
//////            QueuePush(&q, front->left);
//////        }
//////        if (front->right)
//////        {
//////            QueuePush(&q, front->right);
//////        }
//////    }
//////    QueueDestory(&q);
//////}
////
//////层序创建二叉树
//////Node cerate_LevelTree(Node node){
//////    LinkedList<Node> q=new LinkedList<Node>();//还是建个队列
//////    String ch;
//////    Node p;
//////    Scanner scanner=new Scanner(System.in);
//////    ch=scanner.nextLine();//从控制台取出输入第一个结点
//////    if(!ch.equals("null")){//若不为空则让他入队
//////        node=new Node();//生成一个结点
//////        node.data=ch;//把输入的数据存进去
//////        q.add(node);
//////    }
//////    while(!q.isEmpty()){
//////        ch=scanner.nextLine();//再从控制台取元素
//////        p=q.pollFirst();//每次都取出对头结点
//////        if(ch.equals("null")){//若不为空则证明有左孩子
//////            p.lchild=null;
//////        }
//////        else{
//////            p.lchild=new Node();//创建左孩子并入队
//////            p.lchild.data=ch;
//////            q.add(p.lchild);
//////        }
//////        ch=scanner.nextLine();//再取出一个元素
//////        if(ch.equals("null")){//若不为空则证明有右孩子
//////            p.rchild=null;
//////        }
//////        else{
//////            p.rchild=new Node();//创建右孩子并入队
//////            p.rchild.data=ch;
//////            q.add(p.rchild);
//////        }
//////    }
//////    return node;
//////}
////
//////int main()
//////{
//////    string str;
//////    getline(cin, str);
//////
//////    BTDataType a[1024];
//////    for(int i = 0; i < str.size(); i++)
//////    {
//////        a[i] = str[i];
//////    }
//////    int i = 0;
//////    BTNode* node = BinaryTreeCreate(a, &i);
//////
//////
//////    BinaryTreePrevOrder(node);
//////    printf("\n");
//////
//////    BinaryTreeInOrder(node);
//////    printf("\n");
//////
//////    BinaryTreePostOrder(node);
//////    printf("\n");
//////    return 0;
//////}
////void BinaryTreeLevelOrderCreate(BTNode* root) {
////    queue<BTNode *> q;
////    BTDataType ch;
////    BTNode *tmp;
////    cin >> ch;
////    BTNode *newnode = CreateBTNode(ch);
////    newnode->data = ch;
////    q.push(newnode);
////
////    while (!q.empty())
////    {
////        cin >> ch;
////        tmp = q.front();
////        if(tmp == nullptr)
////        {
////
////        }
////    }
////}
////int main()
////{
////    int n = 0;
////    cin >> n;
////    char ch;
////    int left = 0, right = 0;
////    string str;
////    //str = "ABD##E#H##CF##G##";
////
//////    for(int i = 0; i < n; i++)
//////    {
//////        cin >> ch >> left >> right;
//////
//////        str += ch;
//////        if((left == 0 && right != 0) || (left == 0 && right == 0))
//////        {
//////            str += '#';
//////        }
//////    }
////    cout << str << endl;
////
////    BTDataType a[1024];
////    for(int i = 0; i < str.size(); i++)
////    {
////        a[i] = str[i];
////    }
////    int i = 0;
////    BTNode* node = BinaryTreeCreate(a, &i);
////
////    BinaryTreePrevOrder(node);
////    printf("\n");
////    cout << Height(node) << endl;
////    return 0;
////}
//#include <iostream>
//#include <queue>
//#include <vector>
//using namespace std;
//
//typedef int type;
//typedef struct treeNode {
//    type data;
//    treeNode* left;
//    treeNode* right;
//}treeNode;
//
////按照层序遍历构造二叉树
////假设层序序列已经存进vector中，并且是一颗完全二叉树
//treeNode* creatBinTree(vector<int> arr) {
//    queue<treeNode*> q;
//
//    //如果层序序列为空，返回空树
//    if (arr.empty()) {
//        return nullptr;
//    }
//
//    treeNode* head = new treeNode; //创建头节点
//    head->data = arr[0];  //存放数组首元素
//    q.push(head); //入队
//
//    treeNode* bt;
//    int i = 1;
//    while (!q.empty()) {
//        bt = q.front();  //取出头节点，准备给它安排左右孩子
//        q.pop(); //头节点出队，每一次新的循环，都让头出队
//
//        //先弄左孩子
//        //i只要不超过数组的有效长度，就有左孩子
//        if (i < arr.size()) {
//            bt->left = new treeNode;
//            bt->left->data = arr[i];
//            q.push(bt->left);  //左孩子入队
//            i++; //数组后移
//        }
//        else {
//            bt->left = nullptr;
//        }
//
//        //再弄右孩子
//        if (i < arr.size()) {
//            bt->right = new treeNode;
//            bt->right->data = arr[i];
//            q.push(bt->right);  //右孩子入队
//            i++;  //数组后移
//        }
//        else {
//            bt->right = nullptr;
//        }
//    }
//    return head;  //最后队列为空就出while，返回头节点
//}
//
////层序遍历二叉树
//void printBinTree(treeNode* head) {
//    queue<treeNode*> q;
//    treeNode* b;
//
//    //树为空
//    if (head == nullptr) {
//        cout << "treeNode is empty!" <<endl;
//        return;
//    }
//
//    //头节点入队
//    q.push(head);
//
//    while (!q.empty()) {
//
//        b = q.front();  //拿到队头，队头出队
//        q.pop();
//        cout << b->data << endl;  //打印对头的数据
//
//        //对头的左孩子存在就入队
//        if (b->left) {
//            q.push(b->left);
//        }
//
//        //对头的右孩子存在就入队
//        if (b->right) {
//            q.push(b->right);
//        }
//    }
//}
//int Height (treeNode* root)
//{
//    if(root == NULL)
//        return 0;
//    int m = Height ( root->left );
//    int n = Height(root->right);
//    return (m > n) ? (m + 1) : (n + 1);
//}
//int main() {
//    vector<char> ch;
//    int n = 0;
//    cin >> n;
//    char c;
//    int left = 0, right = 0;
//    cout << c << left << right;
//    ch[0] = c;
//    const char*p = &c;
//    p = nullptr;
//    for(int i = 1; i < n; i++)
//    {
//        if(left != 0 && right != 0)
//        {
//            ch.push_back(c);
//        }
//
//        cout << c << left << right;
//
//
//    }
//
//    //treeNode* head = creatBinTree();
//    //printBinTree(head);
//}
//
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//    string str;
//    vector<string> a;
//    getline(cin, str);
//    int len = str.size();
//    int count = 0, begin = 0, end = 0;
//    int flag = 1;
//    while(end < len)
//    {
//        if(str[end] == '\"')
//        {
//            flag = -flag;
//        }
//        if(flag < 0)
//        {
//            while(end < len && str[end] != ' ')
//            {
//                end++;
//            }
//            a.push_back(string(str.begin() + begin, str.begin() + end));
//            begin = ++end;
//            count++;
//        }
//        else
//        {
//            end++;
//            while(end < len && str[end] != '\"')
//            {
//                end++;
//            }
//            a.push_back(string(str.begin() + begin, str.begin() + end));
//            begin = ++end;
//            count++;
//        }
//
//
//    }
//    cout << count << endl;
//    for(int i = 0; i < a.size(); i++)
//    {
//        if(a[i].front() == '\"')
//        {
//            a[i].erase(a[i].begin());
//        }
//        if(a[i].back() =='\"')
//        {
//            a[i].erase(a[i].end());
//        }
//        cout << a[i] << endl;
//    }
//    return 0;
//}
////////////////////
//
//#include <iostream>
//#include <vector>
//using namespace std;
//void func(int N, vector<int> &v)
//{
//    for(int i = 2; i < N;i++)
//    {
//        if(N % i == 0){
//            v.push_back(i);
//        }
//    }
//}
//int main()
//{
//    int N = 0, M = 0;
//    cin >> N >> M;
//    vector<int> dp(2 * M,0);
//    dp[N] = 0;
//    for(int i = N; i <= M; i++)
//    {
//        vector<int>v;
//        func(i,v);
//        int n = v.size();
//        for(int j = 0;j < n; j++){
//            if(dp[i + v[j]])
//            {
//                dp[i + v[j]] = min(dp[i + v[j]], dp[i] + 1);
//            }
//            else
//            {
//                dp[i + v[j]] = dp[i] + 1;
//            }
//        }
//        v.clear();
//    }
//    if(dp[M] == 0)
//    {
//        cout << -1 << endl;
//    }
//    else
//    {
//        cout << dp[M] << endl;
//    }
//    return 0;
//}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string s1;
    bool flag = true;
    vector<string>ans;
    getline(cin, s1);
    int start = 0;
    int end = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        if (flag && (s1[i] == ' '|| i == s1.size()-1))
        {
            end = i;
            if (s1[start] == '"' && s1[end - 1] == '"')
                ans.push_back(s1.substr(start + 1, end - 1 - start - 1));
            else if (i == s1.size() - 1)
                ans.push_back(s1.substr(start, end - start + 1));
            else
                ans.push_back(s1.substr(start, end - start));
            start = end + 1;
            continue;
        }
        else if (flag && s1[i] != ' '&& s1[i] != '"')
        {
            continue;
        }
        else if (s1[i] == '"')
        {
            flag = !flag;
            if(i==s1.size()-1)
                ans.push_back(s1.substr(start+1, i - start-1));
            continue;
        }
        else
            continue;
    }
    int n = ans.size();
    cout << n << endl;
    for (auto c : ans)
    {
        cout << c << endl;
    }
    return 0;
}