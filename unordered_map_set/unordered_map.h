#include "HashTable.h"
template<class K, class V>
class unordered_map
{
    //仿函数
    struct MapKeyOfT
    {
        const K& operator()(const pair<K, V>& kv) //返回键值对当中的键值key
        {
            return kv.first;
        }
    };
public:
    //...
private:
    HashTable<K, pair<K, V>, MapKeyOfT> _ht;
};
