#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct a	//�����˵��ṹ�� 
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
void Input();//���뺯��  
int Filereader(Bill b[]);//���ļ����� 
void Datesort(Bill b[], int len);//���������� 
void Datesearch(Bill b[], int len);//�����ڲ��Һ��� 
void analysis(Bill b[], int len);
void MaxAndMin(Bill b[], int len);
void MonthAmount(Bill b[], int len);
int main()
{
	int j, len;
	Bill b[20];//�������ж���һ���˵��ṹ������ 
	len = Filereader(b);//�Ƚ��ļ������ݶ��������в��������鳤��  
	system("color E");

	do
	{
		menu();
		scanf("%d", &j);//����������� 
		switch (j)
		{
		case 1: Input();
			break;
		case 2:
			len = Filereader(b);//�ٴε��ö��ļ��������� 1�����е���Ϣ¼�� 
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
		case 0: printf("���˳�����\n");
			return 0;
		}
		printf("     \n��������һ������:  ");

	} while (1);

}

void menu()
{
	time_t  t;
	struct  tm* lt;
	time(&t); //��ȡUnixʱ�����
	lt = localtime(&t); //תΪʱ��ṹ��

	system("color E");//�ı�������ɫ 
	printf("\n\n\n\n\t\t\t***************   ѧ���ɼ�����ϵͳ     ********************\n");
	printf("\t\t\t               Time:%d/%d/%d %d:%d:%d\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec); //���ϵͳʱ�� 
	printf("\t\t\t|==========================================================|\n");
	printf("\t\t\t|*************1.  �˵���Ϣ¼��              ***************|\n");
	printf("\t\t\t|*************2.  ��������������˵���Ϣ    ***************|\n");
	printf("\t\t\t|*************3.  �����ڲ�ѯ�˵���Ϣ        ***************|\n");
	printf("\t\t\t|*************4.  ���·�ͳ�����ѽ��        ***************|\n");
	printf("\t\t\t|*************5.  ���˵����ͳ�Ʒ���        ***************|\n");
	printf("\t\t\t|*************6.  ��ѯ������ٺ������˵�  ***************|\n");
	printf("\t\t\t|*************0.  �˳�ϵͳ                  ***************|\n");
	printf("\t\t\t|==========================================================|\n");
	printf("\t\t\t|**********************************************************|\n");
	printf("\n\n\t\t\t      ��ѡ����Ӧ�Ĺ���<������>:");

}

//�������ݺ��� 
void Input()
{
	char i;
	int n;
	FILE* fp;
	Bill* p;
	if ((fp = fopen("X:\\C_C++_code\\cpp-advanced-data-structure\\����ϵͳ\\����ϵͳ\\bill.txt", "a+")) == NULL)
	{
		printf("���ļ�ʧ��\n");
		exit(-1);
	}


	for (i = 'Y'; i == 'Y';)
	{
		p = (Bill*)malloc(sizeof(Bill));
		printf("�����������˵���Ϣ�������˵�ժҪ ��� ���� ������ �˵����� ��ע��\n");

		scanf("%s%f%d%d%d%s%s%s", p->name, &p->money, &p->year, &p->month, &p->day, p->number, p->type, p->tip);
		fprintf(fp, "%16s %6.2f %5d %02d %02d %10s %16s %16s\n", p->name, p->money, p->year, p->month, p->day, p->number, p->type, p->tip);
		printf("�Ƿ����¼����һ���˵���Y/N��\n");
		getchar();
		scanf(" %c", &i);


	}

	fclose(fp);
}

//���ļ����� 
int Filereader(Bill b[])
{
	int i, len;
	FILE* fp;
	if ((fp = fopen("D:\\Demo\\bill.txt", "a+")) == NULL)
	{
		printf("���ļ�ʧ��\n");
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

//�������Ⱥ�˳������ ��ѡ������ 
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
		printf("\t\t\t�˵�ժҪ��%s\n\t\t\t��%.2f\n\t\t\t���ڣ�%4d-%02d-%02d\n\t\t\t�����ţ�%s\n\t\t\t�˵����ࣺ%s \n\t\t\t��ע��  %s \n", b[i].name, b[i].money, b[i].year, b[i].month, b[i].day, b[i].number, b[i].type, b[i].tip);
		printf("\n\t\t\t---------------------------\n");
	}

}
//���ڲ��Һ�����˳����ң� 
void  Datesearch(Bill b[], int len)
{
	int i, j = 1;
	Bill a;
	printf("����������Ҫ��ѯ�����ڣ���ʽ��2018-9-1��  ");
	scanf("%d-%d-%d", &a.year, &a.month, &a.day);
	for (i = 0; i < len; i++)
	{
		if (a.year == b[i].year && a.month == b[i].month && a.day == b[i].day)
		{
			printf("\n---------------------------\n");
			printf("�˵�ժҪ��%s\n��%.2f\n���ڣ�%4d-%02d-%02d\n�����ţ�%s\n�˵����ࣺ%s \n��ע��  %s \n", b[i].name, b[i].money, b[i].year, b[i].month, b[i].day, b[i].number, b[i].type, b[i].tip);
			printf("\n---------------------------\n");
			j = 0;
		}
	}
	if (j)
		printf("������û���˵�\n");

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

	printf("���ѽ�����ٵĶ�����\n---------------------------\n�˵�ժҪ��%s\n��%.2f\n���ڣ�%4d-%02d-%02d\n�����ţ�%s\n�˵����ࣺ%s \n��ע��  %s \n\n", b[min].name, b[min].money, b[min].year, b[min].month, b[min].day, b[min].number, b[min].type, b[min].tip);
	printf("���ѽ�����Ķ�����\n---------------------------\n�˵�ժҪ��%s\n��%.2f\n���ڣ�%4d-%02d-%02d\n�����ţ�%s\n�˵����ࣺ%s \n��ע��  %s \n", b[max].name, b[max].money, b[max].year, b[max].month, b[max].day, b[max].number, b[max].type, b[max].tip);
}

//���·ݷ���ͳ�����ѽ��
void MonthAmount(Bill b[], int len)
{
	int i, j, year, flag[12] = { 0 };
	int k = 1;
	Bill c;
	double sumAccount = 0;
	double sumMonthMoney[12] = { 0 };
	printf("�����뽫Ҫ��ѯ�����:");
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
				printf("%d������%.1fԪ,ռ��Ȱٷֱ�Ϊ:%%%.1f\n", j, sumMonthMoney[j - 1], (sumMonthMoney[j - 1] / sumAccount) * 100);
				flag[j - 1] = 1;
				k = 0;
			}
		}
	}
	if (k)
		printf("��������˵���\n");

}

//���˵����ͳ�Ʒ��� 
void analysis(Bill b[], int len)
{

	float sum1 = 0, sum2 = 0, sum3 = 0, sum = 0;
	int i, j;
	for (i = 0; i < len; i++)
	{
		sum += b[i].money;
	}
	for (i = 0; i < len; i++) {
		if (!strcmp(b[i].type, "����"))
			sum1 += b[i].money;
		if (!strcmp(b[i].type, "�軹��"))
			sum2 += b[i].money;
		if (!strcmp(b[i].type, "��������"))
			sum3 += b[i].money;
	}
	printf("������ռ�����ǣ�%%%.1f\t", (sum1 / sum) * 100);
	printf("�軹����ռ�����ǣ�%%%.1f\t", (sum2 / sum) * 100);
	printf("����������ռ��ȱ����ǣ�%%%.1f\t", (sum3 / sum) * 100);
}
