#include "head.h"
#include<stdio.h>
#include<stdlib.h>
LinkList1 createLink()
{
	char n;
	LinkList1 head,p;
	head=(LinkList1)malloc(sizeof(LinkNode1));
	head->next=NULL;
	printf("��������\n");
	printf("put on-> 0 over\n");
	n=getchar();
	while(n!='0')
	{
		p=(LinkList1)malloc(sizeof(LinkNode1));
		p->c=n;
		p->next=head->next;
		head->next=p;
		printf("put on-> 0 over\n");
		fflush(stdin);
		n=getchar();
	}
	return head;
}
void test2_1(LinkList1 head)
{
	head->next=NULL;
}
void test2_2(LinkList1 head)
{
	LinkList1 p;
	p=head->next;
	while(p)
	{
		printf("%c ",p->c);
		p=p->next;
	}
	printf("\n");
}
char test2_3(LinkList1 head,int i)
{
	int j;
	LinkList1 p;
	p=head->next;
	j=1;
	if(i<1)
	{
		printf("ȡֵλ�ô���\n");
		return '0';
	}
	else
	{
		while(p&&j!=i)
		{
			p=p->next;
			j++;
		}
	}
	if(p=NULL)
	{
		printf("ȡֵλ�ô���\n");
		return '0';
	}
	else return p->c;
}
void test2_4(LinkList1 head,int i)
{
	int j;
	LinkList1 p;
	p=head->next;
	j=1;
	if(i<1)
		printf("ɾ����λ�ò��ԣ�\n");
    else if(i==1)
	{
		head->next=p->next;
		free(p);
	}
	else 
	{
		while(j!=i-1)
		{
			p=p->next;
			j++;
		}
		p->next=p->next->next;
		free(p->next);
	}
}
void test2_5(LinkList1 head,char key)
{
	LinkList1 p,q;
	p=head->next;
	q=head;
	while(p&&p->c!=key)
	{
		p=p->next;
		q=q->next;
	}
	if(p==NULL)
		printf("δ�ҵ���Ԫ�أ�");
	else 
	{
		q->next=p->next;
		free(p);
	}
}
void test2_6(LinkList1 head,char key)
{
	LinkList1 p;
	p=(LinkList1)malloc(sizeof(LinkNode1));
	p->c=key;
	p->next=head->next;
	head->next=p;
}
void test2_7(LinkList1 head,char key)
{
	LinkList1 p,temp;
	temp=(LinkList1)malloc(sizeof(LinkNode1));
	temp->c=key;
	p=head->next;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	temp->next=NULL;
	p->next=temp;
}
void test2_8(LinkList1 head,char key,int i)
{
	LinkList1 p,temp;
	int j;
	temp=(LinkList1)malloc(sizeof(LinkNode1));
	temp->c=key;
	p=head;
	j=0;
	if(i<1)
		printf("�����λ�ò���!\n");
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
int test2_9(LinkList1 head,char key)
{
	LinkList1 p;
	p=head->next;
	while(p&&p->c!=key)
	{
		p=p->next;
	}
	if(p==NULL)
		return 0;
	else return 1;
}
void test2Menu(LinkList1 head)
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
			case 1:test2_1(head);break;
			case 2:test2_2(head);break;
			case 3:
			{
				int i;
				printf("����������λ��\n");
				fflush(stdin);
				scanf("%d",&i);
				printf("��%d��Ԫ��Ϊ%c\n",i,test2_3(head,i));
			}break;
			case 4:
			{
				int i;
				printf("����Ҫɾ����λ��\n");
				fflush(stdin);
				scanf("%d",&i);
				test2_4(head,i);
			}break;
			case 5:
			{
				char key;
				printf("����Ҫɾ����ֵ\n");
				fflush(stdin);
				scanf("%c",&key);
				test2_5(head,key);
			}break;
			case 6:
			{
				char key;
				printf("����Ҫ��ӵ�ֵ\n");
				fflush(stdin);
				scanf("%c",&key);
				test2_6(head,key);
			}break;
			case 7:
			{
				char key;
				printf("����Ҫ��ӵ�ֵ\n");
				fflush(stdin);
				scanf("%c",&key);
				test2_7(head,key);
			}break;
			case 8:
			{
				char k;
				int i;
				printf("������Ҫ��ӵ�Ԫ��ֵ��λ��:");
				fflush(stdin);
				scanf("%c %d",&k,&i);
				test2_8(head,k,i);
			}break;
			case 9:
			{
				char flag;
				int	i;
				printf("����������ֵ\n");
				fflush(stdin);
				scanf("%c",&flag);
				i=test2_9(head,flag);
				if(i)
					printf("����%c\n",flag);
				else printf("������%c\n",flag);
			};break;
		}
	}
}
