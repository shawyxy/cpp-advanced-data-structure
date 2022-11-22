#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
using namespace std;

void unordered_map_test1()
{
	unordered_set<int> us1;							 // 构造int类型的空容器

	string str = "hello world";
	unordered_set<char> us2(str.begin(), str.end()); // 使用迭代器区间构造
	
	unordered_set<int> us3(us1);					 // 拷贝构造
}
void unordered_map_test2()
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
int main()
{
	//unordered_map_test1();
	unordered_map_test2();
	return 0;
}