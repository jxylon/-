#include "head.h"
#include<stdio.h>
#include<stdlib.h>
LinkList2 createLink2()
{
	int n,i=0;
	LinkList2 head,p,tail;
	printf("创建链表\n");
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
		printf("取值位置错误\n");
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
		printf("取值位置错误\n");
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
		printf("删除的位置不对！\n");
	else if(i==1)//无法删除首结点
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
	if(head->k==key)//无法删除首结点
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
			printf("未找到该元素！");
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
		printf("插入的位置不对!\n");
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
		printf("1-> 初始化链表\n");
		printf("2-> 输出线性表元素值\n");
		printf("3-> 取表中的第i个元素的键值\n");
		printf("4-> 删除数组中指定位置的元素\n");
		printf("5-> 删除数组中指定值的元素\n");
		printf("6-> 在表头添加元素\n");
		printf("7-> 在表尾添加元素\n");
		printf("8-> 向表中指定位置处添加键值key的元素\n");
		printf("9-> 在表中的搜索指定元素，看其是否存在\n");
		printf("0-> 退出\n");
		printf("*********************\n");
		printf("输入选项：");
		scanf("%d",&n);
		switch(n)
		{
			case 1:test3_1(head);break;
			case 2:test3_2(head);break;
			case 3:
			{
				int i;
				printf("输入搜索的位置\n");
				fflush(stdin);
				scanf("%d",&i);
				printf("第%d个元素为%d\n",i,test3_3(head,i));
			}break;
			case 4:
			{
				int i;
				printf("输入要删除的位置\n");
				fflush(stdin);
				scanf("%d",&i);
				head=test3_4(head,i);
			}break;
			case 5:
			{
				int key;
				printf("输入要删除的值\n");
				fflush(stdin);
				scanf("%d",&key);
				head=test3_5(head,key);
			}break;
			case 6:
			{
				int key;
				printf("输入要添加的值\n");
				fflush(stdin);
				scanf("%d",&key);
				test3_6(head,key);
			}break;
			case 7:
			{
				int key;
				printf("输入要添加的值\n");
				fflush(stdin);
				scanf("%d",&key);
				test3_7(head,key);
			}break;
			case 8:
			{
				int k;
				int i;
				printf("输入你要添加的元素值和位置:");
				fflush(stdin);
				scanf("%d %d",&k,&i);
				test3_8(head,k,i);
			}break;
			case 9:
			{
				int flag;
				int	i;
				printf("输入搜索的值\n");
				fflush(stdin);
				scanf("%d",&flag);
				i=test3_9(head,flag);
				if(i)
					printf("存在%d\n",flag);
				else printf("不存在%d\n",flag);
			};break;
		}
	}
}