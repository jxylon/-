#define MAX 1024
typedef struct stack//À≥–Ú’ª ¥Ê∑≈int
{
	int data[MAX];
	int top;
}STACK;
void test1_1(STACK * s);
int test1_2(STACK *s);
void test1_3(STACK *s,int num);
int test1_4(STACK *s);
int test1_5(STACK *s);
int test1_6(STACK *s);
void print1(STACK *s);
void menu(STACK * s);