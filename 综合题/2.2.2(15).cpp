#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	char c;
	int time;
	struct node * next;
}NODE;
void sort(NODE * p)
{
	NODE * q,*r,temp;
	while(p->next!=NULL)//£¨3£©
	{
		q=p;
		while(q!=NULL)
		{
			if(q==p||q->time>temp.time)
			{
				temp=*q;
				r=q;
			}
			q=q->next;
		}
		*r=*p;
		r->next=temp.next;
		temp.next=p->next;
		*p=temp;
		p=p->next;
	}
}
void main()
{
	NODE *head=NULL,* tail=NULL, *pb;
	char str[50],*p;
	int n;
	printf("put in a string:");
	gets(str);
	p=str;
	while(*p!='\0')
	{
		pb=head;
		while(pb!=NULL)
		{
			if(pb->c==*p)
			{
				pb->time++;
				break;
			}
			pb=pb->next;
		}
		if(pb==NULL)
		{
			pb=(NODE *)malloc(sizeof(NODE));
			pb->c=*p;
			pb->time=1;//£¨2£©
			pb->next=NULL;
			if(tail==NULL)
				head=tail=pb;
			else 
			{
				tail->next=pb;
				tail=pb;
			}
		}
		p++;
	}
	sort(head);
	pb=head;
	printf("result:\n");
	n=0;
	while(pb!=NULL)
	{
		n++;
		printf("%c(´ÎÊý:%d) ",pb->c,pb->time);
		pb=pb->next;//£¨4£©
		if(n%4==0)
		{
			printf("\n");
			n=0;
		}
	}
	printf("\n");
}