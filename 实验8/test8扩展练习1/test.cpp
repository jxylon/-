#include<stdio.h>
#include<stdlib.h>
#include"head.h"
//从文件中读取数值，创建邻接表
graph * create()
{
	int n,e,i,num;
	char c;
	FILE * fp;
	graph * g;
	arc * newArc=NULL;
	//动态申请graph空间
	g=(graph *)malloc(sizeof(graph));
	fp=fopen("data.txt","r");
	fscanf(fp,"%d %d",&n,&e);
	g->e=e;
	g->n=n;
	fscanf(fp,"%c",&c);
	for(i=1;i<n+1;i++)
	{
		//动态申请ptr空间
		g->vers[i]=(ptr *)malloc(sizeof(ptr));
		fscanf(fp,"%d%c",&num,&c);
		g->vers[i]->data=num;
		g->vers[i]->firstArc=NULL;
		g->vers[i]->indegree=0;
		while(c!='\n')
		{
			//动态申请arc空间
			newArc=(arc *)malloc(sizeof(arc));
			fscanf(fp,"%d%c",&num,&c);
			newArc->tail=num;
			newArc->next=g->vers[i]->firstArc;
			g->vers[i]->firstArc=newArc;
		}
	}
	for(i=1;i<n+1;i++)
	{
		newArc=g->vers[i]->firstArc;
		while(newArc)
		{
			g->vers[newArc->tail]->indegree++;
			newArc=newArc->next;
		}
	}
	fclose(fp);
	return g;
}
void prinGraph(graph * g)
{
	arc * temp;
	int i;
	printf("%d个结点 %d条边\n",g->n,g->e);
	printf("结点为:\n");
	for(i=1;i<g->n+1;i++)
		printf("%d ",g->vers[i]->data);
	printf("\n");
	printf("邻接表为:\n");
	for(i=1;i<g->n+1;i++)
	{
		printf("%d:",g->vers[i]->data);
		temp=g->vers[i]->firstArc;
		while(temp)
		{
			printf("%d ",temp->tail);
			temp=temp->next;
		}
		printf("\n");
	}
}
void topSort(graph * g)
{
	int m,i,j;
	arc * p;
	stack * s=(stack *)malloc(sizeof(stack));
	s->top=-1;
	m=0;
	for(i=1;i<g->n+1;i++)
	{
		if(g->vers[i]->indegree==0)
			s->data[++s->top]=i;
	}
	while(s->top!=-1)
	{
		j=s->data[s->top--];
		printf("%d ",g->vers[j]->data);
		m++;
		p=g->vers[j]->firstArc;
		while(p)
		{
			g->vers[p->tail]->indegree--;
			if(g->vers[p->tail]->indegree==0)
				s->data[++s->top]=p->tail;
			p=p->next;
		}
	}
	printf("\n");
	if(m<g->n)
		printf("图中有环!!!\n");
}