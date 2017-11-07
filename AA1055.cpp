#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std; 

struct Man{
	char name[10];
	int age,money;
};

bool cmp(Man a,Man b){
	if(a.money!=b.money)return a.money>b.money;
	else if(a.age!=b.age)return a.age<b.age;
	else return strcmp(a.name,b.name)<0;
}

int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	vector<Man> man(n),ages(n);
	for(int i=0;i<n;i++){
		scanf("%s %d %d",man[i].name,&man[i].age,&man[i].money);
	}
	sort(man.begin(),man.end(),cmp);
	int Age[100010]={0},num=0;
	for(int i=0;i<n;i++){
		if(Age[man[i].age]<100){
			Age[man[i].age]++;
			ages[num++]=man[i];
		}
	}
	for(int i=1;i<=k;i++){
		printf("Case #%d:\n",i);
		int m,L,R,key=0;
		scanf("%d %d %d",&m,&L,&R);
		for(int j=0;j<num&&key<m;j++){
			if(ages[j].age>=L&&ages[j].age<=R){
				printf("%s %d %d\n",ages[j].name,ages[j].age,ages[j].money);
				key++;
			}
		}
		if(key==0)printf("None\n");
	}
	return 0;
}

