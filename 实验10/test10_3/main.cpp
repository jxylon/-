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
	printf("1->shell排序:\n");
	printf("2->二路归并排序:\n");
	printf("选择排序算法:");
	scanf("%d",&j);
	switch(j)
	{
	case 1:
		{
			printf("shell排序:\n");
			shell(r,n);
			for(i=1;i<=n;i++)
				printf("no:%4d key:%4d\n",r[i].no,r[i].key);
			printf("\n");
		}break;
	case 2:
		{
			printf("二路归并排序:\n");
			llgbpx(r,n);
			for(i=1;i<=n;i++)
				printf("no:%4d key:%4d\n",r[i].no,r[i].key);
			printf("\n");
		}break;
	}
	return 0;
}