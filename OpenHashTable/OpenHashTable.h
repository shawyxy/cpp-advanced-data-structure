#pragma once

template<class K, class V>
struct HashNode
{
    pair<K, V> _kv;                 // 键值对,保存数据
    HashNode<K, V>* _next;          // 后继指针
    HashNode(const pair<K, V> kv)   // 结点构造函数
        :_kv(kv)
        , _next(nullptr)
    {}
};

template<class K, class V>
class HashTable
{
    typedef HashNode<K, V> Node;
public:
    // 析构函数
    ~HashTable()
    {
        for (size_t i = 0; i < _table.size(); i++)
        {
            Node* cur = _table[i];
            while (cur)
            {
                Node* next = cur->_next;
                free(cur);
                cur = next;
            }
            _table[i] = nullptr;
        }
    }
    // 查找函数
    HashNode<K, V>* Find(const K& key)
    {
        if(_table.size() == 0)
        {
            return nullptr;
        }

        size_t pos = key % _table.size();   // 得到下标值
        HashNode<K, V>* cur = _table[pos];  // 找到哈希桶首地址
        while (cur)                         // 遍历链表
        {
            if (cur->_kv.first == key)
            {
                return cur;
            }
            cur = cur->_next;
        }
        return nullptr;
    }
    // 插入函数
    bool Insert(const pair<K, V>& kv)
    {
        if(Find(kv.first) != nullptr) // 元素已经存在
        {
            return false;
        }

        // 扩容操作
        if(_size == _table.size())
        {
            size_t oldSize = _table.size();
            size_t newSize = oldSize == 0 ? 10 : 2 * oldSize;
            vector<Node*> newTable;                         // 建立新表
            newTable.resize(newSize);                       // 扩容
            for(size_t i = 0; i < oldSize; i++)             // 转移数据
            {
                Node* cur = _table[i];                      // 下标i对应的链表的首地址
                while(cur)
                {
                    Node* next = cur->_next;

                    size_t hashi = cur->_kv.first % newSize;// 新下标值
                    cur->_next = newTable[hashi];           // 重新链接
                    newTable[hashi] = cur;

                    cur = next;                             // 链表向后迭代
                }
                _table[i] = nullptr;
            }
            _table.swap(newTable);                          // 替换新哈希表
        }

        // 头插元素
        size_t hashi = kv.first % _table.size();
        Node* newnode = new Node(kv);
        newnode->_next = _table[hashi];
        _table[hashi] = newnode;
        _size++;

        return true;
    }
    // 删除函数
    bool Erase(const K& key)
    {
        size_t pos = key % _table.size();       // 得到key值对应的哈希桶下标
        Node* prev = nullptr;
        Node* cur = _table[pos];
        while (cur)
        {
            if(cur->_kv.first == key)           // 找到和key值对应的结点
            {
                if (prev == nullptr)            // 找到的结点在链表首部
                {
                    _table[pos] = cur->_next;   // 直接将头部往后移动一个单位
                }
                else                            // 找到的结点不在链表首部
                {
                    prev->_next = cur->_next;   // 直接跳过它即可
                }

                delete cur;                     // 释放结点资源
                _size--;                        // 更新计数器
                return true;
            }
            prev = cur;                         // 迭代
            cur = cur->_next;
        }
        return false;
    }
    // 打印函数
    void Print()
    {
        for (size_t i = 0; i < _table.size(); ++i)
        {
            Node* cur = _table[i];
            while(cur)
            {
                printf("[%d:%d]", i, cur->_kv.first);
                if(cur->_next)
                    printf("->");

                cur = cur->_next;
            }
            if(_table[i] == nullptr)
                printf("[%d:*] ", i);
            cout << endl;
        }
    }
private:
    vector<Node*> _table;       // 哈希表
    size_t _size = 0;           // 有效元素个数
};