#include<cstdio>
#include<vector>
using namespace std;
const int MAXN=110;
vector<int> Node[MAXN];//���ľ�̬д����Node[i]��Ž��i�ĺ��ӽ����
int hashTable[MAXN]={0};//��¼ÿ��Ľ�����
void DFS(int index,int level){
	hashTable[level]++;//��leve��Ľ�������1
	for(int j=0;j<Node[index].size();j++){
		DFS(Node[index][j],level+1);//�������к��ӽ�㣬���еݹ� 
	} 
} 
int main(){
	int n,m,parent,k,child;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d",&parent,&k);//���׽���ţ����Ӹ���
		for(int j=0;j<k;j++){
			scanf("%d",&child);//���ӽ����
			Node[parent].push_back(child);//���� 
		} 
	}
	DFS(1,1);//�����Ϊ1�Ž�㣬���Ϊ1
	int maxLevel=-1,maxValue=0;
	for(int i=1;i<MAXN;i++){//����hashTable��������ֵ 
		if(hashTable[i]>maxValue){
			maxValue=hashTable[i];
			maxLevel=i;
		}
	} 
	printf("%d %d\n",maxValue,maxLevel);//������ڵ�����ò���
	return 0; 
}
