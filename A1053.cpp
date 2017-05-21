#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=110;
struct node{
	int weight;//数据域
	vector<int> child;//指针域 
}Node[MAXN];//结点数组 
bool cmp(int a,int b){
	return Node[a].weight>Node[b].weight;
} 
int n,m,S;//结点数，边数，给定的和
int path[MAXN];//记录路径
//当前访问结点为index，numNode为当前路径path上的结点个数,sum为当前结点点权和
void DFS(int index,int numNode,int sum){
	if(sum>S) return;
	if(sum==S){
		if(Node[index].child.size()!=0) return;
		//到达叶子结点，此时path[]中存放了一条完整的路径，输出它
		for(int i=0;i<numNode;i++){
			printf("%d",Node[path[i]].weight);
			if(i<numNode-1)printf(" ");
			else printf("\n");
		} 
		return;
	}
	//if(sum<S)
	for(int i=0;i<Node[index].child.size();i++){//枚举所有子结点 
		int child=Node[index].child[i];//结点index的第i个子结点 
		path[numNode]=child;//将结点child添加到路径path末尾 
		DFS(child,numNode+1,sum+Node[child].weight);
	}
} 
int main(){
	scanf("%d%d%d",&n,&m,&S);//n个数据，m个非叶子结点，S为要求相等的权值和 
	for(int i=0;i<n;i++){
		scanf("%d",&Node[i].weight);
	}
	int id,k,child;
	for(int i=0;i<m;i++){
		scanf("%d%d",&id,&k);//结点编号及孩子结点的个数
		for(int j=0;j<k;j++){
			scanf("%d",&child);
			Node[id].child.push_back(child); 
		} 
		//对每个非叶子结点的所有子结点排序 
		sort(Node[id].child.begin(),Node[id].child.end(),cmp);//排序 
	} 
	path[0]=0;//路径的第一个结点设置为0号结点
	DFS(0,1,Node[0].weight);
	return 0; 
} 
