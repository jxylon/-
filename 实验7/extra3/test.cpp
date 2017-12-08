#include<stdio.h>
#include<stdlib.h>
#include"head.h"
void init(tree t)
{
	int i,num;
	FILE * fp;
	fp=fopen("createTree.txt","r");
	fscanf(fp,"%d",&num);
	for(i=1;i<num+1;i++)
	{
		t[i]=(struct head *)malloc(sizeof(struct head));
		t[i]->child=NULL;
	}
	fclose(fp);
}
void create(tree t)
{
	FILE * fp;
	int i,num;
	char c;
	cnode * p,* tail;
	fp=fopen("createTree.txt","r");
	fscanf(fp,"%d",&num);
	fscanf(fp,"%c",&c);
	for(i=1;i<num+1;i++)
	{
		//printf("输入第%d个结点的信息\n",i);
		//fflush(stdin);
		//scanf("%c",&t[i]->data);
		fscanf(fp,"%c",&t[i]->data);
		fscanf(fp,"%c",&c);
		while(c!='\n'&&c!='\0')
		{
			p=(struct node *)malloc(sizeof(struct node));
			p->child=c-'0';
			p->next=NULL;
			if(t[i]->child==NULL)
			{
				t[i]->child=p;
				tail=p;
			}
			else
			{
				tail->next=p;
				tail=p;
			}
			fscanf(fp,"%c",&c);
		}
		/*printf("第%d个结点有孩子吗y->yes,n->no?",i);
		fflush(stdin);
		isChild=getchar();
		while(isChild=='y')
		{
			p=(struct node *)malloc(sizeof(struct node));
			printf("他的孩子是第几个结点:");
			scanf("%d",&childIndex);
			p->child=childIndex;
			p->next=NULL;
			if(t[i]->child==NULL)
			{
				t[i]->child=p;
				tail=p;
			}
			else
				tail->next=p;
			printf("还有孩子吗?");
			fflush(stdin);
			isChild=getchar();
		}*/
	}
	fclose(fp);
}
void searchChild(tree t)
{
	int i,num;
	char info;
	cnode * temp;
	FILE * fp;
	printf("输入你要查找孩子的结点信息:");
	fflush(stdin);
	info=getchar();
	fp=fopen("createTree.txt","r");
	fscanf(fp,"%d",&num);
	for(i=1;i<num+1;i++)
	{
		if(t[i]->data==info)
		{
			temp=t[i]->child;
			printf("%c的孩子有:",info);
			while(temp!=NULL)
			{
				printf("%c ",t[temp->child]->data);
				temp=temp->next;
			}
			printf("\n");
		}
	}
	fclose(fp);
} 
void prinTree(tree t)
{
	FILE * fp;
	int num,i;
	fp=fopen("createTree.txt","r");
	fscanf(fp,"%d",&num);
	for(i=1;i<num;i++)
	{
		printf("%c ",t[i]->data);
	}
	printf("\n");
	fclose(fp);
}