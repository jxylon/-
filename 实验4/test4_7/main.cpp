#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	int flag;
	char str[MAX];
	STACK * s=(STACK *)malloc(sizeof(STACK));
	printf("������Ҫ�򿪵ĳ����ļ�\n");
	gets(str);
	initStack(s);
	flag=readFile(s,str);
	printf("˳��ջ����:");
	if(flag==0)
		printf("ƥ���޴���\n");
	else if(flag==1)
		printf("�����Ŷ�\n");
	else printf("�����Ŷ�\n");
	LinkStack * ls=(LinkStack *)malloc(sizeof(LinkStack));
	test2_1(ls);
	flag=readFile2(ls,str);
	printf("��ջ����:");
	if(flag==0)
		printf("ƥ���޴���\n");
	else if(flag==1)
		printf("�����Ŷ�\n");
	else printf("�����Ŷ�\n");
	return 0;
}