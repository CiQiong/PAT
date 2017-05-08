//Manacher
#include<cstdio>
#include<cstring>
#define min(x, y) ((x)<(y)?(x):(y))
#define max(x, y) ((x)<(y)?(y):(x))
using namespace std;
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
	int k=1;
	for(int i=1,j=1;i<n;i=i+k){//不要以为是循环复杂度就是N 
		while(i-j>=0&&i+j<n&&N[i-j]==N[i+j]){
			j++;
		}
		N[i]=j-1;
		for(k=1;k<=N[i]&&N[i-k]!=N[i]-k;k++)//镜像,遇到rad[i-k]=rad[i]-k停止，这时不用从j=1开始比较
			N[i+k]=min(N[i-k],N[i]-k);
		j=max(j-k,0);
	}
	int center;
	for(int i=0;i<len;i++)
	{
		if(N[i]>ans)
		{
			ans=N[i];
			center=i;
		}
	}
	printf("%d\n",ans);
	delete N;
	return 0;
} 
 
