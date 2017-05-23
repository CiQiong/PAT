/*
#include<cstdio>
#include<cstring>
int main(){
	char str[90],ans[40][40];
	gets(str);
	int N=strlen(str);
	int n1=(N+2)/3,n3=n1,n2=N+2-n1-n3;
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){
			ans[i][j]=' ';//初始化，将ans数组全赋为空格 
		}
	}
	int pos=0;
	for(int i=1;i<=n1;i++){
		ans[i][1]=str[pos++];
	}
	for(int i=2;i<=n2;i++){
		ans[n1][i]=str[pos++];
	}
	for(int i=n3-1;i>=1;i--){
		ans[i][n2]=str[pos++];
	}
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=n2;j++){
			printf("%c",ans[i][j]);
		}
		printf("\n");
	}
	return 0;
}
*/
0   12
1   11
2   10
3   9
45678
#include<cstdio>
#include<cstring>
int main(){
	char str[100];
	gets(str);
	int N=strlen(str);
	int n1=(N+2)/3,n3=n1,n2=N+2-n1-n3;
	for(int i=0;i<n1-1;i++){
		printf("%c",str[i]);
		for(int j=0;j<n2-2;j++){
			printf(" ");
		}
		printf("%c\n",str[N-i-1]);
	}
	for(int i=0;i<n2;i++){
		printf("%c",str[n1-1+i]);
	}
	return 0;
}
