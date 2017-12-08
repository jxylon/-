#include<stdio.h>
#include<stdlib.h>
#include"head.h"
bitreptr create()
{
	int n;
	FILE * fp;
	bitreptr t=NULL;
	fp=fopen("data.txt","r");
	if(fp==NULL)
		return NULL;
	else
	{
		while(!feof(fp))
		{
			fscanf(fp,"%d ",&n);
			t=InsertNode(t,n);
		}
	}
	return t;
}
int searchElem(bitreptr t,bitreptr * p,bitreptr *q,datatype x)
{
	int flag=0;
	* q=t;
	while(*q)
	{
		if(x>(*q)->data)
		{
			*p=*q;
			*q=(*q)->rchild;
		}
		else if(x<(*q)->data)
		{
			*p=*q;
			*q=(*q)->lchild;
		}
		else
		{
			flag=1;
			break;
		}
	}
	return flag;
}
bitreptr InsertNode(bitreptr t,datatype x)
{
	bitreptr p=t,q,s;
	if(!searchElem(t,&p,&q,x))
	{
		s=(bitreptr)malloc(sizeof(struct bnodept));
		s->data=x;
		s->lchild=NULL;
		s->rchild=NULL;
		if(!p)
			t=s;
		else if(x>p->data)
			p->rchild=s;
		else
			p->lchild=s;
	}
	return t;
}
void inorder(bitreptr t)
{
	if(t)
	{
		inorder(t->lchild);
		printf("%d ",t->data);
		inorder(t->rchild);
	}
}