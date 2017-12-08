#include"head.h"
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	lqueuetp * lq=(lqueuetp *)malloc(sizeof(lqueuetp));
	Menu(lq);
	return 0;
}