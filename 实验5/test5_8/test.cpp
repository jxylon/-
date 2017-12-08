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
void prin(string * s)
{
	int i;
	for(i=0;i<s->length;i++)
		printf("%c",s->ch[i]);
	printf("\n");
}
int pattern_index(string * s1,string * s2)
{
	int i,j;
	for(i=0;i<=s2->length-s1->length;i++)
	{
		j=0;
		while((s1->ch[j]=='?'||s1->ch[j]==s2->ch[j+i])&&(j<s1->length-1))
			j++;
		if(j==s1->length-1)
			return i;
	}
	return -1;
}
