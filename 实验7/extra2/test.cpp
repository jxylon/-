#include<stdio.h>
#include<stdlib.h>
#include"head.h"
tlinktp create()
{
	char isEmpty,isChild,isBro;
	datatype data;
	tlinktp t=NULL;
	printf("该结点是否为空?y or n\n");
	fflush(stdin);
	isEmpty=getchar();
	if(isEmpty=='y')
		return t;
	else
	{
		t=(tlinktp)malloc(sizeof(struct tnodetp));
		printf("输入该结点的值\n");
		scanf("%d",&data);
		t->data=data;
		printf("该结点是否有孩子?y or n\n");
		fflush(stdin);
		isChild=getchar();
		if(isChild=='y')
			t->fch=create();
		else 
			t->fch=NULL;
		printf("该结点是否有兄弟?y or n\n");
		fflush(stdin);
		isBro=getchar();
		if(isBro=='y')
			t->nsib=create();
		else
			t->nsib=NULL;
		return t;
	}
}
int countLeaf(tlinktp t)
{
	int m,n,s;
	if(t!=NULL)
	{
		if(t->fch==NULL)
		s=1;
		else s=0;
		m=countLeaf(t->fch);
		n=countLeaf(t->nsib);
		return m+n+s;
	}
	else 
		return 0;
}
int deepTree(tlinktp t)
{
	int m,n;
	if(t==NULL)
		return 0;
	else
	{
		m=deepTree(t->fch);
		n=deepTree(t->nsib);
		return (m>n-1?m:n-1)+1;
	}
}
void proprint(tlinktp t)
{
	if(t)
	{
		printf("%d ",t->data);
		proprint(t->fch);
		proprint(t->nsib);
	}
}
void Menu(tlinktp t)
{
	int n=1;
	while(n)
	{
		printf("*********************\n");
		printf("1-> 孩子兄弟表示法创建树\n");
		printf("2-> 先序遍历输出树\n");
		printf("3-> 树的叶子数\n");
		printf("4-> 树的深度\n");
		printf("0-> 退出\n");
		printf("*********************\n");
		printf("输入选项：");
		fflush(stdin);
		scanf("%d",&n);
		switch(n)
		{
		case 1:t=create();break;
		case 2:
			{
				proprint(t);
				printf("\n");
			}break;
		case 3:printf("叶子数为%d\n",countLeaf(t));break;
		case 4:printf("树的深度为%d\n",deepTree(t));break;
		}
	}
}