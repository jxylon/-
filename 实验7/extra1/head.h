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
//中序遍历输出树
void inprint(bitreptr * bt);
//后序遍历输出树
void postprint(bitreptr * bt);
//菜单函数
void Menu(bitreptr * bt);