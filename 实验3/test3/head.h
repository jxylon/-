#define Maxline 1024
typedef struct sql
{
	int arr[Maxline];
	int len;
}sqlist;
typedef struct node1
{
	char c;
	struct node1 * next;
}LinkNode1,* LinkList1;
typedef struct node2
{
	int k;
	struct node2 * next;
}LinkNode2,* LinkList2;
typedef struct node3
{
	int k;
	struct node3 * next;
	struct node3 * prior;
}LinkNode3,* LinkList3;
typedef struct node
{
	int exp;
	float coef;
	struct node *next;
}polynode;
/*******************************Á·Ï°1*/
void test1Menu(sqlist * L);
int test1_9(sqlist * L,int flag);
int test1_8(sqlist * L,int i,int num);
void test1_7(sqlist * L,int key);
void test1_6(sqlist * L,int key);
void test1_5(sqlist * L,int num);
int test1_4(sqlist * L,int i);
int test1_3(sqlist * L,int i);
void test1_2(sqlist * L);
void test1_1(sqlist *L);
int create(sqlist * L);
/*******************************Á·Ï°2*/
void test2_1(LinkList1 head);
void test2_2(LinkList1 head);
char test2_3(LinkList1 head,int i);
void test2_4(LinkList1 head,int i);
void test2_5(LinkList1 head,char key);
void test2_6(LinkList1 head,char key);
void test2_7(LinkList1 head,char key);
void test2_8(LinkList1 head,char key,int i);
int test2_9(LinkList1 head,char key);
LinkList1 createLink();
void test2Menu(LinkList1 head);
/*******************************Á·Ï°3*/
LinkList2 createLink2();
void test3_1(LinkList2 head);
void test3_2(LinkList2 head);
int test3_3(LinkList2 head,int i);
LinkList2 test3_4(LinkList2 head,int i);
LinkList2 test3_5(LinkList2 head,int key);
void test3_6(LinkList2 head,int key);
void test3_7(LinkList2 head,int key);
void test3_8(LinkList2 head,int key,int i);
int test3_9(LinkList2 head,int key);
void test3Menu(LinkList2 head);
/*******************************Á·Ï°4*/
LinkList3 createLink3();
void test4Menu(LinkList3 head);
void test4_1(LinkList3 head);
void test4_2(LinkList3 head);
int test4_3(LinkList3 head,int i);
int test4_4(LinkList3 head,int i);
int test4_5(LinkList3 head,int flag);
void test4_6(LinkList3 head,int key);
void test4_7(LinkList3 head,int key);
int test4_8(LinkList3 head,int key,int i);
int test4_9(LinkList3 head,int key);

void addPoly(polynode * pa,polynode * pb);
void print(polynode * pa);
polynode * createPoly();