#include<cstdio>
typedyf long long LL;
//һ 
//��n!���ж��ٸ�������P
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
		ans+=n/p;//�ۼ�n/p^k 
		n/=p;//�൱�ڷ�ĸ�����һ��p 
	}
	return ans;
}
int cal3(int n,int p){//cal2�ĵݹ�汾 
	if(n<p)return 0;
	return n/p+cal(n/p,p);
}


//�� 
//���������C(n,m)=n!/(m!(n-m)!) 
//����һ��ͨ������ʽֱ�Ӽ��㣺 n=21,m=10 
//ֻ�ܼ���21���ڵ�n�����˻ᳬ������ 
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
//��������ͨ�����ƹ�ʽ����C(m,n)=C(m,n-1)+C(m-1,n) n=67,m=33 
//��ͨ�ݹ���� 
LL C2(LL n,LL m){
	if(m==0||m==n)return 1;
	return C2(n-1,m)+C2(n-1,m-1);
} 
//��̬�滮�ĵݹ���� ����<O(n^2) ���������һ������ 
LL res[67][67]={0};
LL C3(LL n,LL m){
	if(m==0||m==n)return 1;
	if(res[n][m]!=0)return res[n][m];
	return res[n][m]=C3(n-1,m)+C3(n-1,m-1);
}
//�����ű���������ĵ��ƴ��룺O(n^2)
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
//��������ͨ������ʽ�ı���������O(m) n=62,m=31 
LL C5(LL n,LL m){
	LL ans=1;
	for(LL i=1;i<=m;i++){
		ans=ans*(n-m+1)/i;//ע��һ��Ҫ�ȳ��ٳ� 
	}
	return ans; 
}


//��
//��μ���(C(n,m))%p
//����һ��ͨ�����ƹ�ʽ����
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
//�����������ݶ���ʽ����
//�������C(n,m)�����ӷֽ�
//ʹ��ɸ���õ�������prime��ע�����������������С��n 
int prime[maxn]; 

//����C(n,m)%p
int calC3(int n,int m,int p){
	int ans=1;
	for(int i=0;prime[i]<=n;i++){
		//����C(n,m)��prime[i]��ָ��c,cal(n,k)Ϊn!�к�������k�ĸ��� 
		int c=cal(n,prime[i])-cal(m,prime[i])-cal(n-m,prime[i]);
		//���ټ���prime[i]^c%p 
		ans=ans*binaryPow(prime[i],c,p)%p;
	}
	return ans;
}
//��������ͨ������ʽ�ı��������� 

//�����ģ�Lucsa����
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
