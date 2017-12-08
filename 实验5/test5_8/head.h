#define Max 1024
typedef struct str
{
	char ch[Max];
	int length;
}string;
void prin(string * s);
void getCh(string * s);
int pattern_index(string * s1,string * s2);