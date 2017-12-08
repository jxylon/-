#include<stdio.h>
#include<math.h>
#include "head.h"
#include<string.h>
void Menu()
{
	int n;
	printf("选择实验:");
	printf("*********************\n");
	printf("1-> 基础练习1\n");
	printf("2-> 基础练习2\n");
	printf("3-> 基础练习3\n");
	printf("4-> 基础练习4\n");
	printf("5-> 基础练习5\n");
	printf("6-> 进阶练习1\n");
	printf("7-> 进阶练习2\n");
	printf("0-> 退出\n");
	printf("*********************\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
		{
			int x,y;
			printf("输入两个数\n");
			scanf("%d %d",&x,&y);
			fun(&x,&y);
			break;
		}
		case 2:
		{
			int i,x,y;
			int a[10];
			printf("输入10个数\n");
			for(i=0;i<10;i++)
				scanf("%d",&a[i]);
			sum(a,10,&x,&y);
			printf("odd=%d,even=%d",x,y);
			break;
		}
		case 3:
		{
			int i;
			int a[10],b[10];
			printf("输入10个数\n");
			for(i=0;i<10;i++)
				scanf("%d",&a[i]);
			dcopy(a,b,10);
			break;
		}
		case 4:
		{
			int i;
			int a[10];
			printf("输入10个数\n");
			for(i=0;i<10;i++)
				scanf("%d",&a[i]);
			exchange(a,10);
			break;
		}
		case 5:
		{
			student stu[2];
			stu[0].no[0]=1;
			stu[0].no[1]=1;
			strcpy(stu[0].name,"zhang");
			stu[0].score.math=90;
			stu[0].score.Englishl=98;
			stu[0].score.music=80;
			stu[1].no[0]=2;
			stu[1].no[1]=1;
			strcpy(stu[1].name,"li");
			stu[1].score.math=95;
			stu[1].score.Englishl=92;
			stu[1].score.music=85;
			printAll(stu,2);
			averageSco(stu,2);
			topStu(stu,2);
			break;
		}
		case 6:
		{
			struct cpxNum cpx,cpx1;
			printf("输入虚部和实部\n");
			scanf("%lf %lf",&cpx.imag,&cpx.real);
			printf("输入虚部和实部\n");
			scanf("%lf %lf",&cpx1.imag,&cpx1.real);
			printf("第一个虚数\n");
			printCpx(cpx);
			printf("第二个虚数\n");
			printCpx(cpx1);
			printf("虚数之和\n");
			addCpx(cpx,cpx1);
			printf("虚数之差\n");
			subCpx(cpx,cpx1);
			printf("虚数之积\n");
			mulCpx(cpx,cpx1);
			printf("第一个虚数的实部\n");
			prinCpxReal(cpx);
			printf("第一个虚数的虚部\n");
			prinCpxImag(cpx);
		}
		case 7:
		{
			int x,y;
			struct triangle tri;
			printf("输入三角形的坐标x1,y1,x2,y2,x3,y3\n");
			fflush(stdin);
			scanf("%lf %lf %lf lf %lf %lf",&tri.x1,&tri.y1,&tri.x2,&tri.y2,&tri.x3,&tri.y3);
			isIso(tri);
			isEquil(tri);
			isRight(tri);
			printf("面积是%.2lf\n",triArea(tri));
			printf("输入一个点坐标");
			fflush(stdin);
			scanf("%d %d",&x,&y);
			isInTriangle(tri,x,y);
		}
	}
}
int fun(int *a,int *b)
{
	if((*a<0&&*b<0)||(*a>0&&*b>0))
	{
		printf("same\n");
		return 1;
	}
	printf("Not Same\n");
	return 0;
}
void sum(int * a,int n,int *odd,int *even)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(*(a+i)%2==0)
			*odd+=*(a+i);
		else *even+=*(a+i);
	}
}
int dcopy(int *a,int *b,int n)
{
	int i,len=0;
	for(i=0;i<n;i++)
	{
		if(*(a+i)%2==0)
		{
			*(b+len)=*(a+i);
			len++;
		}
	}
	for(i=0;i<n;i++)
		printf("%d ",*(b+i));
	return 0;
}
int exchange(int *a,int n)
{
	int i,max,min,temp,maxP,minP;
	max=*a;
	min=*a;
	maxP=minP=0;
	for(i=0;i<n;i++)
	{
		if(*(a+i)>max)
		{
			maxP=i;
			max=*(a+i);
		}
		if(*(a+i)<min)
		{
			minP=i;
			min=*(a+i);
		}
	}
	temp=*(a+maxP);
	*(a+maxP)=*(a+minP);
	*(a+minP)=temp;
	return 0;
}
void printAll(student stu[],int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
			printf("%d",stu[i].no[j]);
		printf(" %s %d %d %d\n",stu[i].name,stu[i].score.Englishl,stu[i].score.math,stu[i].score.music);
	}
}
void averageSco(student stu[],int n)
{
	double sumMath,sumEn,sumMus;
	int i;
	sumMath=sumEn=sumMus=0;
	for(i=0;i<n;i++)
	{
		sumMath+=stu[i].score.math;
		sumEn+=stu[i].score.Englishl;
		sumMus+=stu[i].score.music;
	}
	printf("averageSco:%lf %lf %lf\n",sumMath/n,sumEn/n,sumMus/n);
}
void topStu(student stu[],int n)
{
	int i,j,max,maxI;
	max=stu[0].score.Englishl+stu[0].score.math+stu[0].score.music;
	maxI=0;
	for(i=0;i<n;i++)
	{
		if(stu[i].score.Englishl+stu[i].score.math+stu[i].score.music>max)
		max=stu[i].score.Englishl+stu[i].score.math+stu[i].score.music;
		maxI=i;
	}
	for(j=0;j<2;j++)
		printf("%d",stu[maxI].no[j]);
	printf("top: %s %d %d %d\n",stu[maxI].name,stu[maxI].score.Englishl,stu[maxI].score.math,stu[maxI].score.music);
}
void printCpx(struct cpxNum cpx)
{
	printf("%.2lf+%.2lf i\n",cpx.real,cpx.imag);
}
void addCpx(struct cpxNum cpx1,struct cpxNum cpx2)
{
	double result_imag,result_real;
	result_real=cpx1.real+cpx2.real;
	result_imag=cpx1.imag+cpx2.imag;
	printf("%.2lf+%.2lf i\n",result_real,result_imag);
}
void subCpx(struct cpxNum cpx1,struct cpxNum cpx2)
{
	double result_imag,result_real;
	result_real=cpx1.real-cpx2.real;
	result_imag=cpx1.imag-cpx2.imag;
	printf("%.2lf+%.2lf i\n",result_real,result_imag);
}
void mulCpx(struct cpxNum cpx1,struct cpxNum cpx2)
{
	double result_imag,result_real;
	result_real=cpx1.real*cpx2.real-cpx1.imag*cpx2.imag;
	result_imag=cpx1.imag*cpx2.real+cpx1.real*cpx2.imag;
	printf("%.2lf+%.2lf i\n",result_real,result_imag);
}
void prinCpxReal(struct cpxNum cpx)
{
	printf("%.2lf\n",cpx.real);
}
void prinCpxImag(struct cpxNum cpx)
{
	printf("%.2lf\n",cpx.imag);
}
int isEquil(struct triangle tri)
{
	double len1,len2,len3;
	len1=sqrt(pow((tri.x1-tri.x2),2)+pow((tri.y1-tri.y2),2));
	len2=sqrt(pow((tri.x3-tri.x2),2)+pow((tri.y3-tri.y2),2));
	len3=sqrt(pow((tri.x1-tri.x3),2)+pow((tri.y1-tri.y3),2));
	if(len1==len2&&len1==len3)
	{
		printf("是等腰三角形\n");
		return 1;
	}
	else
	{
		printf("不是等腰三角形\n");
		return 0;
	}
}
int isIso(struct triangle tri)
{
	double len1,len2,len3;
	len1=sqrt(pow((tri.x1-tri.x2),2)+pow((tri.y1-tri.y2),2));
	len2=sqrt(pow((tri.x3-tri.x2),2)+pow((tri.y3-tri.y2),2));
	len3=sqrt(pow((tri.x1-tri.x3),2)+pow((tri.y1-tri.y3),2));
	if(len1==len2||len1==len3||len2==len3)
	{
		printf("是等边三角形\n");
		return 1;
	}
	else
	{
		printf("不是等边三角形\n");
		return 0;
	}
}
int isRight(struct triangle tri)
{
	double len1,len2,len3;
	len1=sqrt(pow((tri.x1-tri.x2),2)+pow((tri.y1-tri.y2),2));
	len2=sqrt(pow((tri.x2-tri.x3),2)+pow((tri.y2-tri.y3),2));
	len3=sqrt(pow((tri.x1-tri.x3),2)+pow((tri.y1-tri.y3),2));
	if((pow(len1,2)==(pow(len2,2)+pow(len3,2)))||(pow(len2,2)==(pow(len1,2)+pow(len3,2)))||(pow(len3,2)==(pow(len1,2)+pow(len2,2))))
	{
		printf("是直角三角形\n");
		return 1;
	}
	else
	{
		printf("不是直角三角形\n");
		return 0;
	}
}
double triArea(struct triangle tri)
{
	double len1,len2,len3,cp,s;
	len1=sqrt(pow((tri.x1-tri.x2),2)+pow((tri.y1-tri.y2),2));
	len2=sqrt(pow((tri.x3-tri.x2),2)+pow((tri.y3-tri.y2),2));
	len3=sqrt(pow((tri.x1-tri.x3),2)+pow((tri.y1-tri.y3),2));
	cp=(len1+len2+len3)/2;
	s=sqrt(cp*(cp-len1)*(cp-len2)*(cp-len3));
		return s;
}
int isInTriangle(struct triangle tri,int x,int y)
{
	double len1,len2,len3,newLen1,newLen2,newLen3;
	len1=sqrt(pow((tri.x1-tri.x2),2)+pow((tri.y1-tri.y2),2));
	len2=sqrt(pow((tri.x3-tri.x2),2)+pow((tri.y3-tri.y2),2));
	len3=sqrt(pow((tri.x1-tri.x3),2)+pow((tri.y1-tri.y3),2));
	newLen1=sqrt(pow((tri.x1-x),2)+pow((tri.y1-y),2));
	newLen2=sqrt(pow((tri.x2-x),2)+pow((tri.y1-y),2));
	newLen3=sqrt(pow((tri.x3-x),2)+pow((tri.y1-y),2));
	if(len1>newLen1&&len1>newLen2&&len2>newLen2&&len2>newLen3&&len3>newLen1&&len3>newLen3)
	{
		printf("在三角形内\n");
		return 1;
	}
	else
	{
		printf("不在三角形内\n");
		return 0;
	}
}