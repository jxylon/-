#include "head.h"
#include<stdio.h>
#include<stdlib.h>
#define MaxLine 1024
/********************/
int create(sqlist * L)
{
	FILE * f;
	int i=0;
	f=fopen("test.txt","r");
	if(f==NULL)
	{
		printf("�ļ���ʧ��!\n");
		return 0;
	}
	while(!feof(f))
	{
		fscanf(f,"%d",&L->arr[i]);
		L->len++;
		i++;
	}
	fclose(f);
	return 1;
}
void test1_1(sqlist *L)
{
	L->len=0;
}
void test1_2(sqlist * L)
{
	int i;
	for(i=0;i<L->len;i++)
		printf("%d ",L->arr[i]);
	printf("\n");
}
int test1_3(sqlist * L,int i)
{
	return L->arr[i-1];
}
int test1_4(sqlist * L,int i)
{
	int j;
	if(i<1||i>L->len)
	{
		printf("ɾ��λ�ò��ԣ�\n");
		return 0;
	}
	else
	{
		for(j=i;j<L->len;j++)
			L->arr[j-1]=L->arr[j];
		L->len=L->len-1;
		return 1;
	}
}
void test1_5(sqlist * L,int num)
{
	int i,j;
	for(i=0;i<L->len;i++)
	{
		if(num==L->arr[i])
		{
			for(j=i;j<L->len-1;j++)
				L->arr[j]=L->arr[j+1];
			L->len--;
			i--;
		}
	}
}
void test1_6(sqlist * L,int key)
{
	int i;
	for(i=L->len-2;i>0;i--)
		L->arr[i]=L->arr[i+1];
	L->arr[0]=key;
	L->len++;
}
void test1_7(sqlist * L,int key)
{
	L->arr[L->len]=key;
	L->len++;
}
int test1_8(sqlist * L,int i,int num)
{
	int j;
	if(L->len==Maxline)
	{
		printf("���\n");
		return 0;
	}
	else if(i<0||i>L->len+1)
	{
		printf("����λ�ò��ԣ�\n");
		return 0;
	}
	else 
	{
		for(j=L->len-1;j>=i-1;j--)
			L->arr[j+1]=L->arr[j];
		L->arr[i-1]=num;
		L->len++;
		return 1;
	}
}
int test1_9(sqlist * L,int flag)
{
	int i;
	for(i=0;i<L->len;i++)
	{
		if(L->arr[i]==flag)
			return 1;
	}
	return 0;
}
void split(sqlist * L)
{
	int i;
	sqlist * a;
	sqlist * b;
	a=(sqlist *)malloc(sizeof(sqlist));
	b=(sqlist *)malloc(sizeof(sqlist));
	test1_1(a);
	test1_1(b);
	for(i=0;i<L->len;i++)
	{
		if(L->arr[i]>0)
			test1_7(a,L->arr[i]);
		else 
			test1_7(b,L->arr[i]);
	}
	printf("A:");
	test1_2(a);
	printf("B:");
	test1_2(b);
}
void maxAndmin(sqlist * L)
{
	int i,min,max;
	min=L->arr[0];
	max=L->arr[0];
	for(i=1;i<L->len;i++)
	{
		if(L->arr[i]>max)
			max=L->arr[i];
		else if(L->arr[i]<min)
			min=L->arr[i];
	}
	printf("max=%d,min=%d\n",max,min);
}
void test1Menu(sqlist * L)
{
	int n=1;
	while(n)
	{
		printf("*********************\n");
		printf("1-> ��ʼ�����Ա�\n");
		printf("2-> ��������\n");
		printf("3-> ������Ա�Ԫ��ֵ\n");
		printf("4-> ȡ���еĵ�i��Ԫ�صļ�ֵ\n");
		printf("5-> ɾ��������ָ��λ�õ�Ԫ��\n");
		printf("6-> ɾ��������ָ��ֵ��Ԫ��\n");
		printf("7-> �ڱ�ͷ���Ԫ��\n");
		printf("8-> �ڱ�β���Ԫ��\n");
		printf("9-> �����ָ��λ�ô���Ӽ�ֵkey��Ԫ��\n");
		printf("10-> �ڱ��е�����ָ��Ԫ�أ������Ƿ����\n");
		printf("11-> ���˳���A\n");
		printf("12-> �ҳ�˳����е���Сֵ�����ֵ\n");
		printf("0-> �˳�\n");
		printf("*********************\n");
		printf("����ѡ�");
		scanf("%d",&n);
		switch(n)
		{
			case 1:test1_1(L);break;
			case 2:create(L);break;
			case 3:test1_2(L);break;
			case 4:
			{
				int i;
				printf("����������λ��\n");
				fflush(stdin);
				scanf("%d",&i);
				printf("��%d��Ԫ��Ϊ%d\n",i,test1_3(L,i));
			}break;
			case 5:
			{
				int i;
				printf("����Ҫɾ����λ��\n");
				fflush(stdin);
				scanf("%d",&i);
				test1_4(L,i);
			}break;
			case 6:
			{
				int key;
				printf("����Ҫɾ����ֵ\n");
				fflush(stdin);
				scanf("%d",&key);
				test1_5(L,key);
			}break;
			case 7:
			{
				int key;
				printf("����Ҫ��ӵ�ֵ\n");
				fflush(stdin);
				scanf("%d",&key);
				test1_6(L,key);
			}break;
			case 8:
			{
				int key;
				printf("����Ҫ��ӵ�ֵ\n");
				fflush(stdin);
				scanf("%d",&key);
				test1_7(L,key);
			}break;
			case 9:
			{
				int k,l;
				printf("������Ҫ��ӵ�Ԫ��ֵ��λ��:");
				fflush(stdin);
				scanf("%d %d",&k,&l);
				test1_8(L,l,k);
			}break;
			case 10:
			{
				int flag,i;
				printf("����������ֵ\n");
				fflush(stdin);
				scanf("%d",&flag);
				i=test1_9(L,flag);
				if(i)
					printf("����%d\n",flag);
				else printf("������%d\n",flag);
			};break;
			case 11:split(L);break;
			case 12:maxAndmin(L);break;
		}
	}
}
