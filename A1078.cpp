#include<cstdio>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=11111;
bool isPrime(int n){
	if(n<=1)return false;
	int sqr=(int)sqrt(1.0*n);
	for(int i=2;i<=sqr;i++){
		if(n%i==0)return false; 
	}
	return true;
}
bool hashTable[maxn]={0};//hashTable[i]==false��ʾδ��ʹ��
int main(){
	int n,TSize,a;
	scanf("%d%d",&TSize,&n);
	while(isPrime(TSize)==false){//�ҵ���һ�����ڵ���TSize������ 
		TSize++;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&a);
		int M=a%TSize;
		if(hashTable[M]==false){
			hashTable[M]=true;
			if(i==0)printf("%d",M);
			else printf(" %d",M);
		}else{//ʹ�ö���̽�鷨 
			int step;
			for(step=1;step<TSize;step++){
				M=(a+step*step)%TSize;
				if(hashTable[M]==false){
					hashTable[M]=true;
					if(i==0)printf("%d",M);
					else printf(" %d",M);
					break;
				}
			} 
			if(step>=TSize){//����Ҳ�������ĵط� 
				if(i>0)printf(" ");
				printf("-");
			}
		}
	}
	return 0; 
} 
