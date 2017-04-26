#include<cstdio>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
const int maxn=50;
struct node{
	int data;
	node* lchild;
	node* rchild;
};
int pre[maxn],in[maxn],post[maxn];//���������Լ�����
int n;//������
//��ǰ��������������������Ϊ[preL,preR]��������������Ϊ[inL,inR]
//create�������ع������Ķ������ĸ�����ַ
node* create(int preL,int preR,int inL,int inR){
	if(preL>preR)return NULL;//���������г���С�ڵ���0����ֱ�ӷ���
	node* root=new node;//�½�һ���µĽ�㣬������ŵ�ǰ�������ĸ����
	root->data=pre[preL];//�½���������Ϊ������ֵ
	int k;
	for(k=inL;k<inR;k++){
		if(in[k]==pre[preL]){//�������������ҵ�������ַ 
			break;
		}
	} 
	int numLeft=k-inL;//�������Ľ�����
	//�����������ĸ�����ַ����ֵ��root����ָ��
	root->lchild=create(preL+1,preL+numLeft,inL,k-1);
	//�����������ĸ�����ַ����ֵ��root����ָ��
	root->rchild=create(preL+numLeft+1,preR,k+1,inR);
	return root;//���ظ�����ַ 
} 
int num=0;//�����������
void postorder(node* root){//������� 
	if(root==NULL)return;
	postorder(root->lchild);
	postorder(root->rchild);
	printf("%d",root->data);
	num++;
	if(num<n)printf(" "); 
} 
int main(){
	scanf("%d",&n);
	char str[5];
	stack<int> st;
	int x,preIndex=0,inIndex=0;//��ջԪ�ء���������λ���Լ���������λ��
	for(int i=0;i<2*n;i++){//��ջ��ջ��2n��
		scanf("%s",str);
		if(strcmp(str,"Push")==0){
			scanf("%d",&x);
			pre[inIndex++]=x;
			st.push(x); 
		}else{
			in[inIndex++]=st.top();
			st.pop();
		}
	}
	node* root=create(0,n-1,0,n-1);
	postorder(root);
	return 0;
}

