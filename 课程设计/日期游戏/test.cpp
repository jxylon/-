#include<stdio.h>
#include<stdlib.h>
#include<windows.h>  
#include<iostream>
#include"head.h"
int travel(bitreptr bt,int level,date d)//2017.6.6------(1)
{
	int l;
	if(bt)
	{
		if(bt->data.day==d.day&&bt->data.month==d.month&&bt->data.year==d.year)
			return level;
		l=travel(bt->lchild,level+1,d);
		if(l!=0)
			return l;
		else
			return travel(bt->rchild,level+1,d);
	}
	return 0;	
}
//求二叉树深度
int deepth(bitreptr bt)
{
	int m,n;
	if(bt==NULL)
		return 0;
	else
	{
		m=deepth(bt->lchild);
		n=deepth(bt->rchild);
		return (m>n?m:n)+1;
	}
}
//建立二叉树
bitreptr create(date d)
{
	int flagNext;
	//队列指针
	lqueuetp * lq=(lqueuetp *)malloc(sizeof(lqueuetp));
	//nextDay下一天，nextMonth下一个月
	date * nextDay=(date *)malloc(sizeof(date));
	date * nextMonth=(date *)malloc(sizeof(date));
	//root二叉树根，ld为左孩子，rd为右孩子
	bitreptr root=(bitreptr)malloc(sizeof(struct bnodept));
	bitreptr temp=NULL,ld,rd;
	//初始化队列
	initLq(lq);
	//初始化root，数据域为d
	root->data=d;
	root->lchild=NULL;
	root->rchild=NULL;
	//将root入队
	pushLq(lq,root);
	//当队列不为空时
	while(!isEmpty(lq))
	{
		//temp队首元素
		temp=popLq(lq);
		//得到temp->data的下一天和下一个月
		flagNext=nextDate(nextDay,nextMonth,temp->data);	
		//如果返回的nextDay或者nextMonth是有效的
		if(flagNext)
		{
			//动态申请空间
			ld=(bitreptr)malloc(sizeof(struct bnodept));
			rd=(bitreptr)malloc(sizeof(struct bnodept));
			ld->data=*nextDay;
			ld->lchild=NULL;
			ld->rchild=NULL;
			rd->data=*nextMonth;
			rd->lchild=NULL;
			rd->rchild=NULL;
			//temp指向ld和rd
			temp->lchild=ld;
			temp->rchild=rd;
			//如果nextDay或者nextMonth中有一个是2001年11月4日 不入队 否则入队
			if(!(nextDay->year==2001&&nextDay->month==11&&nextDay->day==4)&&!(nextMonth->year==2001&&nextMonth->month==11&&nextMonth->day==4))
			{
				pushLq(lq,ld);
				pushLq(lq,rd);
			}
			else
				break;
		}
	}
	//返回根结点
	return root;
}
//判断下一天和下一个月
int nextDate(date * nextD,date * nextM,date d)
{
	int monthDay[12]={31,28,31,30,31,30,31,31,30,31,30,31};

	nextD->day=d.day;
	nextD->month=d.month;
	nextD->year=d.year;
	nextM->day=d.day;
	nextM->month=d.month;
	nextM->year=d.year;
	//month ERROR!
	if(nextD->month<1||nextD->month>12)
		return 0;

	//day ERROR!
	if(nextD->day<1||nextD->day>monthDay[nextD->month-1])
		return 0;

	nextD->day++;
	nextM->month++;

	if(d.year%4==0||(d.year%100==0&&d.year%400==0))
		monthDay[1]+=1;

	if(nextD->day==monthDay[nextD->month-1]+1)
	{
		nextD->day=1;
		nextD->month++;
	}
	if(nextD->month==13)
	{
		nextD->month=1;
		nextD->year++;
	}
	if(nextM->month==13)
	{
		nextM->month=1;
		nextM->year++;
	}
	return 1;
}
//按层次输出二叉树
void prinTree(bitreptr t)
{
	int num=1;
	date nlast,last;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
	bitreptr s=t;
	lqueuetp * lq=(lqueuetp *)malloc(sizeof(lqueuetp));
	initLq(lq);
	pushLq(lq,s);
	last=s->data;
	while(!isEmpty(lq))
	{
		s=lq->front->next->data;
		if(s->lchild)
		{
			pushLq(lq,s->lchild);
			nlast=rearLq(lq);
		}
		if(s->rchild)
		{
			pushLq(lq,s->rchild);
			nlast=rearLq(lq);
		}
		s=popLq(lq);
		if(num==1)
		{
			if(s->data.year==2001&&s->data.month==11&&s->data.day==4)
			{
				SetConsoleTextAttribute(hOut,  FOREGROUND_RED|FOREGROUND_INTENSITY);
				printf("1层:%d年%d月%d日\t",s->data.year,s->data.month,s->data.day);
				SetConsoleTextAttribute(hOut,  FOREGROUND_RED |   FOREGROUND_GREEN |   FOREGROUND_BLUE |  FOREGROUND_INTENSITY);
			}
			else
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN |   FOREGROUND_BLUE |  FOREGROUND_INTENSITY);
				printf("1层:");
				SetConsoleTextAttribute(hOut,  FOREGROUND_RED |   FOREGROUND_GREEN |   FOREGROUND_BLUE |  FOREGROUND_INTENSITY);
				printf("%d年%d月%d日\t",s->data.year,s->data.month,s->data.day);
			}
			if(equalDate(s->data,last))
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN |   FOREGROUND_BLUE |  FOREGROUND_INTENSITY);
				printf("\n2层:");
				SetConsoleTextAttribute(hOut,  FOREGROUND_RED |   FOREGROUND_GREEN |   FOREGROUND_BLUE |  FOREGROUND_INTENSITY);	
				last=nlast;
			}
			num+=2;
		}
		else
		{
			if(s->data.year==2001&&s->data.month==11&&s->data.day==4)
			{
				SetConsoleTextAttribute(hOut,  FOREGROUND_RED|FOREGROUND_INTENSITY);
				printf("%d年%d月%d日\t",s->data.year,s->data.month,s->data.day);
				SetConsoleTextAttribute(hOut,  FOREGROUND_RED |   FOREGROUND_GREEN |   FOREGROUND_BLUE |   FOREGROUND_INTENSITY);
			}
			else
				printf("%d年%d月%d日\t",s->data.year,s->data.month,s->data.day);
			if(equalDate(s->data,last))
			{
				SetConsoleTextAttribute(hOut, FOREGROUND_GREEN |   FOREGROUND_BLUE |  FOREGROUND_INTENSITY);
				printf("\n%d层:",num);
				SetConsoleTextAttribute(hOut,  FOREGROUND_RED |   FOREGROUND_GREEN |   FOREGROUND_BLUE |  FOREGROUND_INTENSITY);
				num++;
				last=nlast;
			}
		}
	}
}
int equalDate(date d1,date d2)
{
	if(d1.day==d2.day&&d1.month==d2.month&&d1.year==d1.year)
		return 1;
	else return 0;
}
date rearLq(lqueuetp * lq)
{
	return lq->rear->data->data;
}
void initLq(lqueuetp * lq)
{
	lq->front=(Node *)malloc(sizeof(Node));
	lq->front->next=NULL;
	lq->rear=lq->front;
}
void pushLq(lqueuetp * lq,bitreptr num)
{
	Node * node=(Node *)malloc(sizeof(Node));
	node->data=num;
	node->next=NULL;
	lq->rear->next=node;
	lq->rear=node;
}
bitreptr popLq(lqueuetp * lq)
{
	Node * p;
	bitreptr x;
	if(lq->front==lq->rear)
		return NULL;
	else 
	{
		p=lq->front->next;
		lq->front->next=p->next;
		if(p->next==NULL)
			lq->rear=lq->front;
		x=p->data;
		free(p);
		return(x);
	}
}
int isEmpty(lqueuetp * lq)
{
	if(lq->front==lq->rear)
		return 1;
	else return 0;
}