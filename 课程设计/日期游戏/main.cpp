#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"head.h"
int main(void)
{
	int year=1,month,day,i,j=1,n;
	unsigned seed=time(NULL);
	srand(seed);
	date d,sd;//d为输入的日期，sd为目标日期
	sd.year=2001;
	sd.month=11;
	sd.day=4;
	while(j)
	{
		int monthDay[12]={31,28,31,30,31,30,31,31,30,31,30,31};
		bitreptr bt=NULL;
		printf("\t\t\t\t\t***********************选项**************************\n");
		printf("\t\t\t\t\t*		1->	手动输入		    *\n");
		printf("\t\t\t\t\t*		2->	随机生成日期		    *\n");
		printf("\t\t\t\t\t*		0->	返回			    *\n");
		printf("\t\t\t\t\t*****************************************************\n");
		printf("输入选项:");
		fflush(stdin);
		scanf("%d",&n);
		switch(n)
		{
		case 1:
			{
				printf("输入年月日:");
				scanf("%d %d %d",&year,&month,&day);
			}break;
		case 2:
			{
				printf("预先设定的日期:");
				year=rand()%102+1900;
				month=rand()%12+1;
				day=rand()%31+1;
				printf("%d年%d月%d日\n",year,month,day);
			}break;
		default:j=0;break;
		}
		if(j==1)
		{
			if(year%4==0||(year%100==0&&year%400==0))
				monthDay[1]+=1;
			if(year>2001||year<1900)
			{
				printf("输入的年份错误!\n");
				fflush(stdin);
				scanf("%d %d %d",&year,&month,&day);
				continue;
			}
			else if(year==2001&&month>11)
			{
				printf("输入的月份错误!\n");
				fflush(stdin);
				scanf("%d %d %d",&year,&month,&day);
				continue;
			}
			else if(year==2001&&month==11&&day>4)
			{
				printf("输入的日期错误!\n");
				fflush(stdin);
				scanf("%d %d %d",&year,&month,&day);
				continue;
			}
			if(day>monthDay[month-1])
			{
				printf("输入的日期错误!\n");
				fflush(stdin);
				scanf("%d %d %d",&year,&month,&day);
				continue;
			}
			d.day=day;
			d.month=month;
			d.year=year;
			//特殊处理
			if(d.year<2001)
				d.year=2000;
			if(year<2001&&(day<=4||month<=10))
			{
				d.year=2001;
			}
			if(day>=4&&day<=15)
				d.day+=10;
			//创建二叉树
			bt=create(d);
			prinTree(bt);
			i=travel(bt,1,sd);
			if(i%2==0)
				printf("\nYES!!!\n");
			else
				printf("\nNO!!!\n");
			fflush(stdin);
			getchar();
			free(bt);
		}
	}
	return 0;
}
