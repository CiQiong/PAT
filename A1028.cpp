#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=100010;
struct Student{
	int id;
	char name[10];
	int score;
}stu[maxn];
bool cmp1(Student a,Student b){
	return a.id<b.id;
} 
bool cmp2(Student a,Student b){
	int s=strcmp(a.name,b.name);
	if(s!=0)return s<0;
	else return a.id<b.id;
} 
bool cmp3(Student a,Student b){
	if(a.score!=b.score)return a.score<b.score;
	else return a.id<b.id;
} 
int main(){
	int x,y;
	scanf("%d%d",&x,&y);
	for(int i=0;i<x;i++){
		scanf("%d%s%d",&stu[i].id,stu[i].name,&stu[i].score);
	}
	if(y==1)sort(stu,stu+x,cmp1);
	else if(y==2)sort(stu,stu+x,cmp2);
	else sort(stu,stu+x,cmp3);
	for(int i=0;i<x;i++){
		printf("%06d %s %d\n",stu[i].id,stu[i].name,stu[i].score);
	}
	return 0;
}
