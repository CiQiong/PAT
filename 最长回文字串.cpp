#include<cstdio>
#include<cstring>
const int maxn=1010;
char S[maxn];
int dp[maxn][maxn];//�������������Ƿ�Ϊ����
int main(){
	gets(S);
	int len=strlen(S),ans=1;
	memset(dp,0,sizeof(dp));//dp�����ʼ��Ϊ0
	//�߽�
	for(int i=0;i<len;i++){
		dp[i][i]=1;
		if(i<len-1){
			if(S[i]==S[i+1]){
				dp[i][i+1]=1;
				ans=2;//��ʼ��ʱע�⵱ǰ����Ĵ��ĳ��� 
			}
		}
	} 
	//״̬ת�Ʒ��� 
	for(int L=3;L<=len;L++){//ö���Ӵ��ĳ��� 
		for(int i=0;i+L-1<len;i++){
			int j=i+L-1;//�Ӵ����Ҷ˵�
			if(S[i]==S[j]&&dp[i+1][j-1]==1){
				dp[i][j]=1;
				ans=L;//����������ִ��ĳ��� 
			} 
		} 
	} 
	printf("%d\n",ans);
	return 0;
} 
 
