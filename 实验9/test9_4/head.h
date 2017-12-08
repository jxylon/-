#define Max 100
typedef int datatype;
typedef struct bnodept
{
	datatype data;
	struct bnodept * lchild,*rchild;
}* bitreptr;
int searchElem(bitreptr t,bitreptr * p,bitreptr *q,datatype x);
bitreptr InsertNode(bitreptr t,datatype x);
bitreptr create();
void inorder(bitreptr t);
