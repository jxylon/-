#define Max 10
typedef struct node
{
	int i,j,value;
}Node;
typedef struct
{
	int mu,nu,tu;
	Node data[Max];
}mat;
mat * add(mat * A,mat * B);
mat * sub(mat * A,mat * B);
mat * mul(mat *A,mat *B);
void print(mat * A);