#include"head.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void init(lqueuetp * lq)
{
	lq->front=(Node *)malloc(sizeof(Node));
	lq->front->next=NULL;
	lq->rear=lq->front;
}
void enQueue(lqueuetp * lq,char str[])
{
	Node * node=(Node *)malloc(sizeof(Node));
	strcpy(node->data,str);
	node->next=NULL;
	lq->rear->next=node;
	lq->rear=node;
	printf("%s���\n",str);
}
void delQueue(lqueuetp * lq)
{
	Node * p;
	if(lq->front==lq->rear)
		printf("����Ϊ��\n");
	else
	{
		p=lq->front->next;
		lq->front->next=p->next;
		printf("%s����\n",p->data);
		if(p->next==NULL)
			lq->rear=lq->front;
		free(p);
		
	}
}
void print(lqueuetp * lq)
{
	Node * p;
	p=lq->front->next;
	printf("***********\n");
	printf("���ڶ�����Ϣ:");
	while(p)
	{
		printf("%s ",p->data);
		p=p->next;
	}
	printf("\n");
}