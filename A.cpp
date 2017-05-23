//A1018
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXV=510;
const int INF=1000000000;

//n��������m������Cmax���������Sp����վ��
//G�ڽӾ���weight��Ȩ��d[]��̾���
//minNeed��¼����Я������Ŀ��minRemain��¼���ٴ��ص���Ŀ
int n,m,Cmax,Sp,numPath=0,G[MAXV][MAXV],weight[MAXV];
int d[MAXV],minNeed=INF,minRemain=INF;
bool vis[MAXV]={false};
vector<int> pre[MAXV];//ǰ��
vector<int> tempPath,path;//��ʱ·��������·��

void Dijkstra(int s){//sΪ��� 
	fill(d,d+MAXV,INF);
	d[s]=0;
	for(int i=0;i<=n;i++){//ѭ��n+1��
		int u=-1,MIN=INF;
		for(int j=0;j<=n;j++){
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		} 
		//�Ҳ���С��INF��d[u]��˵��ʣ�µĶ������㲻��ͨ
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<=n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				} else if(d[u]+G[u][v]==d[v]){
					pre[v].push_back(u);
				}
			}
		} 
	}
} 

void DFS(int v){
	if(v==0){//�ݹ�߽磬Ҷ�ӽ��
		tempPath.push_back(v);
		//·��tempPath����ҪЯ������Ŀ����Ҫ���ص���Ŀ
		int need=0,remain=0;
		for(int i=tempPath.size()-1;i>=0;i--){//���뵹��ö��
			int id=tempPath[i];//��ǰ�����Ϊid
			if(weight[id]>0){
				remain+=weight[id];
			} else {
				if(remain>abs(weight[id])){
					remain-=abs(weight[id]);
				} else {
					need+=abs(weight[id])-remain;
					remain=0;
				}
			}
		} 
		if(need<minNeed){
			minNeed=need;
			minRemain=remain;
			path=tempPath;
		} else if(need==minNeed&&remain<minRemain){
			minRemain=remain;
			path=tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(v);
	for(int i=0;i<pre[v].size();i++){
		DFS(pre[v][i]);
	}
	tempPath.pop_back();
}

int main(){
	scanf("%d%d%d%d",&Cmax,&n,&Sp,&m);
	int u,v;
	fill(G[0],G[0]+MAXV*MAXV,INF);
	for(int i=1;i<=n;i++){
		scanf("%d",&weight[i]);
		weight[i]-=Cmax/2;
	}
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		scanf("%d",&G[u][v]);
		G[v][u]=G[u][v];
	}
	Dijkstra(0);
	DFS(Sp);
	printf("%d",minNeed);
	for(int i=path.size()-1;i>=0;i--){
		printf("%d",path[i]);
		if(i>0) printf("->");
	}
	printf(" %d",minRemain);
	return 0;
}