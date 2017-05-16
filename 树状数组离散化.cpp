//树状数组
//统计序列中在元素左边比该元素小的元素的个数
//离散化做法
//只支持离线查询 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
#define lowbit(i) ((i)&(-i))
struct Node{
	int val;//序列元素的值
	int pos;//原始序号 
}temp[maxn];//temp数组临时存放输入数据
int A[maxn];//离散化后的原始数组
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
//按val从小到大排序
bool cmp(Node a,Node b){
	return a.val<b.val;
} 
int main(){
	int n;
	scanf("%d",&n);
	memset(c,0,sizeof(c));
	for(int i=0;i<n;i++){
		scanf("%d",&temp[i].val);//输入序列元素 
		temp[i].pos=i;//原始序号 
	}
	//离散化
	sort(temp,temp+n,cmp);//按val从小到大排序
	for(int i=0;i<n;i++){
		//遇上一个元素不同时，赋值为元素个数
		if(i==0||temp[i].val!=temp[i-1].val){
			A[temp[i].pos]=i+1;//[注意]这里必须从1开始 
		} else {//与上一个元素相同时,直接继承 
			A[temp[i].pos]=A[temp[i-1].pos]; 
		}
	}
	//正式进入更新和求和操作
	for(int i=0;i<n;i++){
		update(A[i],1);
		printf("%d\n",getSum(A[i]-1));
	} 
	return 0;
	
}


int findKthElement(int K){
	int l=1;r=maxn,mid;//初始化区间为[1,maxn]
	while(l<r){
		mid=(l+r)/2;
		if(getSum(mid)>=K)r=mid;//所求位置不超过mid 
		else l=mid+1;//所求位置大于mid 
	} 
	return l;//返回二分夹出的元素 
} 
