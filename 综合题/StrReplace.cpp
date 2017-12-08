#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void StrDel(char * S,int i,int m)
{
	char Temp[20];
	int lenS=strlen(S);
	if(i+m<lenS)
	{
		strcpy(Temp,&S[i+m]);
		strcpy(&S[i],Temp);
	}
	else if(i+m>=lenS&&i<lenS)
	{
		strcpy(&S[i],"\0");
	}
}
void StrInsert(char * S,char * T,int i)
{
	char * Temp;
	int lenS=strlen(S);
	if(i<=lenS)
	{
		Temp=(char *)malloc(sizeof(char)*20);
		strcpy(Temp,&S[i]);
		strcpy(&S[i],T);
		strcat(S,Temp);
		free(Temp);
	}
}
void StrReplace(char * T,char * P,char * S)
{
	int i=0,j,lenT,lenP,lenS;
	lenT=strlen(T);
	while(i<lenT)
	{
		lenT=strlen(T);
		lenP=strlen(P);
		lenS=strlen(S);
		j=0;
		while(j<lenP)
		{
			if(*(T+i)==*(P+j))
			{
				i++;
				j++;
			}
			else
			{
				i=i-j+1;
				break;
			}
		}
		if(j==lenP)
		{
			i=i-j;
			StrDel(T,i,lenP);
			StrInsert(T,S,i);
		}
	}
}
int main(void)
{
	int min;
//	char str[20]="abcdea";
//	StrReplace(str,"bc","a");
//	puts(str);
	min=1>2?1:2;
	printf("%d",min);
	return 0;
}