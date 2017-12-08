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
//求二叉树的结点数和叶子数
void test2_1(bitreptr * bt);
//按层次遍历二叉树
void test2_2(bitreptr * bt);
//求子树深度
int test2_4(bitreptr * bt);
//求二叉树中以值为x的结点为根的子树的深度
void test2_5(bitreptr * bt,int x);
//菜单函数
void Menu(bitreptr * bt);