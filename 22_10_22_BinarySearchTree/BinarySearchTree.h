//
// Created by 肖越 on 2022/10/22.
//
#pragma once
#include <iostream>
using namespace std;

// 定义结点类
template<class K>
class BSTreeNode
{
    K _key;             // 值
    BSTreeNode* _left;  // 左孩子结点
    BSTreeNode* _right; // 右孩子结点

};

// 定义二叉搜索树类
template<class K>
class BSTree
{
    typedef BSTreeNode<K> Node;
public:
    // 构造函数
    BSTree()
    {

    }
    // 拷贝构造函数
    BSTree(const BSTree<K>& bsTree);
    // 析构函数
    ~BSTree();
    // operator= 重载
    BSTree<K>& operator=(BSTree<K>& bsTree);
    // 删除函数
    bool Erase(const K& key);
    // 插入函数
    bool Insert(const K& key);
    // 查找函数
    Node* Find(const K& key);
    // 中序遍历
    void InOrder();
    void _InOrder();
private:
    Node* _root = nullptr;
};