#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N=40010;//×ÜÈËÊı 
const int M=26*26*26*10+1;
vector<int> selectCourse[M];
int getID(char name[]){
	int id=0;
	for(int i=0;i<3;i++){
		id=id*26+(name[i]-'A');
	}
	id=id*10+(name[3]-'0');
	return id;
}
int main(){
	char name[5];
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<k;i++){
		int course,x;
		scanf("%d%d",&course,&x);
		while(x--){
			scanf("%s",name);
			int id=getID(name);
			selectCourse[id].push_back(course);
		} 
	}
	while(n--){
		scanf("%s",name);
		int id=getID(name);
		sort(selectCourse[id].begin(),selectCourse[id].end());
		printf("%s %d",name,selectCourse[id].size());
		for(int j=0;j<selectCourse[id].size();j++){
			printf(" %d",selectCourse[id][j]);
		}
		printf("\n");
	}
	return 0;
}
