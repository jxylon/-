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
void insert(seqlist r,int n)
{
	int i,j;
	for(i=2;i<=n;i++)
	{
		r[0]=r[i];
		j=i-1;
		while(r[0].key<r[j].key)
		{
			r[j+1]=r[j];
			j--;
		}
		r[j+1]=r[0];
	}
}
void mppx(seqlist r,int n)
{
	int i,j,k;
	rectype x;
	i=1;
	k=1;
	while(i<n&&k>0)
	{
		k=0;
		for(j=1;j<=n-i;j++)
		{
			if(r[j+1].key<r[j].key)
			{
				k++;
				x=r[j];
				r[j]=r[j+1];
				r[j+1]=x;
			}
		}
	}
}
void zjxz(seqlist r,int n)
{
	int i,j,k;
	rectype x;
	for(i=1;i<n;i++)
	{
		k=i;
		for(j=i+1;j<=n;j++)
		{
			if(r[j].key<r[k].key)
				k=j;
		}
		if(i!=k)
		{
			x=r[i];
			r[i]=r[k];
			r[k]=x;
		}
	}
}