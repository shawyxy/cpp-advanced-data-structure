//#include<stdio.h> //若用printf,scanf,getchar,putchar,gets,puts函数需包含该头文件
//#include<stdlib.h> //用malloc,free,realloc函数需包含该头文件
//
//#define MAXSIZE 100
//#define STACKINCREMENT 10
//
//typedef int STDataType;
//
//typedef struct STACK
//{
////请填写完整栈的数据结构
//    STDataType* data;//注意是数组形式
//    int top;
//    int capacity;
//}SqStack;
//
////函数声明
//int InitStack(SqStack &s);
//void ClearStack(SqStack &S);
//int StackEmpty(SqStack S);
//int StackLength(SqStack S);
//int GetTop(SqStack s,STDataType &e);
//int Push(SqStack &s,STDataType e);
//int Pop(SqStack &s,STDataType &e);
//
////初始化,创建空栈
//int InitStack(SqStack *pst)
//{
////请完善代码......
//    pst->data = (STDataType*)malloc(sizeof(STDataType) * 4);
//    pst->top = 0;
//    pst->capacity = 4;
//return 1;
//}
//
////清空栈
//void ClearStack(SqStack* pst)
//{
////请完善代码......
//}
//
////判栈空
//int StackEmpty(SqStack* pst)
//{
////请完善代码......
//}
//
////求栈中元素个数
//int StackLength(SqStack* pst)
//{
//  //请完善代码......
//}
//
////获取栈顶元素值
//int GetTop(SqStack* pst,STDataType &e)
//{
////请完善代码......
//return 1;
//}
//
////入栈
//int Push(SqStack* pst,STDataType e)
//{
////请完善代码......
//    return 1;
//}
//
////出栈
//int Pop(SqStack* pst,STDataType &e)
//{
////请完善代码......
//return  1;
//}
//
////打印栈中元素
//void PrintElem(SqStack* pst)
//{
////请完善代码......
//}
//
//
////主函数
//int main(){
//    STDataType e;
//SqStack S;//定义一个顺序栈
//int n,m;
//InitStack(S);//初始化顺序栈
//scanf("%d",&n);//请输入要入栈的元素个数
//for(int i=0;i<n;i++)
//{
//scanf("%d",&e);
//Push(S,e);//入栈
//}
//PrintElem(&S);//输出栈中元素
//printf("\n");
//scanf("%d",&m);//请输入要出栈的元素个数
//for(int i=0;i<m;i++)
//{
//   Pop(S,e);//出栈
//}
//GetTop(S,e);//输出栈顶元素
//printf("%d %d",e,StackLength(S));
//return 0;
//}
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

using namespace std;
#define MAXSIZE 100
#define STACKINCREMENT 10
typedef int ElemType;

typedef struct STACK
{
    ElemType *base;
    ElemType *top;
    int stacksize;
}SqStack;

//函数声明
int InitStack(SqStack& s);
void ClearStack(SqStack& S);
int StackEmpty(SqStack S);
int StackLength(SqStack S);
int GetTop(SqStack s, ElemType& e);
int Push(SqStack& s, ElemType e);
int Pop(SqStack& s, ElemType& e);

//初始化,创建空栈
int InitStack(SqStack& s){
    s.base = new ElemType[MAXSIZE];
    s.top = s.base;
    s.stacksize = MAXSIZE;
    return 1;
}

//清空栈
void ClearStack(SqStack& S)
{
    if (S.base)
        S.top = S.base;
}

//判栈空
int StackEmpty(SqStack S)
{
    if (S.top == S.base)
    {
        return true;
    }
    else {
        return false;
    }
}

//求栈中元素个数
int StackLength(SqStack S)
{
    return S.top - S.base;
}

//获取栈顶元素值
int GetTop(SqStack s, ElemType& e)
{
    if (s.top == s.base)
        return 0;
    e = *(--s.top);
    return 1;
}

//入栈
int Push(SqStack& s, ElemType e)
{
    if (s.top - s.base == s.stacksize)
        return 0;
    *s.top++ = e;
    return 1;
}

//出栈
int Pop(SqStack& s, ElemType& e)
{
    if (s.top == s.base)
        return 0;
    e = *(--s.top);
    return  1;
}

