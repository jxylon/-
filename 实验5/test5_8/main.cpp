#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	string * s1=(string *)malloc(sizeof(string));
	string * s2=(string *)malloc(sizeof(string));
	s1->length=0;
	getCh(s1);
	s2->length=0;
	fflush(stdin);
	getCh(s2);
	if(pattern_index(s1,s2)!='-1')
		printf("index=%d\n",pattern_index(s1,s2));
	else
		printf("Not found\n");
	return 0;
}