#include<cstdio> 
#include<algorithm> 
#include<cmath>
using namespace std;
//ƽ�������
struct node{
	int v,height;//vΪ���Ȩֵ��heightΪ��ǰ�����߶�
	node *lchild,*rchild;//���Һ��ӽڵ��ַ 
}; 
//����һ���½�㣬vΪ���Ȩֵ 
node* newNode(int v){
	node* Node=new node;//����һ��node�ͱ����ĵ�ַ�ռ�
	Node->v=v;
	Node->height=1;
	Node->lchild=Node->rchild=NULL;
	return Node; 
} 
//��ȡ��rootΪ�����������ĵ�ǰheight
int getHeight(node* root){
	if(root==NULL)return 0;
	return root->height;
} 
//������root��ƽ������
int getBalanceFactor(node* root){
	//�������߶ȼ��������߶�
	return getHeight(root->lchild)-getHeight(root->rchild); 
} 
//���½ӽ��root��height
void updateHeight(node* root){
	//max(���ӵ�height���к��ӵ�height)+1
	root->height=max(getHeight(root->lchild),getHeight(root->rchild)+1);
} 
//
//һ�¼���ÿ������Ȩֵ������ͬ 
//
//search��������AVL����������Ϊx�Ľ��
void search(node* root,int x){
	if(root==NULL){//����������ʧ�� 
		printf("search failed\n");
		return ; 
	}
	if(x==root->v){//���ҳɹ�������֮ 
		printf("%d\n",root->v); 
	}else if(x<root->v){
		search(root->lchild,x);
	}else{
		search(root->rchild,x);
	}
} 
//���������
//����(Left Rotation)
void L(node* &root){
	node* temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	updateHeight(root);//���¸߶� 
	updateHeight(temp);//���¸߶� 
	root=temp;
} 
//����(Right Rotatio)
void R(node* &root){
	node* temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	updateHeight(root);//���¸߶� 
	updateHeight(temp);//���¸߶�
	root=temp;
} 
//����ȨֵΪv�Ľ��
void insert(node* &root,int v){
	if(root==NULL){//����ս�� 
		root=newNode(v);
		return;
	}
	if(v<root->v){//v�ȸ�����ȨֵС
		insert(root->lchild,v);//������������
		updateHeight(root);//��������
		if(getBalanceFactor(root)==2){
			if(getBalanceFactor(root->lchild)==1){//LL�� 
				R(root);
			}else if(getBalanceFactor(root->lchild)==-1){//LR�� 
				L(root->lchild);
				R(root);
			}
		} 
	} else { //v�ȸ�����Ȩֵ�� 
		insert(root->rchild,v);//������������
		updateHeight(root);//��������
		if(getBalanceFactor(root)==-2){
			if(getBalanceFactor(root->rchild)==-1){//RR�� 
				L(root);
			}else if(getBalanceFactor(root->rchild)==1){//RL�� 
				R(root->rchild);
				L(root);
			}
		} 
	} 
} 
//AVL���Ľ���
node* Create(int data[],int n){
	node* root=NULL;//�½��ո����root
	for(int i=0;i<n;i++){
		insert(root,data[i]);//��data[0]~data[n-1]����AVL���� 
	} 
	return root;//���ظ���� 
} 
int main(){
	return 0;
}
