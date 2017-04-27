#include<cstdio>
#include<algorithm>//fill函数 
using namespace std;
const int MAXV=1000;//最大顶点数 
const int INF= 1000000000;//设INF为一个很大的数

int n,m,s,G[MAXV][MAXV];//n为顶点数，m为边数，s为起点
int d[MAXV];//起点到达各点的最短路径长度
bool vis[MAXV]={false};//标记数组，vis[i]==false表明已访问。初值设为false

void Dijkstra(int s){//s为起点 
	fill(d,d+MAXV,INF);//fill函数将整个d数组赋值为INF(慎用memset)
	d[s]=0;//起点s到自身的距离为0
	for(int i=0;i<n;i++){//循环n次 到n个地方 
		int u=-1,MIN=INF;//u使d[u]最小，MIN存放该最小的d[u]（初始化） 
		for(int j=0;j<n;j++){//找到未访问的顶点中d[]最小的 
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		}
		//找不到小于INF的d[u],说明剩下的顶点和起点s不联通
		if(u==-1)return;
		vis[u]=true;//标记u为已访问
		for(int v=0;v<n;v++){
			//如果v未访问&&u能到达v&&以u为中介点可以使d[v]更优
			if(vis[v]==false&&G[u][v]!=INF&&d[u]+G[u][v]<d[v]){
				d[v]=d[u]+G[u][v];//优化d[v] 
			} 
		} 
	} 
} 
int main(){
	int u,v,w;
	scanf("%d%d%d",&n,&m,&s);//n为顶点数，m为边数，s为起点编号
	fill(G[0],G[0]+MAXV*MAXV,INF);//初始化图
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&w);//输入u，v以及u->的边权
		G[u][v]=w; 
	}
	Dijkstra(s);//Dijkstra算法入口
	for(int i=0;i<n;i++){
		printf("%d ",d[i]);//输出所有顶点的最短距离 
	}
	return 0;
} 
