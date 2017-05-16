//��״����
#include<cstdio>
#include<cstring>
const int maxn=100010;
#define lowbit(i) ((i)&(-i)) 
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
int main(){
	int n,x;
	scanf("%d",&n);
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++){
		scanf("%d",&x);//��������Ԫ��
		update(x,1);//x�ĳ��ִ�����1
		printf("%d\n",getSum(x-1));//��ѯ��ǰС��x�����ĸ��� 
	}
	return 0; 
}
