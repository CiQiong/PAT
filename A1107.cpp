//A1107
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1010;
int father[N];
int isRoot[N]={0};//记录每个结点是否作为某个集合的根结点
int course[N]={0};
int findFather(int x){
	int a=x;
	while(x!=father[x]){
		x=father[x];
	}
	//路径压缩
	while(a!=father[a]){
		int z=a;
		father[z]=x;
		a=father[a];
	} 
	return x;
} 

void Union(int a,int b){
	int faA=findFather(a);
	int faB=findFather(b);
	if(faA!=faB){
		father[faA]=faB;
	} 
}

void init(int n){//初始化 
	for(int i=1;i<-n;i++){
		father[i]=i;
		isRoot[i]=false;
	}
}

bool cmp(int a,int b){//将isRoot数组从大到小排序 
	return a>b;
}

int main(){
	int n,k,h;
	scanf("%d",&n);//人数
	init(n);//***
	for(int i=1;i<=n;i++){//对每个人 
		scanf("%d:",&k);//活动个数 
		for(int j=0;i<k;j++){//对每个活动 
			scanf("%d",&h);//输入i号人喜欢的活动 
			if(course[h]==0){//如果活动h第一次有人喜欢 
				course[h]=i;//令i喜欢活动h 
			}
			Union(i,findFather(course[h]));//合并 
		}
	}
	for(int i=1;i<=n;i++){
		isRoot[findFather(i)]++;
	}
	int ans=0;//记录集合数目
	for(int i=1;i<=n;i++){
		if(isRoot[i]!=0){
			ans++;
		}
	} 
	printf("%d\n",ans);
	sort(isRoot+1,isRoot+n+1,cmp);
	for(int i=1;i<=ans;i++){
		printf("%d",isRoot[i]);
		if(i<ans)printf(" ");
	}
	return 0;
} 
