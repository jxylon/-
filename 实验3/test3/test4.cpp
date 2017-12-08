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
	printf("创建链表\n");
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
		printf("取值位置错误\n");
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
		printf("取值位置错误\n");
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
		printf("删除的位置不对！\n");
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
			printf("删除的位置不对！\n");
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
		printf("未找到该元素！\n");
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
		printf("插入的位置不对\n");
		return 0;
	}
	while(q&&j!=i)
	{
		q=q->next;
		j++;
	}
	if(q==NULL)
	{
		printf("插入的位置不对\n");
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
			case 1:test4_1(head);break;
			case 2:test4_2(head);break;
			case 3:
			{
				int i;
				printf("输入搜索的位置\n");
				fflush(stdin);
				scanf("%d",&i);
				printf("第%d个元素为%d\n",i,test4_3(head,i));
			}break;
			case 4:
			{
				int i;
				printf("输入要删除的位置\n");
				fflush(stdin);
				scanf("%d",&i);
				test4_4(head,i);
			}break;
			case 5:
			{
				int key;
				printf("输入要删除的值\n");
				fflush(stdin);
				scanf("%d",&key);
				test4_5(head,key);
			}break;
			case 6:
			{
				int key;
				printf("输入要添加的值\n");
				fflush(stdin);
				scanf("%d",&key);
				test4_6(head,key);
			}break;
			case 7:
			{
				int key;
				printf("输入要添加的值\n");
				fflush(stdin);
				scanf("%d",&key);
				test4_7(head,key);
			}break;
			case 8:
			{
				int k;
				int i;
				printf("输入你要添加的元素值和位置:");
				fflush(stdin);
				scanf("%d %d",&k,&i);
				test4_8(head,k,i);
			}break;
			case 9:
			{
				int flag;
				int	i;
				printf("输入搜索的值\n");
				fflush(stdin);
				scanf("%d",&flag);
				i=test4_9(head,flag);
				if(i)
					printf("存在%d\n",flag);
				else printf("不存在%d\n",flag);
			};break;
		}
	}
}