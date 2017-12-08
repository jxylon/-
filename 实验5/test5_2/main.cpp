#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	string * s=(string *)malloc(sizeof(string));
	s->length=0;
	getCh(s);
	reserve(s);
	prin(s);
	return 0;
}