#define Max 20
typedef int datatype;
typedef struct
{
	datatype vers[Max+1];
	int edges[Max+1][Max+1];
	int n,e;
}graph;
graph * create();
void prinGraph(graph * g);
int index(graph * g,int i);
void InsertLine(graph * g);
void DelLine(graph * g);