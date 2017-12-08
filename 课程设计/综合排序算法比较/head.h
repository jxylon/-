#define Max 900000
typedef struct
{
	int key;
	int no;
}rectype;
typedef struct
{
	rectype data[Max+1];
	double compare,move;
	clock_t begin,end;
}seqlist;
//快速排序算法 递归实现
void quicksort(seqlist * t,int low,int high);
//快速排序算法 找到i的最终位置
int partition(seqlist * r,int i,int j);
//直接插入算法
void insert(seqlist * t,int n);
//冒泡排序
void mppx(seqlist * r,int n);
//简单直接选择排序
void zjxz(seqlist * r,int n);
//希尔排序
void shell(seqlist * r,int n);
//归并算法排序 一趟归并算法
void ytgb(int s,int n,seqlist * r,seqlist * t);
//归并算法排序 合并
void hb(seqlist * r,int h,int m,int w,seqlist * t);
//归并算法排序 两两归并算法
void llgbpx(seqlist * r,int n);
//堆排序 筛选算法
void dpx(seqlist * r,int n);
//堆排序
void sxf(seqlist * r,int t,int w);
//写文件
void writeFile(int n);
//读文件
void readFile(seqlist * r,char * s);
//主菜单
void Menu();
//初始化顺序表
seqlist * initSeqlist();
//六种排序运行
void sort(seqlist * r1,seqlist * r2,seqlist * r3,seqlist * r4,seqlist * r5,seqlist * r6,int num);
//存储性能
void store(seqlist * r1,seqlist * r2,seqlist * r3,seqlist * r4,seqlist * r5,seqlist * r6,double info[6][3]);
