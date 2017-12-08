#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "head.h"
void iniStack(sqstacktp * s)
{
	s->top=0;
}
void iniStack2(sqstacktp2 * s)
{
	s->top=0;
}
int StackEmpty(sqstacktp * s)
{
	if(s->top==0)
		return 1;
	else return 0;
}
void push(sqstacktp * s,char x)
{
	if(s->top==Maxsize)
		printf("overflow\n");
	else
		s->elem[s->top++]=x;
}
void push2(sqstacktp2 * s,float x)
{
	if(s->top==Maxsize)
		printf("overflow\n");
	else
		s->elem2[s->top++]=x;
}
char pop(sqstacktp *s)
{
	if(s->top==0)
		return NULL;
	else
	{
		s->top--;
		return s->elem[s->top];
	}
}
float pop2(sqstacktp2 *s)
{
	if(s->top==0)
		return NULL;
	else
	{
		s->top--;
		return s->elem2[s->top];
	}
}
int size(sqstacktp * s)
{
	return s->top;
}
char top(sqstacktp * s)
{
	if(s->top==0)
		return NULL;
	else return s->elem[s->top-1];
}
float top2(sqstacktp2 * s)
{
	if(s->top==0)
		return NULL;
	else return s->elem2[s->top-1];
}
int precedence(char c)
{
	int z=0;
	switch(c)
	{
	case '#':z=0;break;
	case '(':z=1;break;
	case ')':z=4;break;
	case '+':z=2;break;
	case '-':z=2;break;
	case '*':z=3;break;
	case '/':z=3;break;
	default :z=0;break;
	}
	return z;
}
float operate(float x,char theta,float y)
{
	float result;
	switch(theta)
	{
	case '+':result=x+y;break;
	case '-':result=x-y;break;
	case '*':result=x*y;break;
	case '/':
		{
			if(y!=0)
				result=x/y;
			else result=0;break;
		}
	}
	return result;
}
float exp_reduced()
{
	char ch,theta;
	float a=0,x,y,result;
	int flag=0;
	char op[8];
	strcpy(op,"+-*/#()");
	sqstacktp2 * OPND;
	sqstacktp * OPTR;
	OPTR=(sqstacktp *)malloc(sizeof(sqstacktp));//ÔËËã·û
	OPND=(sqstacktp2 *)malloc(sizeof(sqstacktp2));//ÊýÖµ
	iniStack(OPTR);
	push(OPTR,'#');
	iniStack2(OPND);
	scanf("%c",&ch);
	while(!(ch=='#'&&top(OPTR)=='#'))
	{
		while(!strchr(op,ch))
		{
			a=a*10+ch-'0';
			ch=getchar();
			flag=1;
		}
		if(flag==1)
		{
			push2(OPND,a);
			flag=0;
			a=0;
		}
		else if(precedence(ch)>precedence(top(OPTR)))
		{
			push(OPTR,ch);
			ch=getchar();
		}
		else if(top(OPTR)==')')
		{
			pop(OPTR);
			theta=pop(OPTR);
			pop(OPTR);
			y=pop2(OPND);
			x=pop2(OPND);
			result=operate(x,theta,y);
			push2(OPND,result);
		}
		else
		{
			theta=pop(OPTR);
			y=pop2(OPND);
			x=pop2(OPND);
			result=operate(x,theta,y);
			push2(OPND,result);
		}
	}
	return(top2(OPND));
}

