#include"head.h"
#include<stdio.h>
#include<stdlib.h>
void menu(LinkStack * ls)
{
	int n=1;
	while(n)
	{
		printf("*********************\n");
		printf("1-> 初始化栈\n");
		printf("2-> 显示栈顶元素\n");
		printf("3-> 将一个元素入栈\n");
		printf("4-> 从栈中弹出一个元素\n");
		printf("5-> 判断栈是否为空\n");
		printf("6-> 输出栈各元素\n");
		printf("0-> 退出\n");
		printf("*********************\n");
		printf("输入选项：");
		fflush(stdin);
		scanf("%d",&n);
		switch(n)
		{
			case 1:test2_1(ls);break;
			case 2:
			{
				if(ls->top!=NULL)
					printf("栈顶元素为:%d\n",test2_2(ls));
				else printf("栈顶元素为空\n");
			}break;
			case 3:
			{
				int tmp;
				fflush(stdin);
				printf("输入要入栈的值:");
				scanf("%d",&tmp);
				test2_3(ls,tmp);
			}break;
			case 4:
			{
				int t;
				t=test2_4(ls);
				if(t!=NULL)
					printf("弹栈成功：%d\n",t);
				else printf("弹栈失败!\n");
			}break;
			case 5:
			{
				int t;
				t=test2_5(ls);
				if(t)
					printf("栈空\n");
				else printf("栈不空\n");
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