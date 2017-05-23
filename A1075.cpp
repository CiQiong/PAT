#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=10010;
struct Student{
	int id;
	int score[6];
	bool flag;
	int score_all;
	int solve;
}stu[maxn];
int n,k,m;
int full[6];
bool cmp(Student a,Student b){
	if(a.score_all!=b.score_all)return a.score_all>b.score_all;
	else if(a.solve!=b.solve)return a.solve>b.solve;
	else return a.id<b.id;
}
void init(){//起到初始化作用 
	for(int i=1;i<=n;i++){
		stu[i].id=i;
		stu[i].score_all=0;
		stu[i].solve=0;
		stu[i].flag=false;
		/*
		1. void *memset(void *s,int c,size_t n)
		总的作用：将已开辟内存空间 s 的首 n 个字节的值设为值 c。
		2. memset() 函数常用于内存空间初始化。如：
		char str[100];
		memset(str, 0, 100);  // 则 str 的每个元素都是 0
		*///需要重点掌握 
		memset(stu[i].score,-1,sizeof(stu[i].score));
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&m);
	init();
	for(int i=1;i<=k;i++){
		scanf("%d",&full[i]);//针对full中的某一项，因此用& 
	} 
	int u_id,p_id,score_obtained;
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u_id,&p_id,&score_obtained);
		if(score_obtained!=-1){
			stu[u_id].flag=true;
		}
		if(score_obtained==-1&&stu[u_id].score[p_id]==-1){
			stu[u_id].score[p_id]=0;
		}
		if(score_obtained==full[p_id]&&stu[u_id].score[p_id]<full[p_id]){
			stu[u_id].solve++;
		}
		if(score_obtained>stu[u_id].score[p_id]){
			stu[u_id].score[p_id]=score_obtained;
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			if(stu[i].score[j]!=-1){
				stu[i].score_all+=stu[i].score[j];
			}
		}
	}
	sort(stu+1,stu+1+n,cmp);
	int r=1;
	for(int i=1;i<=n&&stu[i].flag==true;i++){
		if(i>1&&stu[i].score_all!=stu[i-1].score_all){
			r=i;
		}
		printf("%d %05d %d",r,stu[i].id,stu[i].score_all);
		for(int j=1;j<=k;j++){
			if(stu[i].score[j]==-1){
				printf(" -");
			}else{
				printf(" %d",stu[i].score[j]);
			}
		}
		printf("\n");
	}
	return 0;
} 
