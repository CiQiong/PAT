#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=50;
struct node{
	int data;
	node* lchild;
	node* rchild;
};
int pre[maxn],in[maxn],post[maxn];//先序、中序以及后序
int n;//结点个数

//当前二叉树的后序区间为[postL,postR],中序序列为[inL,inR]
//create函数返回构建出的二叉树的根结点的地址
node* create(int postL,int postR,int inL,int inR){
	if(postL>postR ) return NULL;//若后序序列长度小于等于0，则直接返回
	node* root=new node;//新建一个结点，用来存放二叉树的根结点
	root->data=post[postR];//新节点的数据域为根结点的值
	int k;//中序序列中根结点的地址
	for(k=inL;k<=inR;k++){
		if(in[k]==post[postR])break;//找到中序序列中根结点的地址 
	} 
	int numLeft=k-inL;//左子树的结点个数 
	//以右序序列和中序序列左子树两端的结点地址为基准的create返回左子树根结点地址 
	root->lchild=create(postL,postL+numLeft-1,inL,k-1); 
	//返回右子树的根结点地址，赋值给root的右指针
	root->rchild=create(postL+numLeft,postR-1,k+1,inR);
	return root;//返回根结点地址 
} 

int num=0;//已输出的结点个数
void BFS(node* root){
	queue<node*>q;//队列用来存地址
	q.push(root);//将根结点地址入队
	while(!q.empty()){
		node* now=q.front();//取出队首元素
		q.pop();
		printf("%d",now->data);//访问队首元素
		num++;
		if(num<0)printf(" ");
		if(now->lchild!=NULL) q.push(now->lchild);//左子树非空/////////只入队一个吗？ 
		if(now->rchild!=NULL) q.push(now->rchild);//右子树非空 
	} 
} 
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&post[i]);
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]);
	}
	node* root=create(0,n-1,0,n-1);//建树
	BFS(root);//层序遍历
	return 0; 
} 
















