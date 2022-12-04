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
// 字符串转整型
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
            if (_table.size() == 0)
            {
                return nullptr;
            }

            Hash hash;
            size_t size = _table.size();
            size_t start = hash(key) % size;    // 根据key值通过哈希函数得到下标值
            size_t hashi = start;

            while (_table[hashi]._state != EMPTY)
            {
                if (_table[hashi]._state != DELETE && _table[hashi]._kv.first == key)
                {
                    return &_table[hashi];
                }
                hashi++;
                hashi %= size;

                if (hashi == start)
                {
                    break;
                }
            }
            return nullptr;
        }

        bool Insert(const pair<K, V> kv)
        {
            if (Find(kv.first) != nullptr)            // 哈希表中已存在相同key值的元素
            {
                return false;
            }
            
            // 扩容操作
            if (_table.size() == 0 || _size * 10 / _table.size() >= 7) // 扩容
            {
                size_t newSize = _table.size() == 0 ? 10 : _table.size() * 2;
                
                HashTable<K, V, Hash> newHashTable;  // 创建新哈希表
                newHashTable._table.resize(newSize); // 扩容
                for (auto& e : _table) // 遍历原哈希表
                {
                    if (e._state == EXIST)
                    {
                        newHashTable.Insert(e._kv); // 映射到新哈希表
                    }
                }
                _table.swap(newHashTable._table);
            }

            // 插入操作
            Hash hash;
            size_t size = _table.size();
            size_t hashi = hash(kv.first) % size;   // 得到key值对应的哈希值
            while (_table[hashi]._state == EXIST)   // 线性探测
            {
                int i = 0;
                i++;
                hashi = (hashi + i) % size;
            }

            // 探测到空位置，下标是hashi
            _table[hashi]._kv = kv;                 // 插入元素，更新位置上的kv值
            _table[hashi]._state = EXIST;           // 更新位置的状态
            ++_size;                                // 更新有效元素个数

            return true;
        }
        // 删除函数
        bool Erase(const K& key)
        {
            HashData<K, V>* find = Find(key);
            if(find != nullptr)
            {
                find->_state = DELETE;
                _size--;
                return true;
            }
            return false;
        }

        void Print()
        {
            for (size_t i = 0; i < _table.size(); ++i)
            {
                if (_table[i]._state == EXIST)
                {
                    printf("[%d:%d] ", i, _table[i]._kv.first);
                }
                else
                {
                    printf("[%d:*] ", i);
                }
            }
            cout << endl;
        }
private:
    vector<HashData<K, V> > _table;                 // 哈希表
    size_t _size = 0;                               // 有效数据个数
};