#include<cstdio>


int DP(int i){
	if(dp[i]>0)return dp[i];
	for(int j=0;j<n;j++){
		if(G[i][j]!=INF){
			dp[i]=max(dp[i],DP[j]+G[i][j]); 
		}
	} 
	return dp[i];
}
