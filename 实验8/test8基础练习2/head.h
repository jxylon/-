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
graph * create();
void prinGraph(graph * g);
void InsertLine(graph * g);
void DelLine(graph * g);
