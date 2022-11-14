#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

// ��������
template <class K, class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	pair<K, V> _kv; // ��ֵ��
	int _bf; // ƽ������

	AVLTreeNode(const pair<K, V>& kv)// ���캯��
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
	{}
};

// AVLTree��
template <class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;

public:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr) // ������ֱ�Ӳ��뼴��
		{
			Node* newnode = new Node(kv);
			_root = newnode;
			return true;
		}

		// ���ǿգ����ݶ����������Ĳ��ҹ����ҵ��ܲ����λ��
		Node* parent = nullptr;// ����parent����cur�ĸ����
		Node* cur = _root; // �Ӹ���㿪ʼ����λ��

		while (cur)
		{
			if (kv.first < cur->_kv.first) // ���������key��cur��keyС
			{
				parent = cur;
				cur = cur->_left; // ����������
			}
			else if (kv.first > cur->_kv.first) // ���������key��cur��key��
			{

				parent = cur;
				cur = cur->_right;// ����������
			}
			else // ���
				return false;
		}

		// ����ѭ�����Ѿ��ҵ������λ��
		// ��ʱcurΪ�գ�parent��Ҷ�ӽ��
		// �Ƚϲ���key��Ҷ�ӽ���key����Ϊ��������Һ���
		cur = new Node(kv);
		if (kv.first < parent->_kv.first) // ����key��С
		{
			//parent->_left = new Node(kv); // �½����ΪҶ�ӽ�������
			parent->_left = cur;
		}
		else
		{
			//parent->_right = new Node(kv); // �½����ΪҶ�ӽ����Һ���
			parent->_right = cur;
		}
		// �������
		// ���²���Ľ��ĸ��������Ƚڵ�·�����ϸ���
		cur->_parent = parent;
		// ����ƽ������
		while (parent)
		{
			if (parent->_right == cur) // �������ұߣ�bf+1
			{
				parent->_bf++;
			}
			else // ��������ߣ�bf-1
			{
				parent->_bf--;
			}

			if (parent->_bf == 0) // ֱ������AVL���Ĺ���ֹͣ
			{
				break;
			}
			else if (abs(parent->_bf) == 1) // ���ϵ���
			{
				parent = parent->_parent;
				cur = cur->_parent;
			}
			else if (abs(parent->_bf) == 2) // ��ƽ��
			{
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent); // ����
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent); // �ҵ���
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent); // ����˫��
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateLR(parent); // ����˫��
				}
				else // ˵����û����֮ǰ�����Ѿ���������
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
	// �����������
	void InOrder() 
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	// �ҵ�������
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* pParent = parent->_parent; // ���游���ĸ����

		parent->_left = subLR; // �ؽ�subLR��parent��ϵ
		if (subLR != nullptr)
		{
			subLR->_parent = parent;
		}

		subL->_right = parent;// �ؽ�subL��parent��ϵ
		parent->_parent = subL;


		if (parent == _root) // �����Ϊ����㣬��ת���subR��Ϊ����㣬�޸����
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

		subL->_bf = 0; // ����ƽ������
		parent->_bf = 0;
	}
	// ��������
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;
		Node* pParent = parent->_parent; // ���游���ĸ����

		parent->_right = subRL; // �ؽ�subRL��parent��ϵ
		if (subRL != nullptr)
		{
			subRL->_parent = parent;
		}

		subR->_left = parent;// �ؽ�subR��parent��ϵ
		parent->_parent = subR;


		if (parent == _root) // �����Ϊ����㣬��ת���subR��Ϊ����㣬�޸����
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

		subR->_bf = 0; // ����ƽ������
		parent->_bf = 0;
	}
	// ����˫������
	void RotateLR(Node* parent);
	// ����˫������
	void RotateRL(Node* parent);
	// ��������Ӻ���
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