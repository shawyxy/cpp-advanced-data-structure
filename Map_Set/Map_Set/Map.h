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
                return kv.first; // 仿函数取出键值K并返回
            }
        };
    public:
        typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::iterator iterator; //定义正向迭代器
        typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::reverse_iterator reverse_iterator; //定义反向迭代器

        //插入函数
        pair<iterator, bool> insert(const pair<const K, V>& kv)
        {
            return _t.Insert(kv);
        }
        // []运算符重载
        V& operator[](const K& key)
        {
            pair<iterator, bool> ret = insert(make_pair(key, V()));
            return ret = ret.first->second;
        }
        // 迭代器相关
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
