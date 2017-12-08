#include<stdio.h>
#include"head.h"
void create(int arr[N])
{
	int i;
	printf("ÊäÈë%d¸öÊı\n",N);
	for(i=0;i<N;i++)
		scanf("%d",&arr[i]);
}
void sort(int arr[N])
{
	int i,j,temp;
	for(i=0;i<N;i++)
	{
		if(arr[i]==0)
		{
			for(j=0;j<i;j++)
			{
				if(arr[j]!=0)
				{
					temp=arr[j];
					arr[j]=arr[i];
					arr[i]=temp;
				}
			}
		}
	}
}
void prin(int arr[N])
{
	for(int i=0;i<N;i++)
		printf("%d ",arr[i]);
	printf("\n");
}
