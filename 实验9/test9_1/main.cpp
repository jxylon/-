#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	int A[]={2,5,56,10,12,15,8,19,25,32};
	int n,d,i;
	printf("A数值\n下标\t");
	for(i=0;i<10;i++)
		printf("%3d",i);
	printf("\n值\t");
	for(i=0;i<10;i++)
		printf("%3d",A[i]);
	printf("\n输入值:");
	scanf("%d",&d);
	n=search(A,d,10);
	if(n>=0)
		printf("A[%d]=%d\n",n,A[n]);
	else
		printf("%d未找到\n",d);
	return 0;
}