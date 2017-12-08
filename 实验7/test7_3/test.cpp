#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"head.h"
bitreptr * create(char *s)
{
	char * p,temp[Max];//�ַ���s�ĸ���
	bitreptr *t,*q[Max],*root;
	int rear,front;//��ͷ�Ͷ�β
	rear=front=0;
	strcpy(temp,s);
	p=temp;
	while(strlen(p)>0)//�ַ�����Ϊ��
	{
		t=NULL;//��ʼ��Ϊ��
		if(*(p)!='.')//����ַ�������.�򴴽��½��
		{
			t=(bitreptr *)malloc(sizeof(bitreptr));
			t->data=*p;
			t->lchild=NULL;
			t->rchild=NULL;
		}
		q[++rear]=t;//�����Ƿ�Ϊ�ն����
		if(rear==1)//����ǵ�һ�������Ϊ����
			root=t;
		else
		{
			if(t&&q[front+1])//��ǰ���Ͷ�ͷԪ�ض���Ϊ��
			{
				if(rear%2==0)//���rear��ż������ͷԪ��������t�����ǲ�����
					q[front+1]->lchild=t;
				else//���rear����������ͷԪ���Һ�����t������
					q[++front]->rchild=t;
			}
		}
		p++;//ָ����һ���ַ�
	}
	return root;
}
//������������
void preprint(bitreptr * bt)
{
	if(bt!=NULL)
	{
		printf("%c ",bt->data);
		preprint(bt->lchild);
		preprint(bt->rchild);
	}
}