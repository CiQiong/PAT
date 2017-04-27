#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXV=510;//��󶥵���
const int INF=1000000000;//�����
//nΪ��������mΪ������st��ed�ֱ�Ϊ�����յ�
//GΪ�ڽӾ��󣬼�¼��Ȩ��weightΪ��Ȩ
//d[]��¼��̾��룬w[]��¼���Ȩֵ֮�ͣ�num[]��¼���·������
int n,m,st,ed;
int G[MAXV][MAXV],weight[MAXV];
int d[MAXV],w[MAXV],num[MAXV];
bool vis[MAXV]={false};//vis[i]==true��ʾ����i�ѷ��ʣ���ֵ��Ϊfalse

void Dijkstra(int s){//sΪ��� 
	fill(d,d+MAXV,INF);
	memset(w,0,sizeof(w));
	memset(num,0,sizeof(num));
	d[s]=0;
	w[s]=weight[s];
	num[s]=1;
	for(int i=0;i<n;i++){//ѭ��n�� 
		int u=-1,MIN=INF;//uʹd[u]��С��MIN��Ÿ���С��d[u]
		for(int j=0;j<n;j++){//�ҵ�δ���ʵĶ�����d[]��С�� 
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			} 
		} 
		//�Ҳ���С��INF��d[u]��˵��ʣ�µĶ�������s����ͨ
		if(u==-1)return;
		vis[u]=true;//���uΪ�ѷ���
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){//��uΪ�н��ʱ����d[v]��С 
					d[v]=d[u]+G[u][v];//����d[v]
					w[v]=w[u]+weight[v];//����w[v]
					num[v]=num[u];//����num[v] 
				}else if(d[u]+G[u][v]==d[v]){//�ҵ�һ����ͬ���ȵ�·�� 
					if(w[v]+weight[v]>w[v]){//��uΪ�н��ʱ��Ȩֵ���� 
						w[v]=w[u]+weight[v];//w[v]�̳���w[u] 
					}
					//���·���������Ȩֵ�޹أ�����д������
					num[v]+=num[u]; 
				}
			} 
		}
	}
} 
int main(){
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	for(int i=0;i<n;i++){
		scanf("%d",&weight[i]);//�����Ȩ 
	}
	int u,v;
	fill(G[0],G[0]+MAXV*MAXV,INF);//��ʼ��ͼG
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		scanf("%d",&G[u][v]);//�����Ȩ
		G[v][u]=G[u][v];//����ͼ�Գ� 
	} 
	Dijkstra(st);//Dijkstra�㷨���
	printf("%d %d\n",num[ed],w[ed]);//��̾������������·���е����Ȩֵ 
	return 0; 
}
 
