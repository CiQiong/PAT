//A1099
//������A1064�����������˲������
#include<cstdio>
#include<queue>//���������
#include<algorithm>//sort
using namespace std;
const int maxn=110;
struct node{//�������ľ�̬д�� 
	int data;
	int lchild,rchild;
}Node[maxn];
//nΪ��������inΪ�������У�numΪ�Ѿ�����/����Ľ�����
int n,in[maxn],num=0;

void inOrder(int root){
	if(root=-1)return;
	inOrder(Node[root].lchild);
	Node[root].data=in[num++]; 
	inOrder(Node[root].rchild);
} 

void BFS(int root){
	queue<int> q;//���д���ǵ�ַ
	q.push(root);//��������ַ���
	num=0;
	while(!q.empty()){
		int now=q.front();
		q.pop();
		printf("%d",Node[now].data);
		num++;
		if(num<n) printf(" ");
		if(Node[now].lchild!=-1) q.push(Node[now].lchild);
		if(Node[now].rchild!=-1) q.push(Node[now].rchild);
	} 
}
int main(){
	int lchild,rchild;
	scanf("%d",&n);//������
	for(int i=0;i<n;i++){
		scanf("%d%d",&lchild,&rchild);
		Node[i].lchild=lchild;
		Node[i].rchild=rchild;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&in[i]); 
	} 
	sort(in,in+n);
	inOrder(0);
	BFS(0);
	return 0;
}
