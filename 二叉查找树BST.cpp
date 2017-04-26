#include<queue>
#include<cstdio>
using namespace std;
//寻找以root为根结点的书中最大全权值点 
node* findMax(node* root){
	while(root->rchild!=NULL){
		r=root->rchild;//不断往右，直到没有右孩子 
	}
	return root;
}
//寻找以root为根结点的书中最小全权值点 
node* findMax(node* root){
	while(root->lchild!=NULL){
		r=root->lchild;//不断往右，直到没有右孩子 
	}
	return root;
}
//删除以root为根结点的树中权值为x的结点
void deldteNode(node* &root,int x){
	if(root==NULL)return;//不存在权值为x的结点 
	if(root->data==x){//找到想要删除的结点 
		if(root=>lchild==NULL&&root->rchild==NULL){//叶子结点直接删除 
			root=NULL; 
		}else if(root->lchild!=NULL){//左子树不为空时 
			node* pre=findMax(root->lchild);//找root前驱 
			root->data=pre->data;//用前驱覆盖root 
			deleteNode(root->lchild,pre->data);//在左子树中删除结点pre 
		}else{//右子树不为空时 
			node* next->findMin(root->rchild);//找root后继 
			root->data=next->data;//用后继覆盖root 
			deleteNode(root->rchild,next->data);//在右子树中删除结点next 
		}
	}else if(root->data>x){
		deleteNode(root->lchild,x);//在左子树中删除x 
	} else{
		deleteNode(root->rchild,x);//在右子树中删除x 
	} 
} 
