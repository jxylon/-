#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	blink root=NULL;
	int i,n;
	char x;
	printf("�������Ľ����\n");
	scanf("%d",&n);
	printf("��������ֵ\n");
	for(i=0;i<n;i++)
	{
		x=getchar();
		root=add(root,x);
	}
	inorder(root);
	printf("\n");
	return 0;
}