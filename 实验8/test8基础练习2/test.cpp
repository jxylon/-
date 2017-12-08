#include<stdio.h>
#include<stdlib.h>
#include"head.h"
//���ļ��ж�ȡ��ֵ�������ڽӱ�
graph * create()
{
	int n,e,i,num;
	char c;
	FILE * fp;
	graph * g;
	arc * newArc=NULL;
	//��̬����graph�ռ�
	g=(graph *)malloc(sizeof(graph));
	fp=fopen("data.txt","r");
	fscanf(fp,"%d %d",&n,&e);
	g->e=e;
	g->n=n;
	fscanf(fp,"%c",&c);
	for(i=1;i<n+1;i++)
	{
		//��̬����ptr�ռ�
		g->vers[i]=(ptr *)malloc(sizeof(ptr));
		fscanf(fp,"%d%c",&num,&c);
		g->vers[i]->data=num;
		g->vers[i]->firstArc=NULL;
		while(c!='\n')
		{
			//��̬����arc�ռ�
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
	printf("%d����� %d����\n",g->n,g->e);
	printf("���Ϊ:\n");
	for(i=1;i<g->n+1;i++)
		printf("%d ",g->vers[i]->data);
	printf("\n");
	printf("�ڽӱ�Ϊ:\n");
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
	printf("������Ҫ��ӱߵ�������㣺");
	scanf("%d %d",&i,&j);
	//tempΪͷ���ָ��ı߽��
	temp=g->vers[i]->firstArc;
	while(temp!=NULL)
	{
		//��ver[i]����j���ҵ�falg=1
		if(temp->tail==j)
		{
			flag=1;
			break;
		}
		temp=temp->next;
	}
	//���û���ҵ�������ռ��a����ӱ�
	if(flag==0)
	{
		a=(arc *)malloc(sizeof(arc));
		a->tail=j;
		a->next=g->vers[i]->firstArc;
		g->vers[i]->firstArc=a;
	}
	//���Ϸ�ͬ��
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
	arc * temp,*temppost;//tempΪ��ǰ��㣬temppostΪtemp֮��Ľ��
	arc * a=NULL;
	printf("������Ҫɾ���ߵ�������㣺");
	scanf("%d %d",&i,&j);
	temp=g->vers[i]->firstArc;
	//temp��Ϊ��
	if(temp!=NULL)
	{
		temppost=temp->next;
		//���temp->tail==j����ɾ��temp
		if(temp->tail==j)
		{
			g->vers[i]->firstArc=temppost;
			free(temp);
		}
		//ɾ��temppost
		else
		{
			//��ֵΪj��arc��㣬��ɾ��
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
	//ͬ��
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