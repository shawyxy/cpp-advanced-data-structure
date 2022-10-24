#include <iostream>
//#include <stdlib>
//void func(char para[100]) 
//{
//	void* p = malloc(100);
//	printf("%d, %d\n", sizeof(para), sizeof(p));
//}
//int main()
//{
//	char para[100];
//	func(para);
//
//	char a = 101;
//	int sum = 200; 
//	a += 27; 
//	sum += a;
//
//	printf("%d\n", sum);
//	return 0;
//}
void func(char* p) 
{ 
	p = p + 1; 
} 
int main()
{
	char s[] = { '1', '2', '3', '4' }; 
	func(s);
	printf("%c", *s);
	return 0;
}

