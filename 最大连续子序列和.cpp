#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10010;
int A[maxn],dp[maxn];//A[]存放序列,dp[i]存放以A[i]结尾的连续序列的最大和
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){//读入序列 
		scanf("%d",&A[i]);
	}
	//边界
	dp[0]=A[0];
	for(int i=1;i<n;i++){
		//状态转移方程
		dp[i]=max(A[i],dp[i-1]+A[i]); 
	} 
	//dp[i]存放A[i]结尾的连续序列的最大和，需要遍历i得到的最大的才是结果
	int k=0;
	for(int i=1;i<n;i++){
		if(dp[i]>dp[k]){
			k=i;
		}
	} 
	printf("%d",dp[k]);
	return 0;
} 
