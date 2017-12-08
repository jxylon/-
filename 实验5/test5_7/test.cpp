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
void delStr(string * s1,string * s2)
{
	int i=0,j,len;
	while(i<s1->length-1)
	{
		len=0;
		i=0;
		j=0;
		while(j<s2->length-1)
		{
			if(s1->ch[i]!=s2->ch[j])
			{
				i++;
			}
			else 
			{
				i++;
				j++;
				len++;
			}
		}
		i=i-j;
		if(i+len>=s1->length-1)
			s1->length=s1->length-len-1;
		else
		{
			for(j=0;j<len;j++)
				s1->ch[i+j]=s1->ch[i+len+j];
			s1->length=s1->length-len;
		}
	}
}