#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	int flag;
	char str[MAX];
	STACK * s=(STACK *)malloc(sizeof(STACK));
	printf("输入你要打开的程序文件\n");
	gets(str);
	initStack(s);
	flag=readFile(s,str);
	printf("顺序栈方法:");
	if(flag==0)
		printf("匹配无错误\n");
	else if(flag==1)
		printf("右括号多\n");
	else printf("左括号多\n");
	LinkStack * ls=(LinkStack *)malloc(sizeof(LinkStack));
	test2_1(ls);
	flag=readFile2(ls,str);
	printf("链栈方法:");
	if(flag==0)
		printf("匹配无错误\n");
	else if(flag==1)
		printf("右括号多\n");
	else printf("左括号多\n");
	return 0;
}