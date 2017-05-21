#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN=110;
struct node{
	int weight;//������
	vector<int> child;//ָ���� 
}Node[MAXN];//������� 
bool cmp(int a,int b){
	return Node[a].weight>Node[b].weight;
} 
int n,m,S;//������������������ĺ�
int path[MAXN];//��¼·��
//��ǰ���ʽ��Ϊindex��numNodeΪ��ǰ·��path�ϵĽ�����,sumΪ��ǰ����Ȩ��
void DFS(int index,int numNode,int sum){
	if(sum>S) return;
	if(sum==S){
		if(Node[index].child.size()!=0) return;
		//����Ҷ�ӽ�㣬��ʱpath[]�д����һ��������·���������
		for(int i=0;i<numNode;i++){
			printf("%d",Node[path[i]].weight);
			if(i<numNode-1)printf(" ");
			else printf("\n");
		} 
		return;
	}
	//if(sum<S)
	for(int i=0;i<Node[index].child.size();i++){//ö�������ӽ�� 
		int child=Node[index].child[i];//���index�ĵ�i���ӽ�� 
		path[numNode]=child;//�����child��ӵ�·��pathĩβ 
		DFS(child,numNode+1,sum+Node[child].weight);
	}
} 
int main(){
	scanf("%d%d%d",&n,&m,&S);//n�����ݣ�m����Ҷ�ӽ�㣬SΪҪ����ȵ�Ȩֵ�� 
	for(int i=0;i<n;i++){
		scanf("%d",&Node[i].weight);
	}
	int id,k,child;
	for(int i=0;i<m;i++){
		scanf("%d%d",&id,&k);//����ż����ӽ��ĸ���
		for(int j=0;j<k;j++){
			scanf("%d",&child);
			Node[id].child.push_back(child); 
		} 
		//��ÿ����Ҷ�ӽ��������ӽ������ 
		sort(Node[id].child.begin(),Node[id].child.end(),cmp);//���� 
	} 
	path[0]=0;//·���ĵ�һ���������Ϊ0�Ž��
	DFS(0,1,Node[0].weight);
	return 0; 
} 
