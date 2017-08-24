//给出两个多项式，计算他们的和 
#include<cstdio>
int main(){
	double ans[1001]={0};//用来存储和，索引值为幂数，值为总系数 
	int a,b,temp;//两个多项式的系数以及临时幂数 
	double c;
	scanf("%d",&a);
	for(int i=0;i<a;i++){
		scanf("%d%lf",&temp,&c);//输入各项幂数以及对应的系数 
		ans[temp]+=c;
	}
	scanf("%d",&b);
	for(int i=0;i<b;i++){
		scanf("%d%lf",&temp,&c);//输入各项幂数以及对应的系数 
		ans[temp]+=c;
	}
	int ans1=0;
	for(int i=0;i<1001;i++){
		if(ans[i]!=0)ans1++;
	}
	printf("%d",ans1);
	for(int i=1000;i>=0;i--){
		if(ans[i]!=0)printf(" %d %.1f",i,ans[i]);
	}
	return 0;
}
