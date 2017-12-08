#include"head.h"
#include<stdio.h>
#include<stdlib.h>
void menu(LinkStack * ls)
{
	int n=1;
	while(n)
	{
		printf("*********************\n");
		printf("1-> ��ʼ��ջ\n");
		printf("2-> ��ʾջ��Ԫ��\n");
		printf("3-> ��һ��Ԫ����ջ\n");
		printf("4-> ��ջ�е���һ��Ԫ��\n");
		printf("5-> �ж�ջ�Ƿ�Ϊ��\n");
		printf("6-> ���ջ��Ԫ��\n");
		printf("0-> �˳�\n");
		printf("*********************\n");
		printf("����ѡ�");
		fflush(stdin);
		scanf("%d",&n);
		switch(n)
		{
			case 1:test2_1(ls);break;
			case 2:
			{
				if(ls->top!=NULL)
					printf("ջ��Ԫ��Ϊ:%d\n",test2_2(ls));
				else printf("ջ��Ԫ��Ϊ��\n");
			}break;
			case 3:
			{
				int tmp;
				fflush(stdin);
				printf("����Ҫ��ջ��ֵ:");
				scanf("%d",&tmp);
				test2_3(ls,tmp);
			}break;
			case 4:
			{
				int t;
				t=test2_4(ls);
				if(t!=NULL)
					printf("��ջ�ɹ���%d\n",t);
				else printf("��ջʧ��!\n");
			}break;
			case 5:
			{
				int t;
				t=test2_5(ls);
				if(t)
					printf("ջ��\n");
				else printf("ջ����\n");
			}break;
			case 6:print2(ls);break;
		}
	}
}
void test2_1(LinkStack * ls)
{
	ls->top=NULL;
}                                                                                                                                                                                                                                             
int test2_2(LinkStack * ls)
{
	if(ls->top!=NULL)
		return ls->top->info;
	else return NULL;
}
void test2_3(LinkStack * ls,int num)
{
	Link * s=(Link*)malloc(sizeof(Link));
	s->info=num;
	s->next=ls->top;
	ls->top=s;
}
int test2_4(LinkStack * ls)
{
	int x;
	Link * p=NULL;
	if(ls->top!=NULL)
	{
		x=ls->top->info;
		p=ls->top;
		ls->top=p->next;
		free(p);
		return x;
	}
	else 
	{
		return NULL;
	}
}
int test2_5(LinkStack * ls)
{
	if(ls->top==NULL)
		return 1;
	else return 0;
}
void print2(LinkStack * ls)
{
	while(ls->top!=NULL)
	{
		printf("%d ",ls->top->info);
		ls->top=ls->top->next;
	}
	printf("\n");
}