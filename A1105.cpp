#include<cstdio>//输入输出 
#include<cmath>//开根号
#include<algorithm>//排序 
using namespace std;
const int maxn=10010;
int matrix[maxn][maxn],A[maxn];
bool cmp(int a,int b){
	return a>b;
} 
int main(){
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	if(N==1){//只有一个数时特判输出 
		printf("%d",A[0]);
		return 0;
	}
	sort(A,A+N,cmp);
	//int n=sqrt(N);
	int n=(int)ceil(sqrt(1.0*N));
	while(N%n!=0){
		n--;
	}
	int m=N/n,i=1,j=1,now=0;//m为行数，i、j为当前欲填的位置，now指向序列中当前待填的数的下标
	int U=1,D=m,L=1,R=n;//4个边界
	
	while(now<N){
		while(now<N&&j<R){
			matrix[i][j]=A[now++];
			j++;
		}
		while(now<N&&i<D){
			matrix[i][j]=A[now++];
			i++;
		}
		while(now<N&&j>L){
			matrix[i][j]=A[now++];
			j--;
		}
		while(now<N&&i>U){
			matrix[i][j]=A[now++];
			i--;
		}
		U++,D--,L++,R--;//缩小边界
		i++,j++;//位置移动到内层左上角,i++是因为前一步出现了i-- 
		if(now==N-1){
			matrix[i][j]=A[now++];//now没有++的话不会结束 
		}
	}
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			printf("%d",matrix[i][j]);
			if(j<n)printf(" ");
			else printf("\n");
		}
	}
	return 0;
}
 
