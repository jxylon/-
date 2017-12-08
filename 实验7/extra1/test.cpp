#include<stdio.h>
#include<stdlib.h>
#include"head.h"
//先序遍历创建树
bitreptr * create_bnode()
{
	char ch;
	bitreptr * bt=NULL;
	printf("输入树的元素,.->over\n");
	fflush(stdin);
	ch=getchar();
	if(ch=='.')
		return NULL;
	else
	{
		bt=(bitreptr *)malloc(sizeof(bitreptr));
		bt->data=ch;
		bt->lchild=create_bnode();
		bt->rchild=create_bnode();
		return bt;
	}
}
//先序遍历输出树
void preprint(bitreptr * bt)
{
	if(bt!=NULL)
	{
		printf("%c ",bt->data);
		preprint(bt->lchild);
		preprint(bt->rchild);
	}
}
//中序遍历输出树
void inprint(bitreptr * bt)
{
	if(bt!=NULL)
	{
		inprint(bt->lchild);
		printf("%c ",bt->data);
		inprint(bt->rchild);
	}
}
//后序遍历输出树
void postprint(bitreptr * bt)
{
	if(bt!=NULL)
	{
		postprint(bt->lchild);
		postprint(bt->rchild);
		printf("%c ",bt->data);
	}
}
void Menu(bitreptr * bt)
{
	int n=1;
	while(n)
	{
		printf("*********************\n");
		printf("1-> 先序遍历创建树\n");
		printf("2-> 先序遍历输出树\n");
		printf("3-> 中序遍历输出树\n");
		printf("4-> 后序遍历输出树\n");
		printf("0-> 退出\n");
		printf("*********************\n");
		printf("输入选项：");
		fflush(stdin);
		scanf("%d",&n);
		switch(n)
		{
		case 1:bt=create_bnode();break;
		case 2:preprint(bt);printf("\n");break;
		case 3:inprint(bt);printf("\n");break;
		case 4:postprint(bt);printf("\n");break;
		}
	}
}