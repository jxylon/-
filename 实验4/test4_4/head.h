typedef struct node
{
	int data;
	struct node * next;
}Node;
typedef struct
{
	Node * front;
	Node * rear;
}lqueuetp;
void print(lqueuetp * lq);
int test4_4(lqueuetp * lq);
int test4_3(lqueuetp * lq);
void test4_2(lqueuetp * lq,int num);
void test4_1(lqueuetp * lq);
void Menu(lqueuetp * lq);