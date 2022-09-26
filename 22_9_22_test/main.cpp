//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct node{
//	char x;
//	struct node  *next;
//}Sqlist;
//
//int main()
//{
//	Sqlist *header = NULL;
//    Sqlist *p = NULL;
//	int n;
//	scanf("%d",&n);
//	getchar();
//	for(int i = 0; i < n; i++)
//	{
//		if(!header)
//		{
//			header = (node *)malloc(sizeof(node));
//			p = header;
//			scanf("%c",&(header -> x));
//			header -> next = NULL;
//		}
//		else
//		{
//			p->next = (node *)malloc(sizeof(node));
//            p = p->next;
//            scanf("%c", &(p->x));
//            p->next = NULL;
//		}
//	}
//
//	p = header;
//	int i = 0;
//	while(p)
//	{
//		if(i % 2 == 0)
//		{
//			printf("%c", p->x);
//
//		}
//		i++;
//		p = p->next;
//	}
//	return 0;
//}

//#include<stdio.h> //若用printf,scanf,getchar,putchar,gets,puts函数需包含该头文件
//#include<stdlib.h> //用malloc,free,realloc函数需包含该头文件
//
//#define MAXSIZE 100 //设线性表初始分配空间大小
//typedef int ElemType;  //先设定数据元素的类型为整型
//
////0：定义顺序表的结构类型
//typedef struct{
//    ElemType *elem;
//    int length;
//    int listsize;
//}SqList;
//
////1：初始化顺序表
//int InitList_Sq(SqList &L )
//{
//    L.elem=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
//    if (!L.elem) return 0;
//    L.length=0;
//    L.listsize=MAXSIZE;
//    return 1;
//}
//
////2：打印顺序表中所有元素
//void PrintList(SqList &L)
//{
//    int i;
//    for(i=0;i<L.length;i++)
//        printf("%d\n",L.elem[i]);
//}
//
////*****3：在顺序表中第i个位置(i=1~n)插入元素*****
//int ListInsert_Sq(SqList &L,int i,ElemType e){
//    if (i<1 || i>L.length+1)
//        return 0;
////--------补充代码--Start------
//    if(L.length >= MAXSIZE)
//        return 0;
//     int end = L.length;
//     while(end > i)
//     {
//         L.elem[end] = L.elem[end - 1];
//         end--;
//     }
//     L.elem[i - 1] = e;
//     L.length++;
//
////--------补充代码--End-------
//    return 1;
//}
//
////*****4：删除顺序表中第i(i=1~n)个元素，用e返回删除的元素*****
//int ListDelete_Sq(SqList &L, int i, ElemType &e)
//{
////--------补充代码--Start------
//if(i > L.length || i < 1)
//        return 0;
//    e = L.elem[i - 1];
//    int begin = i;
//    while(begin < L.length)
//    {
//        L.elem[begin - 1] = L.elem[begin];
//        begin++;
//    }
//    L.length--;
////--------补充代码--End-------
//    return 1;
//}
//
////主函数
//int main()
//{
////以下代码请认真阅读，切勿做任何修改
//    SqList La;
//    int i,n,e;
//
////初始化顺序表
//    InitList_Sq(La);
////输入元素个数
//    scanf("%d",&n);
////依次读取n个数据插入顺序表
//    for(i=1; i<=n; i++)
//    {
////输入数据元素
//        scanf("%d",&e);
////插入顺序表
//        ListInsert_Sq(La,i,e);
//    }
////按顺序输出顺序表中元素
//    PrintList(La);
//
////----------------------------
////输入要删除元素的位置
//    scanf("%d",&i);
////执行删除
//    ListDelete_Sq(La,i,e);
////输出删除后的元素
//    printf("%d\n",e);
////输出删除后的顺序表的内容
//    PrintList(La);
//    printf("%d\n",La.length);
//    return 0;
//}
//#include<stdio.h> //若用printf,scanf,getchar,putchar,gets,puts函数需包含该头文件
//#include<stdlib.h> //用malloc,free,realloc函数需包含该头文件
//
//#define MAXSIZE 100 //设线性表初始分配空间大小
//typedef int ElemType;  //先设定数据元素的类型为整型
//
////0：定义顺序表的结构类型
//typedef struct{
//    ElemType *elem;
//    int length;
//    int listsize;
//}SqList;
//
////1：初始化顺序表
//int InitList_Sq(SqList &L )
//{
//    L.elem=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
//    if (!L.elem) return 0;
//    L.length=0;
//    L.listsize=MAXSIZE;
//    return 1;
//}
//
////2：打印顺序表中所有元素
//void PrintList(SqList &L)
//{
//    int i;
//    for(i=0;i<L.length;i++)
//        printf("%d\n",L.elem[i]);
//}
//
////3:在顺序表中查找值为e的元素，返回其位置，没有返回0
//int Location_Sq(SqList L, ElemType e)
//{
////--------补充代码--Start------
//    for(int i = 0; i < L.length; i++)
//    {
//        if(L.elem[i] == e)
//        {
//            return i + 1;
//        }
//
//    }
////--------补充代码--End-------
//    return 0;
//}
//
////4：翻转顺序表
//void ReverseList(SqList &L)
//{
////--------补充代码--Start------
//    int begin = 0, end = L.length - 1;
//    while(begin < end)
//    {
//        int tmp = L.elem[begin];
//        L.elem[begin] = L.elem[end];
//        L.elem[end] = tmp;
//        begin++;
//        end--;
//    }
////--------补充代码--End-------
//}
//
////主函数
//int main()
//{
////以下代码请认真阅读，切勿做任何修改
//    SqList La;
//    int i,n,e;
//
////初始化顺序表
//    InitList_Sq(La);
////输入元素个数
//    scanf("%d",&n);
////依次读取n个数据插入顺序表
//    for(i=0;i<n;i++)
//    {
////输入数据元素
//        scanf("%d",&e);
////插入顺序表
//        La.elem[i]=e;
//    }
////数据元素个数赋值
//    La.length=n;
//
////-----------------------------------
////按顺序输出顺序表中元素
//    PrintList(La);
//
////-----------------------------------
////执行2次查找操作
////输入第1次要查找的数据元素值
//    scanf("%d",&e);
////执行查找，输出第1次被查找的数据元素的位置
//    printf("%d\n",Location_Sq(La, e));
////输入第2次要查找的数据元素值，执行查找
//    scanf("%d",&e);
////执行查找，输出第2次被查找的数据元素的位置
//    printf("%d\n",Location_Sq(La, e));
//
////-----------------------------------
////执行翻转操作
//    ReverseList(La);
////输出翻转后的顺序表的内容
//    PrintList(La);
//    return 0;
//}
//
//
// #include<stdio.h> //若用printf,scanf,getchar,putchar,gets,puts函数需包含该头文件
// #include<stdlib.h> //用malloc,free,realloc函数需包含该头文件

