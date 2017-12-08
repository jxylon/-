#define MAX 1024
typedef struct stack
{
	int top;
	char data[MAX];
}STACK;
typedef struct link//Á´Õ» ´æ·Åint
{
	char info;
	struct link * next;
}Link;
typedef struct
{
	Link * top;
}LinkStack;
int readFile(STACK *s,char str[]);
void initStack(STACK *s);
void push(STACK *s,char c);
char pop(STACK *s);

void test2_1(LinkStack * ls);
char test2_4(LinkStack * ls);
void test2_3(LinkStack * ls,char num);
int readFile2(LinkStack *ls,char str[]);