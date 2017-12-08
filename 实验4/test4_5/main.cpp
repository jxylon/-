#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	Node * head=(Node *)malloc(sizeof(Node));
	head->next=NULL;
	createLink(head);
	printf("顺序栈方法:");
	test5_1(head);
	print(head);
	printf("链栈方法:");
	test5_2(head);
	print(head);
	return 0;
}