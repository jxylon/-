#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	tree t;
	init(t);
	create(t);
	printf("树的结点有:");
	prinTree(t);
	searchChild(t);
	return 0;
}