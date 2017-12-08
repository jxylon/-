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
	int odd=N-1,even=0,temp;
	while(odd>even)
	{
		while(odd>=0&&(arr[odd]%2==0))
			odd--;
		while(even<=N-1&&(arr[even]%2!=0))
			even++;
		if(odd>even)
		{
			temp=arr[odd];
			arr[odd]=arr[even];
			arr[even]=temp;
		}
	}
}
void prin(int arr[N])
{
	for(int i=0;i<N;i++)
		printf("%d ",arr[i]);
	printf("\n");
}