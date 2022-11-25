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
// 正向迭代器
template<class T, class Ptr, class Ref>
struct __RBTreeIterator
{
    typedef RBTreeNode<T> Node;
    typedef Ptr pointer;            // 结点指针
    typedef Ref reference;          // 结点指针的引用
    typedef __RBTreeIterator<T, Ptr, Ref> Self; // 正向迭代器的类型

    Node *_node;

    // 迭代器构造函数
    __RBTreeIterator(Node *node)
            : _node(node)            // 由指针构造一个正向迭代器对象
    {}

    // 解引用操作符
    Ref operator*()
    {
        return _node->_data;
    }

    // 成员访问操作符
    Ptr operator->()
    {
        return *_node->data;
    }

    // == 和 !=
    bool operator==(const Self &s) const
    {
        return _node == s._node;
    }

    bool operator!=(const Self &s) const
    {
        return _node != s._node;
    }

    // 前置++
    Self& operator++()
    {
        if (_node->_right) // 当前结点右子树不为空
        {
            Node *left = _node->_right; // 找当前结点右子树中最左结点
            while (left->_left)
            {
                left = left->_left;
            }
            // 找到了
            _node = left; // 更新
        }
        else  // 当前节点右子树为空
        {
            Node *cur = _node;
            Node *parent = cur->_parent;
            while (parent && cur == parent->_right) // 孩子不在父亲右子树中的祖先
            {
                cur = parent;
                parent = parent->_parent; // 向上迭代祖先结点
            }
            _node = parent; // 更新
        }
        return *this; // 返回更新后的迭代器
    }
    // 前置--
    Self& operator--()
    {
        if(_node->_left) // 结点的左子树不为空
        {
            Node* right = _node->_left; // 找到当前结点左子树中最右结点
            while(right->_right)
            {
                right = right->_right;
            }
            _node = right;
            // 找到了
            _node = right; // 更新
        }
        else // 当前结点左子树为空
        {
            Node* cur = _node;
            Node* parent = cur->_parent;
            while(parent && parent->_left) // 找孩子不在父亲的右子树中的祖先
            {
                cur = parent;
                parent = parent->_parent;
            }
            _node = parent; // 更新
        }
        return *this;
    }
};
// 反向迭代器
template<class iterator>
struct __RBTreeReverseIterator
{
    typedef typename iterator::reference Ref; // 结点指针的引用
    typedef typename iterator::pointer Ptr; // 结点指针
    typedef __RBTreeReverseIterator<iterator> Self; // 反向迭代器类型

    iterator _it;  // 用正向迭代器对象构造

    // 构造函数
    __RBTreeReverseIterator(iterator it)
        :_it(it) // 用正向迭代器对象构造一个反向迭代器对象
    {}
    // 解引用操作符
    Ref operator*()
    {
        return *_it; // 返回正向迭代器指向的结点数据的引用
    }
    // 成员访问操作符
    Ptr operator->()
    {
        return _it.operator->(); // 返回正向迭代器重载的operator->()
    }
    // 前置++
    Self& operator++()
    {
        --_it;
        return *this;
    }
    // 前置--
    Self& operator--()
    {
        ++_it;
        return *this;
    }
    bool operator!=(const Self& s) const
    {
        return _it != s._it;
    }
    bool operator==(const Self& s) const
    {
        return _it == s._it;
    }
};

// 红黑树类
template<class K, class T, class KeyOfT>
class RBTree
{
    typedef RBTreeNode<T> Node; // 定义结点
public:
    typedef __RBTreeIterator<T, T&, T*> iterator; // 定义正向迭代器
    typedef __RBTreeReverseIterator<iterator> reverse_iterator; // 定义反向迭代器


    // 插入函数
    pair<iterator, bool> Insert(const T& data)
    {
        if (_root == nullptr)                   // 空树
        {
            _root = new Node(data);
            _root->_col = BLACK;
            return make_pair(iterator(_root), true);
        }

        KeyOfT kot;

        Node *cur = _root;
        Node *parent = nullptr;

        while (cur)                             // 迭代,找到插入位置
        {
            if (kot(data) < kot(cur->_data))      // 插入的值比key值小
            {
                parent = cur;
                cur = cur->_left;               // 往左走
            }
            else if (kot(data) > kot(cur->data)) // 插入的值比key值大
            {
                parent = cur;
                cur = cur->_right;              // 往右走
            }
            else                                // 找不到
            {
                return make_pair(iterator(cur), false);
            }
        }
                                                // 跳出循环,说明找到插入的位置了
        cur = new Node(data);                   // 将cur更新为新插入结点
        Node* newnode = cur;                    // 保存新插入结点以便最后返回
        if (kot(cur->_data) < kot(parent->_data)) // 新结点值比叶子(父)结点小
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
        return make_pair(iterator(newnode), true);
    }
    // 查找函数
    iterator Find(const K& key)
    {
        Node* cur = _root;
        KeyOfT kot;
        while (cur)
        {
            if (key < kot(cur->_kv.first)) // key小于当前结点的key值
            {
                cur = cur->_left; // 在当前结点的左子树中查找
            }
            else if (key > kot(cur->_kv.first)) // key大于当前结点的key值
            {
                cur = cur->_right; // 在当前结点的右子树中查找
            }
            else // 找到了
            {
                return iterator(cur); // 返回当前结点的迭代器
            }
        }
        return end(); // 查找失败
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
    // 迭代器相关
    iterator begin()
    {
        Node* cur = _root;
        while(cur && cur->_left) // 找最左结点
        {
            cur = cur->_left;
        }
        return iterator(cur); // 构造一个迭代器并返回
    }
    iterator end()
    {
        return iterator(nullptr);
    }
    reverse_iterator rbegin()
    {
        Node* right = _root;
        while (right&&right->_right) //寻找最右结点
        {
            right = right->_right;
        }
        return reverse_iterator(iterator(right));
    }
    reverse_iterator rend()
    {
        return reverse_iterator(iterator(nullptr));
    }
private:
    Node *_root = nullptr;
};