//Dijkstra
#include<vector>
#include<cstdio>
#include<algorithm>//fill���� 
using namespace std;

const int MAXV=1000;
const int INF=1000000000;



//��̾������ 
/* 
//�ڽӾ���� 
int n,G[MAXV][MAXV];//nΪ��������MAXVΪ��󶥵���
int d[MAXV];//��㵽���������·������
bool vis[MAXV]={false};//�������

void Dijkstra(int s){//sΪ���
	fill(d,d+MAXV,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		//�Ҳ���С��INF��d[u]��˵��ʣ�µĶ�������s����ͨ 
		if(u==-1) return;
		
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=INF&&d[u]+G[u][v]<d[v]){
				d[v]=d[u]+G[u][v];
			}
		} 
	} 
} 
*/ 

/*
//�ڽӱ��
struct Node{
	int v,dis;//vΪ�ߵ�Ŀ�궥�㣬disΪ��Ȩ 
}; 
vector<Node> Adj[MAXV];//ͼG��Adj[u]��ŴӶ���u�������Ե�������ж���
int n;//nΪ��������ͼGʹ���ڽӱ�ʵ�֣�MAXVΪ��󶥵���
int d[MAXV];//��㵽���������·������
bool vis[MAXV]={false};

void Dijkstra(int s){
	fill(d,d+MAXV,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int MIN=INF,u=-1;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		
		for(int j=0;j<Adj[u].size();j++){
			if(vis[j]==false&&d[u]+Adj[u][j].dis<d[j]){
				d[j]=Adj[u][j].dis+d[u];
			}
		}
	}
} 
*/
/* 
//���·�����
int n,G[MAXV][MAXV];
int d[MAXV];
int pre[MAXV];//pre[v]��ʾ����㵽����v�����·����v��ǰһ������
int vis[MAXV]={false};

int cost[MAXV][MAXV];//��Ȩ 
int c[MAXV];

int weight[MAXV][MAXV];//��Ȩ
int w[MAXV]; 

int num[MAXV]={0};//���·������ 

void Dijkstra(int s){
	fill(d,d+MAXV,INF);
	for(int i=0;i<n;i++){
		pre[i]=i;
	}
	d[s]=0;
	
	num[s]=1;
	
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			//if(vis[v]==false&&G[u][v]!=INF&&G[u][v]+d[u]<d[v]){
			//	d[v]=G[u][v]+d[u];
			//	pre[v]=u;//��¼v��ǰ��������u 
			//}
			if(vis[v]==false&&G[u][v]!=INF){
				if(G[u][v]+d[u]<d[v]){//��uΪ�н�����ʹd[v]���� 
					d[v]=G[u][v]+d[u];
					c[v]=c[u]+cost[u][v];
					w[v]=w[u]+weight[u][v];
					num[v]=num[u];
				} else if(d[u]+G[u][v]==d[v]){
					if(w[u]+weight[u][v]==w[v]&&c[u]+cost[u][v]<c[v]){
						c[v]=c[u]+cost[u][v];//��̾�����ͬʱ���Ƿ���ʹc[v]����
					} else if(w[u]+weight[u][v]<w[v]){
						w[v]=w[u]+weight[u][v];
					}
					num[v]+=num[u];
				}
			} 
		}
	}
} 

void DFS(int s,int v){//sΪ����ţ�vΪ��ǰ���ʵĶ����ţ����е㿪ʼ�ݹ飩
	if(v==s){
		printf("%d\n",s);
		return;
	} 
	DFS(s,pre[v]);//�ݹ����v��ǰ������pre[v] 
	printf("%d\n",v);//�������return����֮�����ÿһ��Ķ���� 
}
*/ 

int n,G[MAXV][MAXV];
int d[MAXV];
int vis[MAXV]={false};

vector<int> pre[MAXV];
void Dijkstra(int s){//sΪ���
	fill(d,d+MAXV,INF);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,MIN=INF;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if(d[v]+G[u][v]==d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
} 
int optvalue;//�ڶ��������ֵ
vector<int> path,tempPath;//����·������ʱ·��
void DFS(int v){//vΪ��ǰ���ʽ��
	//�ݹ�߽�
	if(v==vs){//���������Ҷ�ӽ��st����·������㣩 
		tempPath.push_back(v);//��st������ʱ·��tempPath������� 
		int value;//�����ʱ·��tempPath�ĵڶ���ߵ�ֵ 
		����·��tempPath�ϵ�valueֵ;
		if(value����optvalue){
			optvalue=value;//���µڶ��������ֵ������·�� 
			path=tempPath;
		} 
		tempPath.pop_back();//���ռ���Ľ��ɾ��
		return; 
	} 
	//�ݹ�ʽ
	tempPath.push_back(v);//����ǰ���ʽ�������ʱ·��tempPath����
	for(int i=0;i<pre[v].size();i++){
		DFS(pre[v][i]);//���v��ǰ�����pre[v][i]���ݹ� 
	} 
	tempPath.pop_back();//����������ǰ����㣬����ǰ���vɾ���� 
}

int main(){
	
	return 0;
}
