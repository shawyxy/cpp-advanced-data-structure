#pragma once
#include <iostream>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
using namespace std;

// 定义结点类
template <class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	pair<K, V> _kv;							// 键值对
	int _bf;								// 平衡因子

	AVLTreeNode(const pair<K, V>& kv)		// 构造函数
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}
};

// AVLTree类
template <class K, class V>
struct AVLTree
{
	typedef AVLTreeNode<K, V> Node;

public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)						// 空树，直接插入即可
		{
			Node* newnode = new Node(kv);
			_root = newnode;
			return true;
		}

													// 树非空，根据二叉搜索树的查找规则找到能插入的位置
		Node* parent = nullptr;						// 定义parent保存cur的父结点
		Node* cur = _root;							// 从根结点开始查找

		while (cur)
		{
			if (kv.first < cur->_kv.first)			// 如果参数的key比cur的key小
			{
				parent = cur;
				cur = cur->_left;					// 往左子树走
			}
			else if (kv.first > cur->_kv.first)		// 如果参数的key比cur的key大
			{

				parent = cur;
				cur = cur->_right;					// 往右子树走
			}
			else									// 相等
				return false;
		}

													// 跳出循环，已经找到插入的位置
													// 此时cur为空，parent是叶子结点,将cur更新为插入结点
													// 比较参数key和叶子结点的key以作为它的左或右孩子
		cur = new Node(kv);
		if (kv.first < parent->_kv.first)			// 参数key更小
		{
			//parent->_left = new Node(kv);			// 新结点作为叶子结点的左孩子
			parent->_left = cur;
		}
		else
		{
			//parent->_right = new Node(kv);		// 新结点作为叶子结点的右孩子
			parent->_right = cur;
		}
													// 插入完毕
													// 从新插入的结点的父结点的祖先节点路径往上更新
		cur->_parent = parent;
													// 更新平衡因子
		while (parent)
		{
			if (parent->_right == cur)				// 插入在右边，bf+1
			{
				parent->_bf++;
			}
			else									// 插入在左边，bf-1
			{
				parent->_bf--;
			}

			if (parent->_bf == 0)					// 直到符合AVL树的规则停止
			{
				break;
			}
			else if (abs(parent->_bf) == 1)			// 往上调整
			{
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (abs(parent->_bf) == 2)			// 不平衡
			{
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);				// 左单旋
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);				// 右单旋
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);				// 左右双旋
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);				// 右左双旋
				}
				else								// 说明还没插入之前树就已经有问题了
				{
					assert(false);
				}
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}
	// 中序遍历函数
	void InOrder() 
	{
		_InOrder(_root);
		cout << endl;
	}
    // 验证平衡因子是否正确
    bool IsBalance()
    {
        return _IsBalance(_root);
    }
private:
	// 右单旋函数
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* pParent = parent->_parent;				// 保存父结点的父结点

		parent->_left = subLR;							// 重建subLR和parent联系
		if (subLR != nullptr)
		{
			subLR->_parent = parent;
		}

		subL->_right = parent;							// 重建subL和parent联系
		parent->_parent = subL;


		if (parent == _root)							// 父结点为根结点，旋转后的subL作为根结点，无父结点
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
        subL->_bf = 0;									// 更新平衡因子
        parent->_bf = 0;
	}
	// 左单旋函数
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* pParent = parent->_parent;				// 保存父结点的父结点

		parent->_right = subRL;							// 重建subRL和parent联系
		if (subRL != nullptr)
		{
			subRL->_parent = parent;
		}

		subR->_left = parent;							// 重建subR和parent联系
		parent->_parent = subR;


		if (parent == _root)							// 父结点为根结点，旋转后的subR作为根结点，无父结点
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
        subR->_bf = 0;									// 更新平衡因子
        parent->_bf = 0;
	}
	// 左右双旋函数
	void RotateLR(Node* parent)
    {
        Node* subL = parent->_left;
        Node* subLR = subL->_right;
        int bf = subLR->_bf;

        RotateL(subL);
        RotateR(parent);

        if(bf == -1)
        {
            subL->_bf = 0;
            subLR->_bf = 0;
            parent->_bf = 1;
        }
        else if(bf == 1)
        {
            subL->_bf = -1;
            subLR->_bf = 0;
            parent->_bf = 0;
        }
        else if(bf == 0)
        {
            subL->_bf = 0;
            subLR->_bf = 0;
            parent->_bf = 0;
        }
        else
            assert(false);
    }
	// 右左双旋函数
	void RotateRL(Node* parent)
    {
        Node* subR = parent->_right;
        Node* subRL = subR->_left;
        int bf = subRL->_bf;

        RotateR(subR);
        RotateL(parent);

        if(bf == -1)
        {
            subR->_bf = 1;
            parent->_bf = 0;
            subRL->_bf = 0;
        }
        else if(bf == 1)
        {
            subR->_bf = 0;
            parent->_bf = -1;
            subRL->_bf = 0;
        }
        else if(bf == 0)
        {
            subR->_bf = 0;
            parent->_bf = 0;
            subRL->_bf = 0;
        }
        else
            assert(false);
    }
	// 中序遍历子函数
	void _InOrder(Node* root)
	{
		if (root == nullptr)
		{
			return;
		}

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}
    // 验证平衡因子 子函数
    bool _IsBalance(Node* root)
    {
        if(root == nullptr)
        {
            return false;
        }

        int leftH = Height(root->_left);
        int rightH = Height(root->_right);
        int diff = rightH - leftH;

        if(diff != root->_bf)
        {
            cout << root->_kv.first << "平衡因子异常" << endl;
            return false;
        }

        return abs(diff) < 2
            && _IsBalance(root->_left)
            && _IsBalance(root->_right);

    }
    int Height(Node* root)								// (子)树的高度等于结点高度+高的子树
    {
        if(root == nullptr)								// 空树高度为0
            return 0;

        return max(Height(root->_left), Height(root->_right)) + 1;
    }
private:
	Node* _root = nullptr;
};
