#include<cstdio>
#include<cmath>
const double eps = 1e-8;
#define Equ(a,b) ((fabs((a)-(b)))<(eps))
int main()
{
	double db=1.23;
	if(Equ(db,1.23)){
		printf("true");
	}else{
		printf("false");
	}
	return 0;
}
/*
struct point{
	int x, y;
	point(){}
	point(int a,int b):x(a),y(b) {}
}n[10];
int main()
{
	int num=0;
	for(int i=0;i<=9;i++){
		for(int j=0;j<=3;j++){
			n[num++]=point(i,j);
		}
	}
	for(int i=0;i<num;i++)
	printf("%d,%d\n",n[i].x,n[i].y);
	return 0;
} */
