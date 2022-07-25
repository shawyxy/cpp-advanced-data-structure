//int main()
//{
//	int a = 1, b = 2;
//	std::cout << a << std::endl;
//	std::cout << b << std::endl;
//	return 0;
//}

//int main()
//{
//	int a = 1, b = 2;
//	cout << a << endl;
//	cout << b << endl;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//void Print(int a, int b)
//{
//	cout << a << " " << b << endl;
//}
//void Print(int a, double b)
//{
//	cout << a << " " << b << endl;
//}
//void Print(double a, int b)
//{
//	cout << a << " " << b << endl;
//}
//void Print(double a, double b)
//{
//	cout << a << " " << b << endl;
//}
//int main()
//{
//	Print(1, 2);
//	Print(1, 2.2);
//	Print(1.1, 2);
//	Print(1.1, 2.2);
//	return 0;
//}
//void func(int a, int b = 2, int c = 3)
//{
//	cout << a << endl;
//	cout << b << endl;
//	cout << c << endl;
//}
//int main()
//{
//	func(4, 5, 6);
//	return 0;
//}
//#include <iostream>
//using namespace std;
//extern "C" void func()
//{
//	cout << "extern" << endl;
//}
//int main()
//{
//	func();
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 20;
//	int& ra = a;
//
//	//double& ra = a;//引用类型不匹配
//	int rra = a;//一个对象可以有多个引用
//	int b = 10;
//	ra = b;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a = 20;
//	int& ra = a;//定义引用类型
//
//	cout << a << endl;
//	cout << ra << endl;
//	//打印地址
//	cout << &a << endl;
//	cout << &ra << endl;
//
//	return 0;
//}
//void swap(int& a, int& b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//int main()
//{
//	int a = 1, b = 2;
//	swap(a, b);
//	return 0;
//}
//struct A
//{
//	int a[100000];
//	int data;
//};
//void func(A& a)
//{
//	//statement
//}
//int main()
//{
//	A a;
//	
//	func(a);
//	return 0;
//}

//int& func()
//{
//	static int count = 0;
//	count++;
//	return count;
//}
//int main()
//{
//	int& ret = func();
//	cout << ret << endl;
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	//权限平移
//	int a = 10;
//	int& b = a;
//	//查看a和b的类型
//	cout << typeid(a).name() << endl;
//	cout << typeid(b).name() << endl;
//	//权限不能放大
//	const int c = 20;
//	const int& d = c;
//	//权限可以缩小
//	int e = 30;
//	const int& f = e;
//
//	cout << b << endl;
//	cout << d << endl;
//	cout << f << endl;
//	return 0;
//}
//#include <iostream>
//int main() 
//{
//    int a = 10;
//    int& ra = a;
//    ra = 20;
//    int* pa = &a;
//    *pa = 20;
//    return 0;
//}
//#include <iostream>
//using namespace std;
//#include "test.h"
//
//int main()
//{
//	cout << min(2, 1) << endl;
//	return 0;
//}
//#include <iostream>
//void func()
//{
//	auto b[] = { 1,2,3 };
//}
//int main()
//{
//	int a = 10;
//	int& ra = a;
//
//	auto b = 10; // int
//	auto c = &a; // int*
//	auto* cc = &a; // 强调只能是指针
//	auto d = a;  // int&
//	auto& dd = a; //强调只能是引用
//	
//	return 0;
//}
//#include <iostream>
//using namespace std;
//int main()
//{
//	int a[] = { 1,2,3 };
//
//	for (auto e : a)
//	{
//		e++;
//	}
//	for (auto e : a)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	for (auto& e : a)
//	{
//		e++;
//	}
//	for (auto e : a)
//	{
//		cout << e << " ";
//	}
//	return 0;
//}
#include <iostream>
using namespace std;
void f(int) { cout << "int" << endl; }

void f(int*) { cout << "int*" << endl; }

int main() {
    f(0);
    f(NULL);
    f((int*)NULL);
    return 0;
}
