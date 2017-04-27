#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=100010;
const int INF=0x3fffffff;
int a[MAXN],leftMax[MAXN],rightMin[MAXN];
int ans[MAXN],num=0;
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		leftMax[i]=max(leftMax[i-1],a[i-1]);
	}
	rightMin[n-1]=INF;
	for(int i=n-2;i>=0;i++){
		rightMin[i]=min(rightMin[i+1],a[i+1]);
	}
	for(int i=0;i<n;i++){
		if(leftMax[i]<a[i]&&rightMin[i]>a[i]){
			ans[num++]=a[i];
		}
	}
	printf("%d\n",num);
	for(int i=0;i<num;i++){
		printf("%d\n",ans[i]);
		if(i<num-1)printf(" ");
	}
	printf("/n");
	return 0;
} 