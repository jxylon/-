#define Max_stop 5
#define Max_pave 100
#include<time.h>
typedef struct
{
	char * license_plate;
	char state;//i表示初始状态，s表示在停车场，p表示在便道
	time_t begin;
	time_t end;
}CAR;
typedef struct //停车场
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
//队列基础操作
void init_PAVE(PAVEMENT * p);
int empty_PAVE(PAVEMENT * p);
int full_PAVE(PAVEMENT * p);
void push_PAVE(PAVEMENT *p,CAR car);
CAR pop_PAVE(PAVEMENT * p);
//栈基础操作
void init_STOPPING(STOPPING * sp);
int empty_STOPPING(STOPPING * sp);
int full_STOPPING(STOPPING * sp);
void push_STOPPING(STOPPING * sp,CAR car);
CAR pop_STOPPING(STOPPING * sp);
CAR top_STOPPING(STOPPING * sp);
//栈基础操作
void init_BUFFER(BUFFER * bf);
int empty_BUFFER(BUFFER * bf);
int full_BUFFER(BUFFER * bf);
void push_BUFFER(BUFFER * bf,CAR car);
CAR pop_BUFFER(BUFFER * bf);
//停车场操作
void park(STOPPING * sp,PAVEMENT * pv);
void leave(STOPPING * sp,PAVEMENT * pv,BUFFER * bf);
void Menu();
void init_CAR(CAR car);
void prin(STOPPING * sp,PAVEMENT * pv);
double cost(double d);
