#include<cstdio>
int main(){
	int n;
	scanf("%d",&n);
	int old=0,news=0,ans=5*n;
	while(n--){
		scanf("%d",&news);
		if(news>old){
			ans+=(news-old)*6;
		}else if(news<old){
			ans+=(old-news)*4;
		}
		old=news;
	}
	printf("%d\n",ans);
	return 0;
}
