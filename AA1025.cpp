#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Student{
	char id[14];
	int sore;
	int kid;
	int krank;
}stu[30005];
bool cmp(Student a,Student b){
	if(a.sore!=b.sore)return a.sore>b.sore;
	else return strcmp(a.id,b.id)<0;
}
int main(){
	int n,k,r=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%s %d",stu[r].id,&stu[r].sore);
			stu[r].kid=i;
			r++;
		}
		sort(stu+r-k,stu+r,cmp);
		stu[r-k].krank=1;
		for(int j=r-k+1;j<r;j++){
			if(stu[j].sore==stu[j-1].sore)stu[j].krank=stu[j-1].krank;
			else stu[j].krank=j-(r-k)+1;
		}
	}
	sort(stu,stu+r,cmp);
	printf("%d\n",r);
	int rank=1;
	for(int i=0;i<r;i++){
		if(i>0&&stu[i].sore!=stu[i-1].sore)rank=i+1;
		printf("%s %d %d %d\n",stu[i].id,rank,stu[i].kid,stu[i].krank);
	}
	return 0;
}
