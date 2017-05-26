//Dijkstra
#include<vector>
#include<cstdio>
#include<algorithm>//fill函数 
using namespace std;

const int MAXV=1000;
const int INF=1000000000;



//最短距离求解 
/* 
//邻接矩阵版 
int n,G[MAXV][MAXV];//n为顶点数，MAXV为最大顶点数
int d[MAXV];//起点到达各点的最短路径长度
bool vis[MAXV]={false};//标记数组

void Dijkstra(int s){//s为起点
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
		//找不到小于INF的d[u]，说明剩下的顶点和起点s不连通 
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
//邻接表版
struct Node{
	int v,dis;//v为边的目标顶点，dis为边权 
}; 
vector<Node> Adj[MAXV];//图G，Adj[u]存放从顶点u出发可以到达的所有顶点
int n;//n为顶点数，图G使用邻接表实现，MAXV为最大顶点数
int d[MAXV];//起点到达各点的最短路径长度
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
//最短路径求解
int n,G[MAXV][MAXV];
int d[MAXV];
int pre[MAXV];//pre[v]表示从起点到顶点v的最短路径上v的前一个顶点
int vis[MAXV]={false};

int cost[MAXV][MAXV];//边权 
int c[MAXV];

int weight[MAXV][MAXV];//点权
int w[MAXV]; 

int num[MAXV]={0};//最短路径条数 

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
			//	pre[v]=u;//记录v的前驱顶点是u 
			//}
			if(vis[v]==false&&G[u][v]!=INF){
				if(G[u][v]+d[u]<d[v]){//以u为中介点可以使d[v]更优 
					d[v]=G[u][v]+d[u];
					c[v]=c[u]+cost[u][v];
					w[v]=w[u]+weight[u][v];
					num[v]=num[u];
				} else if(d[u]+G[u][v]==d[v]){
					if(w[u]+weight[u][v]==w[v]&&c[u]+cost[u][v]<c[v]){
						c[v]=c[u]+cost[u][v];//最短距离相同时看是否能使c[v]更优
					} else if(w[u]+weight[u][v]<w[v]){
						w[v]=w[u]+weight[u][v];
					}
					num[v]+=num[u];
				}
			} 
		}
	}
} 

void DFS(int s,int v){//s为起点编号，v为当前访问的顶点编号（从中点开始递归）
	if(v==s){
		printf("%d\n",s);
		return;
	} 
	DFS(s,pre[v]);//递归访问v的前驱顶点pre[v] 
	printf("%d\n",v);//从最深层return回来之后，输出每一层的顶点号 
}
*/ 

int n,G[MAXV][MAXV];
int d[MAXV];
int vis[MAXV]={false};

vector<int> pre[MAXV];
void Dijkstra(int s){//s为起点
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
int optvalue;//第二标尺最优值
vector<int> path,tempPath;//最优路径、临时路径
void DFS(int v){//v为当前访问结点
	//递归边界
	if(v==vs){//如果到达了叶子结点st（即路径的起点） 
		tempPath.push_back(v);//将st加入临时路径tempPath的最后面 
		int value;//存放临时路径tempPath的第二标尺的值 
		计算路径tempPath上的value值;
		if(value优于optvalue){
			optvalue=value;//更新第二标尺最优值与最优路径 
			path=tempPath;
		} 
		tempPath.pop_back();//将刚加入的结点删除
		return; 
	} 
	//递归式
	tempPath.push_back(v);//将当前访问结点加入临时路径tempPath后面
	for(int i=0;i<pre[v].size();i++){
		DFS(pre[v][i]);//结点v的前驱结点pre[v][i]，递归 
	} 
	tempPath.pop_back();//遍历玩所有前驱结点，将当前结点v删除。 
}

int main(){
	
	return 0;
}
