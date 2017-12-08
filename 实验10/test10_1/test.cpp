#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int partition(seqlist r,int i,int j)
{
	rectype pivot=r[i];
	while(i<j)
	{
		while(i<j&&r[j].key>=pivot.key)
			j--;
		if(i<j)
			r[i]=r[j];
		while(i<j&&r[i].key<=pivot.key)
			i++;
		if(i<j)
			r[j]=r[i];
	}
	r[i]=pivot;
	return i;
}
void quicksort(seqlist t,int low,int high)
{
	int pivotpos;
	if(low<high)
	{
		pivotpos=partition(t,low,high);
		quicksort(t,low,pivotpos-1);
		quicksort(t,pivotpos+1,high);
	}
}