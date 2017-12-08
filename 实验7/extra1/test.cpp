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
void Menu(bitreptr * bt)
{
	int n=1;
	while(n)
	{
		printf("*********************\n");
		printf("1-> �������������\n");
		printf("2-> ������������\n");
		printf("3-> ������������\n");
		printf("4-> ������������\n");
		printf("0-> �˳�\n");
		printf("*********************\n");
		printf("����ѡ�");
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