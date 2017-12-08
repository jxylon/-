#define Max 20
typedef int datatype;
typedef struct
{
	datatype vers[Max+1];
	int edges[Max+1][Max+1];
	int n,e;
}graph;
int visited[Max+1]={0};
graph * create();
void prinGraph(graph * g);
void dfs(graph * g,int v);