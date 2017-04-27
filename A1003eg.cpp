#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXV=510;//最大顶点数
const int INF=1000000000;//无穷大
//n为顶点数，m为边数，st和ed分别为起点和终点
//G为邻接矩阵，记录边权，weight为点权
//d[]记录最短距离，w[]记录最大权值之和，num[]记录最短路径条数
int n,m,st,ed;
int G[MAXV][MAXV],weight[MAXV];
int d[MAXV],w[MAXV],num[MAXV];
bool vis[MAXV]={false};//vis[i]==true表示顶点i已访问，初值均为false

void Dijkstra(int s){//s为起点 
	fill(d,d+MAXV,INF);
	memset(w,0,sizeof(w));
	memset(num,0,sizeof(num));
	d[s]=0;
	w[s]=weight[s];
	num[s]=1;
	for(int i=0;i<n;i++){//循环n次 
		int u=-1,MIN=INF;//u使d[u]最小，MIN存放该最小的d[u]
		for(int j=0;j<n;j++){//找到未访问的顶点中d[]最小的 
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			} 
		} 
		//找不到小于INF的d[u]，说明剩下的顶点和起点s不联通
		if(u==-1)return;
		vis[u]=true;//标记u为已访问
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=INF){
				if(d[u]+G[u][v]<d[v]){//以u为中介点时能令d[v]变小 
					d[v]=d[u]+G[u][v];//覆盖d[v]
					w[v]=w[u]+weight[v];//覆盖w[v]
					num[v]=num[u];//覆盖num[v] 
				}else if(d[u]+G[u][v]==d[v]){//找到一条相同长度的路径 
					if(w[v]+weight[v]>w[v]){//以u为中介点时点权值更大 
						w[v]=w[u]+weight[v];//w[v]继承自w[u] 
					}
					//最短路径条数与点权值无关，必须写在外面
					num[v]+=num[u]; 
				}
			} 
		}
	}
} 
int main(){
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	for(int i=0;i<n;i++){
		scanf("%d",&weight[i]);//读入点权 
	}
	int u,v;
	fill(G[0],G[0]+MAXV*MAXV,INF);//初始化图G
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		scanf("%d",&G[u][v]);//读入边权
		G[v][u]=G[u][v];//无向图对称 
	} 
	Dijkstra(st);//Dijkstra算法入口
	printf("%d %d\n",num[ed],w[ed]);//最短距离条数，最短路径中的最大权值 
	return 0; 
}
 
