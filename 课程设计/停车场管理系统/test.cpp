#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"head.h"
//��ʼ��STOPPING
void init_STOPPING(STOPPING * sp)
{
	sp->top=0;
}
//�ж��Ƿ�Ϊ��
int empty_STOPPING(STOPPING * sp)
{
	if(sp->top==0)
		return 1;
	else 
		return 0;
}
//�ж��Ƿ�Ϊ��
int full_STOPPING(STOPPING * sp)
{
	if(sp->top==Max_stop)
		return 1;
	else 
		return 0;
}
//CAR��ջ
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
//CAR��ջ
CAR pop_STOPPING(STOPPING * sp)
{
	if(!empty_STOPPING(sp))
	{
		sp->STOP[sp->top-1].state='i';
		time(&sp->STOP[sp->top-1].end);
	}
	return sp->STOP[--sp->top];
}
//����STOPPINGջ��Ԫ��
CAR top_STOPPING(STOPPING * sp)
{
	CAR x;
	if(!empty_STOPPING(sp))
		x=sp->STOP[sp->top-1];
	return x;
}
//��ʼ��BUFFERջ
void init_BUFFER(BUFFER * bf)
{
	bf->top=0;
}
//�ж��Ƿ�Ϊ��
int empty_BUFFER(BUFFER * bf)
{
	if(bf->top==0)
		return 1;
	else 
		return 0;
}//�ж��Ƿ�Ϊ��
int full_BUFFER(BUFFER * bf)
{
	if(bf->top==Max_stop)
		return 1;
	else 
		return 0;
}
//CAR��ջ
void push_BUFFER(BUFFER * bf,CAR car)
{
	if(!full_BUFFER(bf))
	{
		bf->BUFF[bf->top++]=car;
	}
	else
		return ;
}
//CAR��ջ
CAR pop_BUFFER(BUFFER * bf)
{
	CAR x;
	if(!empty_BUFFER(bf))
		x=bf->BUFF[--bf->top];
	return x;
}
//��ʼ��PAVE����
void init_PAVE(PAVEMENT * p)
{
	p->front=p->rear=0;
}
//�ж��Ƿ�Ϊ��
int empty_PAVE(PAVEMENT * p)
{
	if(p->front==p->rear)
		return 1;
	else 
		return 0;
}
//�ж��Ƿ�Ϊ��
int full_PAVE(PAVEMENT * p)
{
	if((p->rear+1)%Max_pave==p->front)
		return 1;
	else
		return 0;
}
//���
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
//����
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
//��ʼ��CAR
void init_CAR(CAR * car)
{
	car->state='i';
	car->license_plate=(char *)malloc(sizeof(char)*8);
}
//ͣ��
void park(STOPPING * sp,PAVEMENT * pv)
{
	int st,pt;
	CAR x;
	init_CAR(&x);
	printf("�������ĳ��ƺ�:");
	fflush(stdin);
	gets(x.license_plate);
	st=sp->top;
	while(st>0)
	{
		if(!strcmp(x.license_plate,sp->STOP[--st].license_plate))
		{
			printf("��ͣ�������ƺ��Ѿ����ڣ�����������!!!\n\n");
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
			printf("�ڱ���ϳ��ƺ��Ѿ����ڣ�����������!!!\n\n");
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
		printf("����Ϊ%s����������ͣ������%d��λ\n\n",x.license_plate,sp->top);
	}
	else
	{
		push_PAVE(pv,x);
		printf("����Ϊ%s��������������%dλ�õȴ�\n\n",x.license_plate,pv->rear);
	}
}
//�뿪
void leave(STOPPING * sp,PAVEMENT * pv,BUFFER * bf)
{
	int st,find=0;
	double duration;
	CAR x,temp;
	init_CAR(&x);
	init_CAR(&temp);
	printf("�������ĳ��ƺ�:");
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
			printf("����Ϊ%s��������ͣ������δ�ҵ�,����������!!!\n",x.license_plate);
			st=sp->top;
			fflush(stdin);
			gets(x.license_plate);
		}
	}
	while(strcmp(x.license_plate,top_STOPPING(sp).license_plate))
	{
		temp=pop_STOPPING(sp);
		temp.end=time(NULL);
		printf("����Ϊ%s��������ʱ�˳�ͣ����\n\n",temp.license_plate);
		push_BUFFER(bf,temp);
	}
	temp=pop_STOPPING(sp);
	duration=difftime(temp.end,temp.begin);
	printf("����Ϊ%s������ͣ��%.2fs,һ��֧��%.2fԪ\n\n",temp.license_plate,duration,cost(duration));
	printf("����Ϊ%s��������ͣ��������\n\n",temp.license_plate);
	while(!empty_BUFFER(bf))
	{
		temp=pop_BUFFER(bf);
		push_STOPPING(sp,temp);
		printf("����Ϊ%s������ͣ��ͣ������%d��λ\n\n",temp.license_plate,sp->top);
	}
	while(!full_STOPPING(sp))
	{
		if(!empty_PAVE(pv))
		{
			temp=pop_PAVE(pv);
			time(&temp.begin);
			push_STOPPING(sp,temp);
			printf("����Ϊ%s�������ӱ���Ͻ���ͣ������%d��λ\n\n",temp.license_plate,sp->top);
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
	printf("ͣ���������:\n");
	while(st<sp->top)
	{
		time(&sp->STOP[st].end);
		duration=difftime(sp->STOP[st].end,sp->STOP[st].begin);
		printf("%d��λ---------%s:�Ѿ�ͣ��%.2f��(%.2fԪ);\n",st+1,sp->STOP[st].license_plate,duration,cost(duration));
		st++;
	}
	printf("����ϵ����:\n");
	while(pt<pv->rear)
	{
		
		printf("%dλ��---------%s;\n",pt+1,pv->PAVE[pt+1].license_plate);
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
		printf("*******************ͣ��������ϵͳ�˵�*********************\n\n");
		printf("		1->	ͣ��\n");
		printf("		2->	�뿪ͣ��λ\n");
		printf("		3->	�鿴ͣ��λ״̬\n");
		printf("		0->	�˳�\n");
		printf("**********************************************************\n");
		printf("����ѡ�");
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