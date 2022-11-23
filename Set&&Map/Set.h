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
                return key; // 仿函数返回key
            }
        };
    public:

    private:
        RBTree<K, K> _t;
    };
}
