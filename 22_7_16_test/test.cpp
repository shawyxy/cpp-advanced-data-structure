#include <iostream>
void func(char para[100]) {
	void* p = malloc(100);
	printf("%d, %d\n", sizeof(para), sizeof(p));
}
int main()
{
	char para[100];
	func(para);

	char a = 101;
	int sum = 200; a += 27; sum += a; 
	printf("%d\n", sum);
	return 0;
}