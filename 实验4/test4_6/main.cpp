#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	char str[MAX];
	printf("����һ���ַ���:");
	gets(str);
	printf("˳��ջ����:");
	if(test6_1(str)==1)
		printf("���ַ����ǻ���\n");
	else printf("���ַ������ǻ���\n");
	printf("��ջ����:");
	if(test6_2(str)==1)
		printf("���ַ����ǻ���\n");
	else printf("���ַ������ǻ���\n");
	return 0;
}