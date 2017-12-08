#include<stdio.h>
#include<stdlib.h>
#include"head.h"
void initStack(STACK *s)
{
	s->top=0;
}
void push(STACK *s,char c)
{
	if(s->top!=MAX)
		s->data[++s->top]=c;
	else printf("STACK FULL!\n");
}
char pop(STACK *s)
{
	if(s->top!=0)
		return s->data[--s->top];
	else 
		return NULL;
}
int readFile(STACK *s,char str[])
{
	FILE * file;
	char temp,flag;
	file=fopen(str,"r");
	if(file==NULL)
		printf("打开文件失败\n");
	else 
	{
		while(!feof(file))
		{
			fread(&temp,1,1,file);
			if(temp=='{')
				push(s,'{');
			else if(temp=='}')
				flag=pop(s);
		}
	}
	fclose(file);
	if(s->top==0&&flag=='}')//入栈与出栈一样多
		return 0;
	else if(s->top==0&&flag==NULL)//出栈比入栈多
		return 1;
	else return -1;//入栈比出栈多
}
void test2_1(LinkStack * ls)
{
	ls->top=NULL;
}
void test2_3(LinkStack * ls,char c)
{
	Link * s=(Link*)malloc(sizeof(Link));
	s->info=c;
	s->next=ls->top;
	ls->top=s;
}
char test2_4(LinkStack * ls)
{
	char x;
	Link * p=NULL;
	if(ls->top!=NULL)
	{	
		x=ls->top->info;
		p=ls->top;
		ls->top=p->next;
		free(p);
		return x;
	}
	else return NULL;
}
int readFile2(LinkStack *ls,char str[])
{
	FILE * file;
	char temp,flag;
	file=fopen(str,"r");
	if(file==NULL)
		printf("打开文件失败\n");
	else 
	{
		while(!feof(file))
		{
			fread(&temp,1,1,file);
			if(temp=='{')
				test2_3(ls,'{');
			else if(temp=='}')
				flag=test2_4(ls);
		}
	}
	fclose(file);
	if(ls->top==NULL&&flag=='}')//入栈与出栈一样多
		return 0;
	else if(ls->top==NULL&&flag==NULL)//出栈比入栈多
		return 1;
	else return -1;//入栈比出栈多
}