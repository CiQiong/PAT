#include<queue>
#include<cstdio>
using namespace std;
//Ѱ����rootΪ�������������ȫȨֵ�� 
node* findMax(node* root){
	while(root->rchild!=NULL){
		r=root->rchild;//�������ң�ֱ��û���Һ��� 
	}
	return root;
}
//Ѱ����rootΪ������������СȫȨֵ�� 
node* findMax(node* root){
	while(root->lchild!=NULL){
		r=root->lchild;//�������ң�ֱ��û���Һ��� 
	}
	return root;
}
//ɾ����rootΪ����������ȨֵΪx�Ľ��
void deldteNode(node* &root,int x){
	if(root==NULL)return;//������ȨֵΪx�Ľ�� 
	if(root->data==x){//�ҵ���Ҫɾ���Ľ�� 
		if(root=>lchild==NULL&&root->rchild==NULL){//Ҷ�ӽ��ֱ��ɾ�� 
			root=NULL; 
		}else if(root->lchild!=NULL){//��������Ϊ��ʱ 
			node* pre=findMax(root->lchild);//��rootǰ�� 
			root->data=pre->data;//��ǰ������root 
			deleteNode(root->lchild,pre->data);//����������ɾ�����pre 
		}else{//��������Ϊ��ʱ 
			node* next->findMin(root->rchild);//��root��� 
			root->data=next->data;//�ú�̸���root 
			deleteNode(root->rchild,next->data);//����������ɾ�����next 
		}
	}else if(root->data>x){
		deleteNode(root->lchild,x);//����������ɾ��x 
	} else{
		deleteNode(root->rchild,x);//����������ɾ��x 
	} 
} 
