#pragma once
#include "RBTree.h"
namespace xy
{
    template<class K, class V>
    class map 
    {
        struct MapKeyOfT
        {
            const K& operator()(const pair<K, V>& kv)
            {
                return kv.first; // �º���ȡ����ֵK������
            }
        };
    public:
        typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::iterator iterator; //�������������
        typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::reverse_iterator reverse_iterator; //���巴�������

        //���뺯��
        pair<iterator, bool> insert(const pair<const K, V>& kv)
        {
            return _t.Insert(kv);
        }
        // []���������
        V& operator[](const K& key)
        {
            pair<iterator, bool> ret = insert(make_pair(key, V()));
            return ret = ret.first->second;
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
        RBTree<K, pair<K, V>, MapKeyOfT> _t;
    };
}
