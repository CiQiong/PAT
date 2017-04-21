#include<cstdio>
typedyf long long LL;
//一 
//求n!中有多少个质因子P
int cal(int n,int p){
	int ans=0;
	for(int i=2;i<=n;i++){
		int temp=i;
		while(temp%p==0){
			ans++;
			temp/=p;
		}
	}
	return ans;
} 
int cal2(int n,int p){
	int ans=0;
	while(n){
		ans+=n/p;//累加n/p^k 
		n/=p;//相当于分母多乘了一个p 
	}
	return ans;
}
int cal3(int n,int p){//cal2的递归版本 
	if(n<p)return 0;
	return n/p+cal(n/p,p);
}


//二 
//组合数计算C(n,m)=n!/(m!(n-m)!) 
//方法一：通过定义式直接计算： n=21,m=10 
//只能计算21以内的n，多了会超出界限 
LL C1(LL n,LL m){
	LL ans=1;
	for(LL i=1;i<=n;i++){
		ans*=i;
	}
	for(LL i=1;i<=m;i++){
		ans/=i
	}
	for(LL i=1;i<=n-m;i++){
		ans/=i;
	}
	return ans;
}
//方法二：通过递推公式计算C(m,n)=C(m,n-1)+C(m-1,n) n=67,m=33 
//普通递归代码 
LL C2(LL n,LL m){
	if(m==0||m==n)return 1;
	return C2(n-1,m)+C2(n-1,m-1);
} 
//动态规划的递归代码 单次<O(n^2) 多次优先下一个方法 
LL res[67][67]={0};
LL C3(LL n,LL m){
	if(m==0||m==n)return 1;
	if(res[n][m]!=0)return res[n][m];
	return res[n][m]=C3(n-1,m)+C3(n-1,m-1);
}
//把整张表都计算出来的递推代码：O(n^2)
const int n=60;
LL res2[67][67]={0};
void C4(){
	for(int i=0;i<=n;i++){
		res2[i][0]=res2[i][i]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<=i/2;j++){
			res2[i][j]=res2[i-1][j]+res2[i-1][j-1];
			res2[i][i-j]=res2[i][j];//C(i,i-j)=C(i,j) 
		}
	}
} 
//方法三：通过定义式的变形来计算O(m) n=62,m=31 
LL C5(LL n,LL m){
	LL ans=1;
	for(LL i=1;i<=m;i++){
		ans=ans*(n-m+1)/i;//注意一定要先乘再除 
	}
	return ans; 
}


//三
//如何计算(C(n,m))%p
//方法一：通过递推公式计算
int res[1010][1010]={0};
int calC1(int n, int m, int p){
	if(m==0||m==n)return 1;
	if(res[n][m]!=0)return res[n][m];
	return res[n][m]=(C3(n-1,m)+C3(n-1,m-1))%p;
}
void calC2(){
	for(int i=0;i<=n;i++){
		res[i][0]=res[i][i]=1;
	}
	for(int i=2;i<=n;i++){
		for(int j=0;j<=i/2;j++){
			res[i][j]=(res[i-1][j]+res[i-1][j-1])%p;
			res[i][i-j]=res[i][j];
		}
	}
}
//方法二：根据定义式计算
//对组合数C(n,m)质因子分解
//使用筛法得到素数表prime，注意表中最大的素数不得小于n 
int prime[maxn]; 

//计算C(n,m)%p
int calC3(int n,int m,int p){
	int ans=1;
	for(int i=0;prime[i]<=n;i++){
		//计算C(n,m)中prime[i]的指数c,cal(n,k)为n!中含质因子k的个数 
		int c=cal(n,prime[i])-cal(m,prime[i])-cal(n-m,prime[i]);
		//快速计算prime[i]^c%p 
		ans=ans*binaryPow(prime[i],c,p)%p;
	}
	return ans;
}
//方法三：通过定义式的变形来计算 

//方法四：Lucsa定理
int Lucsa(int n,int m){
	if(m==0)return 1;
	return C(n%p,m%p)8Lusca(n/p,m/p)%p;
} 
int main(){
	int n,b,ans;
	scanf("%d%d",&n,&b);
	printf("%d",cal2(n,b));
	return 0;
} 
