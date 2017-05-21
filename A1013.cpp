//A1013
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N=1111;
vector<int> G[N];//�ڽӾ���
bool vis[N];//��Ƕ���i�Ƿ��ѱ�����

int currentPoint;//��ǰ��Ҫɾ���Ķ�����

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
	scanf("%d%d%d",&n,&m,&k);//���붥��������������ѯ��
	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(b);
		G[b].push_back(a);
	} 
	for(int query=0;query<k;query++){
		scanf("%d",&currentPoint);
		memset(vis,false,sizeof(vis));
		int block=0;//��ͨ�����
		for(int i=1;i<=n;i++){
			if(i!=currentPoint&&vis[i]==false){
				dfs(i);
				block++;
			}
		} 
		printf("%d\n",block-1);//��ͨ�����-1������Ҫ���ӵıߵĸ��� 
	}
	return 0; 
}
