#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	tree t;
	init(t);
	create(t);
	printf("���Ľ����:");
	prinTree(t);
	searchChild(t);
	return 0;
}