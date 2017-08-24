#include<cstdio>
#include<vector>
using namespace std;
int main(){
	int n,m;
	scanf("%d",&n);
	vector<int> d(n+1);
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
		d[i]+=d[i-1];
	}
	scanf("%d",&m);
	while(m--){
		int ans,a,b;
		scanf("%d%d",&a,&b);
		if(a>b)swap(a,b);
		ans=d[b-1]-d[a-1];
		printf("%d\n",min(d[n]-ans,ans));
	}
	return 0;
}
