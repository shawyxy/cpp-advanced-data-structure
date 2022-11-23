//
// Created by 肖越 on 2022/11/16.
//

#ifndef RBTREE_RBTREE_H
#define RBTREE_RBTREE_H

#endif //RBTREE_RBTREE_H

#pragma once
#include <iostream>
using namespace std;

enum Color // 使用枚举
{
    RED,
    BLACK
};
// 红黑树结点类
//template<class K, class V> [旧]
template<class T>
struct RBTreeNode
{
    RBTreeNode<T>* _left;
    RBTreeNode<T>* _right;
    RBTreeNode<T>* _parent;

    Color _col;                         // 颜色

    T _data;                            // 数据
    RBTreeNode(const T& data)
            : _left(nullptr)
            , _right(nullptr)
            , _parent(nullptr)
            , _data(data)
            , _col(RED)                 // 默认插入结点为红色
    {}
};
// 红黑树类
template<class K, class T>
class RBTree
{
public:
    typedef RBTreeNode<T> Node;

    // 插入函数
    bool Insert(const T& kv)
    {
        if (_root == nullptr)                   // 空树
        {
            _root = new Node(kv);
            _root->_col = BLACK;
            return true;
        }

        Node *cur = _root;
        Node *parent = nullptr;

        while (cur)                             // 迭代,找到插入位置
        {
            if (kv.first < cur->_kv.first)      // 插入的值比key值小
            {
                parent = cur;
                cur = cur->_left;               // 往左走
            }
            else if (kv.first > cur->_kv.first) // 插入的值比key值大
            {
                parent = cur;
                cur = cur->_right;              // 往右走
            }
            else                                // 找不到
            {
                return false;
            }
        }
                                                // 跳出循环,说明找到插入的位置了
        cur = new Node(kv);                     // 将cur更新为新插入结点
        if (cur->_kv.first < parent->_kv.first) // 新结点值比叶子(父)结点小
        {
            parent->_left = cur;                // 作为父结点的左孩子插入
            cur->_parent = parent;
        }
        else
        {
            parent->_right = cur;
            cur->_parent = parent;
        }
                                                // 插入成功

                                                // 检查并调整颜色
        while (parent && parent->_col == RED)   // 父结点非空且为红,说明它是子树的根结点
        {
            Node *grandparent = parent->_parent;// 祖父结点
                                                // parent的位置分两种情况
            if (parent == grandparent->_left)   // (1). 父结点是祖父节点的左孩子
            {
                Node *uncle = grandparent->_right; // 叔叔就是祖父节点的另一个孩子
                if (uncle != nullptr && uncle->_col == RED) // 情况1:叔叔存在且为红
                {
                    parent->_col = BLACK;       // 父结点变黑
                    uncle->_col = BLACK;        // 叔叔结点变黑
                    grandparent->_col = RED;    // 祖父结点变红

                    cur = grandparent;
                    parent = cur->_parent;      // 继续向上处理
                }
                else                            // 跳出了上面的判断,有两种有效组合:叔叔为空,叔叔为黑
                {
                                                // 情况2：叔叔存在且为黑,右单旋+变色
                                                //     g    右旋       p
                                                //   p   u  -->   cur    g
                                                // cur                     u
                    if (cur == parent->_left)   // cur是parent的左子树
                    {
                        RotateR(grandparent);   // 以祖父结点为轴心右旋

                        parent->_col = BLACK;   // 父节点变黑
                        grandparent->_col = RED;// 祖父结点变黑
                    }
                    else                        // cur是parent的右子树
                    {
                                                // 情况3:
                                                //    g   左右旋     c
                                                //  p   u  -->    p   g
                                                //    c                 u
                        RotateR(grandparent);   // 以祖父结点为轴心右旋

                        grandparent->_col = RED;     // 父节点变黑
                        cur->_col = BLACK; // 祖父结点变黑
                    }
                    break;                      // 旋转后子树根节点变黑,停止向上调整
                }
            }
            else                                // (2). 父结点是祖父节点的右孩子,步骤相同
            {
                Node *uncle = grandparent->_left;
                if (uncle && uncle->_col == RED)
                {
                    uncle->_col = BLACK;
                    parent->_col = BLACK;
                    grandparent->_col = RED;

                    cur = grandparent;
                    parent = cur->_parent;
                }
                else
                {
                    if (cur == parent->_left)
                    {
                        RotateRL(grandparent);

                        cur->_col = BLACK;
                        grandparent->_col = RED;
                    }
                    else
                    {
                        RotateL(grandparent);

                        grandparent->_col = RED;
                        parent->_col = BLACK;
                    }
                    break;
                }
            }
        }
        _root->_col = BLACK;                    // 不论根节点何种颜色,统一处理为黑色
        return true;
    }
    //中序遍历
    void InOrder()
    {
        _InOrder(_root);
        cout << endl;
    }
    //判断是否为红黑树
    bool ISRBTree()
    {
        if (_root == nullptr)
        {
            return true;
        }

        if (_root->_col == RED)
        {
            cout << "error:根结点为红色" << endl;
            return false;
        }

        // 以最左路径的黑色结点数做为的参考值
        Node* cur = _root;
        int BlackCount = 0;
        while (cur)
        {
            if (cur->_col == BLACK)
                BlackCount++;
            cur = cur->_left;
        }

        int count = 0;
        return _ISRBTree(_root, count, BlackCount);
    }
private:
    // 右单旋函数
    void RotateR(Node *parent)
    {
        Node *subL = parent->_left;
        Node *subLR = subL->_right;
        Node *pParent = parent->_parent;        // 保存父结点的父结点

        parent->_left = subLR;                  // 重建subLR和parent联系
        if (subLR != nullptr)
        {
            subLR->_parent = parent;
        }

        subL->_right = parent;                  // 重建subL和parent联系
        parent->_parent = subL;


        if (parent == _root)                    // 父结点为根结点，旋转后的subL作为根结点，无父结点
        {
            _root = subL;
            subL->_parent = nullptr;
        }
        else
        {
            if (pParent->_left == parent)
            {
                pParent->_left = subL;
            }
            else
            {
                pParent->_right = subL;
            }

            subL->_parent = pParent;
        }
    }
    // 左单旋函数
    void RotateL(Node *parent)
    {
        Node *subR = parent->_right;
        Node *subRL = subR->_left;
        Node *pParent = parent->_parent;        // 保存父结点的父结点

        parent->_right = subRL;                 // 重建subRL和parent联系
        if (subRL != nullptr)
        {
            subRL->_parent = parent;
        }

        subR->_left = parent;                   // 重建subR和parent联系
        parent->_parent = subR;


        if (parent == _root)                    // 父结点为根结点，旋转后的subR作为根结点，无父结点
        {
            _root = subR;
            subR->_parent = nullptr;
        }
        else
        {
            if (pParent->_left == parent)
            {
                pParent->_left = subR;
            }
            else
            {
                pParent->_right = subR;
            }

            subR->_parent = pParent;
        }
    }
    // 左右双旋函数
    void RotateLR(Node *parent)
    {
        Node *subL = parent->_left;

        RotateL(subL);
        RotateR(parent);
    }
    // 右左双旋函数
    void RotateRL(Node *parent)
    {
        Node *subR = parent->_right;

        RotateR(subR);
        RotateL(parent);
    }
    //中序遍历子函数
    void _InOrder(Node* root)
    {
        if (root == nullptr)
            return;
        _InOrder(root->_left);
        cout << root->_kv.first << " ";
        _InOrder(root->_right);
    }
    // ISRBTree的子函数
    bool _ISRBTree(Node* root, int count, int BlackCount)
    {
        if (root == nullptr) // 该路径走到空
        {
            if (count != BlackCount) // 黑色结点数量和基准值不相等
            {
                cout << "error:黑色结点的数目不相等" << endl;
                return false;
            }
            return true;
        }

        if (root->_col == RED && root->_parent->_col == RED)
        {
            cout << "error:存在连续红色结点" << endl;
            return false;
        }
        if (root->_col == BLACK)
        {
            count++;
        }
        return _ISRBTree(root->_left, count, BlackCount)
               && _ISRBTree(root->_right, count, BlackCount);
    }
private:
    Node *_root = nullptr;
};