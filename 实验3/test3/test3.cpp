#include "head.h"
#include<stdio.h>
#include<stdlib.h>
LinkList2 createLink2()
{
	int n,i=0;
	LinkList2 head,p,tail;
	printf("��������\n");
	printf("put on-> 0 over\n");
	fflush(stdin);
	scanf("%d",&n);
	while(n!=0)
	{
		if(i==0)
		{
			head=(LinkList2)malloc(sizeof(LinkNode2));
			head->next=head;
			head->k=n;
			tail=head;
			i=1;
		}
		else
		{
			p=(LinkList2)malloc(sizeof(LinkNode2));
			p->k=n;
			tail->next=p;
			p->next=head;
			tail=p;
		}
		printf("put on-> 0 over\n");
		fflush(stdin);
		fflush(stdin);
		scanf("%d",&n);
	}
	return head;
}
void test3_1(LinkList2 head)
{
	head=NULL;
}
void test3_2(LinkList2 head)
{
	LinkList2 p;
	p=head->next;
	printf("%d ",head->k);
	while(p!=head)
	{
		printf("%d ",p->k);
		p=p->next;
	}
	printf("\n");
}
int test3_3(LinkList2 head,int i)
{
	int j;
	LinkList2 p;
	p=head->next;
	j=2;
	if(i<1)
	{
		printf("ȡֵλ�ô���\n");
		return 0;
	}
	else if(i==1)
	{
		return head->k;
	}
	else
	{
		while(p!=head&&j!=i)
		{
			p=p->next;
			j++;
		}
	}
	if(p==head)
	{
		printf("ȡֵλ�ô���\n");
		return 0;
	}
	else return p->k;
}
LinkList2 test3_4(LinkList2 head,int i)
{
	int j;
	LinkList2 p,q,k;
	p=head->next;
	k=head->next;
	q=head;
	j=2;
	if(i<1)
		printf("ɾ����λ�ò��ԣ�\n");
	else if(i==1)//�޷�ɾ���׽��
	{	
		while(k->next!=head)
			k=k->next;
		head=head->next;
		free(q);
		k->next=head;
	}
	else if(i==2)
	{
		head->next=p->next;
		free(p);
	}
	else 
	{
		while(p!=head&&j!=i-1)
		{
			p=p->next;
			j++;
		}
		p->next=p->next->next;
		free(p->next);
	}
	return head;
}
LinkList2 test3_5(LinkList2 head,int key)
{
	LinkList2 p,q,k;
	p=head->next;
	k=head->next;
	q=head;
	if(head->k==key)//�޷�ɾ���׽��
	{		
		while(k->next!=head)
			k=k->next;
		head=head->next;
		free(q);
		k->next=head;
	}
	else 
	{
		while(p!=head&&p->k!=key)
		{
			p=p->next;
			q=q->next;
		}	
		if(p==head)
			printf("δ�ҵ���Ԫ�أ�");
		else 
		{
			q->next=p->next;
			free(p);
		}
	}
	return head;
}
void test3_6(LinkList2 head,int key)
{
	LinkList2 p,q;
	p=(LinkList2)malloc(sizeof(LinkNode2));
	p->k=key;
	q=head->next;
	while(q->next!=head)
	{
		q=q->next;
	}
	q->next=p;
	p->next=head;
	head=p;
}
void test3_7(LinkList2 head,int key)
{
	LinkList2 p,temp;
	temp=(LinkList2)malloc(sizeof(LinkNode2));
	temp->k=key;
	p=head->next;
	while(p->next!=head)
	{
		p=p->next;
	}
	p->next=temp;
	temp->next=head;
}
void test3_8(LinkList2 head,int key,int i)
{
	LinkList2 p,temp;
	int j;
	temp=(LinkList2)malloc(sizeof(LinkNode2));
	temp->k=key;
	p=head;
	j=1;
	if(i<1)
		printf("�����λ�ò���!\n");
	if(i==1)
	{
		temp->next=head;
		head=temp;
	}
	else
	{
		while(j!=i-1)
		{
			p=p->next;
			j++;
		}
		temp->next=p->next;
		p->next=temp;
	}
}
int test3_9(LinkList2 head,int key)
{
	LinkList2 p;
	p=head->next;
	if(head->k==key)
		return 1;
	else
	{
		while(p!=head&&p->k!=key)
		{
			p=p->next;
		}
		if(p==head)
			return 0;
		else return 1;
	}
}
void test3Menu(LinkList2 head)
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
			case 1:test3_1(head);break;
			case 2:test3_2(head);break;
			case 3:
			{
				int i;
				printf("����������λ��\n");
				fflush(stdin);
				scanf("%d",&i);
				printf("��%d��Ԫ��Ϊ%d\n",i,test3_3(head,i));
			}break;
			case 4:
			{
				int i;
				printf("����Ҫɾ����λ��\n");
				fflush(stdin);
				scanf("%d",&i);
				head=test3_4(head,i);
			}break;
			case 5:
			{
				int key;
				printf("����Ҫɾ����ֵ\n");
				fflush(stdin);
				scanf("%d",&key);
				head=test3_5(head,key);
			}break;
			case 6:
			{
				int key;
				printf("����Ҫ��ӵ�ֵ\n");
				fflush(stdin);
				scanf("%d",&key);
				test3_6(head,key);
			}break;
			case 7:
			{
				int key;
				printf("����Ҫ��ӵ�ֵ\n");
				fflush(stdin);
				scanf("%d",&key);
				test3_7(head,key);
			}break;
			case 8:
			{
				int k;
				int i;
				printf("������Ҫ��ӵ�Ԫ��ֵ��λ��:");
				fflush(stdin);
				scanf("%d %d",&k,&i);
				test3_8(head,k,i);
			}break;
			case 9:
			{
				int flag;
				int	i;
				printf("����������ֵ\n");
				fflush(stdin);
				scanf("%d",&flag);
				i=test3_9(head,flag);
				if(i)
					printf("����%d\n",flag);
				else printf("������%d\n",flag);
			};break;
		}
	}
}