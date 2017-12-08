#include<stdio.h>
#include<stdlib.h>
#include"head.h"
void shell(seqlist r,int n)
{
	rectype x;
	int i,j,d;
	d=n/2;
	while(d>=1)
	{
		for(i=d+1;i<=n;i++)
		{
			x=r[i];
			j=i-d;
			while(j>0&&x.key<r[j].key)
			{
				r[j+d]=r[j];
				j=j-d;
			}
			r[j+d]=x;
		}
		d=d/2;
	}
}
void hb(seqlist r,int h,int m,int w,seqlist t)
{
	int i,j,k;
	i=h;
	j=m+1;
	k=h-1;
	while(i<=m&&j<=w)
	{
		k++;
		if(r[i].key<=r[j].key)
			t[k]=r[i++];
		else
			t[k]=r[j++];
	}
	if(i>m)
	{
		while(j<=w)
		{
			t[++k]=r[j++];
		}
	}
	else
		while(i<=m)
		{
			t[++k]=r[i++];
		}
}
void ytgb(int s,int n,seqlist r,seqlist t)
{
	int i=1;
	while(i<=(n-2*s+1))
	{
		hb(r,i,i+s-1,i+2*s-1,t);
		i=i+2*s;
	}
	if(i<(n-s+1))
		hb(r,i,i+s-1,n,t);
	else
		while(i<=n)
			t[i]=r[i++];
}
void llgbpx(seqlist r,int n)
{
	int i,s=1;
	seqlist t;
	while(s<n)
	{
		ytgb(s,n,r,t);
		s=s*2;
		if(s<n)
		{
			ytgb(s,n,r,t);
			s=s*2;
		}
		else
		{
			i=1;
			while(i<=n)
				r[i]=t[i++];
		}
	}
}