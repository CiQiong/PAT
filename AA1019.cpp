//给两个数，第一个数是十进制，判断第一个数在第二个数进制下是不是回文
#include<cstdio>
bool Judge(int z[],int num){//判断是否是回文//可以背会 
	for(int i=0;i<=num/2;i++){
		if(z[i]!=z[num-1-i])return false;
	}
	return true;
} 
int main(){
	int n,b,z[40],num;
	scanf("%d%d",&n,&b);
	do{
		z[num++]=n%b;
		n/=b;
	}while(n!=0);//进制转换//可以背会 
	if(Judge(z,num))printf("Yes\n");
	else printf("No\n");
	for(int i=num-1;i>=0;i--){
		printf("%d",z[i]);
		if(i!=0)printf(" ");
	}
	return 0;
}
