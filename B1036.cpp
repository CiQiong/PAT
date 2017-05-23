#include<cstdio>
int main(){
	int n;
	char a;
	scanf("%d %c",&n,&a);
	int h=n/2+n%2;
	for(int i=0;i<h;i++){
		if(i==0||i==h-1){
			for(int j=0;j<n;j++){
				printf("%c",a);
			}
			printf("\n");
		}else{
			for(int j=0;j<n;j++){
				if(j==0||j==n-1){
					printf("%c",a);
				}
				else{
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	return 0;
} 
