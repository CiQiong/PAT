#include<cstdio>
#include<queue>
using namespace std;
const int maxn=100;
struct node{
	int x,y;//λ��(x,y) 
}Node;
int n,m;//�����СΪm*n
int matrix[maxn][maxn];//01���� 
bool inq[maxn][maxn]={false};//��¼λ��(x,y)�Ƿ�������� 
int X[4]={0,0,1,-1};//�������� 
int Y[4]={1,-1,0,0};
bool judge(int x,int y){//�ж�����(x,y)�Ƿ���Ҫ���� 
	//Խ�緵��false
	if(x<0||x>=n||y<0||y>=m)return false;
	//��ǰλ��Ϊ0����(x,y)������ӣ�����false
	if(matrix[x][y]==0||inq[x][y]==true)return false;
	//���϶������㣬����true
	return true; 
} 
//BSF��������λ��(x,y)���ڵĿ飬�ÿ�������"1"��inq������Ϊtrue
void BFS(int x,int y){
	queue<node>Q;//������� 
	Node.x=x,Node.y=y;
	Q.push(Node);//�����Node���
	inq[x][y]=true;//����(x,y)�������
	while(!Q.empty()){
		node top=Q.front();//ȡ������Ԫ��
		Q.pop();//����Ԫ�س���
		for(int i=0;i<4;i++){//ѭ��4�Σ��õ�4������λ�� 
			int newX=top.x+X[i];
			int newY=top.y+Y[i];
			if(judge(newX,newY)){//�����λ��(x,y)��Ҫ���� 
				//����Node������Ϊ(newX,newY)
				Node.x=newX,Node.y=newY;
				Q.push(Node);//�����Node�������
				inq[newX][newY]=true;//����λ��(newX,newY)������� 
			} 
		} 
	} 
} 
int main(){
	scanf("%d%d",&n,&m);
	for(int x=0;x<n;x++){
		for(int y=0;y<m;y++){
			scanf("%d",&matrix[x][y]);//����01���� 
		}
	}
	int ans=0;//��ſ���
	for(int x=0;x<n;x++){//ö��ÿһ��λ�� 
		for(int y=0;y<m;y++){
			//���Ԫ��Ϊ1���������
			if(matrix[x][y]==1&&inq[x][y]==false){
				ans++;//������һ 
				BFS(x,y);//���������飬���ÿ�����"1"��inq�����Ϊtrue 
			} 
		}
	}
	printf("%d\n",ans);
	return 0;
} 
