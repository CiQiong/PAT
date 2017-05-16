//树状数组
#include<cstdio>
#include<cstring>
const int maxn=100010;
#define lowbit(i) ((i)&(-i)) 
int c[maxn];//树状数组
//update函数将第x个整数加上v
void update(int x,int v){
	for(int i=x;i<maxn;i+=lowbit(i)){
		c[i]+=v;
	}
} 
//getSum函数返回前x个整数之和 
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
		scanf("%d",&x);//输入序列元素
		update(x,1);//x的出现次数加1
		printf("%d\n",getSum(x-1));//查询当前小于x的数的个数 
	}
	return 0; 
}
