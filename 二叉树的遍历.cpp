#include<cstring>
#include<algorithm> 
#include<queue>
#include<cstdio>
using namespace std; 
/* 
struct node{
	int data;//������ 
	int layer;//��� 
	node* lchild;//��ָ���� 
	node* rchlid;//��ָ���� 
}; 
//�������
void preorder(node* root){
	if(root==NULL){
		return;
	}
	printf("%d\n",root->data);
	preorder(root->lchild);
	preorder(root->rchlid);
} 
//�������
void inorder(node* root){
	if(root==NULL){
		return;
	}
	inorder(root->lchild);
	printf("%d\n",root->data);
	inorder(root->rchlid);
} 
//�������
void postorder(node* root){
	if(root==NULL){
		return;
	}
	postorder(root->lchild);
	postorder(root->rchlid);
	printf("%d\n",root->data);
}
//���Ĳ������

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
//��ǰ������������Ϊ[preL,preR],������������Ϊ[inL,inR],���ظ�����ַ 
node* create(int preL,int preR,int inL,int inR){
	if(preL>preR){
		return NULL;//�������г���С�ڵ�����ʱ��ֱ�ӷ��� 
	}
	node* root=new node;//�½�һ���½�㣬������ŵ�ǰ�������ĸ���� 
	root->data=pre[preL];//�½���������Ϊ������ֵ 
	int k;
	for(k=inL;k<=inR;k++){
		if(in[k]==pre[preL]){//�������������ҵ���ǰ�ĸ����λ�� 
			break;
		}
	}
	int numLeft=k-inL;//�������Ľ�����(k-1)-inL+1
	//����������������Ϊ[preL+1,preL+numLeft],��������Ϊ[inL,k-1]
	//�����������ĸ�����ַ����ֵ��root����ָ��
	root->lchild=create(preL+1,preL+numLeft,inL,k-1);
	//����������������Ϊ[preL+numLeft+1,preR],��������Ϊ[k+1,inR]
	//�����������ĸ�����ַ����ֵ��root����ָ��
	root->rchlid=create(preL+numLeft+1,preR,k+1,inR);
	return root;//���ظ�����ַ 
} */ 

//�������ľ�̬ʵ��
 struct node{
 	int data;//������
	int lchild;//ָ����������ָ����
	int rchild;//ָ����������ָ���� 
 }Node[maxn];//������飬maxnΪ������޸���
 //���ľ�ָ̬�� 
 int index=0;
 int newNode(int v){//����һ��Node�����еĽ����µĽ�㣬indexΪ���±�
 	Node[index].data=v;
 	Node[index].lchild=-1;//��-1��maxn��ʾ�գ���Ϊ���鷶Χ��0~maxn-1
	Node[index].rchild=-1;
	return index++;
 } 
 //���ң�rootΪ������������е��±�
 void search(int root,int x,int newdata){
 	if(root==-1){//��-1������NULL
 		return;//����������ͬ(�ݹ�߽�)
	}
	if(Node[root].data==x)
		Node[root].data=newdata;
	}
	search(Node[root].lchild,x,newdata);
	search(Node[root].rchild,x,newdata);
 }
 //���룬rootΪ������������е��±�
 void insert(int &root,int x){//�ǵü�����
 	if(root==-1){
 		root=newNode(x);
 		return;
	 } 
	 if(�ɶ�����������xӦ�ò���������){
	 	insert(Node[root].lchild,x); 
	 }else{
	 	insert(Node[root].rchild,x);
	 }
 }
 //
