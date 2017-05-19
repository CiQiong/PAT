//A1045
/*
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxc=210;//�����ɫ��
const int maxn=10010;//���L
int HashTable[maxc];//����ϲ������ɫ����ӳ��Ϊ�������У���ϲ������ɫӳ��Ϊ-1
int A[maxn],dp[maxn];//����½������е�ԭ����A��DP����
int main(){
	int n,m,x;
	scanf("%d%d",&n,&m);//��ʵn�ò���
	memset(HashTable,-1,sizeof(HashTable));//���������ʼ��Ϊ-1
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		HashTable[x]=i;
	} 
	int L,num=0;//num�����ɫ������Evaϲ������ɫ������
	for(int i=0;i<L;i++){
		scanf("%d",&x);
		if(HashTable[x]>=0){//����ϲ������ɫ����ӵ�A������ 
			A[num++]=HashTable[x]; 
		}
	} 
	//����ȫΪLIS�����ģ��
	int ans=-1;
	for(int i=0;i<num;i++){
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(A[j]<=A[i]&&dp[i]<dp[j]+1){
				dp[i]=dp[j]+1;
			} 
		}
		ans=max(ans,dp[i]);
	} 
	printf("%d\n",ans);
	return 0;
} 
*/
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxc=210;
const int maxn=10010;
int A[maxc],B[maxn],dp[maxc][maxn];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&A[i]);//��������A 
	}
	int L;
	scanf("%d",&L);
	for(int i=1;i<=L;i++){
		scanf("%d",&B[i]);//��������B
	}
	//�߽�
	for(int i=0;i<=m;i++){
		dp[i][0]=0; 
	} 
	for(int i=0;i<=L;i++){
		dp[0][i]=0;
	}
	//״̬ת�Ʒ���
	for(int i=1;i<=m;i++){
		for(int j=1;j<=L;j++){
			int MAX=max(dp[i-1][j],dp[i][j-1]);
			if(A[i]==B[j]){
				dp[i][j]=MAX+1;
			} else {
				dp[i][j]=MAX;
			}
		}
	} 
	printf("%d\n",dp[m][L]);
	return 0;
}
