#include "head.h"
#include<stdio.h>
#include<stdlib.h>
LinkList3 createLink3()
{
	int n;
	LinkList3 head,p,tail;
	head=(LinkList3)malloc(sizeof(LinkNode3));
	head->next=NULL;
	tail=head;
	printf("��������\n");
	printf("put on-> 0 over\n");
	fflush(stdin);
	scanf("%d",&n);
	while(n!=0)
	{
		p=(LinkList3)malloc(sizeof(LinkNode3));
		p->k=n;

		tail->next=p;
		p->prior=tail;
		p->next=NULL;
		tail=p;

		printf("put on-> 0 over\n");
		fflush(stdin);
		scanf("%d",&n);
	}
	return head;
}
void test4_1(LinkList3 head)
{
	head->next=NULL;
}
void test4_2(LinkList3 head)
{
	LinkList3 p;
	p=head->next;
	while(p)
	{
		printf("%d ",p->k);
		p=p->next;
	}
	printf("\n");
}
int test4_3(LinkList3 head,int i)
{
	int j;
	LinkList3 p;
	p=head->next;
	j=1;
	if(i<1)
	{
		printf("ȡֵλ�ô���\n");
		return 0;
	}
	else
	{
		while(p&&j!=i)
		{
			p=p->next;
			j++;
		}
	}
	if(p==NULL)
	{
		printf("ȡֵλ�ô���\n");
		return 0;
	}
	else return p->k;
}
int test4_4(LinkList3 head,int i)
{
	int j;
	LinkList3 p;
	p=head->next;
	j=1;
	if(i<1)
	{
		printf("ɾ����λ�ò��ԣ�\n");
		return 0;
	}
	else 
	{
		while(p&&j!=i)
		{
			p=p->next;
			j++;
		}
		if(p==NULL)
		{
			printf("ɾ����λ�ò��ԣ�\n");
			return 0;
		}
		else 
		{
			p->prior->next=p->next;
			p->next->prior=p->prior;
			free(p);
			return 1;
		}
	}
}
int test4_5(LinkList3 head,int flag)
{
	int j;
	LinkList3 p;
	p=head->next;
	j=1;
	while(p&&p->k!=flag)
	{
		p=p->next;
		j++;
	}
	if(p==NULL)
	{
		printf("δ�ҵ���Ԫ�أ�\n");
		return 0;
	}
	else 
	{
		p->prior->next=p->next;
		p->next->prior=p->prior;
		free(p);
		return 1;
	}
}
void test4_6(LinkList3 head,int key)
{
	LinkList3 p,q;
	p=(LinkList3)malloc(sizeof(LinkNode3));
	p->k=key;
	q=head->next;
	if(q!=NULL)
	{
		p->prior=q->prior;
		q->prior->next=p;
		p->next=q;
		q->prior=p;
	}
	else
	{
		head->next=p;
		p->prior=head;
		p->next=NULL;
	}
}
void test4_7(LinkList3 head,int key)
{
	LinkList3 p,q;
	p=(LinkList3)malloc(sizeof(LinkNode3));
	p->k=key;
	q=head->next;
	while(q->next!=NULL)
	{
		q=q->next;
	}
	q->next=p;
	p->prior=q;
	p->next=NULL;
}
int test4_8(LinkList3 head,int key,int i)
{
	LinkList3 p,q;
	int j;
	p=(LinkList3)malloc(sizeof(LinkNode3));
	p->k=key;
	q=head->next;
	j=1;
	if(i<1)
	{
		printf("�����λ�ò���\n");
		return 0;
	}
	while(q&&j!=i)
	{
		q=q->next;
		j++;
	}
	if(q==NULL)
	{
		printf("�����λ�ò���\n");
		return 0;
	}
	else
	{
		p->prior=q->prior;
		q->prior->next=p;
		p->next=q;
		q->prior=p;
		return 1;
	}
}
int test4_9(LinkList3 head,int key)
{
	LinkList3 p;
	p=head->next;
	while(p&&p->k!=key)
	{
		p=p->next;
	}
	if(p==NULL)
		return 0;
	else return 1;
}
void test4Menu(LinkList3 head)
{
	int n=1;
	while(n)
	{
		printf("*********************\n");
		printf("1-> ��ʼ������\n");
		printf("2-> ������Ա�Ԫ��ֵ\n");
		printf("3-> ȡ���еĵ�i��Ԫ�صļ�ֵ\n");
		printf("4-> ɾ��������ָ��λ�õ�Ԫ��\n");
		printf("5-> ɾ��������ָ��ֵ��Ԫ��\n");
		printf("6-> �ڱ�ͷ���Ԫ��\n");
		printf("7-> �ڱ�β���Ԫ��\n");
		printf("8-> �����ָ��λ�ô���Ӽ�ֵkey��Ԫ��\n");
		printf("9-> �ڱ��е�����ָ��Ԫ�أ������Ƿ����\n");
		printf("0-> �˳�\n");
		printf("*********************\n");
		printf("����ѡ�");
		scanf("%d",&n);
		switch(n)
		{
			case 1:test4_1(head);break;
			case 2:test4_2(head);break;
			case 3:
			{
				int i;
				printf("����������λ��\n");
				fflush(stdin);
				scanf("%d",&i);
				printf("��%d��Ԫ��Ϊ%d\n",i,test4_3(head,i));
			}break;
			case 4:
			{
				int i;
				printf("����Ҫɾ����λ��\n");
				fflush(stdin);
				scanf("%d",&i);
				test4_4(head,i);
			}break;
			case 5:
			{
				int key;
				printf("����Ҫɾ����ֵ\n");
				fflush(stdin);
				scanf("%d",&key);
				test4_5(head,key);
			}break;
			case 6:
			{
				int key;
				printf("����Ҫ��ӵ�ֵ\n");
				fflush(stdin);
				scanf("%d",&key);
				test4_6(head,key);
			}break;
			case 7:
			{
				int key;
				printf("����Ҫ��ӵ�ֵ\n");
				fflush(stdin);
				scanf("%d",&key);
				test4_7(head,key);
			}break;
			case 8:
			{
				int k;
				int i;
				printf("������Ҫ��ӵ�Ԫ��ֵ��λ��:");
				fflush(stdin);
				scanf("%d %d",&k,&i);
				test4_8(head,k,i);
			}break;
			case 9:
			{
				int flag;
				int	i;
				printf("����������ֵ\n");
				fflush(stdin);
				scanf("%d",&flag);
				i=test4_9(head,flag);
				if(i)
					printf("����%d\n",flag);
				else printf("������%d\n",flag);
			};break;
		}
	}
}