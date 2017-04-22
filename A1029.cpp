#include<cstdio>
const int maxn=1000010;
const int INF=0x7fffffff;//int���� 
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
	//ʹ��two pointers��ɨ��Ĺ����У�������һ�������Ѿ�ɨ����ɵ�count��û����λ��������½������Խ������� 
	int mid=(n+m-1)/2;
	int i=0;j=0;
	while(i+j<mid){
		if(S1[i]<S2[j])i++;
		else j++;
	}
	//����������е�ǰλ�ý�С��Ԫ�� 
	if(S1[i]<S2[j])printf("%d",S1[i]);
	else printf("%d",S2[j]);
	return 0;
}
