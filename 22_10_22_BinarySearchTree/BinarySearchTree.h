//
// Created by 肖越 on 2022/10/25.
//
#pragma once
//#include <stdio.h>
#include <iostream>
#include <vector>
#define nullptr NULL

using namespace std;
// 定义结点类
template<class K>
struct BSTreeNode
{
    K _key;                     // 值
    BSTreeNode* _left;          // 左孩子结点
    BSTreeNode* _right;         // 右孩子结点
    BSTreeNode(const K& key)    // 构造函数
    :_key(key)
    , _left(nullptr)
    , _right(nullptr)
    {}
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
    ~BSTree()
    {
        _Destory(_root);
        _root = nullptr;
    }
    // operator= 重载
    BSTree<K>& operator=(BSTree<K>& bsTree);

    // 删除函数
    bool Erase(const K& key);
    // 递归删除函数
    bool EraseR(const K& key);


    // 插入函数
    bool Insert(const K& key)
    {
        if(_root == nullptr)                // 插入一个空树
        {                                   // 插入的数作为根结点的值
            _root = new Node(key);
            return true;
        }
                                            // 树不为空
        Node* parent = nullptr;
        Node* cur = _root;
        while(cur)                          // 迭代，让cur找nullptr
        {
            if(key == cur->_key)            //插入结点和当前结点的值相同
            {
                return false;
            }
            else if(key < cur->_key)        // 插入结点的值小于当前结点的值
            {
                parent = cur;               // 保存父结点
                cur = cur->_left;           // 更新cur
            }
            else if(key > cur->_key)        // 插入结点的值大于当前结点的值
            {
                parent = cur;               // 保存父结点
                cur = cur->_right;          // 更新cur
            }
        }
                                            // 此时，cur已经走到空结点，parent是它的父结点
                                            // 链接新结点和父结点
        cur = new Node(key);                // 创建新结点，放在cur的位置
        if(key > parent->_key)              // 插入结点的值大于父结点的值
        {
            parent->_right = cur;
        }
        else if(key < parent->_key)         // 插入结点的值大于父结点的值
        {
            parent->_left = cur;
        }
        return true;
    }
    // 递归插入函数
    bool InsertR(const K& key);


    // 查找函数
    Node* Find(const K& key);
    // 中序遍历
    void InOrder()
    {
        _InOrder(_root);
        cout << endl;
    }

private:
    bool _EraseR(const K& key);
    bool _InsertR(const K& key);
    void _InOrder(const Node* root)
    {
        if(root == nullptr)
            return;
        
        _InOrder(root->_left);
        cout << root->_key << " ";
        _InOrder(root->_right);
    }
    void _Destory(Node* root)
    {
        if(root == nullptr)
            return;
        
        _Destory(root->_left);
        _Destory(root->_right);
        delete root;
    }
private:
    Node* _root = nullptr;
};

/////////////////__TEST__/////////////////////
void BSTreeTest()
{
    BSTree<int> t;
    vector<int> a = { 8, 3, 1, 10, 6, 4, 7, 14, 13, 4, 3 ,4 };
    for(int i = 0; i < a.size(); i++)
    {
        t.Insert(a[i]);
    }
    //t.InOrder();
    cout << endl;
}

