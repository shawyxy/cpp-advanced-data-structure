//#include <stdio.h>
//#include <stdlib.h>
//#include <stdbool.h>
////二叉排序树结构
//typedef struct Node{
//    int data;
//    struct Node *lchild,*rchild;
//}BitNode, *BiTree;
//
////中序遍历
//void InOrderTraverse(BiTree T){
//    if(T!=NULL){
//        InOrderTraverse(T->lchild);
//        printf("%d ",T->data);
//        InOrderTraverse(T->rchild);
//    }
//}
//
///*递归查找二叉排序树T中是否存在key,指针f指向t的双亲,其初始调用值为NULL*/
///*若查找成功，则指针p指向该数据的元素结点，并返回TRUE*/
///*否则，指针p指向查找路径上访问的最后一个结点并返回FALSE*/
//bool SearchBST(BiTree &T, int key, BiTree f, BiTree &p){
//    //--------补充代码--Start------
//    BitNode * cur = T;
//    while(cur)
//    {
//        if(key < cur->data)
//        {
//            cur = cur->lchild;
//        }
//        else if(key > cur->data)
//        {
//            cur = cur->rchild;
//        }
//        else
//        {
//            return true;
//        }
//    }
//    return false;
//    //--------补充代码--End-------
//}
//
////当二叉排序树t中不存在关键字等于key的数据元素时，插入key并返回TRUE，否则返回FALSE
//bool InsertBST(BiTree &T, int key){
//    //--------补充代码--Start------
//    if(T == NULL)
//    {
//        T = (BitNode*)malloc(sizeof(BitNode));
//        T->data = key;
//        return true;
//    }
//    if(key < T->data)
//    {
//        return InsertBST(T->lchild, key);
//    }
//    else if(key > T->data)
//    {
//        return InsertBST(T->rchild, key);
//    }
//    else
//        return false;
//    //--------补充代码--End-------
//}
//
////主函数
//int main(){
//    int i,n,key,select;
//    BiTree p,T=NULL;
//
//    while(scanf("%d",&select)!=EOF){
//        if(select==0)
//            return 0;
//        else if(select==1){
//            scanf("%d",&n);
//            for(i=1; i<=n; i++)
//            {
//                scanf("%d",&key);
//                getchar();
//                InsertBST(T, key);
//            }
//        }
//        else if(select==2){
//            if(T)
//            {
//                InOrderTraverse(T);
//                printf("\n");
//            }
//        }
//        else if(select==3){
//            scanf("%d",&key);
//            if(!SearchBST(T, key, NULL, p))
//                printf("0\n");
//            else
//                printf("1\n");
//        }
//    }
//    return 0;
//}


//------------------------------------------
//------------------------------------------
//------------------------------------------


#include <stdio.h>
#include <stdlib.h>
//注意后面使用的sort函数是C++ STL中的内容，本题必须使用C++作为提交语言
#include <algorithm>
using namespace std;

//顺序存储结构
typedef struct{
    int *elem;      //指向数据元素基址，0号不存元素
    int length ;
}SSTable;             //静态顺序表

//输出顺序静态表
void PrintSST(SSTable &ST){
    int i;
    for(i=1; i<=ST.length; i++){
        printf("%d ",ST.elem[i]);
    }
    printf("\n");
}

//创建顺序静态表
void CreateSST(SSTable &ST, int n){
    int i;
    ST.elem = (int*)malloc(sizeof(int)*(n+1));
    ST.length = n;
    for( i=1; i<=n; i++){
        scanf("%d",&ST.elem[i]);
        getchar();
    }
}

//顺序查找
int Search_Seq(SSTable &ST, int key){
    //--------补充代码--Start------
    int len = ST.length;
    for(int i = 1; i <= len; i++)
    {
        if(ST.elem[i] == key)
            return i;
    }
    return 0;
    //--------补充代码--End-------
}

//折半查找算法
int Search_Bin(SSTable &ST, int key){
    //--------补充代码--Start------
    int left = 0, right = ST.length - 1;
    int mid = (left + right) / 2;

    while(left <= right)
    {
        if(key < ST.elem[mid])
        {
            right = mid - 1;
        }
        else if(key > ST.elem[mid])
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
        mid = (left + right) / 2;
    }
    return 0;
    //--------补充代码--End-------
}
//主函数
int main(){
    int n,key,select;
    SSTable SST;

    while(scanf("%d",&select)!=EOF){
        if(select==0)
            return 0;
        else if(select==1){
            scanf("%d",&n);
            CreateSST(SST, n);
            PrintSST(SST);
        }
        else if(select==2){
            scanf("%d",&key);
            printf("%d\n",Search_Seq(SST,key));
        }
        else if(select==3){
            scanf("%d",&key);
            //对查找表进行升序排序
            sort(SST.elem+1,SST.elem+SST.length+1);
            printf("%d\n",Search_Bin(SST,key));
        }
    }
    return 0;
}