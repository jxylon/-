#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	int i,n;
	mat * A=(mat *)malloc(sizeof(mat));
	mat * B=(mat *)malloc(sizeof(mat));
	mat * C=NULL;
	printf("������A���������ֵ�����Ԫ�ظ���\n");
    scanf("%d %d %d",&A->mu,&A->nu,&A->tu);
    printf("������A����ķ���Ԫ��ֵ��i,j,value:\n");
	fflush(stdin);
    for(i=1;i<=A->tu;i++)
        scanf("%d %d %d",&A->data[i].i,&A->data[i].j,&A->data[i].value);
	A->data[0].i=A->mu;
	A->data[0].j=A->nu;
	A->data[0].value=A->tu;
    printf("������B���������ֵ�����Ԫ�ظ���\n");
    scanf("%d %d %d",&B->mu,&B->nu,&B->tu);
    printf("������B������ķ���Ԫ��ֵi,j,value:\n");
    for(i=1;i<=B->tu;i++)
        scanf("%d %d %d",&B->data[i].i,&B->data[i].j,&B->data[i].value);
	B->data[0].i=B->mu;
	B->data[0].j=B->nu;
	B->data[0].value=B->tu;
	printf("1->�������\n");
	printf("2->�������\n");
	printf("3->�������\n");
	printf("�������ѡ��:");
	scanf("%d",&n);
	switch(n)
	{
	case 1:
		{
		  	C=add(A,B);
			print(C);
		}break;
	case 2:
		{
			C=sub(A,B);
			print(C);
		}break;
	case 3:
		{
			C=mul(A,B);
			print(C);
		}break;
	}
	return 0;
}