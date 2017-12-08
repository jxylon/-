#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	blink root=NULL;
	int i,n;
	char x;
	printf("输入树的结点数\n");
	scanf("%d",&n);
	printf("输入树的值\n");
	for(i=0;i<n;i++)
	{
		x=getchar();
		root=add(root,x);
	}
	inorder(root);
	printf("\n");
	return 0;
}