// #define MAXSIZE 100 //设线性表初始分配空间大小
// typedef int ElemType;  //先设定数据元素的类型为整型

// //0：定义顺序表的结构类型
// typedef struct{
//    ElemType *elem;
//    int length;
//    int listsize;
// }SqList;

// int ListInsert_Sq(SqList &L,int i,ElemType e){
//    if (i<1 || i>L.length+1)
//        return 0;
// //--------补充代码--Start------
//    if(L.length >= MAXSIZE)
//        return 0;
//     int end = L.length;
//     while(end > i)
//     {
//         L.elem[end] = L.elem[end - 1];
//         end--;
//     }
//     L.elem[i - 1] = e;
//     L.length++;

// //--------补充代码--End-------
//    return 1;
// }
// //1：初始化顺序表
// int InitList_Sq(SqList &L )
// {
//    L.elem=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
//    if (!L.elem) return 0;
//    L.length=0;
//    L.listsize=MAXSIZE;
//    return 1;
// }

// //2：打印顺序表中所有元素
// void PrintList(SqList &L)
// {
//    int i;
//    for(i=0;i<L.length;i++)
//        printf("%d\n",L.elem[i]);
// }

// //3：合并两个有序的顺序表，La,Lb有序，合并到Lc
// void MergeList(SqList La, SqList Lb, SqList &Lc)
// {
// //--------补充代码--Start------
//    int i = 0, j = 0, k = 0;
//    while(i < La.length&&j < Lb.length){
//        if(La.elem[i] < Lb.elem[j]){
//            ListInsert_Sq(Lc,++k,La.elem[i++]);

//        }else{
//            ListInsert_Sq(Lc,++k,Lb.elem[j++]);

