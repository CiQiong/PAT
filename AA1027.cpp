//168=13*13-1Ҳ����˵ÿ���������ֻ����λ����˲���ʹ�ý���ת��
#include<cstdio>
int main(){
	char n[14]={"0123456789ABC"};
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	printf("#%c%c%c%c%c%c",n[a/13],n[a%13],n[b/13],n[b%13],n[c/13],n[c%13]);
	return 0;
}
