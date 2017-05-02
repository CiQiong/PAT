//prime算法最小生成树 
#include<cstdio>
#include<cstring>
#include<algorithm>
const int MAXV=1000;//最大顶点数 
const int INF=1000000000;//设INF为一个很大的数

int n,G[MAXV][MAXV];//n为顶点数，MAXV为最大顶点数
int d[MAXV];//顶点与集合S的最短距离////////////// 
bool vis[MAXV]={false};//标记数组，true表示已经访问，初始值为false

int prime(){//默认0为初始点，函数返回最小生成树的边权之和 
	fill(d,d+MAXV,INF);//fill将数组初始值设为INF(慎用memset)
	d[0]=0;//只有0号点到集合的距离为0，其余为INF
	int ans=0;//存放最小生成树的边权之和//////////// 
	for(int i=0;i<n;i++){//循环n次 
		int u=-1,MIN=INF;//u使d[u]最小，MIN存放最小的d[u]
		for(int j=0;j<n;j++){//找到为访问的顶点中d[]最小的 
			if(vis[j]==false&&d[j]<MIN){
				u=j;
				MIN=d[j];
			}
		} 
		//找不到小于INF的d[u],则剩下的顶点和集合不联通
		if(u==-1)return -1;
		vis[u]=true;//标记u为已访问
		ans+=d[u];//将与集合s距离最小的边加入最小生成树
		for(int v=0;v<n;v++){
			//v未被访问&&且u能到达v&&以u为中介能使v到集合s最近
			if(vis[v]==false&&G[u][v]!=INF&&G[u][v]<d[v]){
				d[v]=G[u][v];///////////// 
			} 
		} 
	} 
	return ans;//返回最小生成树的边权之和 
} 
