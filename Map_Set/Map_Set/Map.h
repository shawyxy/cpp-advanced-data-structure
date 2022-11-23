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
    private:
        RBTree<K, pair<K, V>> _t;
    };
}
