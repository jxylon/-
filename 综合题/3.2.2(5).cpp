#define MAX 1024
#include<stdio.h>
#include<stdlib.h>
typedef struct stack//Ë³ÐòÕ» ´æ·Åint
{
	int data[MAX];
	int top;
}STACK;
void push(STACK *s,int num)
{
	s->data[s->top++]=num;
}
STACK * merge(STACK *s1,STACK *s2)
{
	STACK * s=(STACK *)malloc(sizeof(STACK));
	STACK * r=(STACK *)malloc(sizeof(STACK));
	s->top=0;
	r->top=0;
	while(s1->top!=0&&s2->top!=0)
	{
		if(s1->data[s1->top-1]>=s2->data[s2->top-1])
			s->data[s->top++]=s1->data[--s1->top];
		else
			s->data[s->top++]=s2->data[--s2->top];
	}
	if(s2->top==0)
	{
		while(s1->top!=0)
			s->data[s->top++]=s1->data[--s1->top];
	}
	else
	{
		while(s2->top!=0)
			s->data[s->top++]=s2->data[--s2->top];
	}
	while(s->top!=0)
		r->data[r->top++]=s->data[--s->top];
	return r;
}
int main(void)
{
	STACK * s1=(STACK *)malloc(sizeof(STACK));
	s1->top=0;
	push(s1,2);
	push(s1,3);
	push(s1,4);
	STACK * s2=(STACK *)malloc(sizeof(STACK));
	s2->top=0;
	push(s2,1);
	push(s2,2);
	push(s2,5);
	STACK * s=merge(s1,s2);
	return 0;
}