//#include <iostream>
//
//int main() {
//    float a = 1.11;
//    int b = a;
//    std::cout << b << std::endl;
//    return 0;
//}
//
//#include <iostream>
//#include <string>
//using namespace std;
////父类
//class Person
//{
//public:
//    int _num = 666;
//};
////子类
//class Student : public Person
//{
//public:
//    void fun()
//    {
//        cout << _num << endl;
//        cout << Person::_num << endl;
//    }
//private:
//    int _num = 111;
//};
//int main()
//{
//    Student s;
//    s.fun(); //111
//
//    return 0;
//}
//#include <iostream>
//using namespace std;
////父类
//class Person
//{
//public:
//    void fun(int x)
//    {
//        cout << x << endl;
//    }
//};
////子类
//class Student : public Person
//{
//public:
//    void fun(float x)
//    {
//        cout << x << endl;
//    }
//};
//int main()
//{
//    Student s;
//    s.fun(1);
//    s.fun(2.2);  // 根据参数列表选择父子类中的fun
//    return 0;
//}

//#include <iostream>
//using namespace std;
//class B;
//class A
//{
//public:
//    friend void Show(A& a, B& b);   // 在父类中声明友元
//
//    A(int a = 0)
//    {
//        _a = a;
//        cout << "A()" << endl;
//    }
//    ~A()
//    {
//        cout << "~A()" << endl;
//    }
//private:
//    int _a;
//};
//class B : public A
//{
//public:
//    friend void Show(A& a, B& b);   // 在子类中声明友元
//
//    B(int b = 0)
//    {
//        _b = b;
//        cout << "B()" << endl;
//    }
//    ~B()
//    {
//        A::~A();
//        cout << "~B()" << endl;
//    }
//private:
//    int _b;
//};
//class C : public A
//{
//public:
//    C(int a, int c)
//            :A(a)
//            , _c(c)
//    {}
//public:
//    int _c;
//};
//void Show(A& a, B& b)
//{
//    cout << a._a << endl; // 可以访问
//    cout << b._b << endl; // 不能访问
//}
//
//int main()
//{
//    //A a(1);
//    //B b(2);
//    //C c(1, 2);
//
//    A a(1);
//    B b(2);
//    Show(a, b);
//    return 0;
//}
//#include <iostream>
//#include <vector>
//using namespace std;
//
//int main()
//{
//    int n = 0, flag1 = 1, flag2 = 1;
//    cin >> n;
//    //cin.get();
//    vector<int> str;
//    str.resize(2 * n + 1);
//    for(int i = 1; i <= n; i++)
//    {
//
//        string tmp;
//
//        //getline(cin, tmp);
//        cin >> tmp;
//        str[2 * i - 1] = tmp[0];
//        str[2 * i] = tmp.size();
//        //cin.ignore();
//        //cin.get();
//    }
////    for(int i = 1; i < 2 * n + 1; i++)
////    {
////        cout << str[i] << " ";
////
////    }
//    for(int i = 1; i < n; )
//    {
//        if(str[2 * i - 1] == str[2 * i + 1])
//        {
//            i++;
//        }
//        else
//        {
//            if(i <= n - 1)
//                flag1 = 0;
//            break;
//        }
//    }
//    for(int i = 1; i < n; )
//    {
//        if(str[2 * i] == str[2 * (i + 1)])
//        {
//            i++;
//        }
//        else
//        {
//            if(i <= n - 1)
//                flag2 = 0;
//            break;
//        }
//    }
//
//    if(flag1 == 1 && flag2 == 1)
//    {
//        cout << "both" << endl;
//    }
//    else if(flag1 == 1 && flag2 != 1)
//    {
//        cout << "lexicographically" << endl;
//    }
//    else if(flag1 != 1 && flag2 == 1)
//    {
//        cout << "lengths" << endl;
//    }
//    else if(flag1 != 1 && flag2 != 1)
//    {
//        cout << "none" << endl;
//    }
//    return 0;
//}
//#include <iostream>
//using namespace std;
//class A
//{
//public:
//    A(int a = 0)
//    {
//        _a = a;
//        _sA++;
//    }
//    ~A()
//    {}
//private:
//    int _a;
//public:
//    static int _sA;
//
//};
//class B : public A
//{
//public:
//    B(int b = 0)
//    {
//        _b = b;
//        _sA++;
//    }
//    ~B()
//    {}
//private:
//    int _b;
//};
//int A::_sA = 99;
//
//int main()
//{
//    A a;
//    B b;
//    cout << A::_sA << endl;
//    cout << B::_sA << endl;
//
//    cout << &A::_sA << endl;
//    cout << &B::_sA << endl;
//    return 0;
//}
//
//#include <iostream>
//#include <string>
//using namespace std;
//class Person
//{
//public:
//    string _name; 	//姓名
//};
//class Student : public Person
//{
//protected:
//    int _num;	   //学号
//};
//class Teacher : public Person
//{
//protected:
//    int _id; 	   //编号
//};
//class Assistant : public Student, public Teacher
//{
//protected:
//    string _majorCourse; //主修课程
//};
//int main()
//{
//    Assistant a;
//    a._name = "xioaming"; //二义性：无法明确知道要访问哪一个_name
//    return 0;
//}
//
//#include <iostream>
//using namespace std;
//class UnusualAdd {
//public:
//    int addAB(int A, int B) {
//        // write code here
//        int sum = A;
//        while (B != 0)
//        {
//            A  = sum;
//            sum = A ^ B;
//            B =(A & B) << 1;
//        }
//        return sum;
//    }
//};
//int main()
//{
//
//    UnusualAdd u;
//    cout << u.addAB(1,2);
//    return 0;
//}
