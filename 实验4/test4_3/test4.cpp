#include "head.h"
#include<stdio.h>
#include<stdlib.h>
void test3_1(QUEUE * q)
{
	q->front=q->rear=-1;
}
void test3_2(QUEUE * q,int num)
{
	if(q->rear==Max)
		printf("����\n");
	else
		q->data[++q->rear]=num;
}
int test3_3(QUEUE * q)
{
	int x;
	if(q->front==q->rear)
	{
		printf("�ӿ�\n");
		return NULL;
	}
	else
	{
		x=q->data[++q->front];
	}
	return x;
}
int test3_4(QUEUE * q)
{
	if(q->front==q->rear)
		return 1;
	else return 0;
}
int test3_5(QUEUE * q)
{
	if(q->rear==Max)
		return 1;
	else
		return 0;
}
void print(QUEUE * q)
{
	while(q->rear!=q->front)
	{
		printf("%d ",q->data[++q->front]);

	}
	printf("\n");
}
void Menu(QUEUE * q)
{
	int n=1;
	while(n)
	{
		printf("*********************\n");
		printf("1-> ��ʼ������\n");
		printf("2-> ��һ��Ԫ�����\n");
		printf("3-> ��һ��Ԫ�س���\n");
		printf("4-> �ж����Ƿ�Ϊ��\n");
		printf("5-> �ж����Ƿ�Ϊ��\n");
		printf("6-> �������\n");
		printf("0-> �˳�\n");
		printf("*********************\n");
		printf("����ѡ�");
		scanf("%d",&n);
		switch(n)
		{
			case 1:test3_1(q);break;
			case 2:
				{
					int x;
					printf("����Ҫ��ӵ�ֵ\n");
					scanf("%d",&x);
					test3_2(q,x);
				}break;
			case 3:
				{
					int x;
					x=test3_3(q);
					printf("���ӵ�Ԫ��Ϊ%d\n",x);	
				}break;
			case 4:
				{
					int x;
					x=test3_4(q);
					if(x)
						printf("�ö���Ϊ��\n");
					else printf("�ö��в�Ϊ��\n");
				}break;
			case 5:
				{
					int x;
					x=test3_5(q);
					if(x)
						printf("�ö���Ϊ��\n");
					else printf("�ö��в�Ϊ��\n");	
				}break;
			case 6:
				{
					print(q);
				}break;
		}
	}
}
