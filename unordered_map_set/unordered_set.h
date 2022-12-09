#include "HashTable.h"
namespace xy
{
    template<class K, class Hash = HashFunc<K>>
    class unordered_set
    {
        struct SetKeyOfT
        {
            const K& operator()(const K& key)
            {
                return key;
            }
        };
    public:
        // ...
    private:
        HashTable<K, K, SetKeyOfT> _ht;
    };
}
