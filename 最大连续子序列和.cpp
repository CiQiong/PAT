#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=10010;
int A[maxn],dp[maxn];//A[]�������,dp[i]�����A[i]��β���������е�����
int main(){
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){//�������� 
		scanf("%d",&A[i]);
	}
	//�߽�
	dp[0]=A[0];
	for(int i=1;i<n;i++){
		//״̬ת�Ʒ���
		dp[i]=max(A[i],dp[i-1]+A[i]); 
	} 
	//dp[i]���A[i]��β���������е����ͣ���Ҫ����i�õ������Ĳ��ǽ��
	int k=0;
	for(int i=1;i<n;i++){
		if(dp[i]>dp[k]){
			k=i;
		}
	} 
	printf("%d",dp[k]);
	return 0;
} 
