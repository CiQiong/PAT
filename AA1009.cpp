//计算两个多项式的乘积 
#include<cstdio>
int main(){
	int a,b,temp;//两个多项式的系数以及临时指数 
	double c,aaa[1001]={0},ans[2001]={0};
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d %lf",&temp,&c);//输入各项指数以及对应的系数 
		aaa[temp]=c;
	}
	scanf("%d",&b);
	for(int i=0;i<b;i++){
		scanf("%d %lf",&temp,&c);//输入各项指数以及对应的系数 
		for(int ii=0;ii<1001;ii++)ans[ii+temp]+=aaa[ii]*c;//分别乘以先前每一项 
	}
	int ans1=0;
	for(int i=0;i<2001;i++)if(ans[i]!=0)ans1++;
	printf("%d",ans1);
	for(int i=2000;i>=0;i--)if(ans[i]!=0)printf(" %d %.1f",i,ans[i]);
	return 0;
}
