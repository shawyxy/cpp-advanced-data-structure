#pragma once
#include <iostream>
#include <queue>
using namespace std;

namespace xy
{
    //定义适配器Container
    template<class T, class Container = std::deque<T>>//这里的deque可以设置自己想要的结构,比如vector或list
    class queue{
    public:
        void push(const T& x)
        {
            _con.push_back(x);
        }
        void pop()
        {
            _con.pop_front();
        }
        T& front()
        {
            return _con.front();
        }
        const T& front() const
        {
            return _con.front();
        }
        T& back()
        {
            return _con.back();
        }
        const T& back() const
        {
            return _con.back();
        }
        bool empty()
        {
            return _con.size() == 0;
        }
        const size_t size() const
        {
            return _con.size();
        }
        void swap(queue<T, Container>& st)
        {
            std::swap(st._con);
        }
    private:
        Container _con;//定义成员变量
    };
    /////// __TEST__ ////////
    void test1()
    {
        queue<int> st;
        st.push(1);
        st.push(2);
        st.push(3);
        st.push(4);
        st.push(5);
        cout << "size:" << st.size() << endl;
        while(!st.empty())
        {
            cout << st.front() << " ";
            st.pop();
        }
        cout << endl;
    }
}