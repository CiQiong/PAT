//A1099
//就是在A1064基础上增加了层序遍历
#include<cstdio>
#include<queue>//层序遍历用
#include<algorithm>//sort
using namespace std;
const int maxn=110;
struct node{//二叉树的静态写法 
	int data;
	int lchild,rchild;
}Node[maxn];
//n为结点个数，in为中序序列，num为已经填入/输出的结点个数
int n,in[maxn],num=0;

void inOrder(int root){
	if(root=-1)return;
	inOrder(Node[root].lchild);
	Node[root].data=in[num++]; 
	inOrder(Node[root].rchild);
} 

void BFS(int root){
	queue<int> q;//队列存的是地址
	q.push(root);//将根结点地址入队
	num=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		printf("%d",Node[now].data);
		num++;
		if(num<n) printf(" ");
		if(Node[now].lchild!=-1) q.push(Node[now].lchild);
		if(Node[now].rchild!=-1) q.push(Node[now].rchild);
	} 
}
int main(){
	int lchild,rchild;
	scanf("%d",&n);//结点个数
	for(int i=0;i<n;i++){
		scanf("%d%d",&lchild,&rchild);
		Node[i].lchild=lchild;
		Node[i].rchild=rchild;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]); 
	} 
	sort(in,in+n);
	inOrder(0);
	BFS(0);
	return 0;
}
