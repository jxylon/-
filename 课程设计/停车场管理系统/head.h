#define Max_stop 5
#define Max_pave 100
#include<time.h>
typedef struct
{
	char * license_plate;
	char state;//i��ʾ��ʼ״̬��s��ʾ��ͣ������p��ʾ�ڱ��
	time_t begin;
	time_t end;
}CAR;
typedef struct //ͣ����
{
	CAR STOP[Max_stop];
	int top;
}STOPPING;
typedef struct
{
	CAR PAVE[Max_pave];
	int rear,front;
}PAVEMENT;
typedef struct
{
	CAR BUFF[Max_stop];
	int top;
}BUFFER;
//���л�������
void init_PAVE(PAVEMENT * p);
int empty_PAVE(PAVEMENT * p);
int full_PAVE(PAVEMENT * p);
void push_PAVE(PAVEMENT *p,CAR car);
CAR pop_PAVE(PAVEMENT * p);
//ջ��������
void init_STOPPING(STOPPING * sp);
int empty_STOPPING(STOPPING * sp);
int full_STOPPING(STOPPING * sp);
void push_STOPPING(STOPPING * sp,CAR car);
CAR pop_STOPPING(STOPPING * sp);
CAR top_STOPPING(STOPPING * sp);
//ջ��������
void init_BUFFER(BUFFER * bf);
int empty_BUFFER(BUFFER * bf);
int full_BUFFER(BUFFER * bf);
void push_BUFFER(BUFFER * bf,CAR car);
CAR pop_BUFFER(BUFFER * bf);
//ͣ��������
void park(STOPPING * sp,PAVEMENT * pv);
void leave(STOPPING * sp,PAVEMENT * pv,BUFFER * bf);
void Menu();
void init_CAR(CAR car);
void prin(STOPPING * sp,PAVEMENT * pv);
double cost(double d);
