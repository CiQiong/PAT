#include<cstdio>
#include<cmath>
bool isPrime(int n){
	if(n<=1)return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0)return false;
	}
	return true;
}
int d[111];//可能输入的中最大数变成二进制后的位数
int main(){
	int n,index;
	while(scanf("%d",&n)!=EOF){
		if(n<0)break;
		scanf("%d",&index);
		if(isPrime(n)==false)printf("No\n");
		else{
			int len=0;
			do{
				d[len++]=n%index;//默认实现反转 
				n/=index;
			}while(n!=0);
			for(int i=0;i<len;i++){
				n=n*index+d[i]; 
			}
			if(isPrime(n)==true)printf("Yes\n");
			else printf("No\n"); 
		}
	}
	return 0;
} 

