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
	delStr(s1,s2);
	prin(s1);
	return 0;
}