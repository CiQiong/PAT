#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXV=110;
const int MAXE=10010;
//边集定义部分
struct edge{
	int u,v;//边的两个端点号
	int cost;//边权 
}E[MAXE];//最多有MAXE条边 
bool cmp(edge a,edge b){
	return a.cost<b.cost;
} 
//并查集部分
int father[MAXV];//并查集数组
int findfather(int x){//并查集查询函数 
	int a=x;
	while(x!=father[x]){
		x=father[x];
	}
	//路径压缩
	while(a!=father[a]){
		int z=a;
		a=father[a];
		father[z]=x;
	} 
	return x;
} 
//kruskal部分,返回最小生成树的边权之和，参数n为顶点个数，m为图的边数
int kruskal(int n,int m){
	//ans为所求边权之和，Num_Edge为当前生成树的边数
	int ans=0,Num_Edge=0;
	for(int i=0;i<n;i++){
		father[i]=i;
	} 
	sort(E,E+m,cmp);
	for(int i=0;i<m;i++){//枚举所有边 
		int faU=findfather(E[i].u);
		int faV=findfather(E[i].v);
		if(faU!=faV){
			father[faU]=faV;
			ans+=E[i].cost;
			Num_Edge++;
			if(Num_Edge==n-1)break;
		} 
	}
	if(Num_Edge!=n-1) return -1;
	else return ans;
} 
int main(){
	int n,m;
	scanf("%d%d",&n,&m);//顶点数，边数 
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&E[i].u,&E[i].v,&E[i].cost);
	} 
	int ans=kruskal(n,m);
	printf("%d\n",ans);
	return 0;
}
