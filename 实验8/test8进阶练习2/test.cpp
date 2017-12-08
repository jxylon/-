#include<stdio.h>
#include<stdlib.h>
#include"head.h"
//从文件中读取数值，创建邻接表
void init(lqueuetp * lq)
{
	lq->front=(node *)malloc(sizeof(node));
	lq->front->next=NULL;
	lq->raer=lq->front;
}
void enqueue(lqueuetp * lq,int a)
{
	node * s;
	s=(node *)malloc(sizeof(node));
	s->data=a;
	s->next=NULL;
	lq->raer->next=s;
	lq->raer=s;
}
int dequeue(lqueuetp * lq)
{
	node * s;
	int x;
	if(lq->front==lq->raer)
		return NULL;
	else
	{
		s=lq->front->next;
		lq->front->next=s->next;
		if(s->next==NULL)
			lq->raer=lq->front;
		x=s->data;
		free(s);
		return x;
	}
}
int empty(lqueuetp * lq)
{
	if(lq->front==lq->raer)
		return 1;
	else 
		return 0;
}
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
	if(fp==NULL)
		return NULL;
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
void bfs(graph * g,int v)
{
	lqueuetp * lq=(lqueuetp *)malloc(sizeof(lqueuetp));
	int i,x;
	arc * w;
	init(lq);
	enqueue(lq,v);
	while(!empty(lq))
	{
		x=dequeue(lq);
		if(visited[x]!=1)
			printf("%d ",g->vers[x]->data);
		visited[x]=1;
		w=g->vers[x]->firstArc;
		while(w)
		{
			if(visited[w->tail]!=1)
				enqueue(lq,w->tail);
			w=w->next;
		}
	}
	for(i=1;i<g->n+1;i++)
	{
		if(visited[i]==0)
			bfs(g,i);
	}
}
