#pragma once

// 枚举常量表示位置状态
enum State
{
    EMPTY,
    EXIST,
    DELETE
};


// 哈希表中每个位置的存储结构
template<class K, class V>
struct HashData
{
    pair<K, V> _kv;
    State _state = EMPTY;
};

// 仿函数
template<class K>
struct HashFunc
{
    size_t operator()(const K& key)
    {
        return (size_t)key;
    }
};
// BKDRHash算法
template<>
struct HashFunc<string>
{
    size_t operator()(const string& key)
    {
        size_t ret = 0;
        for(auto& e : key)
        {
            ret *= 131;
            ret += e;
        }
        return ret;
    }
};

template<class K, class V, class Hash = HashFunc<K>>
class HashTable
{
public:
    // 查找函数
    HashData<K, V>* Find(const K& key) 
    {
        if(_table.size() == 0)
        {
            return nullptr;
        }

        size_t
    }
private:
    vector<HashData<K, V>> _table; // 哈希表
    size_t _n = 0;                 // 负载因子
};