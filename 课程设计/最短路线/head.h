#define Max 10
#define Max_dis 9999
typedef char * datatype;
typedef struct 
{
	datatype vers[Max+1];
	double edges[Max+1][Max+1];
	int n,e;
}graph;
void readFile(graph * g);
double prim(graph * g);
void Menu();
void prinWay(graph * g);