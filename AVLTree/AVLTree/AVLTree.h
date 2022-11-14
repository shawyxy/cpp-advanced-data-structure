#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

// 定义结点类
template <class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	pair<K, V> _kv; // 键值对
	int _bf; // 平衡因子

	AVLTreeNode(const pair<K, V>& kv)// 构造函数
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}
};

// AVLTree类
template <class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;

public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr) // 空树，直接插入即可
		{
			Node* newnode = new Node(kv);
			_root = newnode;
			return true;
		}

		// 树非空，根据二叉搜索树的查找规则找到能插入的位置
		Node* parent = nullptr;// 定义parent保存cur的父结点
		Node* cur = _root; // 从根结点开始查找位置

		while (cur)
		{
			if (kv.first < cur->_kv.first) // 如果参数的key比cur的key小
			{
				parent = cur;
				cur = cur->_left; // 往左子树走
			}
			else if (kv.first > cur->_kv.first) // 如果参数的key比cur的key大
			{

				parent = cur;
				cur = cur->_right;// 往右子树走
			}
			else // 相等
				return false;
		}

		// 跳出循环，已经找到插入的位置
		// 此时cur为空，parent是叶子结点
		// 比较参数key和叶子结点的key以作为它的左或右孩子
		cur = new Node(kv);
		if (kv.first < parent->_kv.first) // 参数key更小
		{
			//parent->_left = new Node(kv); // 新结点作为叶子结点的左孩子
			parent->_left = cur;
		}
		else
		{
			//parent->_right = new Node(kv); // 新结点作为叶子结点的右孩子
			parent->_right = cur;
		}
		// 插入完毕
		// 从新插入的结点的父结点的祖先节点路径往上更新
		cur->_parent = parent;
		// 更新平衡因子
		while (parent)
		{
			if (parent->_right == cur) // 插入在右边，bf+1
			{
				parent->_bf++;
			}
			else // 插入在左边，bf-1
			{
				parent->_bf--;
			}

			if (parent->_bf == 0) // 直到符合AVL树的规则停止
			{
				break;
			}
			else if (abs(parent->_bf) == 1) // 往上调整
			{
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (abs(parent->_bf) == 2) // 不平衡
			{
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent); // 左单旋
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent); // 右单旋
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent); // 左右双旋
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateLR(parent); // 右左双旋
				}
				else // 说明还没插入之前树就已经有问题了
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
private:
	// 右单旋函数
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* pParent = parent->_parent; // 保存父结点的父结点

		parent->_left = subLR; // 重建subLR和parent联系
		if (subLR != nullptr)
		{
			subLR->_parent = parent;
		}

		subL->_right = parent;// 重建subL和parent联系
		parent->_parent = subL;


		if (parent == _root) // 父结点为根结点，旋转后的subR作为根结点，无父结点
		{
			_root = subL;
			subL->_parent = nullptr;
		}

		if (pParent->_left == parent)
		{
			pParent->_left = subL;
		}
		else
		{
			pParent->_right = subL;
		}

		subL->_bf = 0; // 更新平衡因子
		parent->_bf = 0;
	}
	// 左单旋函数
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* pParent = parent->_parent; // 保存父结点的父结点

		parent->_right = subRL; // 重建subRL和parent联系
		if (subRL != nullptr)
		{
			subRL->_parent = parent;
		}

		subR->_left = parent;// 重建subR和parent联系
		parent->_parent = subR;


		if (parent == _root) // 父结点为根结点，旋转后的subR作为根结点，无父结点
		{
			_root = subR;
			subR->_parent = nullptr;
		}

		if (pParent->_left == parent)
		{
			pParent->_left = subR;
		}
		else
		{
			pParent->_right = subR;
		}

		subR->_bf = 0; // 更新平衡因子
		parent->_bf = 0;
	}
	// 左右双旋函数
	void RotateLR(Node* parent);
	// 右左双旋函数
	void RotateRL(Node* parent);
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
private:
	Node* _root = nullptr;
};