//prime�㷨��С������ 
#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXV=1000;//��󶥵��� 
const int INF=1000000000;//��INFΪһ���ܴ����

int n,G[MAXV][MAXV];//nΪ��������MAXVΪ��󶥵���
int d[MAXV];//�����뼯��S����̾���////////////// 
bool vis[MAXV]={false};//������飬true��ʾ�Ѿ����ʣ���ʼֵΪfalse

int prime(){//Ĭ��0Ϊ��ʼ�㣬����������С�������ı�Ȩ֮�� 
	fill(d,d+MAXV,INF);//fill�������ʼֵ��ΪINF(����memset)
	d[0]=0;//ֻ��0�ŵ㵽���ϵľ���Ϊ0������ΪINF
	int ans=0;//�����С�������ı�Ȩ֮��//////////// 
	for(int i=0;i<n;i++){//ѭ��n�� 
		int u=-1,MIN=INF;//uʹd[u]��С��MIN�����С��d[u]
		for(int j=0;j<n;j++){//�ҵ�Ϊ���ʵĶ�����d[]��С�� 
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		} 
		//�Ҳ���С��INF��d[u],��ʣ�µĶ���ͼ��ϲ���ͨ
		if(u==-1)return -1;
		vis[u]=true;//���uΪ�ѷ���
		ans+=d[u];//���뼯��s������С�ı߼�����С������
		for(int v=0;v<n;v++){
			//vδ������&&��u�ܵ���v&&��uΪ�н���ʹv������s���
			if(vis[v]==false&&G[u][v]!=INF&&G[u][v]<d[v]){
				d[v]=G[u][v];///////////// 
			} 
		} 
	} 
	return ans;//������С�������ı�Ȩ֮�� 
} 
