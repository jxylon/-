#define Max 20
typedef struct node
{
	int child;
	struct node * next;
}cnode;
typedef struct head
{
	char data;
	cnode * child;
}* link;
typedef link tree[Max+1];
void init(tree t);
void create(tree t);
void searchChild(tree t);
void prinTree(tree t);