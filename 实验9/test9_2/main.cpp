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
	printf("输入值:");
	scanf("%d",&n);
	index=binary_search(tb,0,tb->length,n);
	if(index>=0)
		printf("elem[%d]=%d\n",index,tb->elem[index]);
	else
		printf("未找到该元素\n");
	return 0;
}