#include "head.h"
#include<stdio.h>
#include<stdlib.h>
LinkList1 createLink()
{
	char n;
	LinkList1 head,p;
	head=(LinkList1)malloc(sizeof(LinkNode1));
	head->next=NULL;
	printf("创建链表\n");
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
		printf("取值位置错误\n");
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
		printf("取值位置错误\n");
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
		printf("删除的位置不对！\n");
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
		printf("未找到该元素！");
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
		printf("插入的位置不对!\n");
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
			case 1:test2_1(head);break;
			case 2:test2_2(head);break;
			case 3:
			{
				int i;
				printf("输入搜索的位置\n");
				fflush(stdin);
				scanf("%d",&i);
				printf("第%d个元素为%c\n",i,test2_3(head,i));
			}break;
			case 4:
			{
				int i;
				printf("输入要删除的位置\n");
				fflush(stdin);
				scanf("%d",&i);
				test2_4(head,i);
			}break;
			case 5:
			{
				char key;
				printf("输入要删除的值\n");
				fflush(stdin);
				scanf("%c",&key);
				test2_5(head,key);
			}break;
			case 6:
			{
				char key;
				printf("输入要添加的值\n");
				fflush(stdin);
				scanf("%c",&key);
				test2_6(head,key);
			}break;
			case 7:
			{
				char key;
				printf("输入要添加的值\n");
				fflush(stdin);
				scanf("%c",&key);
				test2_7(head,key);
			}break;
			case 8:
			{
				char k;
				int i;
				printf("输入你要添加的元素值和位置:");
				fflush(stdin);
				scanf("%c %d",&k,&i);
				test2_8(head,k,i);
			}break;
			case 9:
			{
				char flag;
				int	i;
				printf("输入搜索的值\n");
				fflush(stdin);
				scanf("%c",&flag);
				i=test2_9(head,flag);
				if(i)
					printf("存在%c\n",flag);
				else printf("不存在%c\n",flag);
			};break;
		}
	}
}
