#define Max 1024
typedef struct queue
{
	int front;
	int rear;
	int data[Max];
}QUEUE;
void Menu(QUEUE * q);
int test3_5(QUEUE * q);
int test3_4(QUEUE * q);
int test3_3(QUEUE * q);
void test3_2(QUEUE * q,int num);
void test3_1(QUEUE * q);
