#include<stdio.h>
#include<stdlib.h>
#include"head.h"
void sxf(seqlist r,int t,int w)
{
	int i,j;
	rectype x;
	i=t;
	x=r[i];
	j=2*i;
	while(j<=w)
	{
		if((j<w)&&r[j].key>r[j+1].key)
			j++;
		if(x.key>r[j].key)
		{
			r[i]=r[j];
			i=j;
			j=j*2;
		}
		else
			j=w+1;
	}
	r[i]=x;
}
void dpx(seqlist r,int n)
{
	int i;
	rectype x;
	for(i=n/2;i>=1;i--)
		sxf(r,i,n);
	for(i=n;i>=2;i--)
	{
		x=r[1];
		r[1]=r[i];
		r[i]=x;
		sxf(r,1,i-1);
	}
}