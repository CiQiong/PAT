#include<cstdio>
const int N=54;
char mp[6]={"SHCDJ"};
int start[55],end[55],next[55];
int main(){
	int K;
	scanf("%d",&K);
	for(int i=1;i<=N;i++){
		start[i]=i;
		scanf("%d",&next[i]);
	}
	while(K--)
	{
		for(int i=1;i<=N;i++){
			end[next[i]]=start[i];
		}
		for(int i=1;i<=N;i++){
			start[i]=end[i];
		}
	}
	for(int i=1;i<=N;i++){
		if(i!=1)printf(" ");
		end[i]--;
		printf("%c%d",mp[end[i]/13],end[i]%13+1);
	}
	return 0;
}
