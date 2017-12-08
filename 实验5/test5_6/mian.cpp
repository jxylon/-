#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	int maxlen,pos1,pos2,i;
	string * s1=(string *)malloc(sizeof(string));
	string * s2=(string *)malloc(sizeof(string));
	s1->length=0;
	getCh(s1);
	s2->length=0;
	fflush(stdin);
	getCh(s2);
	maxcommonstr(*s1,*s2,maxlen,pos1,pos2);
	printf("maxlen=%d pos1=%d pos2=%d\n",maxlen,pos1,pos2);
	for(i=pos1-1;i<maxlen+pos1-1;i++)
		printf("%c",s1->ch[i]);
	printf("\n");
	return 0;
}