#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	int i, n;
	seqlist r;
	printf("��������,���鳤��Ϊ��\n");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("������ź͹ؼ���:");
		fflush(stdin);
		scanf("%d %d",&r[i].no,&r[i].key);
	}
	quicksort(r,1,n);
	for(i=1;i<n;i++)
		printf("%d %d\n",r[i].no,r[i].key);
	printf("\n");
	return 0;
}