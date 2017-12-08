#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	int i, n;
	seqlist r;
	printf("构建数组,数组长度为：\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("输入序号和关键字:");
		fflush(stdin);
		scanf("%d %d",&r[i].no,&r[i].key);
	}
	quicksort(r,1,n);
	for(i=1;i<n;i++)
		printf("%d %d\n",r[i].no,r[i].key);
	printf("\n");
	return 0;
}