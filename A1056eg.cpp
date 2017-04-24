#include<cstdio>
#include<queue>
using namespace std;
const int maxn=1010;
struct mouse{
	int weight;
	int R;
}mouse[maxn];
int main(){
	int np,ng,order;
	scanf("%d%d",&np,&ng);
	for(int i=0;i<np;i++){
		scanf("%d",&mouse[i].weight);
	}
	queue<int> q;//定义一个队列 
	for(int i=0;i<np;i++){
		scanf("%d",&order);
		q.push(order);
	}
	int temp=np,group;
	while(q.size()!=1){
		
	}
}
