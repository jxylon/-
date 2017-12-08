#include "head.h"
#include<stdio.h>
#include<stdlib.h>
polynode * createPoly()
{
	int exp;
	float coef;
	polynode * p,* head,* tail;
	head=(polynode *)malloc(sizeof(polynode));
	head->next=NULL;
	tail=head;
	printf("put in exp,coef -> -1 over\n");
	fflush(stdin);
	scanf("%d %f",&exp,&coef);
	while(exp>=0)
	{
		p=(polynode *)malloc(sizeof(polynode));
		p->coef=coef;
		p->exp=exp;
		tail->next=p;
		p->next=NULL;
		tail=p;
		printf("put in exp,coef -> -1 over\n");
		fflush(stdin);
		scanf("%d %f",&exp,&coef);
	}
	printf("over\n");
	return head;
}
void addPoly(polynode * pa,polynode * pb)
{
	polynode * p,* q,* r,* pre;
	float x;
	p=pa->next;
	q=pb->next;
	pre=pa;
	while(p&&q)
	{
		if(p->exp==q->exp)
		{
			x=p->coef+q->coef;
			if(x!=0)
			{
				p->coef=x;
				pre=p;
			}
			else
			{
				pre->next=p->next;
				free(p);
			}
			p=pre->next;
			r=q;
			q=q->next;
			free(r);
		}
		else if(p->exp>q->exp)
		{
			r=q->next;
			q->next=p;
			pre->next=q;
			p=q;
			q=r;
		}
		else
		{
			pre=p;
			p=p->next;
		}
	}
	if(q)
		pre->next=q;
	free(pb);
}
void print(polynode * pa)
{
	polynode * p;
	p=pa->next;
	while(p!=NULL)
	{
		if(p->next==NULL)
			printf("%.2fx^%d",p->coef,p->exp);
		else printf("%.2fx^%d+",p->coef,p->exp);
		p=p->next;
	}
	printf("\n");
}