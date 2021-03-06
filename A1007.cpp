#include<cstdio>
const int maxn=10010;
int a[maxn],dp[maxn];//a[i]存放序列，dp[i]存放以a[i]结尾的连续序列的最大和
int s[maxn]={0};//s[i]表示产生dp[i]的连续序列从a的哪一个元素开始
int main(){
	int n;
	scanf("%d",&n);
	bool flag=false;//flag表示数组a中是否全小于0
	for(int i=0;i<n;i++){//读入序列
		scanf("%d",&a[i]);
		if(a[i]>=0)flag=true;//只要有一个数>=0,flag就记true 
	} 
	if(flag==false){
		printf("0 %d %d\n",a[0],a[n-1]);
		return 0;
	} 
	//边界
	dp[0]=a[0];
	for(int i=1;i<n;i++){
		//状态转移方程
		if(dp[i-1]+a[i]>a[i]){
			dp[i]=dp[i-1]+a[i];
			s[i]=s[i-1];
		} else {
			dp[i]=a[i];
			s[i]=i;
		}
	} 
	//因为dp[i]存放的是以a[i]结尾的连续序列的最大和
	//因此需要遍历i得到的最大的才是结果
	int k=0;
	for(int i=1;i<n;i++){
		if(dp[i]>dp[k]){
			k=i;
		}
	} 
	printf("%d %d %d\n",dp[k],a[s[k]],a[k]);
	return 0;
}
