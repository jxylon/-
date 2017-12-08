#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define MAX 1024
typedef struct stack
{
	int top;
	int data[MAX];
}STACK;
void convert(int A[10],int B[10])
{
	int x,y;
	STACK * s=(STACK *)malloc(sizeof(STACK));
	s->top=0;
	for(int i=0;i<10;i++)
	{
		x=A[i];
		if(x%8==0)
		{
			y=0;
			while(x/8!=0)
			{
				y++;
				x=x/8;
			}
			x=(int)pow(10,y);
		}
		else
		{
			while(x%8!=0)
			{
				s->data[s->top++]=x%8;
				x=x/8;
			}
			x=0;
			while(s->top!=0)
			{
				x+=(int)(s->data[--s->top]*pow(10,s->top));
			}
		}
		B[i]=x;
	}
}
int main(void)
{
	int i;
	int A[10]={1,2,3,4,5,6,7,8,64,10},B[10];
	convert(A,B);
	for(i=0;i<10;i++)
		printf("%d ",B[i]);
	return 0;
}