#include<stdio.h>
#include<stdlib.h>
#include"head.h"
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
int judge(string * s1,string * s2)
{
	int i;
	for(i=0;i<s1->length-1;i++)
	{
		if(s1->ch[i]!=s2->ch[i])
			return 0;
	}
	return 1;
}