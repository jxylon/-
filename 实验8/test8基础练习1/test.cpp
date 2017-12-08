#include<stdio.h>
#include<stdlib.h>
#include"head.h"
graph * create()
{
	graph * g=NULL;
	FILE *fp;
	int n,e,i,j;
	datatype ch,f,num;
	fp=fopen("data.txt","r");
	g=(graph *)malloc(sizeof(graph));
	fscanf(fp,"%d %d",&n,&e);
	g->e=e;
	g->n=n;
	fscanf(fp,"%c",&ch);
	for(i=1;i<n+1;i++)
	{
		fscanf(fp,"%d",&num);
		g->vers[i]=num;
		fscanf(fp,"%c",&ch);
	}
	for(i=1;i<n+1;i++)
	{
		for(j=1;j<n+1;j++)
		{
			fscanf(fp,"%d",&f);
			g->edges[i][j]=f;
			fscanf(fp,"%c",&ch);
		}
	}
	fclose(fp);
	return g;
}
void prinGraph(graph * g)
{
	int i,j;
	printf("%d����� %d����\n",g->n,g->e);
	printf("���Ϊ��\n");
	for(i=1;i<g->n+1;i++)
		printf("%d ",g->vers[i]);
	printf("\n�ڽӾ���Ϊ:\n");
	for(i=1;i<g->n+1;i++)
	{
		for(j=1;j<g->n+1;j++)
			printf("%d ",g->edges[i][j]);
		printf("\n");
	}
}
int index(graph * g,int i)
{
	int j;
	for(j=1;j<g->n+1;j++)
	{
		if(g->vers[j]==i)
			return j;
	}
	return NULL;
}
void InsertLine(graph * g)
{
	int i,j,indexI,indexJ;
	printf("������Ҫ��ӱߵ�������㣺");
	scanf("%d %d",&i,&j);
	indexI=index(g,i);
	indexJ=index(g,j);
	g->edges[indexI][indexJ]=1;
	g->edges[indexJ][indexI]=1;
}
void DelLine(graph * g)
{
	int i,j,indexI,indexJ;
	printf("������Ҫɾ���ߵ�������㣺");
	scanf("%d %d",&i,&j);
	indexI=index(g,i);
	indexJ=index(g,j);
	g->edges[indexI][indexJ]=0;
	g->edges[indexJ][indexI]=0;
}
