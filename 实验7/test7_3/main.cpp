#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	char s[Max];
	printf("�����ַ���,(.)��ʾ��\n");
	scanf("%s",s);
	bitreptr * bt=create(s);
	preprint(bt);
	return 0;
}