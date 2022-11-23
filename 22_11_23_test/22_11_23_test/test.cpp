#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

void unordered_set_test1()
{
	unordered_set<int> us1;							 // 构造int类型的空容器

	string str = "hello world";
	unordered_set<char> us2(str.begin(), str.end()); // 使用迭代器区间构造
	
	unordered_set<int> us3(us1);					 // 拷贝构造
}
void unordered_set_test2()
{
	unordered_set<int> us;

	us.insert(1);
	us.insert(1);		// 去重
	us.insert(2);
	us.insert(5);
	us.insert(4);
	us.insert(3);
	us.insert(6);

	for (auto e : us)	// 使用范围for遍历
	{
		cout << e << " ";
	}
	cout << endl;

	unordered_set<int>::iterator pos = us.find(2);  // 找到key为2的位置
	us.erase(pos);									// 删除key为2的元素
	unordered_set<int>::iterator it = us.begin();
	while (it != us.end())							// 迭代器遍历 
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	

	cout << us.count(1) << endl;	// 容器中key为1的元素个数

	cout << us.size() << endl;		// 容器中元素的个数

	us.clear();						// 清空容器

	cout << us.empty() << endl;
}
void unordered_set_test3()
{
	unordered_multiset<int> ums;

	ums.insert(1);
	ums.insert(1);
	ums.insert(2);
	ums.insert(7);
	ums.insert(5);
	ums.insert(4);
	ums.insert(2);

	for(auto e : ums)
	{
		cout << e << " ";
	}
	cout << endl;

}
void unordered_map_test()
{
	unordered_map<int, string> um;

	um.insert(make_pair(1, "一"));
	um.insert(make_pair(1, "一")); 
	um.insert(make_pair(2, "二")); 
	um.insert(make_pair(4, "四")); 
	um.insert(make_pair(3, "三")); 

	for (auto e : um)
	{
		cout << e.first << " ";
	}
	cout << endl;
}
void unordered_map_test1()
{
	unordered_map<int, string> um1; // 构造一个键值对为<int, string>的空容器

	unordered_map<int, string> um2(um1.begin(), um1.end()); // 迭代器区间构造

	unordered_map<int, string> um3(um1); // 拷贝构造
}
void unordered_map_test2()
{
	unordered_map<int, string> um;
	um.insert(make_pair(1, "一"));
	um.insert(make_pair(2, "二"));
	um.insert(make_pair(3, "三"));
	um.insert(make_pair(4, "四"));

	// 迭代器遍历
	unordered_map<int, string>::iterator it = um.begin();
	while (it != um.end())
	{
		cout << "<" << it->first << ", " << it->second << ">" << endl;
		it++;
	}
	cout << endl;

	// 删除key=2的元素
	um.erase(2);

	for (auto e : um)
	{
		cout << "<" << e.first << ", " << e.second << ">" << endl;
	}
	cout << endl;

	// 查找key=3的元素
	auto pos = um.find(3);
	if(pos != um.end())
	{
		cout << "<" << pos->first << ", " << pos->second << ">" << endl;
	}

	// 清空容器
	um.clear();
	// 容器判空
	cout << um.empty() << endl;
}
void unordered_multimap_test()
{
	unordered_multimap<int, string> umm;
	umm.insert(make_pair(1, "一"));
	umm.insert(make_pair(1, "first"));
	umm.insert(make_pair(1, "one"));
	for (auto e : umm)
	{
		cout << "<" << e.first << ", " << e.second << ">" << endl;
	}
	cout << endl;
}

int main()
{
	//unordered_set_test1();
	//unordered_set_test2();
	//unordered_set_test3();
	//unordered_map_test1();
	//unordered_map_test2();
	unordered_multimap_test();


	return 0;
}