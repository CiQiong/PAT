#include<cstdio>
int main(){
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		long long res=a+b;//##
		if(a>0&&b>0&&res<0)
		printf("Case #%d: true\n",i);
		else if(a<0&&b<0&&res>=0)
		printf("Case #%d: false\n",i);
		else if(res>c)
		printf("Case #%d: true\n",i);
		else
		printf("Case #%d: false\n",i);
	}
	return 0;
} 
