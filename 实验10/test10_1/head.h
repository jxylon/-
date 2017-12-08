#define m 100
typedef struct
{
	int key;
	int no;
}rectype;
typedef rectype seqlist[m];
void quicksort(seqlist t,int low,int high);
int partition(seqlist r,int i,int j);
