#include<stdio.h>
#include<stdlib.h>
#include"head.h"
blink add(blink bt,char ch)
{
	if(bt==NULL)
	{
		bt=(blink)malloc(sizeof(bnode));
		bt->data=ch;
		bt->lchild=bt->rchild=NULL;
	}
	else if(ch<bt->data)
		bt->lchild=add(bt->lchild,ch);
	else
		bt->rchild=add(bt->rchild,ch);
	return bt;
}
void inorder(blink bt)
{
	if(bt)
	{
		inorder(bt->lchild);
		printf("%c ",bt->data);
		inorder(bt->rchild);
	}
}