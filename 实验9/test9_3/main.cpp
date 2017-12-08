#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	int i,n,index;
	tbl * tb=(tbl *)malloc(sizeof(tbl));
	tb->length=0;
	FILE * fp;
	fp=fopen("data.txt","r");
	if(fp!=NULL)
	{
		while(!feof(fp))
		{
			fscanf(fp,"%d ",&tb->elem[tb->length++]);
		}
		for(i=0;i<tb->length;i++)
			printf("%d ",tb->elem[i]);
		printf("\n");
	}
	printf("ÊäÈëÖµ:");
	scanf("%d",&n);
	index=binary_search(tb,0,tb->length,n);
	for(i=tb->length;i>index+1;i--)
		tb->elem[i]=tb->elem[i-1];
	tb->elem[index+1]=n;
	for(i=0;i<tb->length+1;i++)
			printf("%d ",tb->elem[i]);
	printf("\n");
	return 0;
}