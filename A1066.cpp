//A1066
#include<cstdio>
#include<algorithm>
using namespace std;
struct node{
	int v,height;
	node *lchild, *rchild;
} *root;

node* newNode(int v){
	node* Node=new node;
	Node->v;
	Node->height=1;
	Node->lchild=Node->rchild=NULL;
	return Node;//返回新建结点的地址 
}

//获取以root为根结点的子树的当前height 
int getHeight(node* root){
	if(root==NULL) return 0;//空结点高度为0
	return root->height; 
}

void updateHeight(node* root){
	root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

int getBalanceFactor(node* root){
	return getHeight(root->lchild)-getHeight(root->rchild); 
}

//左旋
void L(node* &root){
	node* temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
} 
//右旋
void R(node* &root){
	node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updateHeight(root);
	updateHeight(temp);
	root=temp;
} 

//插入权值为v的结点
void insert(node* &root,int v){
	if(root==NULL){//到达空结点 
		root=newNode(v);
		return;
	}
	if(v<root->v){
		insert(root->lchild,v);
		updateHeight(root);
		if(getBalanceFactor(root)==2){
			if(getBalanceFactor(root->lchild)==1){
				R(root);
			}else if(getBalanceFactor(root->lchild)==-1){
				L(root->lchild);
				R(root);
			}
		} 
	} else {//v比根结点权值大 
		insert(root->rchild,v);
		updateHeight(root);
		if(getBalanceFactor(root)==-2){
			if(getBalanceFactor(root->rchild)==-1){
				L(root);
			} else if(getBalanceFactor(root->rchild)==1){
				R(root->rchild);
				L(root);
			}
		}
	}
} 

//ALV树的建立
node* Create(int data[],int n){
	node* root=NULL;
	for(int i=0;i<n;i++){
		insert(root,data[i]);
	}
	return root;
} 

int main(){
	int n,v;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		insert(root,v);
	}
	printf("%d\n",root->v);
	return 0;
}
