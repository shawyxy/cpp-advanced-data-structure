#include <iostream>
using namespace std;
namespace name1
{
	int a = 10;
	int b;
	void func()
	{
		printf("namespace\n");
	}
}
//using namespace name1;
using name1::a;
using name1::func;
int main()
{
	func();
	printf("%d\n", a);
	return 0;
}