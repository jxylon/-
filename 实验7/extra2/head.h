typedef int datatype;
typedef struct tnodetp
{
	datatype data;
	tnodetp * fch,*nsib;
}*tlinktp;
void Menu(tlinktp t);
tlinktp create();
int countLeaf(tlinktp t);
int deepTree(tlinktp t);
void proprint(tlinktp t);