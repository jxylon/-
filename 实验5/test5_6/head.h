#define Max 1024
typedef struct str
{
	char ch[Max];
	int length;
}string;
void getCh(string * s);
void maxcommonstr(string s,string t,int &maxlen,int &pos1,int &pos2);
