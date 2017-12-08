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
void maxcommonstr(string s,string t,int &maxlen,int &pos1,int &pos2)
{
	int i=0,j=0,len,ps,pt,ii;
	maxlen=0;
	while(i<s.length-1)
	{
		ii=i;
		len=0;
		while(j<t.length-1)
		{	
			if(s.ch[i]!=t.ch[j])
			{
				i=ii;
				len=0;
				j++;
			}
			else if(len==0)
			{
				ps=i;
				pt=j;
				i++;
				j++;
				len++;
			}
			else
			{
				i++;
				j++;
				len++;
			}
			if(len>maxlen)
			{
				pos1=ps+1;
				pos2=pt+1;
				maxlen=len;
			}
		}
		i=ii+1;
		j=0;
	}
}
