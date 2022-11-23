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
    private:
        RBTree<K, pair<K, V>> _t;
    };
}
