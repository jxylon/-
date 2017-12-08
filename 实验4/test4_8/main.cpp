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
		printf("1 ->病人到达\n");
		printf("2 ->护士让下一位病人就诊\n");
		printf("3 ->显示当前队伍信息\n");
		printf("0 ->退出\n");
		printf("******************\n");
		printf("输入选项:");
		fflush(stdin);
		scanf("%d",&n);
		switch(n)
		{
			case 1:
				{
					printf("输入病人名字\n");
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