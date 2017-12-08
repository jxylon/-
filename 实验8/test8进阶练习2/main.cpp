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
		printf("1-> 输出有向图\n");
		printf("2-> 对有向图广度优先搜索\n");
		printf("0-> 退出\n");
		printf("***********************\n");
		printf("输入选项:");
		scanf("%d",&i);
		switch(i)
		{
		case 1:prinGraph(g);break;
		case 2:
			{
				bfs(g,1);
				printf("\n");
			}break;
		}
	}
	return 0;
}