#include"head.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int test6_1(char * p)
{
	int i,flag,len;
	STACKC * s=(STACKC *)malloc(sizeof(STACKC));
	s->top=0;
	len=strlen(p);
	for(i=0;i<len/2;i++)
	{
		if(((*p)>='a'&&(*p)<='z')||((*p)>='A'&&(*p)<='Z'))
		{
			s->c[s->top++]=*p;
			p++;
		}
	}
	if(len%2==1)
		p++;
	while(s->top!=0)
	{
		if(s->c[s->top-1]==*p)
		{
			p++;
			s->top--;
		}
		else break;
	}
	if(s->top!=0)
		flag=0;
	else flag=1;
	return flag;
}
int test6_2(char * p)
{
	int i,flag=1,len;
	LinkC * temp=NULL;
	LinkStackC * ls=(LinkStackC *)malloc(sizeof(LinkStackC));
	ls->top=NULL;
	len=strlen(p);
	for(i=0;i<len/2;i++)
	{
		if(((*p)>='a'&&(*p)<='z')||((*p)>='A'&&(*p)<='Z'))
		{
			LinkC * link=(LinkC *)malloc(sizeof(LinkC));
			link->info=*p;
			link->next=ls->top;
			ls->top=link;
			p++;
		}
	}
	if(len%2==1)
		p++;
	while(ls->top!=NULL)
	{
		if(ls->top->info==*p)
		{
			p++;
			temp=ls->top;
			ls->top=temp->next;
			free(temp);
		}
		else break;
	}
	if(ls->top!=NULL)
		flag=0;
	else flag=1;
	return flag;
}
