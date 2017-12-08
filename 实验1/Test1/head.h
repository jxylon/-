#define Maxline 1024
typedef struct
{
	int arr[Maxline];
	int len;
}sqlist;
//函数的声明
//实验1
void test2Menu(char * str);
void test1Menu(sqlist * L);
void init(sqlist * L);
int creat(sqlist * L);
void test1_1(sqlist * L);
void test1_2(sqlist * L);
int test1_3(sqlist * L);
int test1_4(sqlist * L);
void test1_5(sqlist * L,int k);
int test1_6(sqlist * L);
int test1_7(sqlist * L);
int test1_8(sqlist * L);
void test1_9(sqlist * L,int flag);
void test2_1(char str[]);
void test2_2(char * str);
int test2_3(char str[]);
void test2_4(char str[]);
char test2_5(char str[]);
char test2_6(char str[]);
void test3_1(int arr[4][4]);
void test3_2(int arr[4][4]);
int test3_3(int arr[4][4]);
int test3_4(int arr[4][4]);
void test3_5(int arr[4][4]);
void randomArray(int array[10]);//生成随机整型数组
void test4_1(sqlist * L,int num);
int test4_2(sqlist * L,int pos);
void test4_3(sqlist * L);
int test4_4(sqlist * L,int num,int pos);
void test4_5(sqlist * L);
void test4_6(sqlist * L,int num);
void test4_7(sqlist * L);
void test4_7(sqlist * L);
void test5_1(char str[],char c);
void test5_2(char str[],int n);
void test5_3(char str[]);
void test5_4(char str[],int n,char c);
int test6_1(int array[4][4]);
int test6_2(int array[4][4]);
void test6_3(int array[4][4],int temp[]);
void test6_4(int array[4][4],int temp[]);
void test6_5(int array1[4][4],int array2[4][4]);
void Menu();
void test3Menu(int num[4][4]);