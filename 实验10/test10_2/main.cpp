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
	printf("��������,���鳤��Ϊ��\n");
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
	printf("1->��������:\n");
	printf("2->ֱ�Ӳ�������:\n");
	printf("3->ð������:\n");
	printf("4->ѡ������:\n");
	printf("ѡ�������㷨:");
	scanf("%d",&j);
	switch(j)
	{
	case 1:
		{
			printf("��������:\n");
			quicksort(r,1,n);
			for(i=1;i<=n;i++)
				printf("no:%4d key:%4d\n",r[i].no,r[i].key);
			printf("\n");
		}break;
	case 2:
		{
			printf("ֱ�Ӳ�������:\n");
			insert(r,n);
			for(i=1;i<=n;i++)
				printf("no:%4d key:%4d\n",r[i].no,r[i].key);
			printf("\n");
		}break;
	case 3:
		{
			printf("ֱ�Ӳ�������:\n");
			mppx(r,n);
			for(i=1;i<=n;i++)
				printf("no:%4d key:%4d\n",r[i].no,r[i].key);
			printf("\n");
		}break;
	case 4:
		{
			printf("��ѡ������:\n");
			zjxz(r,n);
			for(i=1;i<=n;i++)
				printf("no:%4d key:%4d\n",r[i].no,r[i].key);
			printf("\n");
		}break;
	}
	return 0;
}