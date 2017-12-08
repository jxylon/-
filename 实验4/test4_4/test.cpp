#include"head.h"
#include<stdio.h>
#include<stdlib.h>
void test4_1(lqueuetp * lq)
{
	lq->front=(Node *)malloc(sizeof(Node));
	lq->front->next=NULL;
	lq->rear=lq->front;
}
void test4_2(lqueuetp * lq,int num)
{
	Node * node=(Node *)malloc(sizeof(Node));
	node->data=num;
	node->next=NULL;
	lq->rear->next=node;
	lq->rear=node;
}
int test4_3(lqueuetp * lq)
{
	Node * p;
	int x;
	if(lq->front==lq->rear)
		return NULL;
	else 
	{
		p=lq->front->next;
		lq->front->next=p->next;
		if(p->next==NULL)
			lq->rear=lq->front;
		x=p->data;
		free(p);
		return(x);
	}
}
int test4_4(lqueuetp * lq)
{
	if(lq->front==lq->rear)
		return 1;
	else return 0;
}
void print(lqueuetp * lq)
{
	Node * p=NULL;
	p=lq->front->next;
	while(p)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
}
void Menu(lqueuetp * lq)
{
	int n=1;
	while(n)
	{
		printf("*********************\n");
		printf("1-> ��ʼ������\n");
		printf("2-> ��һ��Ԫ�����\n");
		printf("3-> ��һ��Ԫ�س���\n");
		printf("4-> �ж����Ƿ�Ϊ��\n");
		printf("5-> �������\n");
		printf("0-> �˳�\n");
		printf("*********************\n");
		printf("����ѡ�");
		scanf("%d",&n);
		switch(n)
		{
			case 1:test4_1(lq);break;
			case 2:
				{
					int x;
					printf("����Ҫ��ӵ�ֵ\n");
					scanf("%d",&x);
					test4_2(lq,x);
				}break;
			case 3:
				{
					int x;
					x=test4_3(lq);
					printf("���ӵ�Ԫ��Ϊ%d\n",x);	
				}break;
			case 4:
				{
					int x;
					x=test4_4(lq);
					if(x)
						printf("�ö���Ϊ��\n");
					else printf("�ö��в�Ϊ��\n");
				}break;
			case 5:
				{
					print(lq);
				}break;
		}
	}
}