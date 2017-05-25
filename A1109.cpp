#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
struct Student{
	string name;
	int height;
}stu[10010];
bool cmp(Student a,Student b){
	if(a.height!=b.height)return a.height>b.height;
	else return a.name<b.name;
}
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%s%d",stu[i].name,&stu[i].height);
	}
	sort(stu,stu+n,cmp);
	int m=n/k;
	for(int i=0;i<m;i++){
		
	}
}
