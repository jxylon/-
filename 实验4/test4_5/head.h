#define MAX 1024
typedef struct stack//À≥–Ú’ª ¥Ê∑≈int
{
	int data[MAX];
	int top;
}STACK;
typedef struct link//¡¥’ª ¥Ê∑≈int
{
	int info;
	struct link * next;
}Link;
typedef struct
{
	Link * top;
}LinkStack;
typedef struct node//¡¥±Ì
{
	int a;
	struct node * next;
}Node;
void test1_1(STACK * s);
int test1_2(STACK *s);
void test1_3(STACK *s,int num);
int test1_4(STACK *s);
int test1_5(STACK *s);
int test1_6(STACK *s);
void print1(STACK *s);
void test2_1(LinkStack * ls);
int test2_2(LinkStack * ls);
void test2_3(LinkStack * ls,int num);
int test2_4(LinkStack * ls);
int test2_5(LinkStack * ls);
void print2(LinkStack * ls);
void test5_2(Node * head);
void test5_1(Node * head);
void createLink(Node * head);
void print(Node * head);