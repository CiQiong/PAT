#include<cstdio>
const int maxn=101;
int Prime[maxn],pNum=0;
bool p[maxn]={0};
void find_Prime(){
	for(int i=2;i<maxn;i++){
		if(p[i]==false){
			Prime[pNum++]=i;
			for(int j=i+i;i<maxn;j+=i){
				p[j]=true;
			}
		}
	}
}
int main(){
	find_Prime();
	for(int i=0;i<pNum;i++){
		printf("%d ",Prime[i]);
	}
	return 0;
}
