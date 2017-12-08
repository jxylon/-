#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	STACK * s=(STACK *)malloc(sizeof(STACK));
	menu(s);
	return 0;
}