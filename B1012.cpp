#include<cstdio>
int main(){
	int count[5]={0};
	int ans[5]={0};
	int n,temp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
			scanf("%d",&temp);
			if(temp%10==0){
				ans[0]+=temp;
				count[0]++;
			}else if(temp%5==1){
				if(count[1]%2==0){
					ans[1]+=temp;
				}else{
					ans[1]-=temp;
				}
				count[1]++;
			}else if(temp%5==2){
				count[2]++;
			}else if(temp%5==3){
				ans[3]+=temp;
				ans[3]++;
			}else if(temp%5==4){
				if(temp>ans[4]){
					ans[4]=temp;
			} 
			count[4]++;
		}
	}
	if(count[0])
	return 0;
}
	
