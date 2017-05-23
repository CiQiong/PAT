#include<cstdio>
char S[4]={"WTL"};
int main(){
	double ans=1.0,temp,a;
	int index;
	for(int i=0;i<3;i++){
		temp=0.0;
		for(int j=0;j<3;j++){
			scanf("%lf",&a);
			if(a>temp){
				temp=a;
				index=j;
			}
		}
		ans*=temp;
		printf("%c ",S[index]);
	}
	printf("%.2f",(ans*0.65-1.00)*2.00);
	return 0;
}
