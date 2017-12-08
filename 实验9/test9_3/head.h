#define Max 1024
typedef struct
{
	int elem[Max];
	int length;
}tbl;
int binary_search(tbl * tb,int low,int high,int x);