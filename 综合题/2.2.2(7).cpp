#include<stdio.h>
#include<stdlib.h>
#define MAXLINE 100
typedef int elementType;
typedef struct sqlist
{
	int v[MAXLINE];
	int len;
}sqlist;
typedef struct LinkNode
{
	elementType data;
	struct LinkNode *next;
}*LinkList;
LinkList createLinkList()
{
	elementType n;
	LinkList head,p;
	head=(LinkList)malloc(sizeof(struct LinkNode));
	head->next=NULL;
	printf("put on-> 0 over\n");
	scanf("%d",&n);
	while(n)
	{
		p=(LinkList)malloc(sizeof(struct LinkNode));
		p->data=n;
		p->next=head->next;
		head->next=p;
		printf("put on-> 0 over\n");
		fflush(stdin);
		scanf("%d",&n);
	}
	return head;
}
void merge(LinkList head1,LinkList head2)
{
	LinkList q=head2->next;
	LinkList p=head1->next;
	LinkList tempP,tempQ;
	while(p&&q)
	{
		tempP=p->next;
		tempQ=q->next;
		if(!tempP&&tempQ)
			p->next=q;
		else
		{
			q->next=p->next;
			p->next=q;
		}
		p=tempP;
		q=tempQ;
	}
	head2->next=NULL;
}
int main(void)
{
	LinkList p,q;
	p=createLinkList();
	q=createLinkList();
	merge(p,q);
	p=p->next;
	while(p!=NULL)
	{
		printf("%d ",p->data);
		p=p->next;
	}
	printf("\n");
	return 0;
}