#include<cstring>
#include<algorithm> 
#include<queue>
#include<cstdio>
using namespace std; 
/* 
struct node{
	int data;//数据域 
	int layer;//层次 
	node* lchild;//左指针域 
	node* rchlid;//右指针域 
}; 
//先序遍历
void preorder(node* root){
	if(root==NULL){
		return;
	}
	printf("%d\n",root->data);
	preorder(root->lchild);
	preorder(root->rchlid);
} 
//中序遍历
void inorder(node* root){
	if(root==NULL){
		return;
	}
	inorder(root->lchild);
	printf("%d\n",root->data);
	inorder(root->rchlid);
} 
//后序遍历
void postorder(node* root){
	if(root==NULL){
		return;
	}
	postorder(root->lchild);
	postorder(root->rchlid);
	printf("%d\n",root->data);
}
//树的层序遍历

void LayerOrder(node* root){
	queue<node* > q;
	root->layer=1;
	q.push(root);
	while(!q.empty()){
		node* now=q.front();
		q.pop();
		printf("%d ",now->data);
		if(now->lchild!=NULL){
			now->lchild->layer=now->layer+1;
			q.push(now->lchild);
		}
		if(now->rchlid!=NULL){
			now->rchlid->layer=now->layer+1;
			q.push(now->rchlid);
		}
	}
}
//当前先序序列区间为[preL,preR],中序序列区间为[inL,inR],返回根结点地址 
node* create(int preL,int preR,int inL,int inR){
	if(preL>preR){
		return NULL;//先序序列长度小于等于零时，直接返回 
	}
	node* root=new node;//新建一个新结点，用来存放当前二叉树的根结点 
	root->data=pre[preL];//新结点的数据域为根结点的值 
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==pre[preL]){//在中序序列中找到当前的根结点位置 
			break;
		}
	}
	int numLeft=k-inL;//左子树的结点个数(k-1)-inL+1
	//左子树的先序区间为[preL+1,preL+numLeft],中序区间为[inL,k-1]
	//返回左子树的根结点地址，赋值给root的左指针
	root->lchild=create(preL+1,preL+numLeft,inL,k-1);
	//右子树的先序区间为[preL+numLeft+1,preR],中序区间为[k+1,inR]
	//返回右子树的根结点地址，赋值给root的右指针
	root->rchlid=create(preL+numLeft+1,preR,k+1,inR);
	return root;//返回根结点地址 
} */ 

//二叉树的静态实现
 struct node{
 	int data;//数据域
	int lchild;//指向左子树的指针域
	int rchild;//指向右子树的指针域 
 }Node[maxn];//结点数组，maxn为结点上限个数
 //结点的静态指定 
 int index=0;
 int newNode(int v){//分配一个Node数组中的结点给新的结点，index为其下标
 	Node[index].data=v;
 	Node[index].lchild=-1;//以-1或maxn表示空，因为数组范围是0~maxn-1
	Node[index].rchild=-1;
	return index++;
 } 
 //查找，root为根结点在数组中的下标
 void search(int root,int x,int newdata){
 	if(root==-1){//用-1来代替NULL
 		return;//空树，死胡同(递归边界)
	}
	if(Node[root].data==x)
		Node[root].data=newdata;
	}
	search(Node[root].lchild,x,newdata);
	search(Node[root].rchild,x,newdata);
 }
 //插入，root为根结点在数组中的下标
 void insert(int &root,int x){//记得加引用
 	if(root==-1){
 		root=newNode(x);
 		return;
	 } 
	 if(由二叉树的性质x应该插在左子树){
	 	insert(Node[root].lchild,x); 
	 }else{
	 	insert(Node[root].rchild,x);
	 }
 }
 //
