//ÖÐÐø±éÀú
#include<iostream>
#include<string>
using namespace std;

struct node{
	string data;
	node* lchild;
	node* rchild;
}N[21];

void inorder(node* root){
	if(root==NULL){
		return;
	}
	cout<<"(";
	inorder(root->lchild);
	cout<<root->data;
	inorder(root->rchild);
	cout<<")";
} 

int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>N[i].data>>N[i].lchild>>N[i].rchild;
	}
	inorder(1);
	return 0;
}
