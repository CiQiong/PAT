#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=100;
char A[N],B[N];
int dp[N][N];
int main(){
	int n;
	gets(A+1);//从下表为1开始读入
	gets(B+1);
	int lenA=strlen(A+1);//由于读入时下标从1开始，因此读取长度也从+1开始
	int lenB=strlen(B+1);
	//边界
	for(int i=0;i<=lenA;i++){
		dp[i][0]=0;
	} 
	for(int i=0;i<=lenB;i++){
		dp[0][i]=0;
	} 
	//状态转移方程
	for(int i=1;i<=lenA;i++){
		for(int j=1;j<=lenB;j++){
			if(A[i]==B[j]){
				dp[i][j]=dp[i-1][j-1]+1;
			} else {
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			}
		}
	} 
	printf("%d\n",dp[lenA][lenB]);
	return 0;
} 
