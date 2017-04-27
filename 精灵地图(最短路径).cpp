#include<cstdio>
#include<algorithm>//fill���� 
using namespace std;
const int MAXV=1000;//��󶥵��� 
const int INF= 1000000000;//��INFΪһ���ܴ����

int n,m,s,G[MAXV][MAXV];//nΪ��������mΪ������sΪ���
int d[MAXV];//��㵽���������·������
bool vis[MAXV]={false};//������飬vis[i]==false�����ѷ��ʡ���ֵ��Ϊfalse

void Dijkstra(int s){//sΪ��� 
	fill(d,d+MAXV,INF);//fill����������d���鸳ֵΪINF(����memset)
	d[s]=0;//���s������ľ���Ϊ0
	for(int i=0;i<n;i++){//ѭ��n�� ��n���ط� 
		int u=-1,MIN=INF;//uʹd[u]��С��MIN��Ÿ���С��d[u]����ʼ���� 
		for(int j=0;j<n;j++){//�ҵ�δ���ʵĶ�����d[]��С�� 
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		//�Ҳ���С��INF��d[u],˵��ʣ�µĶ�������s����ͨ
		if(u==-1)return;
		vis[u]=true;//���uΪ�ѷ���
		for(int v=0;v<n;v++){
			//���vδ����&&u�ܵ���v&&��uΪ�н�����ʹd[v]����
			if(vis[v]==false&&G[u][v]!=INF&&d[u]+G[u][v]<d[v]){
				d[v]=d[u]+G[u][v];//�Ż�d[v] 
			} 
		} 
	} 
} 
int main(){
	int u,v,w;
	scanf("%d%d%d",&n,&m,&s);//nΪ��������mΪ������sΪ�����
	fill(G[0],G[0]+MAXV*MAXV,INF);//��ʼ��ͼ
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);//����u��v�Լ�u->�ı�Ȩ
		G[u][v]=w; 
	}
	Dijkstra(s);//Dijkstra�㷨���
	for(int i=0;i<n;i++){
		printf("%d ",d[i]);//������ж������̾��� 
	}
	return 0;
} 
