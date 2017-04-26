#include<cstdio> 
#include<algorithm> 
#include<cmath>
using namespace std;
//平衡二叉树
struct node{
	int v,height;//v为结点权值，height为当前子树高度
	node *lchild,*rchild;//左右孩子节点地址 
}; 
//生成一个新结点，v为结点权值 
node* newNode(int v){
	node* Node=new node;//申请一个node型变量的地址空间
	Node->v=v;
	Node->height=1;
	Node->lchild=Node->rchild=NULL;
	return Node; 
} 
//获取以root为根结点的子树的当前height
int getHeight(node* root){
	if(root==NULL)return 0;
	return root->height;
} 
//计算结点root的平衡因子
int getBalanceFactor(node* root){
	//左子树高度减右子树高度
	return getHeight(root->lchild)-getHeight(root->rchild); 
} 
//更新接结点root的height
void updateHeight(node* root){
	//max(左孩子的height，有孩子的height)+1
	root->height=max(getHeight(root->lchild),getHeight(root->rchild)+1);
} 
//
//一下假设每个结点的权值都不相同 
//
//search函数查找AVL树中数据域为x的结点
void search(node* root,int x){
	if(root==NULL){//空树，查找失败 
		printf("search failed\n");
		return ; 
	}
	if(x==root->v){//查找成功，访问之 
		printf("%d\n",root->v); 
	}else if(x<root->v){
		search(root->lchild,x);
	}else{
		search(root->rchild,x);
	}
} 
//插入操作：
//左旋(Left Rotation)
void L(node* &root){
	node* temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	updateHeight(root);//更新高度 
	updateHeight(temp);//更新高度 
	root=temp;
} 
//右旋(Right Rotatio)
void R(node* &root){
	node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updateHeight(root);//更新高度 
	updateHeight(temp);//更新高度
	root=temp;
} 
//插入权值为v的结点
void insert(node* &root,int v){
	if(root==NULL){//到达空结点 
		root=newNode(v);
		return;
	}
	if(v<root->v){//v比根结点的权值小
		insert(root->lchild,v);//往左子树插入
		updateHeight(root);//更新树高
		if(getBalanceFactor(root)==2){
			if(getBalanceFactor(root->lchild)==1){//LL型 
				R(root);
			}else if(getBalanceFactor(root->lchild)==-1){//LR型 
				L(root->lchild);
				R(root);
			}
		} 
	} else { //v比根结点的权值大 
		insert(root->rchild,v);//往右子树插入
		updateHeight(root);//更新树高
		if(getBalanceFactor(root)==-2){
			if(getBalanceFactor(root->rchild)==-1){//RR型 
				L(root);
			}else if(getBalanceFactor(root->rchild)==1){//RL型 
				R(root->rchild);
				L(root);
			}
		} 
	} 
} 
//AVL树的建立
node* Create(int data[],int n){
	node* root=NULL;//新建空根结点root
	for(int i=0;i<n;i++){
		insert(root,data[i]);//将data[0]~data[n-1]插入AVL树中 
	} 
	return root;//返回根结点 
} 
int main(){
	return 0;
}
