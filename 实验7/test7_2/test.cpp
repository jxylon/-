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
//求二叉树的结点数和叶子数
void test2_1(bitreptr * bt)
{
	int node=0,leaf=0,top=0;
	bitreptr * t,*s[Max];
	t=bt;
	do
	{
		while(t)
		{
			if(t!=NULL)
				node++;
			if(t->lchild==NULL&&t->rchild==NULL)
				leaf++;
			s[top++]=t;
			t=t->lchild;
		}
		if(top!=0)
		{
			t=s[--top];
			t=t->rchild;
		}
	}while(top!=0||t!=NULL);
	printf("结点数=%d 叶子数=%d\n",node,leaf);
}
//按层次遍历二叉树
void test2_2(bitreptr * bt)
{
	int rear=-1,front=-1;
	bitreptr * t,*q[Max];
	t=bt;
	q[++rear]=t;
	while(rear!=front)
	{
		t=q[++front];
		printf("%c ",t->data);
		if(t->lchild)
			q[++rear]=t->lchild;
		if(t->rchild)
			q[++rear]=t->rchild;
	}
	printf("\n");
}
//求子树深度
int test2_4(bitreptr * bt)
{
	int m,n;
	if(bt==NULL)
		return 0;
	else
	{
		m=test2_4(bt->lchild);
		n=test2_4(bt->rchild);
		return (m>n?m:n)+1;
	}
}
//求二叉树中以值为x的结点为根的子树的深度
void test2_5(bitreptr * bt,int x)
{
	if(bt->data-'0'==x)
	{
		printf("%d为根的子树深度为%d\n",x,test2_4(bt));
		return ;
	}
	else
	{
		if(bt->lchild)
			test2_5(bt->lchild,x);
		if(bt->rchild)
			test2_5(bt->rchild,x);
	}
}
void Menu(bitreptr * bt)
{
	int n=1;
	while(n)
	{
		printf("*********************\n");
		printf("1-> 先序遍历创建树\n");
		printf("2-> 求二叉树的结点数和叶子数\n");
		printf("3-> 按层次遍历二叉树\n");
		printf("4-> 先序遍历输出树\n");
		printf("5-> 中序遍历输出树\n");
		printf("6-> 后序遍历输出树\n");
		printf("7-> 求子树深度\n");
		printf("8-> 求二叉树中以值为x的结点为根的子树的深度\n");
		printf("0-> 退出\n");
		printf("*********************\n");
		printf("输入选项：");
		fflush(stdin);
		scanf("%d",&n);
		switch(n)
		{
		case 1:bt=create_bnode();break;
		case 2:test2_1(bt);break;
		case 3:test2_2(bt);break;
		case 4:preprint(bt);printf("\n");break;
		case 5:inprint(bt);printf("\n");break;
		case 6:postprint(bt);printf("\n");break;
		case 7:printf("树的深度为%d\n",test2_4(bt));break;
		case 8:
			{
				int x;
				printf("输入x的值\n");
				scanf("%d",&x);
				test2_5(bt,x);
			}break;
		}
	}
}