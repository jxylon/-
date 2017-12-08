#include<stdio.h>
#include<stdlib.h>
#include"head.h"
//�������������
bitreptr * create_bnode()
{
	char ch;
	bitreptr * bt=NULL;
	printf("��������Ԫ��,.->over\n");
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
//������������
void preprint(bitreptr * bt)
{
	if(bt!=NULL)
	{
		printf("%c ",bt->data);
		preprint(bt->lchild);
		preprint(bt->rchild);
	}
	else 
		return ;
}
//������������
void changeRLBit(bitreptr * bt)
{
	bitreptr * temp;
	if(bt->lchild!=NULL&&bt->rchild!=NULL)
	{
		temp=bt->lchild;
		bt->lchild=bt->rchild;
		bt->rchild=temp;
		changeRLBit(bt->lchild);
		changeRLBit(bt->rchild);
	}
	else if(bt->lchild!=NULL&&bt->rchild==NULL)
	{
		temp=bt->lchild;
		bt->rchild=temp;
		bt->lchild=NULL;
		changeRLBit(bt->rchild);
	}
	else if(bt->lchild==NULL&&bt->rchild!=NULL)
	{
		temp=bt->rchild;
		bt->lchild=temp;
		bt->rchild=NULL;
		changeRLBit(bt->lchild);
	}
}
//�����ӽ��ĸ���
int singleChild(bitreptr * bt)
{
	bitreptr * s[Max],*t;
	int top=0,num=0;
	t=bt;
	do
	{
		while(t)
		{
			if((t->lchild==NULL&&t->rchild!=NULL)||(t->lchild!=NULL&&t->rchild==NULL))
				num++;
			s[top++]=t;
			t=t->lchild;
		}
		if(top!=0)
		{
			t=s[--top];
			t=t->rchild;
		}
	}while(top!=0||t!=NULL);
	return num;
}