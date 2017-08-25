//168=13*13-1也就是说每个数字最大只有两位，因此不用使用进制转换
#include<cstdio>
int main(){
	char n[14]={"0123456789ABC"};
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("#%c%c%c%c%c%c",n[a/13],n[a%13],n[b/13],n[b%13],n[c/13],n[c%13]);
	return 0;
}
