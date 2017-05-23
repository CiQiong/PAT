#include<cstdio>
#include<algorithm>
using namespace std;
int aa[100005]={0};
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&aa[i]);
	}
	sort(aa,aa+n);
	int i=0,j=n-1;
	while(i<j){
		if(aa[i]+aa[j]==m){
			printf("%d %d",aa[i],aa[j]);
			return 0;
		}
		else if(aa[i]+aa[j]<m)i++;
		else j--;
	}
	printf("No Solution");
	return 0;
}
