#define Max 20
typedef int datatype;
typedef struct edge
{
	int tail;
	struct edge * next;
}arc;
typedef struct 
{
	datatype data;
	arc * firstArc;
}ptr;
typedef struct 
{
	ptr * vers[Max+1];
	int n,e;
}graph;
typedef struct NODE
{
	int data;
	struct NODE * next;
}node;
typedef struct 
{
	node * raer;
	node * front;
}lqueuetp;
int visited[Max+1]={0};
graph * create();
void prinGraph(graph * g);
void init(lqueuetp * lq);
int empty(lqueuetp * lq);
int dequeue(lqueuetp * lq);
void enqueue(lqueuetp * lq,int a);
void bfs(graph * g,int v);