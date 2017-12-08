#include<stdio.h>
#include<stdlib.h>
#include"head.h"
int main(void)
{
	int i=1;
	graph * g;
	g=create();
	while(i)
	{
		printf("***********************\n");
		printf("1-> 输出有向图(邻接表)\n");
		printf("2-> 为有向图添加边\n");
		printf("3-> 为有向图删除边\n");
		printf("0-> 退出\n");
		printf("***********************\n");
		printf("输入选项:");
		scanf("%d",&i);
		switch(i)
		{
		case 1:prinGraph(g);break;
		case 2:InsertLine(g);break;
		case 3:DelLine(g);break;
		}
	}
	return 0;
}