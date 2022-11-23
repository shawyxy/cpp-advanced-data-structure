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
                return key; // ·Âº¯Êý·µ»Økey
            }
        };
    public:

    private:
        RBTree<K, K> _t;
    };
}
