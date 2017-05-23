#include<cstdio>
int main(){
	int n;
	scanf("%d",&n);
	int a1,a2,b1,b2;
	int a=0,b=0;
	while(n--){
		scanf("%d%d%d%d",&a1,&a2,&b1,&b2);
		if(a2==a1+b1&&b2!=a1+b1)b++;
		else if(b2==a1+b1&&a2!=a1+b1)a++;
	}
	printf("%d %d",a,b);
	return 0;
}
