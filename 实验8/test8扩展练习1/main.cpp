#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	int i=1;
	graph * g;
	g=create();
	prinGraph(g);
	printf("ÍØÆËÅÅĞòµÄË³ĞòÎª:");
	topSort(g);
	return 0;
}