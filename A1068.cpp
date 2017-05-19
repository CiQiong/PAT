#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10010;
const int maxv=110;
int w[maxn],dp[maxv]={0};//w[i]为钱币价值 
bool choice[maxn][maxv],flag[maxn];
bool cmp(int a,int b){
	return a>b; 
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&w[i]);
	}
	sort(w+1,w+n+1,cmp);//逆序排序
	for(int i=1;i<=n;i++){
		for(int v=m;v>=w[i];v--){
			if(dp[v]<=dp[v-w[i]]+w[i]){
				dp[v]=dp[v-w[i]]+w[i];
				choice[i][v]=1;//放入第i个物品 
			}
			else choice[i][v]=0;//不放第i个物品 
		} 
	} 
	if(dp[m]!=m)printf("No Solution");//无解
	else {
		
		int k=n,num=0,v=m;
		while(k>=0){
			if(choice[k][v]==1){
				flag[k]=true;
				v-=w[k];
				num++;
			}
			else flag[k]=false;
			k--;
		}
		
		for(int i=n;i>=1;i--){
			if(flag[i]==true){
				printf("%d",w[i]);
				num--;
				if(num>0)printf(" ");
			}
		}
	} 
	return 0;
	
}
