typedef struct date
{
	int year;
	int month;
	int day;
}date;
typedef struct bnodept
{
	date data;
	struct bnodept * lchild,* rchild;
}* bitreptr;
//队列
typedef struct node
{
	bitreptr data;
	struct node * next;
}Node;
typedef struct
{
	Node * front;
	Node * rear;
}lqueuetp;
//判断下一天和下一个月
int nextDate(date * nextD,date * nextM,date d);

bitreptr create(date d);

void prinTree(bitreptr t);

int isEmpty(lqueuetp * lq);

bitreptr popLq(lqueuetp * lq);

void pushLq(lqueuetp * lq,bitreptr num);

void initLq(lqueuetp * lq);

int deepth(bitreptr bt);

int travel(bitreptr bt,int level,date d);

date rearLq(lqueuetp * lq);

int equalDate(date d1,date d2);