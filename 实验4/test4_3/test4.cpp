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
		printf("队满\n");
	else
		q->data[++q->rear]=num;
}
int test3_3(QUEUE * q)
{
	int x;
	if(q->front==q->rear)
	{
		printf("队空\n");
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
		printf("1-> 初始化队列\n");
		printf("2-> 将一个元素入队\n");
		printf("3-> 将一个元素出队\n");
		printf("4-> 判队列是否为空\n");
		printf("5-> 判队列是否为满\n");
		printf("6-> 输出队列\n");
		printf("0-> 退出\n");
		printf("*********************\n");
		printf("输入选项：");
		scanf("%d",&n);
		switch(n)
		{
			case 1:test3_1(q);break;
			case 2:
				{
					int x;
					printf("输入要入队的值\n");
					scanf("%d",&x);
					test3_2(q,x);
				}break;
			case 3:
				{
					int x;
					x=test3_3(q);
					printf("出队的元素为%d\n",x);	
				}break;
			case 4:
				{
					int x;
					x=test3_4(q);
					if(x)
						printf("该队列为空\n");
					else printf("该队列不为空\n");
				}break;
			case 5:
				{
					int x;
					x=test3_5(q);
					if(x)
						printf("该队列为满\n");
					else printf("该队列不为满\n");	
				}break;
			case 6:
				{
					print(q);
				}break;
		}
	}
}
