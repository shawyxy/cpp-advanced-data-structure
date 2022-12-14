#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <bitset>
using namespace std;
//int main()
//{
//	bitset<16> bs1;
//	cout << bs1 << endl;
//	bitset<16> bs2(0xffffffff);
//	cout << bs2 << endl;
//	bitset<16> bs3(string("1010101001"));
//	cout << bs3 << endl;
//	return 0;
//}

void test1()
{
	bitset<8> bs;
	cout << "bitset<8> bs:" << bs << endl;

	bs.set();			// ��������λ
	cout << "bs.set():    " << bs << endl;

	bs.flip();			// ��ת����λ
	cout << "bs.flip():   " << bs << endl;

	bs.set(1);			// ���õ�1λ
	cout << "bs.set(1):   " << bs << endl;

	bs.reset(1);		// ��յ�1λ
	cout << "bs.reset(1): " << bs << endl;

	bs.flip(1);			// ��ת��1λ
	cout << "bs.flip(1):  " << bs << endl;

	int size = bs.size();// �ɱ�ʾλ�ĸ���
	cout << "bs.size():   " << size << endl;

	bool any = bs.any(); // �κ�һ��λ�����÷���true
	cout << "any be setted:" << any << endl;

	bs.reset();			 // �������λ
	bool none = bs.none();// û��λ�����÷���true
	cout << "none be setted:" << none << endl;
}
void test2()
{
	bitset<8> bs;
	cin >> bs;
	cout << bs << endl;
}
void test3()
{
	bitset<8> bs1(string("11100000"));
	bitset<8> bs2(string("00000111"));

	bool eql = bs1 != bs2;
	cout << "bs1!=bs2:  " << eql << endl;

	bs1 >>= 3;
	cout << "bs1>>3:    " << bs1 << endl;

	bs2 ^= bs1;
	cout << "bs2 ^= bs1:" << bs2 << endl;
}
void test4()
{
	bitset<8> bs1(string("10101010"));
	bitset<8> bs2(string("01010101"));

	cout << (bs1 & bs2) << endl;
	cout << (bs1 | bs2) << endl;
	cout << (bs1 ^ bs2) << endl;
}
void test5()
{
	bitset<8> bs(string("10101010"));
	cout << bs[1] << endl;
	bs[7] = 0;
	cout << bs << endl;
}
int main()
{
	test5();
	return 0;
}