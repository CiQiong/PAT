#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=100005;
int dis[MAXN],A[MAXN];//A[i]��ʾi��i+1λ�õľ��� 
int main(){
	int sum=0,n,left,right;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&A[i]);
		sum+=A[i];
		dis[i]=sum;//dis[i]Ԥ��1��iλ�õľ���֮�ͣ��������Ժ�ļ��� 
	}
	int query;
	scanf("%d",&query);
	while(query--){
		scanf("%d%d",&left,&right);
		if(left>right)swap(left,right);
		int temp=dis[right-1]-dis[left-1];
		printf("%d\n",min(temp,sum-temp));//һ����������·��ȡ���е���С���� 
	} 
	return 0;
}
