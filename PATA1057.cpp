/* 
//�ֿ�˼�� 
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
*/
 
 //��״����
#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
#define lowbit(i) ((i)&(i-1))
const int MAXN=100010;
stack<int> s;
int c[MAXN];//��״����
void update(int x,int v){//���²�������λ��x�ϵ�Ԫ�ؼ���v 
	for(int i=x;i<MAXN;i+=lowbit(i)){
		c[i]+=v;
	}
} 
int getSum(int x){
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i)){
		sum+=c[i];
	}
	return sum;
} 
void PeekMedian(){//���ַ����K�� 
	int l=1,r=MAXN,mid,K=(s.size()+1)/2;
	while(l<r){
		mid=(l+r)/2;
		if(getSum(mid)>=K)r=mid;
		else l=mid+1;
	}
}
int main(){
	int n,x;
	char str[12];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",str);
		if(strcmp(str,"Push")==0){
			scanf("%d",&x);
			s.push(x);//��ջ
			update(x,1);//��λ��x��1 
		}else if(strcmp(str,"Pop")==0){
			if(s.empty()){
				printf("Invalid\n");
			}else{
				printf("%d\n",s.top());//���ջ�� 
				update(s.top(),-1);//��ջ��Ԫ������λ�ü�1 
				s.pop();//��ջ 
			}
		}else if(strcmp(str,"PeekMedian")==0){//����λ�� 
			if(s.empty()){
				printf("Invalid\n");//û��Ԫ�أ��Ƿ� 
			}else{
				PeekMedian();//����λ�� 
			}
		}
	}
	return 0;
}
