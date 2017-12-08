#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"head.h"
bitreptr * create(char *s)
{
	char * p,temp[Max];//字符串s的复制
	bitreptr *t,*q[Max],*root;
	int rear,front;//队头和队尾
	rear=front=0;
	strcpy(temp,s);
	p=temp;
	while(strlen(p)>0)//字符串不为空
	{
		t=NULL;//初始化为空
		if(*(p)!='.')//如果字符串不是.则创建新结点
		{
			t=(bitreptr *)malloc(sizeof(bitreptr));
			t->data=*p;
			t->lchild=NULL;
			t->rchild=NULL;
		}
		q[++rear]=t;//无论是否为空都入队
		if(rear==1)//如果是第一个入队则为树根
			root=t;
		else
		{
			if(t&&q[front+1])//当前结点和队头元素都不为空
			{
				if(rear%2==0)//如果rear是偶数，队头元素左孩子是t，但是不出队
					q[front+1]->lchild=t;
				else//如果rear是奇数，队头元素右孩子是t，出队
					q[++front]->rchild=t;
			}
		}
		p++;//指向下一个字符
	}
	return root;
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