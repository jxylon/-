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
		printf("1-> �������ͼ\n");
		printf("2-> ������ͼ�����������\n");
		printf("0-> �˳�\n");
		printf("***********************\n");
		printf("����ѡ��:");
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