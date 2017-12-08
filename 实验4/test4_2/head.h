#define MAX 1024
typedef struct link//Á´Õ» ´æ·Åint
{
	int info;
	struct link * next;
}Link;
typedef struct
{
	Link * top;
}LinkStack;
void test2_1(LinkStack * ls);
int test2_2(LinkStack * ls);
void test2_3(LinkStack * ls,int num);
int test2_4(LinkStack * ls);
int test2_5(LinkStack * ls);
void print2(LinkStack * ls);
void menu(LinkStack * ls);