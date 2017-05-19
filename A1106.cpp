#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=100010;
const double INF=1e12;//10^12
vector<int> Node[maxn];//Node[i]存放i的所有孩子结点的编号
int n,num=0;//n为结点数，num为价格最低的叶子结点的个数
double p,r,ans=INF;//ans为最低叶子结点价格
void DFS(int index,int depth){
	if(Node[index].size()==0){
		double price=p*pow(1+r,depth);//当前价格
		if(price<ans){
			ans=price;
			num=1;
		} else if(price==ans){
			num++;
		}
		return;
	}
	for(int i=0;i<Node[index].size();i++){
		DFS(Node[index][i],depth+1);
	}
} 
int main(){
	int k,child;
	scanf("%d%lf%lf",&n,&p,&r);
	r/=100;
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		if(k!=0){
			for(int j=0;j<k;j++){
				scanf("%d",&child);
				Node[i].push_back(child);
			}
		}
	}
	DFS(0,0);//DFS入口
	printf("%.4f %d\n",ans,num);//输出结果
	return 0; 
}
