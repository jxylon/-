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
	if(fp==NULL)
		return NULL;
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
	printf("%d个结点 %d条边\n",g->n,g->e);
	printf("结点为：\n");
	for(i=1;i<g->n+1;i++)
		printf("%d ",g->vers[i]);
	printf("\n邻接矩阵为:\n");
	for(i=1;i<g->n+1;i++)
	{
		for(j=1;j<g->n+1;j++)
			printf("%d ",g->edges[i][j]);
		printf("\n");
	}
}
void dfs(graph * g,int v)
{
	int i;
	printf("%d ",g->vers[v]);
	visited[v]=1;
	for(i=1;i<g->n+1;i++)
	{
		if((g->edges[v][i]==1)&&(visited[i]!=1))
		{
			dfs(g,i);
		}
	}
}