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
void changeRLBit(bitreptr * bt);
//�����ӽ��ĸ���
int singleChild(bitreptr * bt);