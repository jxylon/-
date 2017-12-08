#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	int i,n;
	mat * A=(mat *)malloc(sizeof(mat));
	mat * B=(mat *)malloc(sizeof(mat));
	mat * C=NULL;
	printf("请输入A矩阵的行列值与非零元素个数\n");
    scanf("%d %d %d",&A->mu,&A->nu,&A->tu);
    printf("请输入A矩阵的非零元素值的i,j,value:\n");
	fflush(stdin);
    for(i=1;i<=A->tu;i++)
        scanf("%d %d %d",&A->data[i].i,&A->data[i].j,&A->data[i].value);
	A->data[0].i=A->mu;
	A->data[0].j=A->nu;
	A->data[0].value=A->tu;
    printf("请输入B矩阵的行列值与非零元素个数\n");
    scanf("%d %d %d",&B->mu,&B->nu,&B->tu);
    printf("请输入B矩阵阵的非零元素值i,j,value:\n");
    for(i=1;i<=B->tu;i++)
        scanf("%d %d %d",&B->data[i].i,&B->data[i].j,&B->data[i].value);
	B->data[0].i=B->mu;
	B->data[0].j=B->nu;
	B->data[0].value=B->tu;
	printf("1->矩阵相加\n");
	printf("2->矩阵相减\n");
	printf("3->矩阵相乘\n");
	printf("输入你的选项:");
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