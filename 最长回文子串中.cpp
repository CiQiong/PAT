#include<cstdio>
#include<cstring>
const int maxn=1010;
char S[maxn];
int main(){
	gets(S);
	int len=strlen(S),ans=1;
	int n=len*2+1;
	char *N=new char[n]();
	for(int i=0;i<len;i++){
		N[2*i+1]=S[i];
		N[2*i]='*';
	}
	N[n-1]='*';
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(i-j>=0&&i+j<n&&N[i-j]==N[i+j]){
				if(j>ans)ans=j;
			}else{
				break;
			}
		}
	} 
	printf("%d\n",ans);
	delete N;
	return 0;
} 
 
