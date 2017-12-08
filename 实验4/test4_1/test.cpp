#include"head.h"
#include<stdio.h>
#include<stdlib.h>
void menu(STACK * s)
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
		printf("6-> 判断栈是否为满\n");
		printf("7-> 输出栈各元素\n");
		printf("0-> 退出\n");
		printf("*********************\n");
		printf("输入选项：");
		fflush(stdin);
		scanf("%d",&n);
		switch(n)
		{
			case 1:test1_1(s);break;
			case 2:
			{
				if(s->top!=0)
					printf("栈顶元素为：%d\n",test1_2(s));
				else printf("栈顶元素为空\n");
			}break;
			case 3:
			{
				int tmp;
				fflush(stdin);
				printf("输入要入栈的值：");
				scanf("%d",&tmp);
				test1_3(s,tmp);
			}break;
			case 4:
			{
				if(s->top!=0)
					printf("弹栈成功：%d\n",test1_4(s));
				else printf("弹栈失败!\n");
			}break;
			case 5:
			{
				int t;
				t=test1_5(s);
				if(t)
					printf("栈空\n");
				else printf("栈不空\n");
			}break;
			case 6:
			{
				int t;
				t=test1_6(s);
				if(t)
					printf("栈满\n");
				else printf("栈不满\n");
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
	else printf("栈为满，无法入栈\n");
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