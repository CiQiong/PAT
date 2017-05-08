#include<cstdio>
#include<cstring>
const int maxn=1010;
char S[maxn];
int dp[maxn][maxn];//从左数到右数是否为回文
int main(){
	gets(S);
	int len=strlen(S),ans=1;
	memset(dp,0,sizeof(dp));//dp数组初始化为0
	//边界
	for(int i=0;i<len;i++){
		dp[i][i]=1;
		if(i<len-1){
			if(S[i]==S[i+1]){
				dp[i][i+1]=1;
				ans=2;//初始化时注意当前最长回文串的长度 
			}
		}
	} 
	//状态转移方程 
	for(int L=3;L<=len;L++){//枚举子串的长度 
		for(int i=0;i+L-1<len;i++){
			int j=i+L-1;//子串的右端点
			if(S[i]==S[j]&&dp[i+1][j-1]==1){
				dp[i][j]=1;
				ans=L;//更新最长会问字串的长度 
			} 
		} 
	} 
	printf("%d\n",ans);
	return 0;
} 
 
