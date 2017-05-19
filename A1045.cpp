//A1045
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxc=210;//最大颜色数
const int maxn=10010;//最大L
int HashTable[maxc];//将最喜欢的颜色序列映射为递增序列，不喜欢的颜色映射为-1
int A[maxn],dp[maxn];//最大不下降子序列的原数组A和DP序列
int main(){
	int n,m,x;
	scanf("%d%d",&n,&m);//其实n用不到
	memset(HashTable,-1,sizeof(HashTable));//整个数组初始化为-1
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		HashTable[x]=i;
	} 
	int L,num=0;//num存放颜色序列中Eva喜欢的颜色的总数
	for(int i=0;i<L;i++){
		scanf("%d",&x);
		if(HashTable[x]>=0){//若是喜欢的颜色，则加到A数组中 
			A[num++]=HashTable[x]; 
		}
	} 
	//以下全为LIS问题的模板
	int ans=-1;
	for(int i=0;i<num;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(A[j]<=A[i]&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
			} 
		}
		ans=max(ans,dp[i]);
	} 
	printf("%d\n",ans);
	return 0;
} 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxc=210;
const int maxn=10010;
int A[maxc],B[maxn],dp[maxc][maxn];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&A[i]);//读入序列A 
	}
	int L;
	scanf("%d",&L);
	for(int i=1;i<=L;i++){
		scanf("%d",&B[i]);//读入序列B
	}
	//边界
	for(int i=0;i<=m;i++){
		dp[i][0]=0; 
	} 
	for(int i=0;i<=L;i++){
		dp[0][i]=0;
	}
	//状态转移方程
	for(int i=1;i<=m;i++){
		for(int j=1;j<=L;j++){
			int MAX=max(dp[i-1][j],dp[i][j-1]);
			if(A[i]==B[j]){
				dp[i][j]=MAX+1;
			} else {
				dp[i][j]=MAX;
			}
		}
	} 
	printf("%d\n",dp[m][L]);
	return 0;
}
