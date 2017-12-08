#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	char str[MAX];
	printf("输入一串字符串:");
	gets(str);
	printf("顺序栈方法:");
	if(test6_1(str)==1)
		printf("该字符串是回文\n");
	else printf("该字符串不是回文\n");
	printf("链栈方法:");
	if(test6_2(str)==1)
		printf("该字符串是回文\n");
	else printf("该字符串不是回文\n");
	return 0;
}