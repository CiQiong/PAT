#include<cstdio>
int main(){
	int n;
	scanf("%d",&n);
	double ans=0.0,temp;
	for(int i=1;i<=n;i++){
		scanf("%lf",&temp);
		ans+=temp*(i*(n+1-i));
	}
	printf("%.2f\n",ans);
	return 0;
}
