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
		printf("1-> �������ͼ(�ڽӱ�)\n");
		printf("2-> Ϊ����ͼ��ӱ�\n");
		printf("3-> Ϊ����ͼɾ����\n");
		printf("0-> �˳�\n");
		printf("***********************\n");
		printf("����ѡ��:");
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