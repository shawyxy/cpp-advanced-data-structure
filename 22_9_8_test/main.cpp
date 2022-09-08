#include <iostream>
using namespace std;
int func(int a, int b, int c)
{
    int d = 0;
    d = a > b ? a : b;
    d = d > c ? d : c;
    return d;
}

int main()
{
    int a = 0, b = 0, c = 0;
    while(scanf("%d %d %d", &a, &b, &c) != EOF)
    {
        cout << func(a, b, c) << endl;
    }

    return 0;
}

//int main()
//{
//    int n = 0;
//    cin >> n;
//    int num = 1;
//    for(int i = 1; i <= n; i++)
//    {
//        for(int j = 0; j < i; j++)
//        {
//            cout << num++ << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}
//int main()
//{
//    int n = 0, a = 0, b = 0;
//    int i = 1;
//    cin >> n;
//    while(n--)
//    {
//        cin >> a >> b;
//        cout <<"Case #" << i++ << ":" << endl << a + b << endl;
//    }
//    return 0;
//}
