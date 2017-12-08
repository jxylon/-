#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int search(int A[],int x,int n)
{
	int i=0;
	while(i<n&&A[i]!=x)
		i++;
	if(i>=n)
		return -1;
	else
		return i;
}
