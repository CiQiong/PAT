#include<cstdio>
#include<cstring>//strcmp
#include<stack>
using namespace std;
const int maxn=100010;
const int sqrN=316;//sqrt(100001),��ʾ����Ԫ�ظ���

stack<int> st;//ջ
int block[sqrN];//��¼ÿһ���д��ڵ�Ԫ�ظ���
int table[maxn];//hash���飬��¼Ԫ�ص�ǰ���ڵĸ���

void peekMedian(int k){
	int sum=0;//sum��ŵ�ǰ�ۼƴ��ڵ����ĸ���
	int idx=0;//���
	while(sum+block[idx]<k){
		sum+=table[idx++];//�ۼӿ���Ԫ�ظ�����ֱ��sum�ﵽk 
	} 
	int num=idx*sqrN;
	while(sum+table[num]<k){
		sum+=table[num++];
	}
	printf("%d\n",num);//sum�ﵽk 
} 
void Push(int x){
	st.push(x);
	block[x/sqrN]++;
	table[x]++;
}
void Pop(){
	int x=st.top();
	st.pop();
	block[x/sqrN]--;
	table[x]--;
	printf("%d\n",x);
}
int main(){
	int x,query;
	memset(block,0,sizeof(block));
	memset(table,0,sizeof(table));
	char cmd[20];//����
	scanf("%d",&query);//��ѯ��Ŀ
	for(int i=0;i<query;i++){
		scanf("%s",cmd);
		if(strcmp(cmd,"Push")==0){
			scanf("%d",&x);
			Push(x);//��ջ 
		}else if(strcmp(cmd,"Pop")==0){
			if(st.empty()==true){
				printf("Invalid\n");
			}else{
				Pop();//��ջ 
			}
		}else{
			if(st.empty()==true){
				printf("Invalid\n");
			}else{
				int K=st.size();
				if(K%2==1)K=(K+1)/2;
				else K=K/2;
				peekMedian(K);
			}
		} 
	} 
	return 0;
}
