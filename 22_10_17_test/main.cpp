//#pragma once
//#include <iostream>
//#include<stdlib.h>
//#include<assert.h>
//
//using namespace std;
//typedef int SeqDataType;
//
//typedef struct SeqList
//{
//    SeqDataType* data;
//    int size;
//    int capacity;
//}SeqList;
//
//int SeqListInit(SeqList* sq);//初始化
//void SeqListDestory(SeqList* sq);//销毁内存
//void SeqListPrint(SeqList* sq);//打印
//int SeqListEmpty(SeqList* sq);//判空
//int SeqCheckCapacity(SeqList* sq);//检查容量
//int SeqListSize(SeqList* sq);//长度
//void SeqListPushBack(SeqList* sq, SeqDataType x);//尾增
//void SeqListPushFront(SeqList* sq, SeqDataType x); //头增
//void SeqListPopBack(SeqList* sq, SeqDataType x);//尾删
//void SeqListPopFront(SeqList* sq);//头删
//
//void SeqListInsert(SeqList* sq, SeqDataType x);//任意位置插入
//void SeqListErase(SeqList* sq, SeqDataType x);//任意位置删除
////初始化
//int SeqListInit(SeqList* sq)
//{
//    assert(sq);
//
//    sq->data = nullptr;
//    sq->capacity = 0;
//    sq->size = 0;
//    return 1;
//}
////销毁内存
//void SeqListDestory(SeqList* sq)
//{
//    assert(sq);
//
//    free(sq->data);
//    sq->data = nullptr;
//    sq->capacity = 0;
//}
////打印
//void SeqListPrint(SeqList* sq)
//{
//    assert(sq);
//
//    for (int i = 0; i < sq->size; i++)
//    {
//        printf("%d ", sq->data[i]);
//    }
//    printf("\n");
//}
////判空
//int SeqListEmpty(SeqList* sq)
//{
//    if(sq->size == 0)
//        return 1;
//    return 0;
//}
//
////检查容量
//int SeqCheckCapacity(SeqList* sq)
//{
//    assert(sq);
////    if (sq->capacity == sq->size)//增容
////    {
////        int Newcapacity = sq->capacity == 0 ? 4 : sq->capacity * 2;//如果容量为0，则开辟4个
////        SeqDataType* NewArr = (SeqDataType*)realloc(sq->data, sizeof(SeqDataType) * Newcapacity);
////        if (NULL == NewArr)
////        {
////            perror("realloc\n");
////            return;
////        }
////        sq->data = NewArr;//更新内存地址
////        sq->capacity = Newcapacity;//更新容量
////    }
//    if(sq->size == 10)
//        return -1;
//}
//int SeqListSize(SeqList* sq)//长度
//{
//    assert(sq);
//    return sq->size;
//}
////尾增
//void SeqListPushBack(SeqList* sq, SeqDataType x)
//{
//    assert(sq);
//    SeqCheckCapacity(sq);
//    sq->data[sq->size] = x;
//    sq->size++;
//}
////头增
//void SeqListPushFront(SeqList* sq, SeqDataType x)
//{
//    assert(sq);
//    SeqCheckCapacity(sq);
//
//    int end = sq->size ;
//    while (end>= 0)
//    {
//        sq->data[end] = sq->data[end - 1];//数据往后移动一位
//        end--;
//    }
//    sq->data[0] = x;
//
//    ++sq->size;
//}
////尾删
//void SeqListPopBack(SeqList* sq, SeqDataType x)
//{
//    assert(sq);
//    --sq->size;
//}
////头删
//void SeqListPopFront(SeqList* sq)
//{
//    assert(sq);
//
//    int start = 0;
//    while (start++ <= sq->size - 1)
//    {
//        sq->data[start] = sq->data[start + 1];//数据向前移动一位
//    }
//    sq->size--;
//}
////查找
//int SeqListFind(SeqList* sq, SeqDataType x)
//{
//    assert(sq);
//    for (int i = 0; i < sq->size; i++)
//    {
//        if (sq->data[i] == x)
//        {
//            //printf("找到了\n");
//            return i;
//        }
//    }
//}
////任意位置插入
//void SeqListInsert(SeqList* sq, SeqDataType x, int adr)
//{
//    assert(sq);
//    SeqCheckCapacity(sq);
//
//    int end = sq->size;
//    while (end >= adr)
//    {
//        sq->data[end] = sq->data[end - 1];//移动数据
//        end--;
//    }
//    sq->data[adr] = x;//插入数据
//    sq->size++;
//}
////任意位置删除
//void SeqListErase(SeqList* sq, int adr)
//{
//    assert(sq);
//    int begin = adr;
//    while (begin + 1 <= sq->size - 1)
//    {
//        sq->data[begin] = sq->data[begin + 1];
//        begin++;
//    }
//    sq->size--;
//}
////主函数
//
//int main( )
//{
//    SeqList Q;
//    int select = 0;
//    SeqDataType e = 0;
//    SeqListInit(&Q);
//    //处理输入输出
//    while(scanf("%d", &select) != EOF)
//    {
//        //程序结束
//        if(select==-1)
//            return 0;
//            //输出元素
//        else if(select==0)
//            SeqListPrint(&Q);
//            //进队
//        else if(select==1)
//        {
//            //--------补充代码--Start------
//            scanf("%d", &e);
//            SeqListPushBack(&Q, e);
//            //--------补充代码--End-------
//        }
//            //出队
//        else if(select==2)
//        {
//            //--------补充代码--Start------
//            if(SeqListEmpty(&Q))
//                return -1;
//            SeqListPopFront(&Q);
//            //--------补充代码--End-------
//        }
//            //求队头
//        else if(select==3)
//        {
//            if(SeqListEmpty(&Q))
//                return -1;
//            if(SeqListFind(&Q, Q.data[0]) == 0)
//            {
//                printf("d\n", Q.data[0]);
//            }
//            else
//                return -1;
//
//        }
//            //求队列长度
//        else if(select==4)
//            printf("%d\n",SeqListSize(&Q));
//            //判断队空
//        else if(select==5)
//            printf("%d\n",SeqListEmpty(&Q));
//    }
//    SeqListDestory(&Q);
//    return 0;
//}
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//#include <stdlib.h>
//#define MAX_SIZE 10
//typedef int SQDateType;
//
//typedef struct SeqList
//{
//    SQDateType* a;
//    int size; //有效数据个数
//    int cacpcity = MAX_SIZE;//容量
//}SL;
//int flag = 0;
////增删查改
//void SeqListInit(SL* ps);
//void SeqListDestory(SL* ps);
//int SeqListFind(SL* ps, SQDateType x);
//int SeqListModity(SL* ps, int pos, SQDateType x);
//
////头插 尾插  头删  尾删  任意位置插入、删除
//void SeqListPushBack(SL* ps, SQDateType x);
//void SeqListPushFront(SL* ps, SQDateType x);
//
//void SeqListPopBack(SL* ps);
//void SeqListPopFront(SL* ps);
//
//void SeqListInsert(SL* ps, int pos, SQDateType x);
//void SeqListErase(SL* ps, int pos);
//int SeqListSize(SL *ps);
//int SeqListEmpty(SL* ps);
////打印
//void SeqListPrintf(SL* ps);
////扩容
//void SeqLIstCheckCacpcity(SL* ps);
//
//
//void SeqLIstCheckCacpcity(SL* ps)
//{
//    //判断表满就扩容
//    if (ps->size == ps->cacpcity)
//    {
//        int newcacpcity = ps->cacpcity == 0 ? 4 : ps->cacpcity * 2;
//
//        SQDateType* tmp = (SQDateType*)realloc(ps->a, newcacpcity * 2 * sizeof(SQDateType));
//
//        if (tmp == NULL)
//        {
//            printf("realloc is fail\n");
//            exit(-1);
//        }
//
//        else
//        {
//            ps->a = tmp;
//            ps->cacpcity = newcacpcity;
//        }
//    }
//}
//
////初始化
//void SeqListInit(SL* ps)
//{
//    ps->a = NULL;
//    ps->size = 0;
//    ps->cacpcity = 0;
//}
//
////尾插
//void SeqListPushBack(SL* ps, SQDateType x)
//{
//    SeqLIstCheckCacpcity(ps);
//
//    ps->a[ps->size] = x;
//    ps->size++;
//
//}
//
//void SeqListPrintf(SL* ps)
//{
//    for (int i = 0; i < ps->size; i++)
//    {
//        printf("%d\n", ps->a[i]);
//    }
//}
//
////头插
//void SeqListPushFront(SL* ps, SQDateType x)
//{
//
//    SeqLIstCheckCacpcity(ps);
//    if(ps->cacpcity > 10)
//    {
//        flag = 1;
//    }
//    int end = ps->size - 1;
//    int start = 0;
//    while (end>=start)
//    {
//        ps->a[end + 1] = ps->a[end];
//        end--;
//    }
//
//    ps->a[0] = x;
//    ps->size++;
//
//}
//
////尾删
//void SeqListPopBack(SL* ps)
//{
//    assert(ps->size > 0);
//    ps->size--;
//
//}
//
////头删
//void SeqListPopFront(SL* ps)
//{
//    assert(ps->size > 0);
//    printf("%d\n", ps->a[0]);
//    int start = 1;
//    while (start < ps->size)
//    {
//        ps->a[start-1] = ps->a[start];
//        start++;
//    }
//    ps->size--;
//
//}
//
////
//void SeqListInsert(SL* ps, int pos, SQDateType x)
//{
//    assert(pos< ps->size );
//    SeqLIstCheckCacpcity(ps);
//
//    int end = ps->a[ps->size - 1];
//    while (end <= pos)
//    {
//        ps->a[end + 1] = ps->a[end];
//        end--;
//
//    }
//
//    ps->a[pos] = x;
//    ps->size++;
//}
//
//
//int SeqListEmpty(SL* ps)
//{
//    if(ps->size == 0)
//        return 1;
//    return 0;
//}
//void SeqListErase(SL* ps, int pos)
//{
//    assert(pos < ps->size);
//    int start = pos+1;
//    while (start <ps->size )
//    {
//        ps->a[start-1] = ps->a[start];
//        start++;
//    }
//
//    ps->size--;
//}
//
//int SeqListSize(SL *ps)
//{
//    return ps->size;
//}
//
//
//int SeqListFind(SL* ps, SQDateType x)
//{
//    for (int i = 0; i < ps->size; i++)
//    {
//        if (ps->a[i] == x)
//        {
//            return i;
//        }
//    }
//
//    return -1;
//
//}
//
//int SeqListModity(SL* ps, int pos, SQDateType x)
//{
//    assert(pos < ps->size);
//
//    ps->a[pos] = x;
//
//    return 0;
//}
//
//#include <iostream>
//#include <stdlib.h>
//#define MAXSIZE 10
//
//typedef int dataType;
//
//
//typedef struct node
//{
//    dataType data[MAXSIZE];
//    int head; // 下标
//    int tail;
//} queue;
//
//// 创建队列
//queue *queueCreate();
//
//// 队列是否为空
//int queueIsempty(queue *);
//
//// 遍历队列
//int queueTravel(queue *);
//
//// 入队
//int enQueue(queue *, dataType *);
//
//// 出队
//int deQueue(queue *, dataType *);
//
//// 清除队列元素
//int clearQueue(queue *);
//
//// 销毁队列
//int queueDestroy(queue *);
//
//// 创建队列
//queue *queueCreate()
//{
//    queue *qu;
//
//    qu = (queue*)malloc(sizeof(queue));
//    if (NULL == qu)
//    {
//        perror("malloc: ");
//        return NULL;
//    }
//
//    qu->head = 0;
//    qu->tail = 0;
//
//    return qu;
//}
//
//// 队列是否为空
//int queueIsempty(queue *qu)
//{
//    return (qu->head == qu->tail);
//}
//
//// 遍历队列
//int queueTravel(queue *qu)
//{
//    if (queueIsempty(qu))
//    {
//        // 队列为空
//        return 0;
//    }
//
//    int i = (qu->head + 1) % MAXSIZE;
//    while (i != qu->tail)
//    {
//        printf("%d\n", qu->data[i]);
//        i = (i + 1) % MAXSIZE;
//    }
//
//    printf("%d\n", qu->data[i]);
//
//    return 0;
//}
//
//// 入队
//int enQueue(queue *qu, dataType *data)
//{
//    // 元素入在队尾 队头所在的位置不存放元素
//    if ((qu->tail + 1) % MAXSIZE == qu->head)
//    {
//        // 队列已满
//        return -1;
//    }
//
//    // 循环队列
//    qu->tail = (qu->tail + 1) % MAXSIZE;
//    // 元素入队
//    qu->data[qu->tail] = *data;
//
//    return 0;
//}
//
//// 出队
//int deQueue(queue *qu, dataType *data)
//{
//    if (queueIsempty(qu))
//        return -1;
//
//    qu->head = (qu->head + 1) % MAXSIZE;
//    *data = qu->data[qu->head];
//
//    return 0;
//}
//
//// 清除队列元素
//int clearQueue(queue *qu)
//{
//    qu->head = qu->tail;
//
//    return 0;
//}
//
//// 销毁队列
//int queueDestroy(queue *qu)
//{
//    free(qu);
//
//    return 0;
//}
//int queueSize(queue* qu)
//{
//    return (qu->tail - qu->head + MAXSIZE) % MAXSIZE;
//}
//int main( )
//{
//    queue* Q;
//    int select = 0;
//    int e = 0;
//    Q = queueCreate();
//    //处理输入输出
//    while(scanf("%d", &select) != EOF)
//    {
//        //程序结束
//        if(select==-1)
//            return 0;
//            //输出元素
//        else if(select==0)
//            queueTravel(Q);
//            //进队
//        else if(select==1)
//        {
//            if ((Q->tail + 1) % SIZE_MAX == Q->head)
//            {
//                printf("-1\n");
//                return -1;
//            }
//            //--------补充代码--Start------
//            scanf("%d", &e);
//            enQueue(Q, &e);
//            //--------补充代码--End-------
//        }
//            //出队
//        else if(select==2)
//        {
//            //--------补充代码--Start------
//            if(queueIsempty(Q) == 1)
//            {
//                printf("-1\n");
//                return -1;
//            }
//            printf("%d\n", Q->data[Q->head + 1]);
//            deQueue(Q, &e);
//            //--------补充代码--End-------
//        }
//            //求队头
//        else if(select==3)
//        {
//            if(queueIsempty(Q) == 1)
//            {
//                printf("-1\n");
//                return -1;
//            }
//            printf("%d\n", Q->data[Q->tail - 1]);
//        }
//            //求队列长度
//        else if(select==4)
//            printf("%d\n",queueSize(Q));
//            //判断队空
//        else if(select==5)
//        {
//            printf("%d\n",queueIsempty(Q));
//        }
//    }
//    return 0;
//}
#include <iostream>
using namespace std;
template<typename T, typename L>
L Add(const T& x, const L& y)
{
    return (x + y);
}

template <class T>
class BookList
{
private:
    vector<T> list;
};
template <class T>
void test()
{
    BookList<T> bl;
}
int main()
{
    auto a = Add(2, 2.2); // 编译成功
    cout << a << endl;
    return 0;
}