//
// Created by 肖越 on 2022/9/17.
//

#ifndef INC_22_9_17_VECTOR1_MYVECTOR_H
#define INC_22_9_17_VECTOR1_MYVECTOR_H

#endif //INC_22_9_17_VECTOR1_MYVECTOR_H
#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace xy {
    template<class T>
    class vector {
    public:
        //vector的空间是由指针维护的
        typedef T *iterator;
        typedef const T *const_iterator;

        //迭代器
        iterator begin() {
            return _start;
        }

        iterator end() {
            return _finish;
        }

        //const
        const_iterator begin() const {
            return _start;
        }

        const_iterator end() const {
            return _finish;
        }

        size_t size() const {
            return _finish - _start;
        }

        size_t capacity() const {
            return _end_of_storage - _start;
        }

        bool empty() {
            return capacity() == size();
        }

        T &operator[](size_t pos) {
            assert(pos < size());
            return _start[pos];
        }

        const T &operator[](size_t pos) const {
            assert(pos < size());
            return _start[pos];
        }

        T &front() {
            return *_start;
        }

        const T &front() const {
            return *_start;
        }

        T &back() {
            return *(_finish - 1);
        }

        const T &back() const {
            return *(_finish - 1);
        }

        vector<T> &operator=(vector<T> &v) {
            swap(v);
            return *this;
        }

        void swap(vector<T> &v) {
            std::swap(v._start, _start);
            std::swap(v._finish, _finish);
            std::swap(v._end_of_storage, _end_of_storage);
        }

        //构造函数
        //1.无参
        //由于初始化的重要性,使用初始化列表
        vector()
                : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {}

        //2.有参
        //v2(v1)
        //传统写法
//        vector(const vector<T>& v)
//                :_start(nullptr)
//                , _finish(nullptr)
//                , _end_of_storage(nullptr)
//        {
//            _start = new T[v.size()];//开相同大小的内存
//            //memcpy(_start, v._start, v.size());
//            for(size_t i = 0; i < v.size(); i++)//拷贝数据
//            {
//                _start[i] = v._start[i];
//            }
//            _finish = _start + v.size();
//            _end_of_storage = _start + v.capacity();
//        }
        //v2(v1)
        //新写法1
        vector(const vector<T>& v)
                : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {
            vector<T> tmp = v;
            swap(tmp);
        }

        //构造n个val值
        vector(size_t n, const T &val = T())//这里的T()是T类型的默认构造
                : _start(nullptr), _finish(nullptr), _end_of_storage(nullptr) {
            reserve(n);
            for (size_t i = 0; i < n; i++) {
                _start[i] = val;
            }
        }

        //任意容器的迭代器区间构造
        template<class InputIterator>
        vector(InputIterator begin, InputIterator end)
                :_start(nullptr)
                , _finish(nullptr)
                , _end_of_storage(nullptr)
        {
            while (begin < end)
            {
                push_back(*begin);
                begin++;
            }
        }

        //析构函数
        ~vector() {
            assert(_start);

            delete[] _start;
            _start = nullptr;
            _finish = nullptr;
            _end_of_storage = nullptr;
        }

        void reserve(size_t n) {
            size_t len = size();
            if (n > capacity())//空间不够就扩容
            {
                T *tmp = new T[n];
                for (size_t i = 0; i < len; i++) {
                    tmp[i] = _start[i];
                }
                delete[] _start;//释放原空间

                //更新新空间的成员变量
                _start = tmp;
                _finish = _start + len;
                _end_of_storage = _start + n;
            }
        }

        void resize(size_t n, const T &val) {
            //1.要修改的容量小于当前元素个数
            if (n < size()) {
                _finish = _start + n;//将个数更新到第n个
                return;
            }
            //2.大于容量,扩容
            if (n > capacity()) {
                reserve(n);
            }
            //3.介于两者之间,直接增加size且尾插n个元素
            iterator begin = _finish;
            _finish = _start + n;
            while (begin < _finish) {
                *begin = val;
                begin++;
            }
        }

        iterator insert(iterator pos, const T &x) {
            assert(pos <= _finish);

            if (size() == capacity())//扩容
            {
                size_t newCapacity = (capacity() == 0) ? 4 : (capacity() * 2);
                reserve(newCapacity);

                //更新pos
                pos = _start + size();
            }
            //挪动数据
            iterator end = _finish - 1;
            while (end >= pos) {
                *(end + 1) = *end;
                end--;
            }
            *pos = x;//插入
            _finish++;//更新长度
            return pos;//返回插入的位置的迭代器
        }

        void push_back(const T &x) {
            insert(end(), x);
        }

        void pop_back() {
            assert(_finish > _start);
            _finish--;
        }

        //返回值是要删除的位置
        iterator erase(iterator pos, const T &x) {
            iterator end = pos + 1;
            while (end >= pos) {
                *(end + 1) = *end;
                end--;
            }
            *pos = x;
            _finish--;

            return pos;
        }

    private:
        iterator _start;//元素开始(结合图示)
        iterator _finish;//元素末尾
        iterator _end_of_storage;//容量的末尾
    };

    void Test1() {
        xy::vector<int> v1;
        xy::vector<int> v2(10, 5);

        int array[] = {1, 2, 3, 4, 5};
        xy::vector<int> v3(array, array + sizeof(array) / sizeof(array[0]));

        xy::vector<int> v4(v3);

        for (size_t i = 0; i < v2.size(); ++i) {
            cout << v2[i] << " ";
        }
        cout << endl;

        auto it = v3.begin();
        while (it != v3.end()) {
            cout << *it << " ";
            ++it;
        }
        cout << endl;

        for (auto e: v4) {
            cout << e << " ";
        }
        cout << endl;
    }

    void Test2() {
        xy::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        cout << v.size() << endl;
        cout << v.capacity() << endl;
        cout << v.front() << endl;
        cout << v.back() << endl;
        cout << v[0] << endl;
        for (auto e: v) {
            cout << e << " ";
        }
        cout << endl;

        v.pop_back();
        v.pop_back();
        for (auto e: v) {
            cout << e << " ";
        }
        cout << endl;

        v.insert(v.begin(), 0);
        for (auto e: v) {
            cout << e << " ";
        }
        cout << endl;

        v.erase(v.begin() + 1);
        for (auto e: v) {
            cout << e << " ";
        }
        cout << endl;
    }
}

