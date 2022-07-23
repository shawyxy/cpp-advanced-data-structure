#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct a	//定义账单结构体 
{
	char name[50];
	float money;
	int year;
	int month;
	int day;
	char number[10];
	char type[10];
	char tip[20];
}Bill;
void menu();
void Input();//输入函数  
int Filereader(Bill b[]);//读文件函数 
void Datesort(Bill b[], int len);//日期排序函数 
void Datesearch(Bill b[], int len);//按日期查找函数 
void analysis(Bill b[], int len);
void MaxAndMin(Bill b[], int len);
void MonthAmount(Bill b[], int len);
int main()
{
	int j, len;
	Bill b[20];//主函数中定义一个账单结构体数组 
	len = Filereader(b);//先将文件中数据读入数组中并返回数组长度  
	system("color E");

	do
	{
		menu();
		scanf("%d", &j);//输入操作命令 
		switch (j)
		{
		case 1: Input();
			break;
		case 2:
			len = Filereader(b);//再次调用读文件函数，将 1命令中的信息录入 
			Datesort(b, len);
			break;
		case 3: Datesearch(b, len);
			break;
		case 4: MonthAmount(b, len);
			break;
		case 5: analysis(b, len);
			break;
		case 6: MaxAndMin(b, len);
			break;
		case 0: printf("已退出程序\n");
			return 0;
		}
		printf("     \n请输入下一步操作:  ");

	} while (1);

}

