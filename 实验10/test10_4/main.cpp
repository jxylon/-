#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"head.h"
int main(void)
{
	int i,k,t,f,n;
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
	printf("二路归并排序:\n");
	dpx(r,n);
	for(i=1;i<=n;i++)
		printf("no:%4d key:%4d\n",r[i].no,r[i].key);
	printf("\n");
	return 0;
}