#define Max 20
typedef int datatype;
typedef struct
{
	int top;
	int data[Max];
}stack;
typedef struct edge
{
	int tail;
	struct edge * next;
}arc;
typedef struct 
{
	datatype data;
	arc * firstArc;
	int indegree;
}ptr;
typedef struct 
{
	ptr * vers[Max+1];
	int n,e;
}graph;
graph * create();
void prinGraph(graph * g);
void topSort(graph * g);
void initStack(stack * s);