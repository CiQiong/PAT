//计算两个数的和，且按要求输出 
#include<cstdio>
int main(){
	int a,b,sum;
	scanf("%d%d",&a,&b);
	sum=a+b;
	if(sum<0){//如果和是负数，先输出负号，再把这个数变成正数以便以后计算 
		printf("-");
		sum=-sum;
	} 
	int len=0,num[10];
	do{
		num[len++]=sum%10;
		sum/=10;
	}while(sum);
	for(int i=len-1;i>=0;i--){
		printf("%d",num[i]);
		if(i>0&&i%3==0)printf(",");
	}
	return 0;
}
