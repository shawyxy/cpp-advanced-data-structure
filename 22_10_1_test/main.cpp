//#include <iostream>
//#include<stdlib.h>
//#include<string>
//using namespace std;
//typedef int ElemType;
//typedef struct LNode{
//    ElemType data;
//    LNode *next;
//}LNode,*LinkList;
//
//void CreateList_L(LinkList &L,int n)
//{
//
//    L=new LNode;
//    L->next=NULL;
//    for(int i = n; i > 0; --i)
//    {
//        LNode *p = new LNode;
//        cin >> p->data;
//        p->next = L->next;
//        L->next = p;
//    }
//}
//int GetElem (LinkList &L,int i,ElemType &e)
//{
//    LinkList p = L->next;
//    int j = 1;
//    while(p && j < i)
//    {
//        p = p->next;
//        ++j;
//    }
//    if(!p||j>i)
//        return 0;
//    e = p->data;
//    return 1;
//}
//
//int ListInsert (LinkList &L,int i,ElemType &e)
//{
//    LinkList p = L, s = NULL;
//    int j = 0;
//    while(p && j<i-1)
//    {
//        p = p->next;
//        ++j;
//    }
//    if(!p || j > i - 1)
//        return 0;
//    s = (LNode*)malloc(sizeof(LNode));
//    s->data = e;
//    s->next = p->next;
//    p->next = s;
//    return 1;
//}
//int ListDelete(LinkList &L,int i,ElemType &e)
//{
//    LinkList p = L, q = NULL;
//
//    int j = 0;
//    while (p->next && j < i - 1)
//    {
//        p = p->next;
//        ++j;
//    }
//    if(!(p->next) || j>i-1)
//    {
//        return 0;
//    }
//    q = p->next;
//    p->next = q->next;
//    e = q->data;
//    return 1;
//}
//void ShowList(LinkList &L)
//{
//    LinkList p;
//    p=L;
//    while (p->next != NULL)
//    {
//        p = p->next;
//        cout << p->data << " ";
//    }
//}
//
//int main() {
//    LinkList L;
//    int n = 0, m = 0, pos = 0;
//    ElemType e;
//    cin >> n;
//    CreateList_L(L,n);
//    cin >> m;
//    string x;
//    while(m--)
//    {
//        cin >> x;
//        if( x == "insert")
//        {
//            cin >> pos;
//            cin >> e;
//
//            if(ListInsert(L,pos,e)==1)
//            {
//                cout << "insert OK" << endl;
//                n++;
//            }
//            else if(ListInsert(L,pos,e) == 0)
//            {
//                cout << "insert fail" << endl;
//            }
//
//        }
//        else if(x == "delete")
//        {
//            cin >> pos;
//
//            if(ListDelete(L,pos,e)==1)
//            {
//                cout << "delete OK" << endl;
//                n--;
//            }
//            else if(ListDelete(L,pos,e)==0)
//            {
//                cout << "delete fail" << endl;
//            }
//        }
//        else if(x == "get")
//        {
//            cin >> pos;
//            if(GetElem (L,pos,e)==0)
//            {
//                cout << "get fail" << endl;
//            }
//            else if(GetElem (L,pos,e) == 1)
//            {
//                cout << e << endl;
//            }
//        }
//        else if(x == "show")
//        {
//            if(n == 0)
//                cout << "Link list is empty" << endl;
//            else if( n > 0 )
//            {   ShowList(L);
//                cout << endl;
//            }
//        }
//
//    }
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
////定义全局变量
////未定义
//int g_unval;
////已定义
//int g_val = 1;
//int main(int argc, char* argv[], char *envp[])
//{
//    printf("代码区:%p\n", main);
//    char* str = "hello";
//    printf("只读常量区:%p\n", str);
//    printf("初始化数据区:%p\n", &g_val);
//    printf("未初始化数据区:%p\n", &g_unval);
//
//    int* p = (int*)malloc(5);
//    printf("堆区:%p\n", p);
//    printf("栈区:%p\n", &str);
//    printf("栈区:%p\n", &p);
//
//    //命令行参数
//    for(int i = 0; i < argc; i++)
//    {
//        printf("命令行参数:%p\n", argv[i]);
//    }
//    //环境变量
//    int i = 0;
//    while(envp[i])
//    {
//        printf("环境变量:%p\n", envp[i]);
//        i++;
//    }
//    return 0;
//}
