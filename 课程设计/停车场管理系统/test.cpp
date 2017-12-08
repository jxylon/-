#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"head.h"
//初始化STOPPING
void init_STOPPING(STOPPING * sp)
{
	sp->top=0;
}
//判断是否为空
int empty_STOPPING(STOPPING * sp)
{
	if(sp->top==0)
		return 1;
	else 
		return 0;
}
//判断是否为满
int full_STOPPING(STOPPING * sp)
{
	if(sp->top==Max_stop)
		return 1;
	else 
		return 0;
}
//CAR入栈
void push_STOPPING(STOPPING * sp,CAR car)
{
	if(!full_STOPPING(sp))
	{
		car.state='s';
		sp->STOP[sp->top++]=car;
		time(&car.begin);
	}
	else
		return ;
}
//CAR出栈
CAR pop_STOPPING(STOPPING * sp)
{
	if(!empty_STOPPING(sp))
	{
		sp->STOP[sp->top-1].state='i';
		time(&sp->STOP[sp->top-1].end);
	}
	return sp->STOP[--sp->top];
}
//返回STOPPING栈顶元素
CAR top_STOPPING(STOPPING * sp)
{
	CAR x;
	if(!empty_STOPPING(sp))
		x=sp->STOP[sp->top-1];
	return x;
}
//初始化BUFFER栈
void init_BUFFER(BUFFER * bf)
{
	bf->top=0;
}
//判断是否为空
int empty_BUFFER(BUFFER * bf)
{
	if(bf->top==0)
		return 1;
	else 
		return 0;
}//判断是否为满
int full_BUFFER(BUFFER * bf)
{
	if(bf->top==Max_stop)
		return 1;
	else 
		return 0;
}
//CAR入栈
void push_BUFFER(BUFFER * bf,CAR car)
{
	if(!full_BUFFER(bf))
	{
		bf->BUFF[bf->top++]=car;
	}
	else
		return ;
}
//CAR出栈
CAR pop_BUFFER(BUFFER * bf)
{
	CAR x;
	if(!empty_BUFFER(bf))
		x=bf->BUFF[--bf->top];
	return x;
}
//初始化PAVE队列
void init_PAVE(PAVEMENT * p)
{
	p->front=p->rear=0;
}
//判断是否为空
int empty_PAVE(PAVEMENT * p)
{
	if(p->front==p->rear)
		return 1;
	else 
		return 0;
}
//判断是否为满
int full_PAVE(PAVEMENT * p)
{
	if((p->rear+1)%Max_pave==p->front)
		return 1;
	else
		return 0;
}
//入队
void push_PAVE(PAVEMENT *p,CAR car)
{
	if(!full_PAVE(p))
	{
		p->PAVE[(p->rear+1)%Max_pave]=car;
		p->rear=(p->rear+1)%Max_pave;
		car.state='p';
	}
	else 
		return ;
}
//出队
CAR pop_PAVE(PAVEMENT * p)
{
	CAR x;
	if(!empty_PAVE(p))
	{
		x=p->PAVE[(p->front+1)%Max_pave];
		x.state='i';
		p->front=(p->front+1)%Max_pave;
	}
	return x;
}
//初始化CAR
void init_CAR(CAR * car)
{
	car->state='i';
	car->license_plate=(char *)malloc(sizeof(char)*8);
}
//停车
void park(STOPPING * sp,PAVEMENT * pv)
{
	int st,pt;
	CAR x;
	init_CAR(&x);
	printf("输入您的车牌号:");
	fflush(stdin);
	gets(x.license_plate);
	st=sp->top;
	while(st>0)
	{
		if(!strcmp(x.license_plate,sp->STOP[--st].license_plate))
		{
			printf("在停车场车牌号已经存在，请重新输入!!!\n\n");
			st=sp->top;
			fflush(stdin);
			gets(x.license_plate);
			continue;
		}
	}
	pt=pv->front;
	while(pv->rear-pt>0)
	{
		if(!strcmp(x.license_plate,pv->PAVE[++pt].license_plate))
		{
			printf("在便道上车牌号已经存在，请重新输入!!!\n\n");
			pt=pv->front;
			fflush(stdin);
			gets(x.license_plate);
			continue;
		}
	}
	if(!full_STOPPING(sp))
	{
		x.begin=time(NULL);
		push_STOPPING(sp,x);
		printf("牌照为%s的汽车进入停车场的%d车位\n\n",x.license_plate,sp->top);
	}
	else
	{
		push_PAVE(pv,x);
		printf("牌照为%s的汽车进入便道的%d位置等待\n\n",x.license_plate,pv->rear);
	}
}
//离开
void leave(STOPPING * sp,PAVEMENT * pv,BUFFER * bf)
{
	int st,find=0;
	double duration;
	CAR x,temp;
	init_CAR(&x);
	init_CAR(&temp);
	printf("输入您的车牌号:");
	fflush(stdin);
	gets(x.license_plate);
	st=sp->top;
	while(!find)
	{
		while(st>0)
		{
			if(!strcmp(x.license_plate,sp->STOP[--st].license_plate))
			{
				find=1;
				break;
			}
		}
		if(st==0&&find==0)
		{
			printf("牌照为%s的汽车在停车场中未找到,请重新输入!!!\n",x.license_plate);
			st=sp->top;
			fflush(stdin);
			gets(x.license_plate);
		}
	}
	while(strcmp(x.license_plate,top_STOPPING(sp).license_plate))
	{
		temp=pop_STOPPING(sp);
		temp.end=time(NULL);
		printf("牌照为%s的汽车暂时退出停车场\n\n",temp.license_plate);
		push_BUFFER(bf,temp);
	}
	temp=pop_STOPPING(sp);
	duration=difftime(temp.end,temp.begin);
	printf("牌照为%s的汽车停车%.2fs,一共支付%.2f元\n\n",temp.license_plate,duration,cost(duration));
	printf("牌照为%s的汽车从停车场开走\n\n",temp.license_plate);
	while(!empty_BUFFER(bf))
	{
		temp=pop_BUFFER(bf);
		push_STOPPING(sp,temp);
		printf("牌照为%s的汽车停回停车场的%d车位\n\n",temp.license_plate,sp->top);
	}
	while(!full_STOPPING(sp))
	{
		if(!empty_PAVE(pv))
		{
			temp=pop_PAVE(pv);
			time(&temp.begin);
			push_STOPPING(sp,temp);
			printf("牌照为%s的汽车从便道上进入停车场的%d车位\n\n",temp.license_plate,sp->top);
		}
		else
			break;
	}
}
double cost(double d)
{
	if(d<=10)
		return 1.0;
	else
		return 1.0+(d-10)*0.2;
}
void prin(STOPPING * sp,PAVEMENT * pv)
{
	int st=0,pt=pv->front;
	double duration;
	printf("**********************************************************\n");
	printf("停车场的情况:\n");
	while(st<sp->top)
	{
		time(&sp->STOP[st].end);
		duration=difftime(sp->STOP[st].end,sp->STOP[st].begin);
		printf("%d车位---------%s:已经停车%.2f秒(%.2f元);\n",st+1,sp->STOP[st].license_plate,duration,cost(duration));
		st++;
	}
	printf("便道上的情况:\n");
	while(pt<pv->rear)
	{
		
		printf("%d位置---------%s;\n",pt+1,pv->PAVE[pt+1].license_plate);
		pt++;
	}
}
void Menu()
{
	STOPPING * sp=(STOPPING *)malloc(sizeof(STOPPING));
	BUFFER * bf=(BUFFER *)malloc(sizeof(BUFFER));
	PAVEMENT * pv=(PAVEMENT *)malloc(sizeof(PAVEMENT));
	init_STOPPING(sp);
	init_BUFFER(bf);
	init_PAVE(pv);
	int n=1;
	while(n)
	{
		printf("*******************停车场管理系统菜单*********************\n\n");
		printf("		1->	停车\n");
		printf("		2->	离开停车位\n");
		printf("		3->	查看停车位状态\n");
		printf("		0->	退出\n");
		printf("**********************************************************\n");
		printf("输入选项：");
		fflush(stdin);
		scanf("%d",&n);
		switch(n)
		{
		case 1:park(sp,pv);break;
		case 2:leave(sp,pv,bf);break;
		case 3:prin(sp,pv);break;
		}
	}
}