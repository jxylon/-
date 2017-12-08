#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int binary_search(tbl * tb,int low,int high,int x)
{
	int mid;
	mid=(low+high)/2;
	if(low>high)
		return -1;
	else
	{
		if(tb->elem[mid]==x)
			return mid;
		else if(tb->elem[mid]<x)
		{
			low=mid+1;
			return binary_search(tb,low,high,x);
		}
		else
		{
			high=mid-1;
			return binary_search(tb,low,high,x);
		}
	}
}