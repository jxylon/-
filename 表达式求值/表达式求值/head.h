#define Maxsize 1024

typedef struct stack
{
	char elem[Maxsize];
	int top;
}sqstacktp;
typedef struct stack1
{
	float elem2[Maxsize];
	int top;
}sqstacktp2;
char top(sqstacktp * s);
int size(sqstacktp * s);
void iniStack(sqstacktp * s);
int StackEmpty(sqstacktp * s);
void push(sqstacktp * s,char x);
char pop(sqstacktp *s);
float exp_reduced();
float operate(int x,char theta,int y);
int precedence(char c);