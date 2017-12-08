#include<stdio.h>
#include<stdlib.h>
#include"head.h"
mat * add(mat * A,mat * B)
{
	int a=1,b=1,k=1;
	mat * C=(mat *)malloc(sizeof(mat));
	if((A->mu==B->mu)&&(A->nu==B->nu))
	{
		C->mu=A->mu;
		C->nu=A->nu;
		C->tu=0;
		C->data[0].i=A->mu;
		C->data[0].j=A->nu;
		C->data[0].value=A->tu;
		while(a<=A->tu&&b<=B->tu)
		{
			if(A->data[a].i==B->data[b].i)
			{
				if(A->data[a].j<B->data[b].j)
				{
					C->data[k].i=A->data[a].i;
					C->data[k].j=A->data[a].j;
					C->data[k].value=A->data[a].value;
					k++;
					a++;
					C->tu++;
					continue;
				}
				else if(A->data[a].j>B->data[b].j)
				{
					C->data[k].i=B->data[b].i;
					C->data[k].j=B->data[b].j;
					C->data[k].value=B->data[b].value;
					k++;
					b++;
					C->tu++;
					continue;
				}
				else
				{
					C->data[k].i=A->data[a].i;
					C->data[k].j=A->data[a].j;
					C->data[k].value=A->data[a].value+B->data[b].value;
					b++;
					a++;
					k++;
					C->tu++;
					continue;
				}
			}
			else if(A->data[a].i<B->data[b].i)
			{
					C->data[k].i=A->data[a].i;
					C->data[k].j=A->data[a].j;
					C->data[k].value=A->data[a].value;
					k++;
					a++;
					C->tu++;
					continue;
			}
			else
			{
					C->data[k].i=B->data[b].i;
					C->data[k].j=B->data[b].j;
					C->data[k].value=B->data[b].value;
					k++;
					b++;
					C->tu++;
					continue;
			}
		}
		if(b<=B->tu)
		{
			while(b<=B->tu)
			{
				C->data[k].i=B->data[b].i;
				C->data[k].j=B->data[b].j;
				C->data[k].value=B->data[b].value;
				k++;
				b++;
				C->tu++;
			}
		}
		if(a<=A->tu)
		{
			while(a<=A->tu)
			{
				C->data[k].i=A->data[a].i;
				C->data[k].j=A->data[a].j;
				C->data[k].value=A->data[a].value;
				k++;
				a++;
				C->tu++;
			}
		}
		return C;
	}
	else
	{
		printf("无法相加!\n");
		return NULL;
	}
	
}
mat * sub(mat * A,mat * B)
{
	int a=1,b=1,k=1;
	mat * C=(mat *)malloc(sizeof(mat));
	if((A->mu==B->mu)&&(A->nu==B->nu))
	{
		C->mu=A->mu;
		C->nu=A->nu;
		C->tu=0;
		C->data[0].i=A->mu;
		C->data[0].j=A->nu;
		C->data[0].value=A->tu;
		while(a<=A->tu&&b<=B->tu)
		{
			if(A->data[a].i==B->data[b].i)
			{
				if(A->data[a].j<B->data[b].j)
				{
					C->data[k].i=A->data[a].i;
					C->data[k].j=A->data[a].j;
					C->data[k].value=A->data[a].value;
					k++;
					a++;
					C->tu++;
					continue;
				}
				else if(A->data[a].j>B->data[b].j)
				{
					C->data[k].i=B->data[b].i;
					C->data[k].j=B->data[b].j;
					C->data[k].value=(B->data[b].value)*(-1);
					k++;
					b++;
					C->tu++;
					continue;
				}
				else
				{
					C->data[k].i=A->data[a].i;
					C->data[k].j=A->data[a].j;
					C->data[k].value=A->data[a].value-B->data[b].value;
					b++;
					a++;
					k++;
					C->tu++;
					continue;
				}
			}
			else if(A->data[a].i<B->data[b].i)
			{
					C->data[k].i=A->data[a].i;
					C->data[k].j=A->data[a].j;
					C->data[k].value=A->data[a].value;
					k++;
					a++;
					C->tu++;
					continue;
			}
			else
			{
					C->data[k].i=B->data[b].i;
					C->data[k].j=B->data[b].j;
					C->data[k].value=(B->data[b].value)*(-1);
					k++;
					b++;
					C->tu++;
					continue;
			}
		}
		if(b<=B->tu)
		{
			while(b<=B->tu)
			{
				C->data[k].i=B->data[b].i;
				C->data[k].j=B->data[b].j;
				C->data[k].value=(B->data[b].value)*(-1);
				k++;
				b++;
				C->tu++;
			}
		}
		if(a<=A->tu)
		{
			while(a<=A->tu)
			{
				C->data[k].i=A->data[a].i;
				C->data[k].j=A->data[a].j;
				C->data[k].value=A->data[a].value;
				k++;
				a++;
				C->tu++;
			}
		}	
		return C;
	}
	else
	{
		printf("无法相减!\n");
		return NULL;
	}

}
mat * mul(mat *A,mat *B)
{
	mat *C;
	int p,j,q,i,r,k,t;
	//用于结果的暂存
	int temp[Max];
	int num[Max],rpot[Max];
	C = (mat*)malloc(sizeof(mat));
	if(C==NULL)
	{
		printf("申请内存空间失败！\n");
		return NULL;  
	}
	//A的列值与B的行值不相等时
	if(A->nu!=B->mu)
		return NULL;
	C->mu=A->mu;
	C->nu=B->nu;
	//当A或B中的非零元素为0时
	if(A->tu*B->tu==0)
	{
		C->tu=0;
		return C;
	}
	//计算B矩阵中每行非0元素的个数
	for(i=1;i<=B->mu;i++)
		num[i]=0;
	for(i=1;i<=B->tu;i++)
		num[B->data[i].i]++;
	rpot[1]=1;
	//计算B矩阵中每行首位非0元素的位置
	for(i=2;i<=B->mu;i++)
		rpot[i]=rpot[i-1]+num[i-1];
	r=1;//记录当前C矩阵中非0元素的个数
	p=1;//指示当前A矩阵中非零元素的位置
	//进行矩阵的乘积运算
	for(i=1;i<=A->mu;i++)
	{
		//将Cij的累加器初始化
		for(j=1;j<=B->nu;j++)
			temp[j]=0;
		//求Cij第i行的元素集合
		while(i==A->data[p].i)
		{
			k=A->data[p].j;//获取A矩阵中第p个非零元素的列值
			//确定B中的k行的非零元素在B.data中的下限位置
			if(k<B->mu)
				t=rpot[k+1];
			else
				t=B->tu+1;
			//将B中第k行的每一列非零元素与A中非零元素记录到累加器中
			for(q=rpot[k];q<t;q++)
			{
				j=B->data[q].j;
				temp[j] += A->data[p].value*B->data[q].value;
			}
			p++;
		}
	//将第i行的结果赋值给C矩阵
		for(j=1;j<=B->nu;j++)
		{
			if(temp[j]!=0)
			{
				C->data[r].i=i;
				C->data[r].j=j;
				C->data[r].value=temp[j];
				r++;
			}
		}
	}
	C->tu=r;
	return C;  
}
void print(mat * A)
{
	int flag;
	if(A!=NULL)
	{
		for(int i=1;i<=A->mu;i++)
		{
			for(int j=1;j<=A->nu;j++)
			{
				flag=0;
				for(int k=1;k<=A->tu;k++)
				{
					if((i==A->data[k].i)&&(j==A->data[k].j))
					{
						printf("%d ",A->data[k].value);
						flag=1;
					}
				}
				if(flag==0)
					printf("0 ");
			}
			printf("\n");
		}
	}
}