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
	if(judge(s1,s2))
		printf("s1��s2��ǰ׺\n");
	else
		printf("s1����s2��ǰ׺\n");
	return 0;
}