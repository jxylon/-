#define Max 20
typedef struct bnodept
{
	char data;
	struct bnodept * lchild,* rchild;
}bitreptr;
//�������������
bitreptr * create_bnode();
//������������
void preprint(bitreptr * bt);
//������������
void inprint(bitreptr * bt);
//������������
void postprint(bitreptr * bt);
//�˵�����
void Menu(bitreptr * bt);