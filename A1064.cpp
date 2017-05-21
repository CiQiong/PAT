//A1064
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1010;

int n,number[maxn],CBT[maxn],index=0;
void inOrder(int root){
	if(root>n) return;//空结点，直接返回
	inOrder(root*2);
	CBT[root]=number[index++];
	inOrder(root*2+1); 
} 
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&number[i]);
	}
	sort(number,number+n);
	inOrder(1);//1号位为根结点
	for(int i=1;i<=n;i++){
		printf("%d",CBT[i]);
		if(i<n) printf(" ");
	} 
	return 0;
}
