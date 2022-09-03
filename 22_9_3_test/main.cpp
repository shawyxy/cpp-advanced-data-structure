#include <iostream>
//int main()
//{
//    int value = 1024;
//    char condition = *((char*)(&value));
//    if(condition) value += 1; condition = *((char*)(&value)); if(condition) value += 1; condition = *((char*)(&value)); printf("%d %d", value, condition);
////    char a=101;
////    int sum=200; a+=27;sum+=a; printf("%d\n",sum);
//   return 0;
//}
//#include <stdio.h>
//void func(char *p) { p = p + 1; } int main()
//{
//    char s[] = {'1', '2', '3', '4'};
//    func(s);
//    printf("%c", *s);
//    return 0;
//}
//void fun(char **p) {
//    int i;
//    for(i = 0; i < 4; i++)
//        printf("%s", p[i]); }
//int main() {
//    char *s[6] = {"ABCD", "EFGH", "IJKL", "MNOP", "QRST", "UVWX"}; fun(s);
//    printf("\n");
//    return 0;
//}
using namespace std;
//int main() {
//    cout<<sizeof(int*)<<endl;
//    int *k[10][30]; printf("%d\n", sizeof(k)); return 0;
//}
//int main()
//{
//    char *p = nullptr;
//    string s;
//    cin>>s;
//
//    return 0;
//}
//int main() {
//    static char *s[] = {"black", "white", "pink", "violet"}; char **ptr[] = {s+3, s+2, s+1, s}, ***p;
//    p = ptr;
//    ++p;
//    printf("%s", **p+1);
//    return 0; }
//
//#include <stdio.h>
//int main() {
//    int m[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}; int(*p)[4] = (int(*)[4])m; printf("%d", p[1][2]);
//    return 0;
//}
//int main() {
//    char p1[15]="abcd", *p2="ABCD", str[50]="xyz"; strcpy(str + 2, strcat(p1+2, p2+1));
//    printf("%s", str);
//    return 0;
////}
//#include<stdio.h>
//char* f(char* str, char ch) {
//    char* it1 = str; char* it2 = str; while(*it2 != '\0') {
//        while (*it2 == ch) {
//            it2++; }
//        *it1++ = *it2++; }
//    return str; }
//int main() {
//    char a[10];
//    strcpy(a, "abcdcccd"); printf("%s", f(a, 'c')); return 0;
//}
//int main() {
//    char arr[2][4]; strcpy (arr[0],"you"); strcpy (arr[1],"me"); arr[0][3]='&'; printf("%s \n",arr); return 0;
//}
//struct st {
//    int *p; int i; char a;
//};
//int main()
//{
//    int sz = sizeof(struct st);
//    cout<<sz;
//}
#include<stdio.h>
#define Mul(x,y) ++x*++y
int main()
{
int a = 1;
int b = 2;
int c = 3; printf("%d\n",Mul(a+b,b+c)); return 0;
}

