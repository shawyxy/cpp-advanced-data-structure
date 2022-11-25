#pragma once
#include "RBTree.h"
namespace xy
{
    template<class K>
    class set
    {
        struct SetKeyOfT
        {
            const K& operator()(const K& key)
            {
                return key;         // �º�������key
            }
        };
    public:
        typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator; // �������������
        typedef typename RBTree<K, K, SetKeyOfT>::reverse_iterator reverse_iterator; // ���巴�������

        //���뺯��
        pair<iterator, bool> insert(const K& key)
        {
            return _t.Insert(key);
        }
        // ���������
        iterator begin()
        {
            return _t.begin();
        }
        iterator end()
        {
            return _t.end();
        }
        reverse_iterator rbegin()
        {
            return _t.rbegin();
        }
        reverse_iterator rend()
        {
            return _t.rend();
        }

    private:
        RBTree<K, K, SetKeyOfT> _t;
    };
}
