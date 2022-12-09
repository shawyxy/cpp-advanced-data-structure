#include "HashTable.h"
namespace xy
{
    template<class K, class V, class Hash = HashFunc<K>>
    class unordered_map
    {
        struct MapKeyOfT
        {
            const K& operator()(const pair<K, V>& kv)
            {
                return kv.first;
            }
        };
    public:
        // ...
    private:
        HashTable<K, pair<K, V>, MapKeyOfT> _ht;
    };

}
