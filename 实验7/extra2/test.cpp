#include<stdio.h>
#include<stdlib.h>
#include"head.h"
tlinktp create()
{
	char isEmpty,isChild,isBro;
	datatype data;
	tlinktp t=NULL;
	printf("�ý���Ƿ�Ϊ��?y or n\n");
	fflush(stdin);
	isEmpty=getchar();
	if(isEmpty=='y')
		return t;
	else
	{
		t=(tlinktp)malloc(sizeof(struct tnodetp));
		printf("����ý���ֵ\n");
		scanf("%d",&data);
		t->data=data;
		printf("�ý���Ƿ��к���?y or n\n");
		fflush(stdin);
		isChild=getchar();
		if(isChild=='y')
			t->fch=create();
		else 
			t->fch=NULL;
		printf("�ý���Ƿ����ֵ�?y or n\n");
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
		printf("1-> �����ֵܱ�ʾ��������\n");
		printf("2-> ������������\n");
		printf("3-> ����Ҷ����\n");
		printf("4-> �������\n");
		printf("0-> �˳�\n");
		printf("*********************\n");
		printf("����ѡ�");
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
		case 3:printf("Ҷ����Ϊ%d\n",countLeaf(t));break;
		case 4:printf("�������Ϊ%d\n",deepTree(t));break;
		}
	}
}