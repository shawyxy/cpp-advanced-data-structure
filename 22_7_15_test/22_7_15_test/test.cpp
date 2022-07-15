#include <iostream>
using namespace std;
namespace A
{
	int add(int a, int b)
	{
		return a + b;
	}
	double add(double a, double b)
	{
		return a + b;
	}
}

void func1(int a = 10, int b = 20, int c = 30)
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl << endl;
}
int main()
{
	cout << "hello" << endl;
	int a = 1, b = 2;
	double c = 1.1, d = 2.2;
	cout << A::add(a, b) << endl << A::add(c, d) << endl;
	func1(1);
	func1(1, 2);
	func1(1, 2, 3);
	func1(3);

	return 0;
}