namespace bit
{
    template<class T>
    class vector
    {
    public:
        // Vector的迭代器是一个原生指针
        typedef T* iterator;
        typedef const T* const_iterator;

        ///////////////////////////////////////////////////
        // 构造和销毁
        vector()
                : _start(nullptr)
                , _finish(nullptr)
                , _endOfStorage(nullptr)
        {}

        vector(size_t n, const T& value = T())
                : _start(nullptr)
                , _finish(nullptr)
                , _endOfStorage(nullptr)
        {
            reserve(n);
            while (n--)
            {
                push_back(value);
            }
        }

        /*
        * 理论上将，提供了vector(size_t n, const T& value = T())之后
        * vector(int n, const T& value = T())就不需要提供了，但是对于：
        * vector<int> v(10, 5);
        * 编译器在编译时，认为T已经被实例化为int，而10和5编译器会默认其为int类型
        * 就不会走vector(size_t n, const T& value = T())这个构造方法，
        * 最终选择的是：vector(InputIterator first, InputIterator last)
        * 因为编译器觉得区间构造两个参数类型一致，因此编译器就会将InputIterator实例化为int
        * 但是10和5根本不是一个区间，编译时就报错了
        * 故需要增加该构造方法
        */
        vector(int n, const T& value = T())
                : _start(new T[n])
                , _finish(_start+n)
                , _endOfStorage(_finish)
        {
            for (int i = 0; i < n; ++i)
            {
                _start[i] = value;
            }
        }

