#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int dis[MAXN],A[MAXN];//A[i]表示i到i+1位置的距离 
int main(){
	int sum=0,n,left,right;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		sum+=A[i];
		dis[i]=sum;//dis[i]预存1到i位置的距离之和，减少了以后的计算 
	}
	int query;
	scanf("%d",&query);
	while(query--){
		scanf("%d%d",&left,&right);
		if(left>right)swap(left,right);
		int temp=dis[right-1]-dis[left-1];
		printf("%d\n",min(temp,sum-temp));//一定有两条线路，取其中的最小距离 
	} 
	return 0;
}
