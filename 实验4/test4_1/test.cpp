#include"head.h"
#include<stdio.h>
#include<stdlib.h>
void menu(STACK * s)
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
		printf("6-> �ж�ջ�Ƿ�Ϊ��\n");
		printf("7-> ���ջ��Ԫ��\n");
		printf("0-> �˳�\n");
		printf("*********************\n");
		printf("����ѡ�");
		fflush(stdin);
		scanf("%d",&n);
		switch(n)
		{
			case 1:test1_1(s);break;
			case 2:
			{
				if(s->top!=0)
					printf("ջ��Ԫ��Ϊ��%d\n",test1_2(s));
				else printf("ջ��Ԫ��Ϊ��\n");
			}break;
			case 3:
			{
				int tmp;
				fflush(stdin);
				printf("����Ҫ��ջ��ֵ��");
				scanf("%d",&tmp);
				test1_3(s,tmp);
			}break;
			case 4:
			{
				if(s->top!=0)
					printf("��ջ�ɹ���%d\n",test1_4(s));
				else printf("��ջʧ��!\n");
			}break;
			case 5:
			{
				int t;
				t=test1_5(s);
				if(t)
					printf("ջ��\n");
				else printf("ջ����\n");
			}break;
			case 6:
			{
				int t;
				t=test1_6(s);
				if(t)
					printf("ջ��\n");
				else printf("ջ����\n");
			}break;
			case 7:print1(s);break;
		}
	}
}
void test1_1(STACK * s)
{
	s->top=0;
}
int test1_2(STACK *s)
{
	return s->data[s->top-1];
}
void test1_3(STACK *s,int num)
{
	if(s->top!=MAX)
	{
		s->data[s->top]=num;
		s->top++;
	}
	else printf("ջΪ�����޷���ջ\n");
}
int test1_4(STACK *s)
{
	return s->data[--s->top];
}
int test1_5(STACK *s)
{
	if(s->top==0)
		return 1;
	else return 0;
}
int test1_6(STACK *s)
{
	if(s->top==MAX)
		return 1;
	else return 0;
}
void print1(STACK *s)
{
	int i=s->top;
	while(i!=0)
	{
		printf("%d ",s->data[--i]);
	}
	printf("\n");
}