void menu()
{
	time_t  t;
	struct  tm* lt;
	time(&t); //获取Unix时间戳。
	lt = localtime(&t); //转为时间结构。

	system("color E");//改变字体颜色 
	printf("\n\n\n\n\t\t\t***************   学生成绩管理系统     ********************\n");
	printf("\t\t\t               Time:%d/%d/%d %d:%d:%d\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec); //输出系统时间 
	printf("\t\t\t|==========================================================|\n");
	printf("\t\t\t|*************1.  账单信息录入              ***************|\n");
	printf("\t\t\t|*************2.  按日期排序输出账单信息    ***************|\n");
	printf("\t\t\t|*************3.  按日期查询账单信息        ***************|\n");
	printf("\t\t\t|*************4.  按月份统计消费金额        ***************|\n");
	printf("\t\t\t|*************5.  按账单类别统计分析        ***************|\n");
	printf("\t\t\t|*************6.  查询金额最少和最多的账单  ***************|\n");
	printf("\t\t\t|*************0.  退出系统                  ***************|\n");
	printf("\t\t\t|==========================================================|\n");
	printf("\t\t\t|**********************************************************|\n");
	printf("\n\n\t\t\t      请选择相应的功能<输入编号>:");

}

//输入数据函数 
void Input()
{
	char i;
	int n;
	FILE* fp;
	Bill* p;
	if ((fp = fopen("X:\\C_C++_code\\cpp-advanced-data-structure\\管理系统\\管理系统\\bill.txt", "a+")) == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}


	for (i = 'Y'; i == 'Y';)
	{
		p = (Bill*)malloc(sizeof(Bill));
		printf("请输入您的账单信息（包括账单摘要 金额 日期 订单号 账单分类 备注）\n");

		scanf("%s%f%d%d%d%s%s%s", p->name, &p->money, &p->year, &p->month, &p->day, p->number, p->type, p->tip);
		fprintf(fp, "%16s %6.2f %5d %02d %02d %10s %16s %16s\n", p->name, p->money, p->year, p->month, p->day, p->number, p->type, p->tip);
		printf("是否继续录入下一个账单（Y/N）\n");
		getchar();
		scanf(" %c", &i);


	}

	fclose(fp);
}

//读文件函数 
int Filereader(Bill b[])
{
	int i, len;
	FILE* fp;
	if ((fp = fopen("D:\\Demo\\bill.txt", "a+")) == NULL)
	{
		printf("打开文件失败\n");
		exit(-1);
	}
	for (i = 0;; i++)
	{
		if (fscanf(fp, "%16s%f", b[i].name, &b[i].money) == EOF) break;
		fscanf(fp, "%5d%02d%02d%10s%16s%16s", &b[i].year, &b[i].month, &b[i].day, b[i].number, b[i].type, b[i].tip);
		len = i + 1;
	}
	fclose(fp);
	return len;
}

//按日期先后顺序排序 （选择排序） 
void Datesort(Bill b[], int len)
{
	int i, j, k;
	Bill t;
	for (i = 0; i < len - 1; i++)
	{
		k = i;
		for (j = k + 1; j < len; j++)
		{
			if (b[j].year < b[k].year)
				k = j;
			else if (b[j].year == b[k].year)
			{
				if (b[j].month < b[k].month)
					k = j;
				else if (b[j].month == b[k].month)
				{
					if (b[j].day < b[k].day)
						k = j;
				}
			}
		}
		if (k != i)
		{
			t = b[k];
			b[k] = b[i];
			b[i] = t;
		}
	}
	printf("\n\t\t\t---------------------------\n");
	for (i = 0; i < len; i++)
	{
		printf("\t\t\t账单摘要：%s\n\t\t\t金额：%.2f\n\t\t\t日期：%4d-%02d-%02d\n\t\t\t订单号：%s\n\t\t\t账单分类：%s \n\t\t\t备注：  %s \n", b[i].name, b[i].money, b[i].year, b[i].month, b[i].day, b[i].number, b[i].type, b[i].tip);
		printf("\n\t\t\t---------------------------\n");
	}

}
//日期查找函数（顺序查找） 
void  Datesearch(Bill b[], int len)
{
	int i, j = 1;
	Bill a;
	printf("请输入您需要查询的日期（格式如2018-9-1）  ");
	scanf("%d-%d-%d", &a.year, &a.month, &a.day);
	for (i = 0; i < len; i++)
	{
		if (a.year == b[i].year && a.month == b[i].month && a.day == b[i].day)
		{
			printf("\n---------------------------\n");
			printf("账单摘要：%s\n金额：%.2f\n日期：%4d-%02d-%02d\n订单号：%s\n账单分类：%s \n备注：  %s \n", b[i].name, b[i].money, b[i].year, b[i].month, b[i].day, b[i].number, b[i].type, b[i].tip);
			printf("\n---------------------------\n");
			j = 0;
		}
	}
	if (j)
		printf("该日期没有账单\n");

}
void MaxAndMin(Bill b[], int len)
{
	int i, min, max;
	min = 0;
	max = 0;
	for (i = 1; i < len; i++)
	{

		if (b[max].money < b[i].money)
			max = i;
		if (b[min].money > b[i].money)
			min = i;
	}

	printf("消费金额最少的订单：\n---------------------------\n账单摘要：%s\n金额：%.2f\n日期：%4d-%02d-%02d\n订单号：%s\n账单分类：%s \n备注：  %s \n\n", b[min].name, b[min].money, b[min].year, b[min].month, b[min].day, b[min].number, b[min].type, b[min].tip);
	printf("消费金额最多的订单：\n---------------------------\n账单摘要：%s\n金额：%.2f\n日期：%4d-%02d-%02d\n订单号：%s\n账单分类：%s \n备注：  %s \n", b[max].name, b[max].money, b[max].year, b[max].month, b[max].day, b[max].number, b[max].type, b[max].tip);
}

//按月份分析统计消费金额
void MonthAmount(Bill b[], int len)
{
	int i, j, year, flag[12] = { 0 };
	int k = 1;
	Bill c;
	double sumAccount = 0;
	double sumMonthMoney[12] = { 0 };
	printf("请输入将要查询的年份:");
	scanf("%d", &year);
	for (i = 0; i < len; i++)
	{
		if (year == b[i].year)
		{
			sumAccount += b[i].money;
		}
	}

	for (i = 0; i < len; i++) {
		if (b[i].year == year) {
			for (j = 1; j <= 12; j++) {
				if (b[i].month == j) {
					sumMonthMoney[j - 1] += b[i].money;
				}
			}
		}
	}
	for (i = 0; i < len; i++) {
		for (j = 1; j <= 12; j++) {
			if (b[i].month == j && !flag[j - 1]) {
				printf("%d月消费%.1f元,占年度百分比为:%%%.1f\n", j, sumMonthMoney[j - 1], (sumMonthMoney[j - 1] / sumAccount) * 100);
				flag[j - 1] = 1;
				k = 0;
			}
		}
	}
	if (k)
		printf("该年度无账单！\n");

}

//按账单类别统计分析 
void analysis(Bill b[], int len)
{

	float sum1 = 0, sum2 = 0, sum3 = 0, sum = 0;
	int i, j;
	for (i = 0; i < len; i++)
	{
		sum += b[i].money;
	}
	for (i = 0; i < len; i++) {
		if (!strcmp(b[i].type, "消费"))
			sum1 += b[i].money;
		if (!strcmp(b[i].type, "借还款"))
			sum2 += b[i].money;
		if (!strcmp(b[i].type, "人情往来"))
			sum3 += b[i].money;
	}
	printf("消费所占比例是：%%%.1f\t", (sum1 / sum) * 100);
	printf("借还款所占比例是：%%%.1f\t", (sum2 / sum) * 100);
	printf("人情往来所占年度比例是：%%%.1f\t", (sum3 / sum) * 100);
}
