#define Max 120
typedef struct bnodept
{
	char data;
	struct bnodept * lchild,* rchild;
}bitreptr;
void preprint(bitreptr * bt);
bitreptr * create(char *s);