#include <iostream>
#include <stdlib.h>
#define MAXSIZE 100

using namespace std;

typedef struct {
 int* base;
 int* top;
 int stacksize;
}Sqstack;

//初始化栈
int Initial(Sqstack& s)
{
 s.base = (int*)malloc(sizeof(int));
 if (!s.base)
 {
  return 0;
 }
 s.top = s.base;
 s.stacksize = MAXSIZE;
}

//入栈
void push(Sqstack& s, int e)
{
 if (s.top - s.base == s.stacksize)
 {
  return;
 }
 *s.top++ = e;
}
//获取栈的长度
int Stacklength(Sqstack& s)
{
 return s.top - s.base;
}

//出栈
void Pop(Sqstack& s)
{
    if(s.stacksize == 0)
        return;
 s.top--;
}

//取栈顶元素
int getTop(Sqstack& s) {
 return *(s.top);
}


//打印栈中元素
int Print(Sqstack& s)
{
 if (s.base == s.top)
 {
  return 0;
 }
 else
  for (; s.base != s.top; s.base++)
  {
   printf("%d\n", s.base);
  }
}

int main()
{
 int i, e;
 Sqstack s;
 Initial(s);
 int num = 0;

 while(scanf("%d", &num) != EOF)
 {
     push(s,num);
 }
  //push(s, num);

 while (s.top != s.base)
 {
  cout << getTop(s) << ' ';
  Pop(s);
 }
 return 0;
}