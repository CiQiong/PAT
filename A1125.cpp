#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int n;
	int c[10010];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&c[i]);
	}
	sort(c,c+n);
	int ans=0;
	for(int i=0;i<n;i++){
		ans=(ans+c[i])/2;
	}
	printf("%d",ans);
	return 0;
}
