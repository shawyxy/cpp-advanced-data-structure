#include <iostream>
using namespace std;
template<class T>


class __list_node
{
public:
    __list_node(const T& val = T())
            :_next(nullptr)
            ,_pre(nullptr)
            ,node(val)
    {}
public:
    __list_node<T>* _next;
    __list_node<T>* _pre;
    T node;
};

template<class T>
class __list_itertaor//这里是迭代器
{
public:
    typedef __list_node<T>  Node;
    __list_itertaor(Node* node)
    {
        _node = node;
    }

    bool operator!=(const __list_itertaor<T>& it)
    {
        return _node != it._node;
    }
    __list_itertaor<T>& operator++()
    {
        _node = _node->_next;
        return *this;
    }
    T& operator*()
    {
        return _node->node;
    }
private:
    Node* _node;
};
template<class T>
void ListPrint(const __list_node<T>& ls)
{
    auto it = ls.begin();
    while(it != ls.end())
    {
        cout << *it << " ";
    }
    cout << endl;
}
int main() {
    return 0;
}
