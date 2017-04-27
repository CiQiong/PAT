#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100005;
const int TABLE=1000010;
struct Node{//���徲̬����(����һ) 
	int address,data,next;
	int order;//����������ϵ���ţ���Ч����Ϊ2maxn 
}node[maxn];
bool isExist[TABLE]={false};//����ֵ�Ƿ��Ѿ�����
bool cmp(Node a,Node b){//��order��С�������� 
	return a.order<b.order; 
} 
int main(){
	memset(isExist,false,sizeof(isExist));//��ʼ��isExistΪδ����
	for(int i=0;i<maxn;i++){//��ʼ��(�����) 
		node[i].order=2*maxn;//��ʾ��ʼʱ��Ϊ��Ч��� 
	} 
	int n,begin,address;
	scanf("%d%d",&begin,&n);//��ʼ��ַ��������
	for(int i=0;i<n;i++){//�������н�� 
		scanf("&d",&address);
		scanf("%d%d",&node[address].data,&node[address].next);
		node[address].address=address;
	} 
	//δɾ������Ч����������ɾ������Ч������
	int countValid=0,countRemoved=0,p=begin;
	while(p!=-1){//ö������(������) 
		if(!isExist[abs(node[p].data)]){//data�ľ���ֵ������ 
			isExist[abs(node[p].data)]=true;//����Ѵ���
			node[p].order=countValid++;//��ɾ������Ŵ�0��ʼ 
		}else {//data�ľ���ֵ�Ѵ��� 
			node[p].order=maxn+countRemoved++;//��ɾ������Ŵ�maxn��ʼ 
		}
		p=node[p].next;//��һ����� 
	} 
	sort(node,node+maxn,cmp);//��order��С��������(������)
	//������(������)
	int count=countValid+countRemoved;//��Ч������
	for(int i=0;i<count;i++){
		if(i!=countValid-1&&i!=count-1){//�����һ����� 
			printf("%05d %d %05d\n",node[i].address,node[i].data,node[i+1].address);
		}else{//���һ����㵥������ 
			printf("%05d %d -1\n",node[i].address,node[i].data);
		}
	} 
	return 0;
}