#include"head.h"
#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	lqueuetp * lq=(lqueuetp *)malloc(sizeof(lqueuetp));
	init(lq);
	char str[20];
	int n=1;
	while(n)
	{
		printf("******************\n");
		printf("1 ->���˵���\n");
		printf("2 ->��ʿ����һλ���˾���\n");
		printf("3 ->��ʾ��ǰ������Ϣ\n");
		printf("0 ->�˳�\n");
		printf("******************\n");
		printf("����ѡ��:");
		fflush(stdin);
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				{
					printf("���벡������\n");
					fflush(stdin);
					gets(str);
					enQueue(lq,str);
				}break;
			case 2:
				{
					delQueue(lq);
				}break;
			case 3:
				{
					print(lq);
				}break;
		}
	}
	return 0;
}