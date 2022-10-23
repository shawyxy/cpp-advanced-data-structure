//
// Created by 肖越 on 2022/10/23.
//
#include "BinaryTree.h"
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

//创建结点
BTNode* CreateBTNode(BTDataType x)
{
    BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}