#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	//next_permutation()
	//给出一个序列在全排列中的下一个序列
	int a[10]={1,2,3,4,5,6,7};
	do{
		printf("%d%d%d%d%d%d\n",a[0],a[1],a[2],a[3],a[4],a[5]);
	}while(next_permutation(a+1,a+5));
	return 0;
}

 
