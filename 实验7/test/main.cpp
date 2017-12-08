#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	int n;
	bitreptr * bt=create_bnode();
	n=singleChild(bt);
	printf("%d\n",n);
	return 0;
}
