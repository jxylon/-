#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <windows.h>
#include <conio.h>
#include "head.h"
#define N 10
void Menu()
{
	int n;
	printf("ѡ��ʵ��:");
	printf("*********************\n");
	printf("1-> ������ϰ1&&������ϰ1\n");
	printf("2-> ������ϰ2&&������ϰ2\n");
	printf("3-> ������ϰ3&&������ϰ3\n");
	printf("0-> �˳�\n");
	printf("*********************\n");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
		{
			sqlist * L;
			L=(sqlist *)malloc(sizeof(sqlist));
			test1Menu(L);
			break;
		}
		case 2:
		{
			char str[Maxline];
			test2Menu(str);
		}
		case 3:
		{
			int n[4][4];
			test3Menu(n);
		}
	}
}
void test1Menu(sqlist * L)
{
	int n=1;
	while(n)
	{
		printf("*********************\n");
		printf("1-> ��ʼ������\n");
		printf("2-> ��������\n");
		printf("3-> ʹ���±귨�������Ԫ��ֵ\n");
		printf("4-> ʹ��ָ�뷨�������Ԫ��ֵ\n");
		printf("5-> ������������ż�����\n");
		printf("6-> �������������������\n");
		printf("7-> ������������������K��\n");
		printf("8-> ��������ż��λ�õ�Ԫ�ؼ�����\n");
		printf("9-> �ҳ������е����ֵ\n");
		printf("10-> �ҳ������е���Сֵ\n");
		printf("11-> �������е�����ָ��Ԫ�أ������Ƿ����\n");
		printf("12-> ɾ ��������ָ��ֵ��Ԫ��\n");
		printf("13-> ɾ��������ָ��λ�õ�Ԫ��\n");
		printf("14-> ɾ��������ֵ��ͬ��Ԫ��\n");
		printf("15-> ��Ԫ����ָ��λ�����Ԫ��\n");
		printf("16-> ��Ԫ�ؽ�������\n");
		printf("17-> ���������������Ԫ�أ�������������\n");
		printf("18-> ������Ԫ�ط���\n");
		printf("0-> �˳�\n");
		printf("*********************\n");
		printf("����ѡ�");
		scanf("%d",&n);
		switch(n)
		{
			case 1:init(L);break;
			case 2:creat(L);break;
			case 3:test1_1(L);break;
			case 4:test1_2(L);break;
			case 5:printf("%d\n",test1_3(L));break;
			case 6:printf("%d\n",test1_4(L));break;
			case 7:
			{
				int k;
				printf("put in k");
				fflush(stdin);
				scanf("%d",&k);
				test1_5(L,k);break;
			}
			case 8:printf("%d\n",test1_6(L));break;
			case 9:printf("%d\n",test1_7(L));break;
			case 10:printf("%d\n",test1_8(L));break;
			case 11:
				{
					int flag;
					printf("����������ֵ\n");
					fflush(stdin);
					scanf("%d",&flag);
					test1_9(L,flag);
				};break;
			case 12:
			{
				int k;
				printf("������Ҫɾ����Ԫ�ص�ֵ:");
				fflush(stdin);
				scanf("%d ",&k);
				test4_1(L,k);
				fflush(stdin);
				break;
			}
			case 13:
			{
				int k;
				printf("������Ҫɾ����Ԫ�ص�λ��:");
				fflush(stdin);
				scanf("%d ",&k);
				test4_2(L,k);
			}break;
			case 14:test4_3(L);break;
			case 15:
			{
				int k,l;
				printf("������Ҫ��ӵ�Ԫ��ֵ��λ��:");
				fflush(stdin);
				scanf("%d %d",&k,&l);
				test4_4(L,l,k);
			}break;
			case 16:test4_5(L);break;
			case 17:
			{
				int k;
				printf("������Ҫ��ӵ�Ԫ��:");
				fflush(stdin);
				scanf("%d ",&k);
				test4_6(L,k);
			}break;
			case 18:test4_7(L);break;
		}
	}
}
void test2Menu(char * str)
{
	int n=1;
	while(n)
	{
		printf("*********************\n");
		printf("1-> �����ַ���\n");
		printf("2-> ʹ���±귨������ַ���\n");
		printf("3-> ʹ��ָ�뷨������ַ���\n");
		printf("4-> ͳ���ַ����е�Сд��ĸ�ĸ���\n");
		printf("5-> ͳ���ַ�����ԭ����ĸ��Сд���ĸ������ظ���ĸ���ظ�������\n");
		printf("6-> �ҳ��ַ����е���Сֵ\n");
		printf("7-> �ҳ��ַ����е����ֵ\n");
		printf("8-> ɾ���ַ����е�ָ���ַ�\n");
		printf("9-> ɾ���ַ���ָ��λ�õ��ַ�\n");
		printf("10->ɾ���ַ��������е�Ԫ����ĸ\n");
		printf("11-> ���ַ����е�ָ��λ�����һ���ַ�\n");
		printf("0-> �˳�\n");
		printf("*********************\n");
		printf("����ѡ�");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			{
				printf("�����ַ���:");
				fflush(stdin);
				gets(str);
			}break;
			case 2:test2_1(str);break;
			case 3:test2_2(str);break;
			case 4:printf("�ַ�����ԭ����ĸ��Сд���ĸ������ظ���ĸ���ظ���������%d��\n",test2_3(str));break;
			case 5:test2_4(str);break;
			case 6:printf("�ַ����е����ֵΪ%c\n",test2_5(str));break;
			case 7:printf("�ַ����е���СֵΪ%c\n",test2_6(str));break;
			case 8:
			{
				char c;
				printf("������Ҫɾ�����ַ�");
				fflush(stdin);
				c=getchar();
				test5_1(str,c);
			}break;
			case 9:
			{
				int c;
				printf("������Ҫɾ�����ַ���λ��");
				fflush(stdin);
				scanf("%d",&c);
				test5_2(str,c);				
			}break;
			case 10:test5_3(str);break;
			case 11:
			{
				int k,c;
				printf("������Ҫ��ӵ��ַ�ֵ��λ��");
				fflush(stdin);
				scanf("%c %d",&c,&k);
				test5_4(str,k,c);
			}break;
		}
	}	
}
void test3Menu(int num[4][4])
{
	int n=1;
	while(n)
	{
		printf("*********************\n");
		printf("1-> �������4X4\n");
		printf("2-> ʹ���±귨����þ���\n");
		printf("3-> ʹ��ָ�뷨����þ���\n");
		printf("4-> ͳ�ƾ����еķ�0Ԫ�ĸ���\n");
		printf("5-> ���������Ԫ�صĺ�\n");
		printf("6-> ����ת��\n");
		printf("7-> �ж��Ƿ��ǶԳƾ���\n");
		printf("8-> �ж��Ƿ��������Ǿ���\n");
		printf("9-> ������A��������Ԫ�ش浽һ��һά������\n");
		printf("10->������A��������Ԫ�ش浽һ��һά������\n");
		printf("11->ʵ��A+B\n");
		printf("0-> �˳�\n");
		printf("*********************\n");
		printf("����ѡ�");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			{
				int i,j;
				for(i=0;i<4;i++)
				{
					for(j=0;j<4;j++)
						scanf("%d",&num[i][j]);
				}
				break;
			}
			case 2:test3_1(num);break;
			case 3:test3_2(num);break;
			case 4:printf("�����еķ�0Ԫ�ĸ�����%d��\n",test3_3(num));break;
			case 5:printf("��������Ԫ�صĺ�:%d\n",test3_4(num));break;
			case 6:test3_5(num);break;
			case 7:test6_1(num);break;
			case 8:test6_2(num);break;
			case 9:
			{
				int n[6];
				test6_3(num,n);
				for(int i=0;i<6;i++)
					printf("%d ",n[i]);
			}break;
			case 10:
			{
				int n[6];
				test6_4(num,n);
				for(int i=0;i<6;i++)
					if(n[i]>=0)
						printf("%d ",n[i]);
			}break;
			case 11:
			{
				int num1[4][4];
				int i,j;
				printf("�������4X4\n");
				fflush(stdin);
				for(i=0;i<4;i++)
				{
					for(j=0;j<4;j++)
						scanf("%d",&num[i][j]);
				}
				test6_5(num,num1);
			}break;
		}
	}	
}
void init(sqlist * L)
{
	L->len=0;
}
int creat(sqlist * L)
{
	FILE * f;
	int i=0;
	f=fopen("test.txt","r");
	if(f==NULL)
	{
		printf("�ļ���ʧ��!\n");
		return 0;
	}
	while(!feof(f))
	{
		fscanf(f,"%d",&L->arr[i]);
		L->len++;
		i++;
	}
	fclose(f);
	return 1;
}
void test1_1(sqlist * L)
{
	int i;
	for(i=0;i<L->len;i++)
		printf("%d ",L->arr[i]);
	printf("\n");
}
void test1_2(sqlist * L)
{
	int i;
	for(i=0;i<L->len;i++)
		printf("%d ",*(L->arr+i));
	printf("\n");
}
int test1_3(sqlist * L)
{
	int i,sum=0;
	for(i=0;i<L->len;i++)
	{
		if(L->arr[i]%2==0)
			sum+=L->arr[i];
	}
	return sum;
}
int test1_4(sqlist * L)
{
	int i,sum=0;
	for(i=0;i<L->len;i++)
	{
		if(L->arr[i]%2==1)
			sum+=L->arr[i];
	}
	return sum;
}
void test1_5(sqlist * L,int k)
{
	int i;
	for(i=0;i<L->len;i++)
		L->arr[i]*=k;
	for(i=0;i<L->len;i++)
		printf("%d ",L->arr[i]);
}
int test1_6(sqlist * L)
{
	int i,sum=0;
	for(i=0;i<L->len;i++)
	{
		if(i%2==0)
			sum+=L->arr[i];
	}
	return sum;
}
int test1_7(sqlist * L)
{
	int i,max=L->arr[0];
	for(i=1;i<L->len;i++)
		if(L->arr[i]>max)
			max=L->arr[i];
	return max;
}
int test1_8(sqlist * L)
{
	int i,min=L->arr[0];
	for(i=1;i<L->len;i++)
		if(L->arr[i]<min)
			min=L->arr[i];
	return min;
}
void test1_9(sqlist * L,int flag)
{
	int i,j=0;
	for(i=0;i<L->len;i++)
	{
		if(L->arr[i]==flag)
		{
			j=1;
			break;
		}
	}
	if(j==0)
		printf("Not found\n");
	else printf("Found it\n");
}
void test2_1(char str[])
{
	int i=0;
	printf("�ַ���Ϊ��");
	while(str[i]!='\0')
	{
		printf("%c",str[i]);
		i++;
	}
	printf("\n");
}
void test2_2(char * str)
{
	int i=0;
	printf("�ַ���Ϊ��");
	while(*(str+i)!='\0')
	{
		printf("%c",*(str+i));
		i++;
	}
	printf("\n");
}
int test2_3(char str[])
{
	int i=0,count=0;
	while(str[i]!='\0')
	{
		if(str[i]>='a'&&str[i]<='z')
			count++;
		i++;
	}
	return count;
}
void test2_4(char str[])
{
	int i=0,count[5]={0},all=0;
	while(str[i]!='\0')
	{
		if(str[i]=='a')
			count[str[i]-'a']=1;
		if(str[i]=='e')
			count[str[i]-'e'+1]=1;
		if(str[i]=='i')
			count[str[i]-'i'+2]=1;
		if(str[i]=='o')
			count[str[i]-'o'+3]=1;
		if(str[i]=='u')
			count[str[i]-'u'+4]=1;
		i++;
	}
	for(i=0;i<5;i++)
		all+=count[i];
	printf("һ��%d��",all);
}
char test2_5(char str[])
{
	int i=0;
	char maxChar=str[i];
	while(str[i]!='\0')
	{
		if(str[i]>maxChar)
			maxChar=str[i];
		i++;
	}
	return maxChar;
}
char test2_6(char str[])
{
	int i=0;
	char minChar=str[i];
	while(str[i]!='\0')
	{
		if(str[i]<minChar)
			minChar=str[i];
		i++;
	}
	return minChar;
}
void test3_1(int arr[4][4])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			printf("%d ",arr[i][j]);
		printf("\n");
	}
}
void test3_2(int arr[4][4])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			printf("%d ",*(*(arr+i)+j));
		printf("\n");
	}
}
int test3_3(int arr[4][4])
{
	int i,j,count=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			if(arr[i][j]!=0)
				count++;
	}
	return count;
}
int test3_4(int arr[4][4])
{
	int i,j,sum=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			sum+=arr[i][j];
	}
	return sum;
}
void test3_5(int arr[4][4])
{
	int i,j,temp;
	for(i=0;i<4;i++)
	{
		for(j=i+1;j<4;j++)
		{
			temp=arr[i][j];
			arr[i][j]=arr[j][i];
			arr[j][i]=temp;
		}
	}
}
void test4_1(sqlist * L,int num)
{
	int i,j;
	for(i=0;i<L->len;i++)
	{
		if(num==L->arr[i])
		{
			for(j=i;j<L->len-1;j++)
				L->arr[j]=L->arr[j+1];
			L->len--;
			i--;
		}
	}
}
int test4_2(sqlist * L,int i)
{
	int j;
	if(i<1||i>L->len)
	{
		printf("ɾ��λ�ò��ԣ�\n");
		return 0;
	}
	else
	{
		for(j=i;j<L->len;j++)
			L->arr[j-1]=L->arr[j];
		L->len=L->len-1;
		return 1;
	}
}
void test4_3(sqlist * L)
{
	int i,j,k,temp;
	for(i=0;i<L->len;i++)
	{
		temp=L->arr[i];
		for(j=i+1;j<L->len;j++)
		{
			if(temp==L->arr[j])
			{
				for(k=j;k<L->len-1;k++)
					L->arr[k]=L->arr[k+1];
				L->len--;
				j--;
			}
		}
	}
}
int test4_4(sqlist * L,int i,int num)
{
	int j;
	if(L->len==Maxline)
	{
		printf("���\n");
		return 0;
	}
	else if(i<0||i>L->len+1)
	{
		printf("����λ�ò��ԣ�\n");
		return 0;
	}
	else 
	{
		for(j=L->len-1;j>=i-1;j--)
			L->arr[j+1]=L->arr[j];
		L->arr[i-1]=num;
		L->len++;
		return 1;
	}
}
void test4_5(sqlist * L)
{
	int i,j,t;
	for(i=0;i<L->len-1;i++)
	{
		t=L->arr[i];
		for(j=i+1;j<L->len;j++)
		{
			if(L->arr[j]==0)
				break;
			else if(L->arr[i]>L->arr[j])
			{
				t=L->arr[i];
				L->arr[i]=L->arr[j];
				L->arr[j]=t;
			}
		}
	}
}
void test4_6(sqlist * L,int num)
{
	int i;
	for(i=0;i<L->len;i++)
	{
		if(num>L->arr[i]&&num<=L->arr[i+1])
			break;
	}
	test4_4(L,i,num);
	test4_5(L);
}
void test4_7(sqlist * L)
{
	int i,t,length=L->len;
	for(i=0;i<length/2;i++)
	{
		t=L->arr[i];
		L->arr[i]=L->arr[length-i-1];
		L->arr[length-i]=t;
	}
}
void test5_1(char str[],char c)
{
	int i=0,j=0;
	char temp[30];
	while(str[i]!='\0')
	{
		if(str[i]!=c)
			temp[j]=str[i];
		else
			j--;
		j++;
		i++;
	}
	temp[j]='\0';
	strcpy(str,temp);
}
void test5_2(char str[],int n)
{
	int i=n;
	while(str[i]!='\0')
	{
		str[i]=str[i+1];
		i++;
	}
}
void test5_3(char str[])
{
	int i=0,j;
	while(str[i]!='\0')
	{
		if(str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='A'||str[i]=='E'||str[i]=='I'||str[i]=='O'||str[i]=='U')
		{
			j=i;
			while(str[j]!='\0')
			{
				str[j]=str[j+1];
				j++;
			}
		}
		i++;
	}
}
void test5_4(char str[],int n,char c)
{
	int i,len;
	for(i=0;i<len;i++)
	{
		if(str[i]=='\0')
			len=i;
	}
	for(i=len+1;i>n;i++)
		str[i]=str[i-1];
	str[n]=c;
}
int test6_1(int array[4][4])
{
	int i,j;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(array[i][j]!=array[j][i])
			{
				printf("���ǶԳƾ���");
				return 0;
			}
		}
	}
	printf("�ǶԳƾ���");
	return 1;
}
int test6_2(int array[4][4])
{
	int i,j;
	for(i=1;i<4;i++)
	{
		for(j=0;j<i;j++)
		{
			if(array[i][j]!=0)
			{
				printf("���������Ǿ���");
				return 0;
			}
		}
	}
	printf("�������Ǿ���");
	return 1;
}
void test6_3(int array[4][4],int temp[])
{
	int i,j,n=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<i;j++)
		{
			temp[n]=array[i][j];
			n++;
		}
	}
}
void test6_4(int array[4][4],int temp[])
{
	int i,j,n=0;
	for(i=0;i<4;i++)
	{
		for(j=i;j<4-i;j++)
		{
			temp[n]=array[i][j];
			n++;
		}
	}
}
void test6_5(int array1[4][4],int array2[4][4])
{
	int i,j,array[4][4];
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			array[i][j]=array1[i][j]+array2[i][j];
		}
	}
	test3_1(array);
}
