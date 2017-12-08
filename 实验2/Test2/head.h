typedef struct sc
{
	int math;
	int Englishl;
	int music;
}scores;
typedef struct st
{
	int no[2];
	char name[10];
	scores score;
}student;
struct cpxNum
{
	double real;
	double imag;
};
struct triangle
{
	double x1,x2,x3,y1,y2,y3;
};
//สตั้2
int fun(int *a,int *b);
void sum(int * a,int n,int *odd,int *even);
int dcopy(int *a,int *b,int n);
int exchange(int *a,int n);
void printAll(student stu[],int n);
void averageSco(student stu[],int n);
void topStu(student stu[],int n);
void printCpx(struct cpxNum cpx);
void addCpx(struct cpxNum cpx1,struct cpxNum cpx2);
void subCpx(struct cpxNum cpx1,struct cpxNum cpx2);
void mulCpx(struct cpxNum cpx1,struct cpxNum cpx2);
void prinCpxReal(struct cpxNum cpx);
void prinCpxImag(struct cpxNum cpx);
int isEquil(struct triangle tri);
int isIso(struct triangle tri);
int isRight(struct triangle tri);
double triArea(struct triangle tri);
int isInTriangle(struct triangle tri,int x,int y);
void Menu();