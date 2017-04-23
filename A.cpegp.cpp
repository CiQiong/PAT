#include<cstdio>
#include<map>
using namespace std;
int main(){
	int n,m,col;
	scanf("%d%d",&n,&m);
	map<int,int>count;
	while(n--){
		while(m--){
			scanf("%d",&col);
			if(count.find(col)!=count.end())count[col]++;
			else count[col]=1;
		}
	}
	int k=0,max=0;
	for(map<int,int>::iterator it=count.begin();it!=count.end();it++){
		if(it->second>max){
			k=it->first;
			max=it->second;
		}
	}
	printf("%d\n",k);
	return 0;
}
