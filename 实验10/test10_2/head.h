#define m 100
typedef struct
{
	int key;
	int no;
}rectype;
typedef rectype seqlist[m];
void quicksort(seqlist t,int low,int high);
int partition(seqlist r,int i,int j);
void insert(seqlist t,int n);
void mppx(seqlist r,int n);
void zjxz(seqlist r,int n);