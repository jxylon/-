#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"head.h"
int main(void)
{
	int i,k,t,f,n,j;
	unsigned seed=time(NULL);
	seqlist r;
	srand(seed);
	printf("构建数组,数组长度为：\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		t=1;
		r[i].no=i;
		f=rand()%1000;
		for(k=1;k<=i;k++)
			if(r[k].key==f)
				t=0;
		if(t)
			r[i].key=f;
		else
			i--;
	}
	for(i=1;i<=n;i++)
		printf("no:%4d key:%4d\n",r[i].no,r[i].key);
	printf("1->快速排序:\n");
	printf("2->直接插入排序:\n");
	printf("3->冒泡排序:\n");
	printf("4->选择排序:\n");
	printf("选择排序算法:");
	scanf("%d",&j);
	switch(j)
	{
	case 1:
		{
			printf("快速排序:\n");
			quicksort(r,1,n);
			for(i=1;i<=n;i++)
				printf("no:%4d key:%4d\n",r[i].no,r[i].key);
			printf("\n");
		}break;
	case 2:
		{
			printf("直接插入排序:\n");
			insert(r,n);
			for(i=1;i<=n;i++)
				printf("no:%4d key:%4d\n",r[i].no,r[i].key);
			printf("\n");
		}break;
	case 3:
		{
			printf("直接插入排序:\n");
			mppx(r,n);
			for(i=1;i<=n;i++)
				printf("no:%4d key:%4d\n",r[i].no,r[i].key);
			printf("\n");
		}break;
	case 4:
		{
			printf("简单选择排序:\n");
			zjxz(r,n);
			for(i=1;i<=n;i++)
				printf("no:%4d key:%4d\n",r[i].no,r[i].key);
			printf("\n");
		}break;
	}
	return 0;
}