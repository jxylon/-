#define MAX 1024
#include<stdio.h>
#include<stdlib.h>
typedef struct stack//À≥–Ú’ª ¥Ê∑≈int
{
	int data[MAX];
	int top;
}STACK;
typedef struct link//¡¥’ª ¥Ê∑≈int
{
	int info;
	struct link * next;
}Link;
typedef struct
{
	Link * top;
}LinkStack;
typedef struct node//¡¥±Ì
{
	int a;
	struct node * next;
}Node;
void test1_1(STACK * s)
{
	s->top=0;
}
void test1_3(STACK *s,int num)
{
	s->data[s->top]=num;
	s->top++;
}
int test1_4(STACK *s)
{
	return s->data[--s->top];
}
void test2_1(LinkStack * ls)
{
	ls->top=NULL;
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
void createLink(Node * head)
{
	Node * p=NULL;
	char a;
	int num;
	printf("Do you want to add x to linklist,y->yes,n->no\n");
	fflush(stdin);
	a=getchar();
	while(a=='y')
	{
		printf("put in a num:");
		scanf("%d",&num);
		p=(Node *)malloc(sizeof(Node));
		p->a=num;
		p->next=head->next;
		head->next=p;
		printf("Do you want to add x to linklist,y->yes,n->no\n");
		fflush(stdin);
		a=getchar();
	}
}
void print(Node * head)
{
	Node * p=NULL;
	p=head->next;
	while(p!=NULL)
	{
		printf("%d ",p->a);
		p=p->next;
	}
	printf("\n");
}
void test5_1(Node * head)
{
	Node * p=NULL;
	STACK * s=(STACK *)malloc(sizeof(STACK));
	test1_1(s);
	p=head->next;
	while(p!=NULL)
	{
		test1_3(s,p->a);
		p=p->next;
	}
	p=head->next;
	while(p!=NULL)
	{
		p->a=test1_4(s);
		p=p->next;
	}
}
void test5_2(Node * head)
{
	Node * p=NULL;
	LinkStack * ls=(LinkStack *)malloc(sizeof(LinkStack));
	test2_1(ls);
	p=head->next;
	while(p!=NULL)
	{
		test2_3(ls,p->a);
		p=p->next;
	}
	p=head->next;
	while(p!=NULL)
	{
		p->a=test2_4(ls);
		p=p->next;
	}
}
int main(void)
{
	Node * head=(Node *)malloc(sizeof(Node));
	head->next=NULL;
	createLink(head);
	printf("À≥–Ú’ª∑Ω∑®:");
	test5_1(head);
	print(head);
	printf("¡¥’ª∑Ω∑®:");
	test5_2(head);
	print(head);
	return 0;
}