//        }
//    }
//    while(i < La.length)
//        ListInsert_Sq(Lc,++k,La.elem[i++]);
//    while(j < Lb.length)
//        ListInsert_Sq(Lc,++k,Lb.elem[j++]);

// //--------补充代码--End-------
// }

// //主函数
// int main()
// {
// //以下代码请认真阅读，切勿做任何修改
// //将list[0]和list[1]合并到list[2]
//    SqList list[3];
//    int i,k,n,e;

// //构造2个数据表
//    for(k=0;k<2;k++)
//    {
// //初始化顺序表list 1,2
//        InitList_Sq(list[k]);
// //有序输入第k个顺序表数据元素个数
//        scanf("%d",&n);
// //依次读取n个数据插入顺序表
//        for(i=0;i<n;i++)
//        {
// //输入数据元素
//            scanf("%d",&e);
// //插入顺序表
//            list[k].elem[i]=e;
//        }
// //数据元素个数赋值
//        list[k].length=n;
//    }
// //初始化顺序表list 3
//    InitList_Sq(list[2]);

// //-----------------------------------
// //执行合并操作
//    MergeList(list[0], list[1], list[2]);
// //按顺序输出顺序表list[3]中元素
//    PrintList(list[2]);
//    return 0;
// }
// #include<stdio.h> //若用printf,scanf,getchar,putchar,gets,puts函数需包含该头文件
// #include<stdlib.h> //用malloc,free,realloc函数需包含该头文件

// #define MAXSIZE 100 //设线性表初始分配空间大小
// typedef int ElemType;  //先设定数据元素的类型为整型

// //0：定义顺序表的结构类型
// typedef struct{
//    ElemType *elem;
//    int length;
//    int listsize;
// }SqList;

// //1：初始化顺序表
// int InitList_Sq(SqList &L )
// {
//    L.elem=(ElemType*)malloc(sizeof(ElemType)*MAXSIZE);
//    if (!L.elem) return 0;
//    L.length=0;
//    L.listsize=MAXSIZE;
//    return 1;
// }

// //2：打印顺序表中所有元素
// void PrintList(SqList &L)
// {
//    int i;
//    for(i=0;i<L.length;i++)
//        printf("%d\n",L.elem[i]);
// }

// //*****3：在顺序表中第i个位置(i=1~n)插入元素*****
// int ListInsert_Sq(SqList &L,int i,ElemType e){
//    if (i<1 || i>L.length+1)
//        return 0;
// //--------补充代码--Start------
//    if(L.length >= MAXSIZE)
//        return 0;
//     int end = L.length;
//     while(end > i)
//     {
//         L.elem[end] = L.elem[end - 1];
//         end--;
//     }
//     L.elem[i - 1] = e;
//     L.length++;

// //--------补充代码--End-------
//    return 1;
// }

// //*****4：删除顺序表中第i(i=1~n)个元素，用e返回删除的元素*****
// int ListDelete_Sq(SqList &L, int i, ElemType &e)
// {
// //--------补充代码--Start------
// if(i > L.length || i < 1)
//        return 0;
//    e = L.elem[i - 1];
//    int begin = i;
//    while(begin < L.length)
//    {
//        L.elem[begin - 1] = L.elem[begin];
//        begin++;
//    }
//    L.length--;
// //--------补充代码--End-------
//    return 1;
// }

// //主函数
// int main()
// {
// //以下代码请认真阅读，切勿做任何修改
//    SqList La;
//    int i,n,e;

// //初始化顺序表
//    InitList_Sq(La);
// //输入元素个数
//    scanf("%d",&n);
// //依次读取n个数据插入顺序表
//    for(i=1; i<=n; i++)
//    {
// //输入数据元素
//        scanf("%d",&e);
// //插入顺序表
//        ListInsert_Sq(La,i,e);
//    }
// //按顺序输出顺序表中元素
//    PrintList(La);

// //----------------------------
// //输入要删除元素的位置
//    scanf("%d",&i);
// //执行删除
//    ListDelete_Sq(La,i,e);
// //输出删除后的元素
//    printf("%d\n",e);
// //输出删除后的顺序表的内容
//    PrintList(La);
//    printf("%d\n",La.length);
//    return 0;
// }
#include <iostream>
using namespace std;
int main()
{
   cout << "hello " << endl;
   return 0;
}