//给一个字符串，变成U型
//n2=(n+2)/3+n%3,n1=n3=(n+2)/3
#include<cstdio>
#include<cstring>
int main(){
	char str[81];
	gets(str);
	int n=strlen(str);
	int n1=(n+2)/3,n2=n+2-n1*2;
	for(int i=0;i<n1-1;i++){
		printf("%c",str[i]);
		for(int j=0;j<n2-2;j++)printf(" ");
		printf("%c\n",str[n-1-i]);
	}
	for(int i=0;i<n2;i++)printf("%c",str[i+n1-1]);
	return 0;
}
