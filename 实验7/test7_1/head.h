typedef struct node
{
	char data;
	struct node * lchild,*rchild;
}bnode;
typedef struct node * blink;
blink add(blink bt,char ch);
void inorder(blink bt);