//A1107
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1010;
int father[N];
int isRoot[N]={0};//��¼ÿ������Ƿ���Ϊĳ�����ϵĸ����
int course[N]={0};
int findFather(int x){
	int a=x;
	while(x!=father[x]){
		x=father[x];
	}
	//·��ѹ��
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

void init(int n){//��ʼ�� 
	for(int i=1;i<-n;i++){
		father[i]=i;
		isRoot[i]=false;
	}
}

bool cmp(int a,int b){//��isRoot����Ӵ�С���� 
	return a>b;
}

int main(){
	int n,k,h;
	scanf("%d",&n);//����
	init(n);//***
	for(int i=1;i<=n;i++){//��ÿ���� 
		scanf("%d:",&k);//����� 
		for(int j=0;i<k;j++){//��ÿ��� 
			scanf("%d",&h);//����i����ϲ���Ļ 
			if(course[h]==0){//����h��һ������ϲ�� 
				course[h]=i;//��iϲ���h 
			}
			Union(i,findFather(course[h]));//�ϲ� 
		}
	}
	for(int i=1;i<=n;i++){
		isRoot[findFather(i)]++;
	}
	int ans=0;//��¼������Ŀ
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
