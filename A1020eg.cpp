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
int pre[maxn],in[maxn],post[maxn];//���������Լ�����
int n;//������

//��ǰ�������ĺ�������Ϊ[postL,postR],��������Ϊ[inL,inR]
//create�������ع������Ķ������ĸ����ĵ�ַ
node* create(int postL,int postR,int inL,int inR){
	if(postL>postR ) return NULL;//���������г���С�ڵ���0����ֱ�ӷ���
	node* root=new node;//�½�һ����㣬������Ŷ������ĸ����
	root->data=post[postR];//�½ڵ��������Ϊ������ֵ
	int k;//���������и����ĵ�ַ
	for(k=inL;k<=inR;k++){
		if(in[k]==post[postR])break;//�ҵ����������и����ĵ�ַ 
	} 
	int numLeft=k-inL;//�������Ľ����� 
	//���������к������������������˵Ľ���ַΪ��׼��create����������������ַ 
	root->lchild=create(postL,postL+numLeft-1,inL,k-1); 
	//�����������ĸ�����ַ����ֵ��root����ָ��
	root->rchild=create(postL+numLeft,postR-1,k+1,inR);
	return root;//���ظ�����ַ 
} 

int num=0;//������Ľ�����
void BFS(node* root){
	queue<node*>q;//�����������ַ
	q.push(root);//��������ַ���
	while(!q.empty()){
		node* now=q.front();//ȡ������Ԫ��
		q.pop();
		printf("%d",now->data);//���ʶ���Ԫ��
		num++;
		if(num<0)printf(" ");
		if(now->lchild!=NULL) q.push(now->lchild);//�������ǿ�/////////ֻ���һ���� 
		if(now->rchild!=NULL) q.push(now->rchild);//�������ǿ� 
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
	node* root=create(0,n-1,0,n-1);//����
	BFS(root);//�������
	return 0; 
} 
















