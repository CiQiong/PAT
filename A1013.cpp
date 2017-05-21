//A1013
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=1111;
vector<int> G[N];//邻接矩阵
bool vis[N];//标记顶点i是否已被访问

int currentPoint;//当前需要删除的顶点编号

void dfs(int v){
	if(v==currentPoint) return;
	vis[v]=true;
	for(int i=0;i<G[v].size();i++){
		if(G[v][i]==false){
			dfs(G[v][i]);
		}
	}
} 

int n,m,k;
int main(){
	scanf("%d%d%d",&n,&m,&k);//输入顶点数、边数、查询数
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	} 
	for(int query=0;query<k;query++){
		scanf("%d",&currentPoint);
		memset(vis,false,sizeof(vis));
		int block=0;//连通块个数
		for(int i=1;i<=n;i++){
			if(i!=currentPoint&&vis[i]==false){
				dfs(i);
				block++;
			}
		} 
		printf("%d\n",block-1);//连通块个数-1就是需要增加的边的个数 
	}
	return 0; 
}