//打印栈中元素
void PrintElem(SqStack S)
{
    ElemType* p = S.base;
    while (p < S.top)
    {
        printf("%d ", *p);
        p++;
    }
}
void test1()
{
    ElemType e;
    SqStack S;//定义一个顺序栈
    int n, m;
    InitStack(S);//初始化顺序栈
    scanf("%d", &n);//请输入要入栈的元素个数
    for (int i = 0;i < n;i++)
    {
        scanf("%d", &e);
        Push(S, e);//入栈
    }
    PrintElem(S);//输出栈中元素
    printf("\n");
    scanf("%d", &m);//请输入要出栈的元素个数
    for (int i = 0;i < m;i++)
    {
        Pop(S, e);//出栈
    }
    GetTop(S, e);//输出栈顶元素
    printf("%d %d", e, StackLength(S));
}
void test2()
{
    int num = 0, option = 0;
    char str[100];
    int i = 0;

    scanf("%d %d", &num, &option);
    if(option == 8)
    {
        sprintf(str,"%o", num);//8
        cout << str << endl;
    }
    else if(option == 16)
    {
        sprintf(str,"%X", num);//16
        cout << str << endl;
    }
    else
    {
        string res;
        while(num)
        {
            str[i++] = num % 2;
            num /= 2;
        }
        for(i--; i >= 0; i--)
        {
            printf("%d",str[i]);
        }
    }
}
//主函数
int main() {
    test1();
    //test2();

    return 0;
}
//using namespace std;
//typedef int StackDataType;
//
//typedef struct ST
//{
//    StackDataType* a;
//    int size;
//    int capacity;
//}ST;
//
//void StackInit(ST* pst);
//void StackDestory(ST* pst);
//void StackPop(ST* pst);
//void StackPush(ST* pst, StackDataType x);
//StackDataType StackTop(ST* pst);
//bool StackEmpty(ST* pst);
//int StackSize(ST* pst);
//
//void StackInit(ST* pst)
//{
//    assert(pst);
//
//    pst->a = NULL;
//    pst->capacity = 0;
//    pst->size = 0;
//}
//void StackDestory(ST* pst)
//{
//    assert(pst);
//
//    free(pst->a);
//    pst->a = NULL;
//    pst->capacity = 0;
//    pst->size = 0;
//}
//void StackPop(ST* pst)
//{
//    assert(pst);
//    if (pst->size == 0)
//        return;
//
//    pst->size--;
//}
//void StackPush(ST* pst, StackDataType x)
//{
//    assert(pst);
//
//    if (pst->capacity == pst->size)
//    {
//        int newCapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
//        StackDataType* tmp = (StackDataType*)realloc(pst->a, sizeof(StackDataType) * newCapacity);
//        if (tmp == NULL)
//        {
//            printf("realloc failed\n");
//            exit(-1);
//        }
//        pst->a = tmp;
//    }
//    pst->a[pst->size] = x;
//    pst->size++;
//}
//StackDataType StackTop(ST* pst)
//{
//    assert(pst);
//    if (pst->size == 0)
//        return -1;
//
//    return pst->a[pst->size - 1];
//}
//bool StackEmpty(ST* pst)
//{
//    assert(pst);
//
//    return pst->size == 0;
//}
//int StackSize(ST* pst)
//{
//    assert(pst);
//
//    return pst->size;
//}
//
////主函数
//void test1()
//{
//    StackDataType e;
//    ST S;//定义一个顺序栈
//    int n,m;
//    StackInit(&S);//初始化顺序栈
//    scanf("%d",&n);//请输入要入栈的元素个数
//    for(int i=0;i<n;i++)
//    {
//        scanf("%d", &e);
//        StackPush(&S,e);//入栈
//    }
//    for(int i = 0; i < n ; i++)
//    {
//        cout << S.a[i] << ' ';
//    }
//    cout << endl;
//    scanf("%d",&m);//请输入要出栈的元素个数
//    for(int i=0;i<m;i++)
//    {
//        StackPop(&S);//出栈
//    }
//    printf("%d %d", StackTop(&S), StackSize(&S));
//}

