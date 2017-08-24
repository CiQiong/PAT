//典型的阅读理解题
//题目大意;
//给出三行double数，每行有三个数，每行最大的数分别为a，b，c 
//分别输出每行最大的数所在的位置(W/T/L)，然后运用公式ans=(a*b*c*0.65-1)*2输出答案
#include<cstdio>
int main(){
	char s[4]={"WTL"};
	double ans=1.0,max,a;
	int index;
	for(int i=0;i<3;i++){
		max=0.0;
		for(int j=0;j<3;j++){
			scanf("%lf",&a);
			if(a>max){
				max=a;
				index=j;
			}
		}
		ans*=max;
		printf("%c ",s[index]);
	}
	printf("%.2f",(ans*0.65-1)*2);
	return 0;
} 
