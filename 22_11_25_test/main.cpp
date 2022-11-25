//#include <iostream>
//using namespace std;
//
//#define MAXSIZE 20 //记录最大个数
//typedef struct{
//    int data[MAXSIZE];
//    int length; //顺序表长度
//}SqList;
//
////创建顺序表
//void CreateSqList(SqList &L, int n){
//    int i;
//    L.length = n;
//    for(i=0; i<L.length; i++){
//        scanf("%d",&L.data[i]);
//        getchar();
//    }
//}
//
////输出顺序表
//void PrintSqList(SqList &L){
//    int i;
//    for(i=0; i<L.length; i++)
//        printf("%d\n",L.data[i]);
//}
////直接插入排序,Acc=1表示升序,Acc=-1表示降序
//void InsertSort(SqList &L,int Acc){
////--------补充代码--Start------
//    if(Acc == 1)
//    {
//        for (int i = 0; i < L.length - 1; i++)
//        {
//            int end = i;
//            int tmp = L.data[end + 1];
//            while (end >= 0)
//            {
//                if (tmp < L.data[end])//原值大于要插入的数
//                {
//                    L.data[end + 1] = L.data[end];//往后挪动
//                    end--;//向前比较
//                }
//                else
//                {
//                    break;
//                }
//            }
//            //循环终止（插入位置）有两种情况
//            //此时end在空出来的前一个位置
//            L.data[end + 1] = tmp;
//        }
//    }
//    else if(Acc == -1)
//    {
//        for (int i = 0; i < L.length - 1; i++)
//        {
//            int end = i;
//            int tmp = L.data[end + 1];
//            while (end >= 0)
//            {
//                if (tmp > L.data[end])//原值小于要插入的数
//                {
//                    L.data[end + 1] = L.data[end];//往后挪动
//                    end--;//向前比较
//                }
//                else
//                {
//                    break;
//                }
//            }
//            //循环终止（插入位置）有两种情况
//            //此时end在空出来的前一个位置
//            L.data[end + 1] = tmp;
//        }
//    }
////--------补充代码--End------
//}
//
////折半插入排序
//void BInsertSort(SqList &L){
////--------补充代码--Start------
//    for(int i = 0; i < L.length; i++)
//    {
//        int mid = 0, tmp = 0;
//        int left = 0, right = i - 1;
//        while(left <= right)
//        {
//            mid = (left + right) / 2;
//            if(L.data[mid] > L.data[i])
//            {
//                right = mid - 1;
//            }
//            else
//            {
//                left = mid + 1;
//            }
//
//            tmp = L.data[i];
//
//            for(int j = i; j > right + 1; j--)
//            {
//                L.data[j] = L.data[j - 1];
//            }
//            L.data[right + 1] = tmp;
//        }
//    }
//
////--------补充代码--End------
//}
//
////主函数
//int main(){
//    int n,Acc;
//    SqList List,TempList;
//    int select;
//
//    while(scanf("%d",&select)!=EOF){
//        getchar();
//        if(select==0)
//            return 0;
//        else if(select==1){
//            scanf("%d",&n);
//            CreateSqList(List, n);
//        }
//        if(select==2){
//            TempList=List;
//            scanf("%d",&Acc);
//            getchar();
//            InsertSort(TempList,Acc);
//            PrintSqList(TempList);
//        }
//        else if(select==3){
//            TempList=List;
//            BInsertSort(TempList);
//            PrintSqList(TempList);
//        }
//    }
//    return 0;
//}
//#include <iostream>
//#include <algorithm>
//#include <stack>
//using namespace std;
//#define MAXSIZE 20                //记录最大个数
//
////学生结构体
//typedef struct{
//    char name[10];
//    int age;
//    int no;
//}Student;
//typedef struct{
//    Student data[MAXSIZE+1];
//    int length;                          //顺序表长度
//}SqList;
//
////创建顺序表
//void CreateSqList(SqList &L, int n){
//    L.length = n;
//    for(int i=0; i<L.length; i++){
//        scanf("%d %d %s",&L.data[i].no,&L.data[i].age,L.data[i].name);
//        getchar();
//    }
//}
//
////输出顺序表
//void PrintSqList(SqList &L){
//    for(int i=0; i<L.length; i++)
//        printf("%d %d %s\n",L.data[i].no,L.data[i].age,L.data[i].name);
//}
//
////按照学号起泡排序，Acc=1表示升序,Acc=-1表示降序
//void BubbleSort(SqList &L, int Acc){
//    //--------补充代码--Start------
//    if(Acc == -1)
//    {
//        for (int i = 0; i < L.length; i++)
//        {
//            int exchange = 0;
//            //or j<-[1, n - i)
//            for (int j = 0; j < L.length - i - 1; j++)
//            {
//                if ((L.data[j + 1]).no > (L.data[j]).no)
//                {
//                    swap(L.data[j + 1], L.data[j]);
//                    exchange = 1;
//                }
//            }
//            if (exchange == 0)
//                break;
//        }
//    }
//    else if(Acc == 1)
//    {
//        for (int i = 0; i < L.length; i++)
//        {
//            int exchange = 0;
//            //or j<-[1, n - i)
//            for (int j = 0; j < L.length - i - 1; j++)
//            {
//                if ((L.data[j + 1]).no < (L.data[j]).no)
//                {
//                    swap(L.data[j + 1], L.data[j]);
//                    exchange = 1;
//                }
//            }
//            if (exchange == 0)
//                break;
//        }
//    }
//    //--------补充代码--End------
//}
//
////=============按照学号快速排序start=============
////一趟快速排序过程,Acc=1表示升序,Acc=-1表示降序
////int Partition(SqList &L, int low, int high, int Acc){
////    //--------补充代码--Start------
////
////    //--------补充代码--End------
////}
//void QSort(SqList &L, int low, int high, int Acc) {
////    int pivotloc;
////    if(low<high){                                           //当L.data[low..high]为空或只有一个记录时无需排序
////        pivotloc=Partition(L, low, high, Acc); //对 L.data[low..high]] 进行一次划分,并返回枢轴位置
////        QSort(L, low, pivotloc-1, Acc);                 //递归处理左区间
////        QSort(L, pivotloc+1, high, Acc);       //递归处理右区间
////    }
//}
//// 快速排序前后指针法
//int PartSort3(Student* a, int begin, int end, int Acc)
//{
//
//    if(Acc == 1)
//    {
//        if (begin >= end)
//            return -1;
//        int prev = begin;
//        int cur = prev + 1;
//        int keyi = begin;
//        while (cur <= end)
//        {
//            if (a[cur].no < a[keyi].no)
//            {
//                prev++;
//                if (prev != cur)
//                {
//                    swap((a[cur]), (a[prev]));
//                }
//            }
//            cur++;
//        }
//        swap((a[keyi]), (a[prev]));
//        keyi = prev;
//        return keyi;
//    }
//    else if(Acc == -1)
//    {
//        if (begin >= end)
//            return -1;
//        int prev = begin;
//        int cur = prev + 1;
//        int keyi = begin;
//        while (cur <= end)
//        {
//            if (a[cur].no > a[keyi].no)
//            {
//                prev++;
//                if (prev != cur)
//                {
//                    swap((a[cur]), (a[prev]));
//                }
//            }
//            cur++;
//        }
//        swap((a[keyi]), (a[prev]));
//        keyi = prev;
//        return keyi;
//    }
//}
//
//
//// 快速排序 非递归实现
//void QuickSortNonR(Student* a, int begin, int end, int Acc)
//{
//    stack<int> st;
//
//    st.push(end);
//    st.push(begin);
//    while (!st.empty())
//    {
//        int left = st.top();
//        st.pop();
//
//        int right = st.top();
//        st.pop();
//
//        int keyi = PartSort3(a, left, right, Acc);
//
//        //keyi左边区间大于1
//        if (keyi - left > 1)
//        {
//            st.push(keyi - 1);
//            st.push(left);
//        }
//
//        //keyi右边区间大于1
//        if (right - keyi > 1)
//        {
//            st.push(right);
//            st.push(keyi + 1);
//        }
//    }
//}
//
//void QuickSort(SqList &L,int Acc){
//    QuickSortNonR(L.data, 0, L.length - 1, Acc);
//}
////=============按照学号快速排序end=============
//
////主函数
//int main(){
//    int n,Acc,SortType;
//    SqList List,TempList;
//    int select;
//
//    while(scanf("%d",&select)!=EOF){
//        if(select==0)
//            return 0;
//        else if(select==1){
//            scanf("%d",&n);
//            CreateSqList(List, n);
//        }
//        if(select==4){
//            TempList=List;
//            scanf("%d",&Acc);
//            BubbleSort(TempList,Acc);
//            PrintSqList(TempList);
//        }
//        if(select==5){
//            TempList=List;
//            scanf("%d",&Acc);
//            QuickSort(TempList,Acc);
//            PrintSqList(TempList);
//        }
//    }
//    return 0;
//}
//#include <iostream>
//using namespace std;
//#define MAXSIZE 20                //记录最大个数
//
////学生结构体
//typedef struct{
//    char name[10];
//    int age;
//    int no;
//}Student;
//typedef struct{
//    Student data[MAXSIZE+1];
//    int length;                          //顺序表长度
//}SqList;
//
////创建顺序表
//void CreateSqList(SqList &L, int n){
//    L.length = n;
//    for(int i=0; i<L.length; i++){
//        scanf("%d %d %s",&L.data[i].no,&L.data[i].age,L.data[i].name);
//        getchar();
//    }
//}
//
////输出顺序表
//void PrintSqList(SqList &L){
//    for(int i=0; i<L.length; i++)
//        printf("%d %d %s\n",L.data[i].no,L.data[i].age,L.data[i].name);
//}
//
////按照学号简单选择排序,Acc=1表示升序,Acc=-1表示降序
//void SelectSort(SqList &L,int Acc){
//    //--------补充代码--Start------
//    //确定边界
//    if(Acc == 1)
//    {
//        int begin = 0;
//        int end = L.length - 1;
//        while (begin < end)
//        {
//            //寻找每次遍历的最值
//            int maxi = begin, mini = begin;
//            for (int i = begin + 1; i <= end; i++)
//            {
//                if (L.data[maxi].no < L.data[i].no)
//                {
//                    maxi = i;
//                }
//                if (L.data[mini].no > L.data[i].no)
//                {
//                    mini = i;
//                }
//            }
//            swap((L.data[begin]), (L.data[mini]));
//            if (begin == maxi)
//            {
//                maxi = mini;
//            }
//            swap((L.data[end]), (L.data[maxi]));
//            //更新边界
//            begin++;
//            end--;
//        }
//    }
//    else if(Acc == -1)
//    {
//        int begin = 0;
//        int end = L.length - 1;
//        while (begin < end)
//        {
//            //寻找每次遍历的最值
//            int maxi = begin, mini = begin;
//            for (int i = begin + 1; i <= end; i++)
//            {
//                if (L.data[maxi].no > L.data[i].no)
//                {
//                    maxi = i;
//                }
//                if (L.data[mini].no < L.data[i].no)
//                {
//                    mini = i;
//                }
//            }
//            swap((L.data[begin]), (L.data[mini]));
//            if (begin == maxi)
//            {
//                maxi = mini;
//            }
//            swap((L.data[end]), (L.data[maxi]));
//            //更新边界
//            begin++;
//            end--;
//        }
//    }
//    //--------补充代码--End------
//}
//
////主函数
//int main(){
//    int n,Acc,SortType;
//    SqList List,TempList;
//    int select;
//
//    while(scanf("%d",&select)!=EOF){
//        if(select==0)
//            return 0;
//        else if(select==1){
//            scanf("%d",&n);
//            CreateSqList(List, n);
//        }
//        if(select==6){
//            TempList=List;
//            scanf("%d",&Acc);
//            SelectSort(TempList,Acc);
//            PrintSqList(TempList);
//        }
//    }
//    return 0;
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <cstring>
//#define MAXSIZE 20                //记录最大个数
//
////学生结构体
//typedef struct{
//    char name[10];
//    int age;
//    int no;
//}Student;
//typedef struct{
//    Student data[MAXSIZE+1];
//    int length;                          //顺序表长度
//}SqList;
//
////创建顺序表
//void CreateSqList(SqList &L, int n){
//    L.length = n;
//    for(int i=0; i<L.length; i++){
//        scanf("%d %d %s",&L.data[i].no,&L.data[i].age,L.data[i].name);
//        getchar();
//    }
//}
//
////输出顺序表
//void PrintSqList(SqList &L){
//    for(int i=0; i<L.length; i++)
//        printf("%d %d %s\n",L.data[i].no,L.data[i].age,L.data[i].name);
//}
//
////=============按照学号归并排序start=============
////归并排序 (将有序的S[i..m]和S[m+1..n]合并为有序的T[i..n])
//void Merge(Student S[], Student T[], int i, int m, int n){
//    //--------补充代码--Start------
//
//    //--------补充代码--End------
//}
////将S[s..t]归并排序为T[s..t]
//void MSort(Student S[], Student T1[], int s, int t){
//    int mid;
//    if(s==t)
//        T1[s]=S[s];
//    else{
//        Student T2[MAXSIZE];
//        mid=(s+t)/2;                              //将S[s..t]平分为S[s..m]和S[m+1..t]
//        MSort(S, T2, s, mid);
//        MSort(S, T2, mid+1, t);
//        Merge(T2, T1, s, mid, t);
//    }
//}
//// 归并排序非递归实现
//void MergeSortNonR(Student* a, int n)
//{
//    Student * tmp = (Student*)malloc(n * sizeof(Student));
//    if (tmp == NULL)
//    {
//        printf("malloc fail\n");
//        exit(-1);
//    }
//
//    int gap = 1;
//    while (gap < n)
//    {
//        for (int i = 0; i < n; i += gap * 2)
//        {
//            int begin1 = i, end1 = i + gap - 1;
//            int begin2 = i + gap, end2 = i + gap * 2 - 1;
//            int j = begin1;
//
//            // 越界-修正边界
//            if (end1 >= n)
//            {
//                end1 = n - 1;
//                // [begin2, end2]修正为不存在区间
//                begin2 = n;
//                end2 = n - 1;
//            }
//            else if (begin2 >= n)
//            {
//                // [begin2, end2]修正为不存在区间
//                begin2 = n;
//                end2 = n - 1;
//            }
//            else if(end2 >= n)
//            {
//                end2 = n - 1;
//            }
//
//            while (begin1 <= end1 && begin2 <= end2)
//            {
//                //归并
//                if (a[begin1].no < a[begin2].no)
//                {
//                    tmp[j++] = a[begin1++];
//                }
//                else
//                {
//                    tmp[j++] = a[begin2++];
//                }
//
//            }
//            //处理剩余数据
//            while (begin1 <= end1)
//            {
//                tmp[j++] = a[begin1++];
//            }
//            while (begin2 <= end2)
//            {
//                tmp[j++] = a[begin2++];
//            }
//        }
//        memcpy(a, tmp, n * sizeof(Student));
//
//
//        gap *= 2;
//    }
//
//    free(tmp);
//}
//
//void MergeSort(SqList &L){
//    //MSort(L.data, L.data, 1, L.length);
//    MergeSortNonR(L.data, L.length);
//}
////=============按照学号归并排序end=============
//
////主函数
//int main(){
//    int n,Acc,SortType;
//    SqList List,TempList;
//    int select;
//
//    while(scanf("%d",&select)!=EOF){
//        if(select==0)
//            return 0;
//        else if(select==1){
//            scanf("%d",&n);
//            CreateSqList(List, n);
//        }
//        if(select==7){
//            TempList=List;
//            MergeSort(TempList);
//            PrintSqList(TempList);
//        }
//    }
//    return 0;
//}
