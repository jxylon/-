#define Max 1024
typedef struct str
{
	char ch[Max];
	int length;
}string;
void getCh(string * s);
void reserve(string * s);
void prin(string * s);