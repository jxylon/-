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
void InsertLine(graph * g)
{
	int flag=0,i,j;
	arc * temp;
	arc * a=NULL;
	printf("输入你要添加边的两个结点：");
	scanf("%d %d",&i,&j);
	//temp为头结点指向的边结点
	temp=g->vers[i]->firstArc;
	while(temp!=NULL)
	{
		//在ver[i]中找j，找到falg=1
		if(temp->tail==j)
		{
			flag=1;
			break;
		}
		temp=temp->next;
	}
	//如果没有找到就申请空间给a，添加边
	if(flag==0)
	{
		a=(arc *)malloc(sizeof(arc));
		a->tail=j;
		a->next=g->vers[i]->firstArc;
		g->vers[i]->firstArc=a;
	}
	//与上方同理
	temp=g->vers[j]->firstArc;
	flag=0;
	while(temp!=NULL)
	{
		if(temp->tail==i)
		{
			flag=1;
			break;
		}
		temp=temp->next;
	}
	if(flag==0)
	{
		a=(arc *)malloc(sizeof(arc));
		a->tail=i;
		a->next=g->vers[j]->firstArc;
		g->vers[j]->firstArc=a;
	}
}
void DelLine(graph * g)
{
	int flag=0,i,j;
	arc * temp,*temppost;//temp为当前结点，temppost为temp之后的结点
	arc * a=NULL;
	printf("输入你要删除边的两个结点：");
	scanf("%d %d",&i,&j);
	temp=g->vers[i]->firstArc;
	//temp不为空
	if(temp!=NULL)
	{
		temppost=temp->next;
		//如果temp->tail==j，就删除temp
		if(temp->tail==j)
		{
			g->vers[i]->firstArc=temppost;
			free(temp);
		}
		//删除temppost
		else
		{
			//找值为j的arc结点，并删除
			while(temppost!=NULL)
			{
				if(temppost->tail==j)
				{
					temp->next=temppost->next;
					free(temppost);
				}
				temp=temp->next;
				temppost=temp->next;
			}
		}
	}
	//同理
	temp=g->vers[j]->firstArc;
	if(temp!=NULL)
	{
		temppost=temp->next;
		if(temp->tail==i)
		{
			g->vers[j]->firstArc=temppost;
			free(temp);
		}
		else
		{
			while(temppost!=NULL)
			{
				if(temppost->tail==i)
				{
					temp->next=temppost->next;
					free(temppost);
				}
				temp=temp->next;
				temppost=temp->next;
			}
		}
	}
}