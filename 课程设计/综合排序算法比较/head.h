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
//���������㷨 �ݹ�ʵ��
void quicksort(seqlist * t,int low,int high);
//���������㷨 �ҵ�i������λ��
int partition(seqlist * r,int i,int j);
//ֱ�Ӳ����㷨
void insert(seqlist * t,int n);
//ð������
void mppx(seqlist * r,int n);
//��ֱ��ѡ������
void zjxz(seqlist * r,int n);
//ϣ������
void shell(seqlist * r,int n);
//�鲢�㷨���� һ�˹鲢�㷨
void ytgb(int s,int n,seqlist * r,seqlist * t);
//�鲢�㷨���� �ϲ�
void hb(seqlist * r,int h,int m,int w,seqlist * t);
//�鲢�㷨���� �����鲢�㷨
void llgbpx(seqlist * r,int n);
//������ ɸѡ�㷨
void dpx(seqlist * r,int n);
//������
void sxf(seqlist * r,int t,int w);
//д�ļ�
void writeFile(int n);
//���ļ�
void readFile(seqlist * r,char * s);
//���˵�
void Menu();
//��ʼ��˳���
seqlist * initSeqlist();
//������������
void sort(seqlist * r1,seqlist * r2,seqlist * r3,seqlist * r4,seqlist * r5,seqlist * r6,int num);
//�洢����
void store(seqlist * r1,seqlist * r2,seqlist * r3,seqlist * r4,seqlist * r5,seqlist * r6,double info[6][3]);
