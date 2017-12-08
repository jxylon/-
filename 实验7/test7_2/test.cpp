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
}
//������������
void inprint(bitreptr * bt)
{
	if(bt!=NULL)
	{
		inprint(bt->lchild);
		printf("%c ",bt->data);
		inprint(bt->rchild);
	}
}
//������������
void postprint(bitreptr * bt)
{
	if(bt!=NULL)
	{
		postprint(bt->lchild);
		postprint(bt->rchild);
		printf("%c ",bt->data);
	}
}
//��������Ľ������Ҷ����
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
	printf("�����=%d Ҷ����=%d\n",node,leaf);
}
//����α���������
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
//���������
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
//�����������ֵΪx�Ľ��Ϊ�������������
void test2_5(bitreptr * bt,int x)
{
	if(bt->data-'0'==x)
	{
		printf("%dΪ�����������Ϊ%d\n",x,test2_4(bt));
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
		printf("1-> �������������\n");
		printf("2-> ��������Ľ������Ҷ����\n");
		printf("3-> ����α���������\n");
		printf("4-> ������������\n");
		printf("5-> ������������\n");
		printf("6-> ������������\n");
		printf("7-> ���������\n");
		printf("8-> �����������ֵΪx�Ľ��Ϊ�������������\n");
		printf("0-> �˳�\n");
		printf("*********************\n");
		printf("����ѡ�");
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
		case 7:printf("�������Ϊ%d\n",test2_4(bt));break;
		case 8:
			{
				int x;
				printf("����x��ֵ\n");
				scanf("%d",&x);
				test2_5(bt,x);
			}break;
		}
	}
}