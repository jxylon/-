#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"head.h"
void Menu()
{
	//r1,r2,r3,r4,r5,r6�ֱ��Ǹ����㷨�Ľṹָ��
	seqlist * r1,* r2,* r3,* r4,* r5,* r6;
	//n�ܲ˵�ѡ�m�ļ��˵�ѡ�numΪ�ļ�����������
	int n=1,m=1,num;
	//�ļ���
	char * s;		
	//info�洢֮ǰ�����㷨�ıȽϴ������ƶ�����������ʱ�䣬durationΪʱ���
	double info[6][3]={0},duration[6];
	s=(char *)malloc(sizeof(char)*6);
	while(n)
	{
		printf("\t\t\t\t\t*******************�ۺ������㷨�˵�**********************\n");
		printf("\t\t\t\t\t*		1->	��ȡ�ļ�			*\n");
		printf("\t\t\t\t\t*		2->	��������			*\n");
		printf("\t\t\t\t\t*		3->	�鿴���			*\n");
		printf("\t\t\t\t\t*		0->	�˳�				*\n");
		printf("\t\t\t\t\t*********************************************************\n");
		printf("����ѡ�");
		fflush(stdin);
		scanf("%d",&n);
		switch(n)
		{
		case 1:
			{
						//��r1,r2,r3,r4,r5,r6��ʼ��
						r1=initSeqlist();
						r2=initSeqlist();
						r3=initSeqlist();
						r4=initSeqlist();
						r5=initSeqlist();
						r6=initSeqlist();
						//����
						system("cls");
						printf("\t\t\t\t\t***********************�ļ�ѡ��**************************\n");
						printf("\t\t\t\t\t*		1->	50000������->data1.txt		*\n");
						printf("\t\t\t\t\t*		2->	60000������->data2.txt		*\n");
						printf("\t\t\t\t\t*		3->	70000������->data3.txt		*\n");
						printf("\t\t\t\t\t*		4->	80000������->data4.txt		*\n");
						printf("\t\t\t\t\t*		5->	90000������->data5.txt		*\n");
						printf("\t\t\t\t\t*		0->		����			*\n");
						printf("\t\t\t\t\t*********************************************************\n");
						printf("����ѡ�");
						fflush(stdin);
						scanf("%d",&m);
						num=50000+10000*(m-1);
						//ѡ���ļ�
						switch(m)
						{
						case 1:s="data1.txt";break;
						case 2:s="data2.txt";break;
						case 3:s="data3.txt";break;
						case 4:s="data4.txt";break;
						case 5:s="data5.txt";break;
						default:break;
						}
						//��m��=0��ȡ�ļ�
						if(m!=0)
						{
							readFile(r1,s);
							readFile(r2,s);
							readFile(r3,s);
							readFile(r4,s);
							readFile(r5,s);
							readFile(r6,s);
							printf("��ȡ�ļ��ɹ�!!!\n\n");
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
				printf("\t\t\t\t\t*******************%d������������***********************\n",num);
				printf("�Ƚ���  		 �ƶ�����(ͬ�ϴζԱ�)				�Ƚϴ���(ͬ�ϴζԱ�)				����ʱ��(s)(ͬ�ϴζԱ�)\n\n");
				printf("ֱ�Ӳ���		%10.0lf(%.2lf%%)				%10.0lf(%.2lf%%)				%10.4lf(%.2lf%%)\n\n",r1->compare,100*(r1->compare-info[0][0])/r1->compare,r1->move,100*(r1->move-info[0][1])/r1->move,duration[0],100*(duration[0]-info[0][2])/duration[0]);
				printf("ð������		%10.0lf(%.2lf%%)				%10.0lf(%.2lf%%)				%10.4lf(%.2lf%%)\n\n",r2->compare,100*(r2->compare-info[1][0])/r2->compare,r2->move,100*(r2->move-info[1][1])/r2->move,duration[1],100*(duration[1]-info[1][2])/duration[1]);
				printf("ѡ������		%10.0lf(%.2lf%%)				%10.0lf(%.2lf%%)				%10.4lf(%.2lf%%)\n\n",r3->compare,100*(r3->compare-info[2][0])/r3->compare,r3->move,100*(r3->move-info[2][1])/r3->move,duration[2],100*(duration[2]-info[2][2])/duration[2]);
				printf("��������		%10.0lf(%.2lf%%)				%10.0lf(%.2lf%%)				%10.4lf(%.2lf%%)\n\n",r4->compare,100*(r4->compare-info[3][0])/r4->compare,r4->move,100*(r4->move-info[3][1])/r4->move,duration[3],100*(duration[3]-info[3][2])/duration[3]);
				printf("������			%10.0lf(%.2lf%%)				%10.0lf(%.2lf%%)				%10.4lf(%.2lf%%)\n\n",r5->compare,100*(r5->compare-info[4][0])/r5->compare,r5->move,100*(r5->move-info[4][1])/r5->move,duration[4],100*(duration[4]-info[4][2])/duration[4]);
				printf("�鲢����		%10.0lf(%.2lf%%)				%10.0lf(%.2lf%%)				%10.4lf(%.2lf%%)\n\n",r6->compare,100*(r6->compare-info[5][0])/r6->compare,r6->move,100*(r6->move-info[5][1])/r6->move,duration[5],100*(duration[5]-info[5][2])/duration[5]);
				store(r1,r2,r3,r4,r5,r6,info);
			}break;
		default:break;
		}
	}
}
//�洢�ļ��ĸ�����Ϣ
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
//�����н����������򷽷�������
void sort(seqlist * r1,seqlist * r2,seqlist * r3,seqlist * r4,seqlist * r5,seqlist * r6,int num)
{
	//���ڽ���ֱ�Ӳ�������!!!
	printf("���ڽ���ֱ�Ӳ�������!!!\n\n");
	r1->begin=clock();
	insert(r1,num);
	r1->end=clock();
	printf("���!\n\n");
	//���ڽ���ð������!!!
	printf("���ڽ���ð������!!!\n\n");
	r2->begin=clock();
	mppx(r2,num);
	r2->end=clock();
	printf("���!\n\n");
	//���ڽ���ѡ������!!!
	printf("���ڽ���ѡ������!!!\n\n");
	r3->begin=clock();
	zjxz(r3,num);
	r3->end=clock();
	printf("���!\n\n");
	//���ڽ��п�������!!!
	printf("���ڽ��п�������!!!\n\n");
	r4->begin=clock();
	quicksort(r4,1,num);
	r4->end=clock();
	printf("���!\n\n");
	//���ڽ��ж�����!!!
	printf("���ڽ��ж�����!!!\n\n");
	r5->begin=clock();
	dpx(r5,num);
	r5->end=clock();
	printf("���!\n\n");
	//���ڽ��й鲢����!!!
	printf("���ڽ��й鲢����!!!\n\n");
	r6->begin=clock();
	llgbpx(r6,num);
	r6->end=clock();
	printf("���!\n\n");
}
//��ʼ��seqlist
seqlist * initSeqlist()
{
	seqlist * r;
	r=(seqlist *)malloc(sizeof(seqlist));
	r->compare=0;
	r->move=0;
	return r;
}
//��ȡ�ļ�
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
//д��������ļ�
void writeFile(int n)
{
	FILE * fp=NULL;
	unsigned seed=time(NULL);
	int i,t;
	srand(seed);
	fp=fopen("data1.txt","w");
	if(fp==NULL)
	{
		printf("���ļ�ʧ��\n");
		return ;
	}
	else
	{
		for(i=1;i<=n;i++)
		{
		//	printf("������ź͹ؼ���:");
		//	fflush(stdin);
			t=rand()%n+1;
			fprintf(fp,"%d ",t);
		}
	}
	fclose(fp);
}
//���������㷨 �ҵ�i������λ��
int partition(seqlist * r,int i,int j)
{
	//pivotΪ���������Ԫ��
	rectype pivot=r->data[i];
	//����һ������ֱ��i=j����
	while(i<j)
	{
		while(i<j&&r->data[j].key>=pivot.key)//����ɨ�裬ֱ���ҵ���pivot�Ĺؼ���С��Ԫ��
		{
			//�Ƚϴ�����һ
			r->compare++;
			j--;
		}
		//�Ƚϴ�����һ
		r->compare++;
		if(i<j)
		{
			r->move++;
			//data[i]��data[j]����,iָ����һ��Ԫ��
			r->data[i]=r->data[j];
			i++;
		}
		while(i<j&&r->data[i].key<=pivot.key)//����ɨ�裬֪���ҵ���pivot�Ĺؼ��ִ��Ԫ��
		{
			//�Ƚϴ�����һ
			r->compare++;
			i++;
		}
		if(i<j)
		{
			//data[i]��data[j]����,jָ��ǰһ��Ԫ��
			r->data[j]=r->data[i];
			r->move++;
			j--;
		}
	}
	r->data[i]=pivot;
	r->move++;
	return i;
}
//���������㷨 �ݹ�ʵ��
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
//ֱ�Ӳ����㷨 ��������
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
//ð������
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
//��ֱ��ѡ������
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
//ϣ������
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
//�鲢�㷨���� �ϲ�
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
//�鲢�㷨���� һ�˹鲢�㷨
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
//�鲢�㷨���� �����鲢�㷨
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
//������ ɸѡ�㷨
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
//������
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
