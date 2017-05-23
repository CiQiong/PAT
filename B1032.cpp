#include<cstdio>
const int maxn=100010;
int school[maxn]={0};
int main()
{
	int n,id,score;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&id,&score);
		school[id]+=score;
	}
	int maxid=1,maxscore=-1; 
	for(int i=0;i<n;i++){
		if(school[i+1]>maxscore){
			maxscore=school[i+1];
			maxid=i+1;
		}
	}
	printf("%d %d",maxid,maxscore);
	return 0;
} 
