typedef struct node
{
	char data[20];
	struct node * next;
}Node;
typedef struct
{
	Node * front;
	Node * rear;
}lqueuetp;
void print(lqueuetp * lq);
void enQueue(lqueuetp * lq,char str[]);
void delQueue(lqueuetp * lq);
void init(lqueuetp * lq);
