#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"head.h"
void Menu()
{
	//r1,r2,r3,r4,r5,r6分别是各类算法的结构指针
	seqlist * r1,* r2,* r3,* r4,* r5,* r6;
	//n总菜单选项，m文件菜单选项，num为文件的整数个数
	int n=1,m=1,num;
	//文件名
	char * s;		
	//info存储之前各类算法的比较次数，移动次数，运行时间，duration为时间差
	double info[6][3]={0},duration[6];
	s=(char *)malloc(sizeof(char)*6);
	while(n)
	{
		printf("\t\t\t\t\t*******************综合排序算法菜单**********************\n");
		printf("\t\t\t\t\t*		1->	读取文件			*\n");
		printf("\t\t\t\t\t*		2->	进行排序			*\n");
		printf("\t\t\t\t\t*		3->	查看结果			*\n");
		printf("\t\t\t\t\t*		0->	退出				*\n");
		printf("\t\t\t\t\t*********************************************************\n");
		printf("输入选项：");
		fflush(stdin);
		scanf("%d",&n);
		switch(n)
		{
		case 1:
			{
						//对r1,r2,r3,r4,r5,r6初始化
						r1=initSeqlist();
						r2=initSeqlist();
						r3=initSeqlist();
						r4=initSeqlist();
						r5=initSeqlist();
						r6=initSeqlist();
						//清屏
						system("cls");
						printf("\t\t\t\t\t***********************文件选项**************************\n");
						printf("\t\t\t\t\t*		1->	50000个整数->data1.txt		*\n");
						printf("\t\t\t\t\t*		2->	60000个整数->data2.txt		*\n");
						printf("\t\t\t\t\t*		3->	70000个整数->data3.txt		*\n");
						printf("\t\t\t\t\t*		4->	80000个整数->data4.txt		*\n");
						printf("\t\t\t\t\t*		5->	90000个整数->data5.txt		*\n");
						printf("\t\t\t\t\t*		0->		返回			*\n");
						printf("\t\t\t\t\t*********************************************************\n");
						printf("输入选项：");
						fflush(stdin);
						scanf("%d",&m);
						num=50000+10000*(m-1);
						//选择文件
						switch(m)
						{
						case 1:s="data1.txt";break;
						case 2:s="data2.txt";break;
						case 3:s="data3.txt";break;
						case 4:s="data4.txt";break;
						case 5:s="data5.txt";break;
						default:break;
						}
						//当m！=0读取文件
						if(m!=0)
						{
							readFile(r1,s);
							readFile(r2,s);
							readFile(r3,s);
							readFile(r4,s);
							readFile(r5,s);
							readFile(r6,s);
							printf("读取文件成功!!!\n\n");
						}
			}break;
		case 2:sort(r1,r2,r3,r4,r5,r6,num);break;
		case 3:
			{
				duration[0]=(double)(r1->end - r1->begin) / CLOCKS_PER_SEC;
				duration[1]=(double)(r2->end - r2->begin) / CLOCKS_PER_SEC;
				duration[2]=(double)(r3->end - r3->begin) / CLOCKS_PER_SEC;
				duration[3]=(double)(r4->end - r4->begin) / CLOCKS_PER_SEC;
				duration[4]=(double)(r5->end - r5->begin) / CLOCKS_PER_SEC;
				duration[5]=(double)(r6->end - r6->begin) / CLOCKS_PER_SEC;
				system("cls");
				printf("\t\t\t\t\t*******************%d个整数排序结果***********************\n",num);
				printf("比较项  		 移动次数(同上次对比)				比较次数(同上次对比)				运行时间(s)(同上次对比)\n\n");
				printf("直接插入		%10.0lf(%.2lf%%)				%10.0lf(%.2lf%%)				%10.4lf(%.2lf%%)\n\n",r1->compare,100*(r1->compare-info[0][0])/r1->compare,r1->move,100*(r1->move-info[0][1])/r1->move,duration[0],100*(duration[0]-info[0][2])/duration[0]);
				printf("冒泡排序		%10.0lf(%.2lf%%)				%10.0lf(%.2lf%%)				%10.4lf(%.2lf%%)\n\n",r2->compare,100*(r2->compare-info[1][0])/r2->compare,r2->move,100*(r2->move-info[1][1])/r2->move,duration[1],100*(duration[1]-info[1][2])/duration[1]);
				printf("选择排序		%10.0lf(%.2lf%%)				%10.0lf(%.2lf%%)				%10.4lf(%.2lf%%)\n\n",r3->compare,100*(r3->compare-info[2][0])/r3->compare,r3->move,100*(r3->move-info[2][1])/r3->move,duration[2],100*(duration[2]-info[2][2])/duration[2]);
				printf("快速排序		%10.0lf(%.2lf%%)				%10.0lf(%.2lf%%)				%10.4lf(%.2lf%%)\n\n",r4->compare,100*(r4->compare-info[3][0])/r4->compare,r4->move,100*(r4->move-info[3][1])/r4->move,duration[3],100*(duration[3]-info[3][2])/duration[3]);
				printf("堆排序			%10.0lf(%.2lf%%)				%10.0lf(%.2lf%%)				%10.4lf(%.2lf%%)\n\n",r5->compare,100*(r5->compare-info[4][0])/r5->compare,r5->move,100*(r5->move-info[4][1])/r5->move,duration[4],100*(duration[4]-info[4][2])/duration[4]);
				printf("归并排序		%10.0lf(%.2lf%%)				%10.0lf(%.2lf%%)				%10.4lf(%.2lf%%)\n\n",r6->compare,100*(r6->compare-info[5][0])/r6->compare,r6->move,100*(r6->move-info[5][1])/r6->move,duration[5],100*(duration[5]-info[5][2])/duration[5]);
				store(r1,r2,r3,r4,r5,r6,info);
			}break;
		default:break;
		}
	}
}
//存储文件的各类信息
void store(seqlist * r1,seqlist * r2,seqlist * r3,seqlist * r4,seqlist * r5,seqlist * r6,double info[6][3])
{
	info[0][0]=r1->compare;
	info[0][1]=r1->move;
	info[0][2]=(double)(r1->end - r1->begin) / CLOCKS_PER_SEC;
	info[1][0]=r2->compare;
	info[1][1]=r2->move;
	info[1][2]=(double)(r2->end - r2->begin) / CLOCKS_PER_SEC;
	info[2][0]=r3->compare;
	info[2][1]=r3->move;
	info[2][2]=(double)(r3->end - r3->begin) / CLOCKS_PER_SEC;
	info[3][0]=r4->compare;
	info[3][1]=r4->move;
	info[3][2]=(double)(r4->end - r4->begin) / CLOCKS_PER_SEC;
	info[4][0]=r5->compare;
	info[4][1]=r5->move;
	info[4][2]=(double)(r5->end - r5->begin) / CLOCKS_PER_SEC;
	info[5][0]=r6->compare;
	info[5][1]=r6->move;
	info[5][2]=(double)(r6->end - r6->begin) / CLOCKS_PER_SEC;
}
//对序列进行六种排序方法的排序
void sort(seqlist * r1,seqlist * r2,seqlist * r3,seqlist * r4,seqlist * r5,seqlist * r6,int num)
{
	//正在进行直接插入排序!!!
	printf("正在进行直接插入排序!!!\n\n");
	r1->begin=clock();
	insert(r1,num);
	r1->end=clock();
	printf("完成!\n\n");
	//正在进行冒泡排序!!!
	printf("正在进行冒泡排序!!!\n\n");
	r2->begin=clock();
	mppx(r2,num);
	r2->end=clock();
	printf("完成!\n\n");
	//正在进行选择排序!!!
	printf("正在进行选择排序!!!\n\n");
	r3->begin=clock();
	zjxz(r3,num);
	r3->end=clock();
	printf("完成!\n\n");
	//正在进行快速排序!!!
	printf("正在进行快速排序!!!\n\n");
	r4->begin=clock();
	quicksort(r4,1,num);
	r4->end=clock();
	printf("完成!\n\n");
	//正在进行堆排序!!!
	printf("正在进行堆排序!!!\n\n");
	r5->begin=clock();
	dpx(r5,num);
	r5->end=clock();
	printf("完成!\n\n");
	//正在进行归并排序!!!
	printf("正在进行归并排序!!!\n\n");
	r6->begin=clock();
	llgbpx(r6,num);
	r6->end=clock();
	printf("完成!\n\n");
}
//初始化seqlist
seqlist * initSeqlist()
{
	seqlist * r;
	r=(seqlist *)malloc(sizeof(seqlist));
	r->compare=0;
	r->move=0;
	return r;
}
//读取文件
void readFile(seqlist * r,char * s)
{
	int i=1;
	FILE * fp=NULL;
	fp=fopen("data1.txt","r");
	if(fp==NULL)
		return ;
	while(!feof(fp))
	{
		r->data[i].no=i;
		fscanf(fp,"%d ",&r->data[i].key);
		i++;
	}
	fclose(fp);
}
//写随机数进文件
void writeFile(int n)
{
	FILE * fp=NULL;
	unsigned seed=time(NULL);
	int i,t;
	srand(seed);
	fp=fopen("data1.txt","w");
	if(fp==NULL)
	{
		printf("打开文件失败\n");
		return ;
	}
	else
	{
		for(i=1;i<=n;i++)
		{
		//	printf("输入序号和关键字:");
		//	fflush(stdin);
			t=rand()%n+1;
			fprintf(fp,"%d ",t);
		}
	}
	fclose(fp);
}
//快速排序算法 找到i的最终位置
int partition(seqlist * r,int i,int j)
{
	//pivot为进行排序的元素
	rectype pivot=r->data[i];
	//进行一趟排序，直到i=j结束
	while(i<j)
	{
		while(i<j&&r->data[j].key>=pivot.key)//向左扫描，直到找到比pivot的关键字小的元素
		{
			//比较次数加一
			r->compare++;
			j--;
		}
		//比较次数加一
		r->compare++;
		if(i<j)
		{
			r->move++;
			//data[i]与data[j]交换,i指向下一个元素
			r->data[i]=r->data[j];
			i++;
		}
		while(i<j&&r->data[i].key<=pivot.key)//向右扫描，知道找到比pivot的关键字大的元素
		{
			//比较次数加一
			r->compare++;
			i++;
		}
		if(i<j)
		{
			//data[i]与data[j]交换,j指向前一个元素
			r->data[j]=r->data[i];
			r->move++;
			j--;
		}
	}
	r->data[i]=pivot;
	r->move++;
	return i;
}
//快速排序算法 递归实现
void quicksort(seqlist * t,int low,int high)
{
	int pivotpos;
	if(low<high)
	{
		t->compare++;
		pivotpos=partition(t,low,high);
		quicksort(t,low,pivotpos-1);
		quicksort(t,pivotpos+1,high);
	}
}
//直接插入算法 带监视哨
void insert(seqlist * r,int n)
{
	int i,j;
	for(i=2;i<=n;i++)
	{
		r->data[0]=r->data[i];
		r->move++;
		j=i-1;
		while(r->data[0].key<r->data[j].key)
		{
			r->compare++;
			r->data[j+1]=r->data[j];
			r->move++;
			j--;
		}
		r->data[j+1]=r->data[0];
		r->move++;
	}
}
//冒泡排序
void mppx(seqlist * r,int n)
{
	int i,j,k;
	rectype x;
	i=1;
	k=1;
	while(i<n&&k>0)
	{
		k=0;
		for(j=1;j<=n-i;j++)
		{
			r->compare++;
			if(r->data[j+1].key<r->data[j].key)
			{
				k++;
				x=r->data[j];
				r->data[j]=r->data[j+1];
				r->data[j+1]=x;
				r->move+=3;
			}
		}
	}
}
//简单直接选择排序
void zjxz(seqlist * r,int n)
{
	int i,j,k;
	rectype x;
	for(i=1;i<n;i++)
	{
		k=i;
		for(j=i+1;j<=n;j++)
		{
			r->compare++;
			if(r->data[j].key<r->data[k].key)
			{
				k=j;
			}
		}
		r->compare++;
		if(i!=k)
		{
			x=r->data[i];
			r->data[i]=r->data[k];
			r->data[k]=x;
			r->move+=3;
		}
	}
}
//希尔排序
void shell(seqlist * r,int n)
{
	rectype x;
	int i,j,d;
	d=n/2;
	while(d>=1)
	{
		for(i=d+1;i<=n;i++)
		{
			x=r->data[i];
			r->move++;
			j=i-d;
			while(j>0&&x.key<r->data[j].key)
			{
				r->compare++;
				r->data[j+d]=r->data[j];
				r->move++;
				j=j-d;
			}
			r->data[j+d]=x;
			r->move++;
		}
		d=d/2;
	}
}
//归并算法排序 合并
void hb(seqlist * r,int h,int m,int w,seqlist * t)
{
	int i,j,k;
	i=h;
	j=m+1;
	k=h-1;
	while(i<=m&&j<=w)
	{
		k++;
		r->compare++;
		if(r->data[i].key<=r->data[j].key)
		{
			t->data[k]=r->data[i++];
			r->compare++;
			r->move++;
		}
		else
		{
			t->data[k]=r->data[j++];
			r->move++;
		}
	}
	r->compare++;
	if(i>m)
	{
		while(j<=w)
		{
			r->compare++;
			t->data[++k]=r->data[j++];
			r->move++;
		}
	}
	else
		while(i<=m)
		{
			r->compare++;
			t->data[++k]=r->data[i++];
			r->move++;
		}
}
//归并算法排序 一趟归并算法
void ytgb(int s,int n,seqlist * r,seqlist * t)
{
	int i=1;
	while(i<=(n-2*s+1))
	{
		r->compare++;
		hb(r,i,i+s-1,i+2*s-1,t);
		i=i+2*s;
	}
	r->compare++;
	if(i<(n-s+1))
		hb(r,i,i+s-1,n,t);
	else
		while(i<=n)
		{
			r->compare++;
			t->data[i]=r->data[i++];
		}
}
//归并算法排序 两两归并算法
void llgbpx(seqlist * r,int n)
{
	int i,s=1;
	seqlist * t;
	t=(seqlist *)malloc(sizeof(seqlist));
	while(s<n)
	{
		r->compare++;
		ytgb(s,n,r,t);
		s=s*2;
		r->compare++;
		if(s<n)
		{
			ytgb(s,n,r,t);
			s=s*2;
		}
		else
		{
			i=1;
			while(i<=n)
			{
				r->data[i]=t->data[i++];
				r->compare++;
			}
		}
	}
}
//堆排序 筛选算法
void sxf(seqlist * r,int t,int w)
{
	int i,j;
	rectype x;
	i=t;
	x=r->data[i];
	r->move++;
	j=2*i;
	while(j<=w)
	{
		r->compare+=2;
		if((j<w)&&r->data[j].key>r->data[j+1].key)
			j++;
		if(x.key>r->data[j].key)
		{
			r->data[i]=r->data[j];
			i=j;
			j=j*2;
		}
		else
			j=w+1;
	}
	r->data[i]=x;
	r->move++;
}
//堆排序
void dpx(seqlist * r,int n)
{
	int i;
	rectype x;
	for(i=n/2;i>=1;i--)
	{
		sxf(r,i,n);
		r->compare++;
	}
	for(i=n;i>=2;i--)
	{
		r->compare++;
		x=r->data[1];
		r->data[1]=r->data[i];
		r->data[i]=x;
		r->move+=3;
		sxf(r,1,i-1);
	}
}
