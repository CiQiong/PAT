#include<cstdio>
const int maxn=1000010;
const int INF=0x7fffffff;//int上限 
int S1[maxn]={0};
int S2[maxn]={0};
int main(){
	int n,m;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("&d",&S1[i]);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("&d",&S2[i]);
	}
	S1[n]=S2[m]=INF;
	//使得two pointers在扫描的过程中，可以在一个序列已经扫描完成但count还没到中位数的情况下解决访问越界的问题 
	int mid=(n+m-1)/2;
	int i=0;j=0;
	while(i+j<mid){
		if(S1[i]<S2[j])i++;
		else j++;
	}
	//输出两个序列当前位置较小的元素 
	if(S1[i]<S2[j])printf("%d",S1[i]);
	else printf("%d",S2[j]);
	return 0;
}
