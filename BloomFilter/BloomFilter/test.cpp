#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
using namespace std;
#include "BloomFilter.h"
void TestBloomFilter1()
{
	BloomFilter<10> bf;
	string arr1[] = { "����", "����", "�㽶", "����", "ƻ��", "��÷", "����", "ƻ��", "�㽶", "ƻ��", "â��" };

	for (auto& str : arr1)
	{
		bf.Set(str);
	}

	for (auto& str : arr1)
	{
		cout << bf.Test(str) << endl;
	}
	cout << endl << endl;

	string arr2[] = { "����1", "����1", "�㽶", "����2", "ƻ��1", "��÷", "����3", "ƻ��2", "�㽶", "ƻ��3", "â��" };

	for (auto& str : arr2)
	{
		cout << str << ":" << bf.Test(str) << endl;
	}
}

void TestBloomFilter2()
{
	srand(time(0));
	const size_t N = 100000;
	BloomFilter<N> bf;
	cout << sizeof(bf) << endl;

	std::vector<std::string> v1;
	std::string url = "https://blog.csdn.net/chenlong_cxy/article/details/126525366";

	for (size_t i = 0; i < N; ++i)
	{
		v1.push_back(url + std::to_string(1234 + i));
	}

	for (auto& str : v1)
	{
		bf.Set(str);
	}

	// ����
	std::vector<std::string> v2;
	for (size_t i = 0; i < N; ++i)
	{
		std::string url = "https://blog.csdn.net/chenlong_cxy/article/details/126525366";
		url += std::to_string(rand() + i);
		v2.push_back(url);
	}

	size_t n2 = 0;
	for (auto& str : v2)
	{
		if (bf.Test(str))
		{
			++n2;
		}
	}
	cout << "�����ַ���������:" << (double)n2 / (double)N << endl;

	std::vector<std::string> v3;
	for (size_t i = 0; i < N; ++i)
	{
		string url = "zhihu.com";
		url += std::to_string(rand() + i);
		v3.push_back(url);
	}

	size_t n3 = 0;
	for (auto& str : v3)
	{
		if (bf.Test(str))
		{
			++n3;
		}
	}
	cout << "�������ַ���������:" << (double)n3 / (double)N << endl;
}
int main()
{
	TestBloomFilter1();
	TestBloomFilter2();

	return 0;
}