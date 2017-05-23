#include<cstdio>
struct person{
	char name[11];
	char id[11];
	int score;
}M,F,temp;
int main(){
	M.score=101;
	F.score=-1;
	int n;
	char gender;//ÐÔ±ð¡£
	scanf("%d",&n);
	while(n--){
		scanf("%s %c %s %d",temp.name,&gender,temp.id,&temp.score);
		if(gender=='M'&&temp.score<M.score)M=temp;
		else if(gender=='F'&&temp.score>F.score)F=temp;
	} 
	if(F.score==-1)printf("Absent\n");
	else printf("%s %s\n",F.name,F.id);
	if(M.score==101)printf("Absent\n");
	else printf("%s %s\n",M.name,M.id);
	if(F.score==-1||M.score==101)printf("NA\n");
	else printf("%d\n",F.score-M.score);
	return 0;
}
