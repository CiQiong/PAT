//½øÖÆ×ª»»
#include<cstdio>
int main(){
	int a,b,d;
	scanf("%d%d%d",&a,&b,&d);
	int sum=a+b;
	int ans[31],c=0;
	do{
		ans[c++]=sum%d;
		sum=sum/d;
	} while(sum!=0);
	for(int i=c-1;i>=0;i--){
		printf("%d",ans[i]);
	}
	return 0;
}
