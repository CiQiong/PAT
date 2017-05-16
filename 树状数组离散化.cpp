//��״����
//ͳ����������Ԫ����߱ȸ�Ԫ��С��Ԫ�صĸ���
//��ɢ������
//ֻ֧�����߲�ѯ 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
#define lowbit(i) ((i)&(-i))
struct Node{
	int val;//����Ԫ�ص�ֵ
	int pos;//ԭʼ��� 
}temp[maxn];//temp������ʱ�����������
int A[maxn];//��ɢ�����ԭʼ����
int c[maxn];//��״����

//update��������x����������v
void update(int x,int v){
	for(int i=x;i<maxn;i+=lowbit(i)){
		c[i]+=v;
	}
} 
//getSum��������ǰx������֮��
int getSum(int x){
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i)){
		sum+=c[i];
	}
	return sum;
} 
//��val��С��������
bool cmp(Node a,Node b){
	return a.val<b.val;
} 
int main(){
	int n;
	scanf("%d",&n);
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++){
		scanf("%d",&temp[i].val);//��������Ԫ�� 
		temp[i].pos=i;//ԭʼ��� 
	}
	//��ɢ��
	sort(temp,temp+n,cmp);//��val��С��������
	for(int i=0;i<n;i++){
		//����һ��Ԫ�ز�ͬʱ����ֵΪԪ�ظ���
		if(i==0||temp[i].val!=temp[i-1].val){
			A[temp[i].pos]=i+1;//[ע��]��������1��ʼ 
		} else {//����һ��Ԫ����ͬʱ,ֱ�Ӽ̳� 
			A[temp[i].pos]=A[temp[i-1].pos]; 
		}
	}
	//��ʽ������º���Ͳ���
	for(int i=0;i<n;i++){
		update(A[i],1);
		printf("%d\n",getSum(A[i]-1));
	} 
	return 0;
	
}


int findKthElement(int K){
	int l=1;r=maxn,mid;//��ʼ������Ϊ[1,maxn]
	while(l<r){
		mid=(l+r)/2;
		if(getSum(mid)>=K)r=mid;//����λ�ò�����mid 
		else l=mid+1;//����λ�ô���mid 
	} 
	return l;//���ض��ּг���Ԫ�� 
} 
