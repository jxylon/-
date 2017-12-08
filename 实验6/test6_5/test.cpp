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
		printf("�޷����!\n");
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
		printf("�޷����!\n");
		return NULL;
	}

}
mat * mul(mat *A,mat *B)
{
	mat *C;
	int p,j,q,i,r,k,t;
	//���ڽ�����ݴ�
	int temp[Max];
	int num[Max],rpot[Max];
	C = (mat*)malloc(sizeof(mat));
	if(C==NULL)
	{
		printf("�����ڴ�ռ�ʧ�ܣ�\n");
		return NULL;  
	}
	//A����ֵ��B����ֵ�����ʱ
	if(A->nu!=B->mu)
		return NULL;
	C->mu=A->mu;
	C->nu=B->nu;
	//��A��B�еķ���Ԫ��Ϊ0ʱ
	if(A->tu*B->tu==0)
	{
		C->tu=0;
		return C;
	}
	//����B������ÿ�з�0Ԫ�صĸ���
	for(i=1;i<=B->mu;i++)
		num[i]=0;
	for(i=1;i<=B->tu;i++)
		num[B->data[i].i]++;
	rpot[1]=1;
	//����B������ÿ����λ��0Ԫ�ص�λ��
	for(i=2;i<=B->mu;i++)
		rpot[i]=rpot[i-1]+num[i-1];
	r=1;//��¼��ǰC�����з�0Ԫ�صĸ���
	p=1;//ָʾ��ǰA�����з���Ԫ�ص�λ��
	//���о���ĳ˻�����
	for(i=1;i<=A->mu;i++)
	{
		//��Cij���ۼ�����ʼ��
		for(j=1;j<=B->nu;j++)
			temp[j]=0;
		//��Cij��i�е�Ԫ�ؼ���
		while(i==A->data[p].i)
		{
			k=A->data[p].j;//��ȡA�����е�p������Ԫ�ص���ֵ
			//ȷ��B�е�k�еķ���Ԫ����B.data�е�����λ��
			if(k<B->mu)
				t=rpot[k+1];
			else
				t=B->tu+1;
			//��B�е�k�е�ÿһ�з���Ԫ����A�з���Ԫ�ؼ�¼���ۼ�����
			for(q=rpot[k];q<t;q++)
			{
				j=B->data[q].j;
				temp[j] += A->data[p].value*B->data[q].value;
			}
			p++;
		}
	//����i�еĽ����ֵ��C����
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