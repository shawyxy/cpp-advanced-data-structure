#include<iostream>
using namespace std;
#include <string>
#include <vector>
#include "CloseHashTable.h"

void CloseHashTableTest1()
{
	HashTable<int, int> ht;

	ht.Insert(make_pair(1, 1));
	ht.Insert(make_pair(2, 2));
	ht.Insert(make_pair(3, 3));
	ht.Insert(make_pair(3, 13));
    ht.Erase(1);
	ht.Print();
}
int main()
{
	CloseHashTableTest1();
	return 0;
}