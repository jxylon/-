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
//��������Ľ������Ҷ����
void test2_1(bitreptr * bt);
//����α���������
void test2_2(bitreptr * bt);
//���������
int test2_4(bitreptr * bt);
//�����������ֵΪx�Ľ��Ϊ�������������
void test2_5(bitreptr * bt,int x);
//�˵�����
void Menu(bitreptr * bt);