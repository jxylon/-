#include<stdio.h>
#include<stdlib.h>
#include"head.h"
void reserve(string * s)
{
	int i;
	char temp;
	for(i=0;i<(s->length-1)/2;i++)
	{
		temp=s->ch[i];
		s->ch[i]=s->ch[s->length-2-i];
		s->ch[s->length-1-i]=temp;
	}
}
void prin(string * s)
{
	int i;
	for(i=0;i<s->length;i++)
		printf("%c",s->ch[i]);
	printf("\n");
}
void getCh(string * s)
{
	char c=' ';
	printf("get ch,@->over\n");
	while(c!='@')
	{
		c=getchar();
		s->ch[s->length]=c;
		s->length++;
	}
}
