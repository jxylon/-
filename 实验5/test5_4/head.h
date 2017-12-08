#define Max 1024
typedef struct str
{
	char ch[Max];
	int length;
}string;
int judge(string * s1,string * s2);
void getCh(string * s);