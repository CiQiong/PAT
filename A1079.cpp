#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=100010;
struct node{
	double data;//数据域 
	vector<int> child;//指针域 
}Node[maxn];//存放树 
int n;
double p,r,ans=0;
void DFS(int index,int depth){
	if(Node[index].child.size()==0){//到达叶结点 
		ans+=Node[index].data*pow(1+r,depth);//累加叶结点货物的价格 
		return;
	}
	for(int i=0;i<Node[index].child.size();i++){
		DFS(Node[index].child[i],depth+1);//递归访问子结点 
	} 
} 
int main(){
	int k,child;
	scanf("%d%lf%lf",&n,&p,&r);
	r/=100;
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		if(k==0){
			scanf("%lf",Node[i].data);
		}else{
			for(int j=0;j<k;j++){
				scanf("%d",&child);
				Node[i].child.push_back(child);
			}
		}
	}
	DFS(0, 0);
	printf("%.1f\n",p*ans);
	return 0;
}
