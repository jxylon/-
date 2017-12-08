#define MAX 1024
typedef struct stackC//À≥–Ú’ª ¥Ê∑≈char
{
	char c[MAX];
	int top;
}STACKC;
typedef struct linkC//¡¥’ª ¥Ê∑≈char
{
	char info;
	linkC * next;
}LinkC;
typedef struct
{
	LinkC * top;
}LinkStackC;
int test6_1(char * p);
int test6_2(char * p);