        // 若使用iterator做迭代器，会导致初始化的迭代器区间[first,last)只能是vector的迭代器
        // 重新声明迭代器，迭代器区间[first,last)可以是任意容器的迭代器
        template<class InputIterator>
        vector(InputIterator first, InputIterator last)
        {
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        vector(const vector<T>& v)
                : _start(nullptr)
                , _finish(nullptr)
                , _endOfStorage(nullptr)
        {
            reserve(v.capacity());
            iterator it = begin();
            const_iterator vit = v.cbegin();
            while (vit != v.cend())
            {
                *it++ = *vit++;
            }
            _finish = it;
        }

        vector<T>& operator=(vector<T> v)
        {
            swap(v);
            return *this;
        }

        ~vector()
        {
            if (_start)
            {
                delete[] _start;
                _start = _finish = _endOfStorage = nullptr;
            }
        }

        /////////////////////////////////////////////////////
        // 迭代器相关
        iterator begin()
        {
            return _start;
        }

        iterator end()
        {
            return _finish;
        }

        const_iterator cbegin() const
        {
            return _start;
        }

        const_iterator cend() const
        {
            return _finish;
        }

        //////////////////////////////////////////////////
        // 容量相关
        size_t size() const
        {
            return _finish - _start;
        }

        size_t capacity() const
        {
            return _endOfStorage - _start;
        }

        bool empty() const
        {
            return _start == _finish;
        }

        void reserve(size_t n)
        {
            if (n > capacity())
            {
                size_t oldSize = size();
                // 1. 开辟新空间
                T* tmp = new T[n];

                // 2. 拷贝元素
                // 这里直接使用memcpy会有问题吗？同学们思考下
                //if (_start)
                //	memcpy(tmp, _start, sizeof(T)*size);

                if (_start)
                {
                    for (size_t i = 0; i < oldSize; ++i)
                        tmp[i] = _start[i];

                    // 3. 释放旧空间
                    delete[] _start;
                }

                _start = tmp;
                _finish = _start + oldSize;
                _endOfStorage = _start + n;
            }
        }

        void resize(size_t n, const T& value = T())
        {
            // 1.如果n小于当前的size，则数据个数缩小到n
            if (n <= size())
            {
                _finish = _start + n;
                return;
            }

            // 2.空间不够则增容
            if (n > capacity())
                reserve(n);

            // 3.将size扩大到n
            iterator it = _finish;
            _finish = _start + n;
            while (it != _finish)
            {
                *it = value;
                ++it;
            }
        }

        ///////////////////////////////////////////////////////////
        // 元素访问
        T& operator[](size_t pos)
        {
            assert(pos < size());
            return _start[pos];
        }

        const T& operator[](size_t pos)const
        {
            assert(pos < size());
            return _start[pos];
        }

        T& front()
        {
            return *_start;
        }

        const T& front()const
        {
            return *_start;
        }

        T& back()
        {
            return *(_finish - 1);
        }

        const T& back()const
        {
            return *(_finish - 1);
        }
        /////////////////////////////////////////////////////
        // vector的修改操作
        void push_back(const T& x)
        {
            insert(end(), x);
        }

        void pop_back()
        {
            erase(end() - 1);
        }

        void swap(vector<T>& v)
        {
            std::swap(_start, v._start);
            std::swap(_finish, v._finish);
            std::swap(_endOfStorage, v._endOfStorage);
        }

        iterator insert(iterator pos, const T& x)
        {
            assert(pos <= _finish);

            // 空间不够先进行增容
            if (_finish == _endOfStorage)
            {
                //size_t size = size();
                size_t newCapacity = (0 == capacity()) ? 1 : capacity() * 2;
                reserve(newCapacity);

                // 如果发生了增容，需要重置pos
                pos = _start + size();
            }

            iterator end = _finish - 1;
            while (end >= pos)
            {
                *(end + 1) = *end;
                --end;
            }

            *pos = x;
            ++_finish;
            return pos;
        }

        // 返回删除数据的下一个数据
        // 方便解决:一边遍历一边删除的迭代器失效问题
        iterator erase(iterator pos)
        {
            // 挪动数据进行删除
            iterator begin = pos + 1;
            while (begin != _finish) {
                *(begin - 1) = *begin;
                ++begin;
            }

            --_finish;
            return pos;
        }
    private:
        iterator _start;		// 指向数据块的开始
        iterator _finish;		// 指向有效数据的尾
        iterator _endOfStorage;  // 指向存储容量的尾
    };

    /// /////////////////////////////////
/// 对模拟实现的vector进行严格测试
    void Test1()
    {
        bit::vector<int> v1;
        bit::vector<int> v2(10, 5);

        int array[] = { 1,2,3,4,5 };
        bit::vector<int> v3(array, array+sizeof(array)/sizeof(array[0]));

        bit::vector<int> v4(v3);

        for (size_t i = 0; i < v2.size(); ++i)
        {
            cout << v2[i] << " ";
        }
        cout << endl;

        auto it = v3.begin();
        while (it != v3.end())
        {
            cout << *it << " ";
            ++it;
        }
        cout << endl;

        for (auto e : v4)
        {
            cout << e << " ";
        }
        cout << endl;
    }

    void Test2()
    {
        bit::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(4);
        v.push_back(5);
        cout << v.size() << endl;
        cout << v.capacity() << endl;
        cout << v.front() << endl;
        cout << v.back() << endl;
        cout << v[0] << endl;
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;

        v.pop_back();
        v.pop_back();
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;

        v.insert(v.begin(), 0);
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;

        v.erase(v.begin() + 1);
        for (auto e : v)
        {
            cout << e << " ";
        }
        cout << endl;
    }

}

