#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"head.h"
void readFile(graph * g)
{
	char c,str[4]="";
	int i,j;
	FILE * fp=NULL;
	fp=fopen("data.txt","r");
	fscanf(fp,"%d %d",&g->n,&g->e);
	fscanf(fp,"%c",&c);
	for(i=1;i<=g->n;i++)
	{
		g->vers[i]=(char *)malloc(sizeof(char)*4);
		fgets(g->vers[i],5,fp);
		fscanf(fp,"%c",&c);
	}
	for(i=1;i<=g->n;i++)
	{
		for(j=1;j<=g->n;j++)
		{
			g->edges[i][j]=0;
			fscanf(fp,"%lf",&g->edges[i][j]);
			fscanf(fp,"%c",&c);
		}
	}
	fclose(fp);
}
void prinWay(graph * g)
{
	int i,j;
	printf("城市名称为:");
	for(i=1;i<=g->n;i++)
	{
		printf("%s ",g->vers[i]);
	}
	printf("\n城市间的距离为:\n");
	for(i=1;i<=g->n;i++)
	{
		for(j=i+1;j<=g->n;j++)
		{
			printf("%s-----%s：里程数 %.2lf\n",g->vers[i],g->vers[j],g->edges[i][j]);
		}
	}
}
double prim(graph * g)
{
	double lowcost[Max+1],min,sum=0;
	int closet[Max+1];
	int i,j,k;
	for(i=2;i<=g->n;i++)
	{
		lowcost[i]=g->edges[1][i];
		closet[i]=1;
	}
	for(i=2;i<=g->n;i++)
	{
		min=Max_dis;
		k=0;
		for(j=2;j<=g->n;j++)
		{
			if((lowcost[j]<min)&&(lowcost[j]!=0))
			{
				min=lowcost[j];
				k=j;
			}
		}
		printf("%s-----%s：里程数 %.2lf\n",g->vers[k],g->vers[closet[k]],g->edges[k][closet[k]]);
		sum+=g->edges[k][closet[k]];
		lowcost[k]=0;
		closet[k]=0;
		for(j=2;j<=g->n;j++)
		{
			if((g->edges[k][j]<lowcost[j])&&(g->edges[k][j]!=0))
			{
				lowcost[j]=g->edges[k][j];
				closet[j]=k;
			}
		}
	}
	return sum;
}
void Menu()
{
	int n,m=1;
	double sum;
	graph * g=(graph *)malloc(sizeof(graph));
	while(m)
	{
		printf("\t\t\t\t\t*******************建设地铁路线菜单**********************\n");
		printf("\t\t\t\t\t*		1->	读取地铁信息			*\n");
		printf("\t\t\t\t\t*		2->	最佳建设方案			*\n");
		printf("\t\t\t\t\t*		3->	查看总费用  			*\n");
		printf("\t\t\t\t\t*		0->	退出				*\n");
		printf("\t\t\t\t\t*********************************************************\n");
		printf("输入选项：");
		fflush(stdin);
		scanf("%d",&n);
		switch(n)
		{
		case 1:
			{
				readFile(g);
				prinWay(g);
			}break;
		case 2:
			{
				sum=prim(g);
			}break;
		case 3:
			{
				printf("最佳总里程数为:%.2lf\n",sum);
			}break;
		default:m=0;break;
		}
	}
}