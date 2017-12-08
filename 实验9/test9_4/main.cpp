#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	bitreptr t=NULL;
	t=create();
	inorder(t);
	printf("\n");
	return 0;
}