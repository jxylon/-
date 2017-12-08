#define Max 20
typedef struct bnodept
{
	char data;
	struct bnodept * lchild,* rchild;
}bitreptr;
//先序遍历创建树
bitreptr * create_bnode();
//先序遍历输出树
void preprint(bitreptr * bt);
//交换左右子树
void changeRLBit(bitreptr * bt);
//单孩子结点的个数
int singleChild(bitreptr * bt);