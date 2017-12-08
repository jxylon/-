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
		printf("文件打开失败!\n");
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
		printf("删除位置不对！\n");
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
		printf("溢出\n");
		return 0;
	}
	else if(i<0||i>L->len+1)
	{
		printf("插入位置不对！\n");
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
		printf("1-> 初始化线性表\n");
		printf("2-> 创建数组\n");
		printf("3-> 输出线性表元素值\n");
		printf("4-> 取表中的第i个元素的键值\n");
		printf("5-> 删除数组中指定位置的元素\n");
		printf("6-> 删除数组中指定值的元素\n");
		printf("7-> 在表头添加元素\n");
		printf("8-> 在表尾添加元素\n");
		printf("9-> 向表中指定位置处添加键值key的元素\n");
		printf("10-> 在表中的搜索指定元素，看其是否存在\n");
		printf("11-> 拆分顺序表A\n");
		printf("12-> 找出顺序表中的最小值和最大值\n");
		printf("0-> 退出\n");
		printf("*********************\n");
		printf("输入选项：");
		scanf("%d",&n);
		switch(n)
		{
			case 1:test1_1(L);break;
			case 2:create(L);break;
			case 3:test1_2(L);break;
			case 4:
			{
				int i;
				printf("输入搜索的位置\n");
				fflush(stdin);
				scanf("%d",&i);
				printf("第%d个元素为%d\n",i,test1_3(L,i));
			}break;
			case 5:
			{
				int i;
				printf("输入要删除的位置\n");
				fflush(stdin);
				scanf("%d",&i);
				test1_4(L,i);
			}break;
			case 6:
			{
				int key;
				printf("输入要删除的值\n");
				fflush(stdin);
				scanf("%d",&key);
				test1_5(L,key);
			}break;
			case 7:
			{
				int key;
				printf("输入要添加的值\n");
				fflush(stdin);
				scanf("%d",&key);
				test1_6(L,key);
			}break;
			case 8:
			{
				int key;
				printf("输入要添加的值\n");
				fflush(stdin);
				scanf("%d",&key);
				test1_7(L,key);
			}break;
			case 9:
			{
				int k,l;
				printf("输入你要添加的元素值和位置:");
				fflush(stdin);
				scanf("%d %d",&k,&l);
				test1_8(L,l,k);
			}break;
			case 10:
			{
				int flag,i;
				printf("输入搜索的值\n");
				fflush(stdin);
				scanf("%d",&flag);
				i=test1_9(L,flag);
				if(i)
					printf("存在%d\n",flag);
				else printf("不存在%d\n",flag);
			};break;
			case 11:split(L);break;
			case 12:maxAndmin(L);break;
		}
	}
}
